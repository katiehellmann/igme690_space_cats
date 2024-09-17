#include "Render/HoloPlayViewportClient.h"

#include "Render/HoloPlayRendering.h"
#include "Game/HoloPlayCapture.h"
#include "Misc/HoloPlayLog.h"
#include "Misc/HoloPlayStats.h"
#include "Misc/HoloPlayHelpers.h"
#include "IHoloPlayRuntime.h"
#include "Game/HoloPlaySceneCaptureComponent2D.h"
#include "Managers/HoloPlayDisplayManager.h"

#include "CanvasTypes.h"
#include "ClearQuad.h"

#include "CanvasItem.h"
#include "ImageUtils.h"

#include "Runtime/Launch/Resources/Version.h"

#include "Misc/FileHelper.h"
#include "GameFramework/PlayerController.h"
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
#include "GameFramework/PlayerInput.h"
#endif
#include "Engine/LocalPlayer.h"
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ScreenRendering.h"
#include "Engine/Console.h"

#if WITH_EDITOR
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"
#include "LevelEditor.h"
#include "EditorSupportDelegates.h"
#endif // WITH_EDITOR

#if ENGINE_MAJOR_VERSION < 5 || ENGINE_MINOR_VERSION < 1
#include "ImageWriteTask.h"
#include "IImageWrapperModule.h"
#endif


DECLARE_GPU_STAT_NAMED(CopyToQuilt, TEXT("Copy to quilt"));

static FName LevelEditorModuleName(TEXT("LevelEditor"));

FOnHoloPlayFrameReady FHoloPlayViewportClient::OnHoloPlayFrameReady;


void FHoloPlayScreenshotRequest::RequestScreenshot(const FString & InFilename, bool bAddFilenameSuffix, FHoloPlayScreenshotRequest::FQuiltSettings InQuiltSettings)
{
	FString GeneratedFilename = InFilename;
	CreateViewportScreenShotFilename(GeneratedFilename);
	QuiltSettings = InQuiltSettings;
	FString Extension = "png";
	const UHoloPlaySettings* HoloPlaySettings = GetDefault<UHoloPlaySettings>();
	if (HoloPlaySettings->HoloPlayScreenshotQuiltSettings.UseJPG)
	{
		Extension = "jpg";
	}

	// Compose the screenshot's filename
	if (bAddFilenameSuffix)
	{
		const bool bRemovePath = false;
		GeneratedFilename = FPaths::GetBaseFilename(GeneratedFilename, bRemovePath);
		if (QuiltSettings.NumColumns > 0)
		{
			// Make a filename suffix in a way similar to what Unity plugin does
			FString Suffix = FString::Printf(TEXT("_qs%dx%da%.2f"), QuiltSettings.NumColumns, QuiltSettings.NumRows, QuiltSettings.Aspect);
			FString GoodFilename;

			static int32 LastScreenshotIndex = -1;

			// We're inserting numeric suffix before the quilt settings, so let's use custom version of the GenerateNextBitmapFilename()
			for (int32 Index = LastScreenshotIndex + 1; Index < 10000; Index++)
			{
				GoodFilename = FString::Printf(TEXT("%s%05i%s.%s"), *GeneratedFilename, Index, *Suffix, *Extension );
				if (IFileManager::Get().FileExists(*GoodFilename) == false)
				{
					LastScreenshotIndex = Index;
					break;
				}
			}
			Filename = GoodFilename;
		}
		else
		{
			// This will add numeric suffix to the file name
			FFileHelper::GenerateNextBitmapFilename(GeneratedFilename, Extension, Filename);
		}
	}
	else
	{
		// Use exact provided file name, just add folder and extension
		Filename = GeneratedFilename;
		if (FPaths::GetExtension(Filename).Len() == 0)
		{
			Filename += TEXT(".png");
		}
	}
}

void FHoloPlayScreenshotRequest::CreateViewportScreenShotFilename(FString& InOutFilename)
{
	FString TypeName;

	TypeName = InOutFilename.IsEmpty() ? TEXT("Screenshot") : InOutFilename;
	check(!TypeName.IsEmpty());

	//default to using the path that is given
	InOutFilename = TypeName;
	if (!TypeName.Contains(TEXT("/")))
	{
		InOutFilename = GetDefault<UEngine>()->GameScreenshotSaveDirectory.Path / TypeName;
	}
}

FHoloPlayViewportClient::FHoloPlayViewportClient()
	: bIgnoreInput(false)
	, CurrentMouseCursor(EMouseCursor::Default)
	, QuiltRT(nullptr)
	, LastRenderedComponent(nullptr)
	, LastViewportUpdateTime(0)
	, bLastModeWas2D(false)
	, Viewport(nullptr)
{
#if WITH_EDITOR
	if (FModuleManager::Get().IsModuleLoaded(LevelEditorModuleName))
	{
		// Need to capture 2 "redraw viewport" delegates. The first one reacts on property changes, the second one - to moving objects in level editor viewport.
		FLevelEditorModule& LevelEditor = FModuleManager::GetModuleChecked<FLevelEditorModule>(LevelEditorModuleName);
		LevelEditor.OnRedrawLevelEditingViewports().AddRaw(this, &FHoloPlayViewportClient::OnRedrawViewport);
		FEditorSupportDelegates::RedrawAllViewports.AddRaw(this, &FHoloPlayViewportClient::OnRedrawAllViewports);
	}
#endif
}

FHoloPlayViewportClient::~FHoloPlayViewportClient()
{
#if WITH_EDITOR
	if (FModuleManager::Get().IsModuleLoaded(LevelEditorModuleName))
	{
		FLevelEditorModule& LevelEditor = FModuleManager::GetModuleChecked<FLevelEditorModule>(LevelEditorModuleName);
		LevelEditor.OnRedrawLevelEditingViewports().RemoveAll(this);
		FEditorSupportDelegates::RedrawAllViewports.RemoveAll(this);
	}
#endif
}

#if WITH_EDITOR
void FHoloPlayViewportClient::OnRedrawAllViewports()
{
	LastViewportUpdateTime = FPlatformTime::Seconds();
}

void FHoloPlayViewportClient::OnRedrawViewport(bool bInvalidateHitProxies)
{
	LastViewportUpdateTime = FPlatformTime::Seconds();
}
#endif // WITH_EDITOR

void FHoloPlayViewportClient::Draw(FViewport* InViewport, FCanvas* InCanvas)
{
	check(IsInGameThread());

	SCOPE_CYCLE_COUNTER(STAT_Draw_GameThread);

	const UHoloPlaySettings* HoloPlaySettings = GetDefault<UHoloPlaySettings>();
	const FHoloPlayRenderingSettings& RenderingSettings = HoloPlaySettings->HoloPlayRenderingSettings;
	TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlayCaptureComponent = HoloPlay::GetGameHoloPlayCaptureComponent();

	// Find if we're recording the video, to override rendering mode
	bool bIsRecordingMovie = (HoloPlay::GetMovieSceneCapture() != nullptr) || OnHoloPlayFrameReady.IsBound();
#if WITH_EDITOR
	// Force realtime when sequencer is open. Actually, should update viewport only when time was changed (ISequencer::OnGlobalTimeChanged event).
	bool bIsSequencerOpen = IHoloPlayRuntime::Get().HasActiveSequencers();
#endif

	// Clear entire canvas
	InCanvas->Clear(FLinearColor::Black);

	if (!HoloPlayCaptureComponent.IsValid())
	{
		InCanvas->Clear(FLinearColor::Blue);
		return;
	}

	// create render QuiltRT if not exists
	GetQuiltRT(HoloPlayCaptureComponent);

	if (HoloPlayCaptureComponent->GetRenderingConfigs().Configs.Num() == 0)
	{
		ensureMsgf(false, TEXT("There is no rendering configs"));
		InCanvas->Clear(FLinearColor::Green);
		return;
	}

	bool bShow2D = RenderingSettings.bRender2D;
	EHoloPlayPerformanceMode PerfMode = EHoloPlayPerformanceMode::Realtime;

	bool bPendingQuiltScreenshot = HoloPlayQuiltScreenshotRequest.IsValid();
	bool bPendingLenticularScreenshot = HoloPlayLenticularScreenshotRequest.IsValid();
	if (bPendingQuiltScreenshot || bPendingLenticularScreenshot || bIsRecordingMovie)
	{
		// When hologram screenshot is pending, disable 2D mode
		bShow2D = false;
	}

#if WITH_EDITOR
	const FHoloPlayEditorSettings& EditorSettings = HoloPlaySettings->HoloPlayEditorSettings;
	PerfMode = EditorSettings.PerformanceMode;

	if (PerfMode == EHoloPlayPerformanceMode::RealtimeAdaptive)
	{
		// Recognize if user is changing anything in the scene. Render a simplified view if yes.
//		bShow2D = FSlateApplication::Get().HasAnyMouseCaptor() || FSlateApplication::Get().IsDragDropping() || GUnrealEd->IsUserInteracting();
		bShow2D |= GUnrealEd->IsUserInteracting();
	}
#endif // WITH_EDITOR

	// Process Screenshot 2Ds before offset Tiling scene capture
	ProcessScreenshot2D(HoloPlayCaptureComponent);

	// If we render in 2D mode, just render one full view and return. Note: we do not use 'bShouldRender' logic
	// here, because we don't have a cached RenderTarget to preserve previously rendered image between frames,
	// as we're using for quilt renders. In a case we won't draw anything, the picture on the screen will be black.
	if (bShow2D)
	{
		Render2DView(HoloPlayCaptureComponent.Get(), InViewport);
		bLastModeWas2D = true;
		return;
	}

#if WITH_EDITOR
	// Logic for realtime/non-realtime rendering
	bool bShouldRender = false;
	if (HoloPlayCaptureComponent->GetOverrideQuiltTexture2D() != nullptr)
	{
		// We won't display the actual picture, as there's an override - don't render anything
		bShouldRender = false;
	}
	else if (PerfMode == EHoloPlayPerformanceMode::Realtime || PerfMode == EHoloPlayPerformanceMode::RealtimeAdaptive ||
		bIsRecordingMovie || bIsSequencerOpen || bPendingQuiltScreenshot || bPendingLenticularScreenshot)
	{
		// Forced realtime mode, always render
		bShouldRender = true;
	}
	else if (PerfMode == EHoloPlayPerformanceMode::NonRealtime)
	{
		// Always re-render the hologram in non-realtime mode when:
		// - not in editor
		// - viewport has been just created - ensured by setting LastRenderedComponent to null in constructor
		// - rendering component has been switched to another one (LastRenderedComponent)
		// - recording a movie
		// - when rendering mode (actually, only 2D -> non-2D) changed (bLastModeWas2D)
		if (bLastModeWas2D)
		{
			// Switching from 2D to hologram: we should re-render Quilt when in non-realtime mode
			bShouldRender = true;
			bLastModeWas2D = false;
		}
		if (HoloPlayCaptureComponent.Get() != LastRenderedComponent)
		{
			// Capture component has been changed. This will also happen when rendering a very first frame
			bShouldRender = true;
			LastRenderedComponent = HoloPlayCaptureComponent.Get();
		}
		if (LastViewportUpdateTime > 0 && (FPlatformTime::Seconds() > LastViewportUpdateTime + EditorSettings.NonRealtimeUpdateDelay))
		{
			// Enough time passed since the last editor viewport update, i.e. no scene updates has been made, so - redraw the hologram
			bShouldRender = true;
			// Indicate that no update is required on the next frame (unless something will be changed)
			LastViewportUpdateTime = -1;
		}
	}
#else
	const bool bShouldRender = true;
#endif // WITH_EDITOR

	// Render scene to quilt. Update only when bShouldRender is true. If it is false, then previously rendered picture will be reused.
	if (bShouldRender)
	{
		// Render the actual scene to quilt texture
		RenderToQuilt(HoloPlayCaptureComponent.Get());
	}

	// Synchronize game and rendering thread before lenticular shader
	FlushRenderingCommands();

	if (OnHoloPlayFrameReady.IsBound())
	{
		ProcessQuiltForMovie(QuiltRT);
	}
	else
	{
		ProcessScreenshotQuilt(QuiltRT);
	}

	// Note: lenticular screenshot is handled by the engine code, in ProcessScreenShots() method. It will simply
	// capture the window contents and save it to the bitmap. When Quilt or 2D mode is forced, lenticular screenshot will
	// capture the Quilt of 2D image!
	bool bRenderQuilt = (RenderingSettings.QuiltMode || bIsRecordingMovie) && !bPendingLenticularScreenshot;
	RenderQuiltToLenticular(HoloPlayCaptureComponent.Get(), InViewport, bRenderQuilt);
}

void FHoloPlayViewportClient::Render2DView(UHoloPlaySceneCaptureComponent2D* CaptureComponent, const FViewport* InViewport)
{
	// Render a single picture to render target
	CaptureComponent->Render2DView();

	UTextureRenderTarget2D* RenderTarget = CaptureComponent->GetTextureTarget2DRendering();

	HoloPlay::FRender2DViewContext Render2DViewContext =
	{
		InViewport,
		RenderTarget->GetResource()
	};

	// Paint render target contents on screen
	ENQUEUE_RENDER_COMMAND(Render2DView)(
		[Render2DViewContext](FRHICommandListImmediate& RHICmdList)
	{
		HoloPlay::Render2DView_RenderThread(RHICmdList, Render2DViewContext);
	});
}

void FHoloPlayViewportClient::RenderToQuilt(UHoloPlaySceneCaptureComponent2D* CaptureComponent)
{
	// Render to multiple render targets
	CaptureComponent->RenderViews();

	// Copy data from multiple render targets into a single quilt image
	uint32 CurrentViewIndex = 0;
	for (const FHoloPlayRenderingConfig& RenderingConfig : CaptureComponent->GetRenderingConfigs().Configs)
	{
		UTextureRenderTarget2D* RenderTarget = RenderingConfig.GetRenderTarget();
		if (RenderTarget == nullptr || RenderTarget->GetResource() == nullptr)
		{
			UE_LOG(HoloPlayLogRender, Error, TEXT("RenderTarget is null"));

			return;
		}

		for (int32 ViewIndex = 0; ViewIndex < RenderingConfig.GetViewInfoArr().Num(); ++ViewIndex)
		{
			HoloPlay::FCopyToQuiltRenderContext RenderContext =
			{
				QuiltRT->GameThread_GetRenderTargetResource(),
				CaptureComponent->GetTilingValues(),
				RenderTarget->GetResource(),
				CurrentViewIndex,
				ViewIndex,
				RenderingConfig.GetViewInfoArr().Num(),
				RenderingConfig.GetViewRows(),
				RenderingConfig.GetViewColumns(),
				RenderingConfig.GetViewInfoArr()[ViewIndex]
			};

			ENQUEUE_RENDER_COMMAND(CopyToQuiltCommand)(
				[RenderContext, CurrentViewIndex](FRHICommandListImmediate& RHICmdList)
				{
					SCOPE_CYCLE_COUNTER(STAT_CopyToQuiltShader_RenderThread);
					SCOPED_GPU_STAT(RHICmdList, CopyToQuilt);

					HoloPlay::CopyToQuiltShader_RenderThread(RHICmdList, RenderContext);
				});

			CurrentViewIndex++;
		}
	}
}

void FHoloPlayViewportClient::RenderQuiltToLenticular(UHoloPlaySceneCaptureComponent2D* HoloPlayCaptureComponent, const FViewport* InViewport, bool bForceQuiltMode)
{
	bool bIsOverrideQuiltTexture2D = HoloPlayCaptureComponent->GetOverrideQuiltTexture2D() != nullptr;

	// Lenticular shader rendering
	HoloPlay::FLenticularRenderContext RenderContext =
	{
		InViewport,
		QuiltRT->GameThread_GetRenderTargetResource(),
		HoloPlayCaptureComponent->GetTilingValues(),
		bIsOverrideQuiltTexture2D ? HoloPlayCaptureComponent->GetOverrideQuiltTexture2D()->GetResource() : nullptr,
		bForceQuiltMode
	};
	ENQUEUE_RENDER_COMMAND(RenderLenticularShaderCommand)(
		[RenderContext](FRHICommandListImmediate& RHICmdList)
		{
			SCOPE_CYCLE_COUNTER(STAT_RenderLenticularShader_RenderThread);
			HoloPlay::RenderLenticularShader_RenderThread(RHICmdList, RenderContext);
		});
}

bool FHoloPlayViewportClient::InputKey(FViewport * InViewport, int32 ControllerId, FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad)
{
	GHoloPlayRuntime->OnHoloPlayInputKeyDelegate().Broadcast(InViewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);

	auto HoloPlaySettings = GetDefault<UHoloPlaySettings>();

	// Process special input first
	if (Key == EKeys::Escape && EventType == EInputEvent::IE_Pressed)
	{
		IHoloPlayRuntime::Get().StopPlayer();
	}

	if (HoloPlaySettings->HoloPlayLenticularScreenshotSettings.InputKey == Key && EventType == EInputEvent::IE_Pressed)
	{
		PrepareLenticularScreenshot(HoloPlaySettings->HoloPlayLenticularScreenshotSettings.FileName, true);
	}

	if (HoloPlaySettings->HoloPlayScreenshotQuiltSettings.InputKey == Key && EventType == EInputEvent::IE_Pressed)
	{
		PrepareScreenshotQuilt(HoloPlaySettings->HoloPlayScreenshotQuiltSettings.FileName, true);
	}

	if (HoloPlaySettings->HoloPlayScreenshot2DSettings.InputKey == Key && EventType == EInputEvent::IE_Pressed)
	{
		PrepareScreenshot2D(HoloPlaySettings->HoloPlayScreenshot2DSettings.FileName, true);
	}

	if (IgnoreInput())
	{
		return false;
	}

	bool bResult = false;

	// Make sure we are playing in separate window
	if (IHoloPlayRuntime::Get().GetCurrentHoloPlayModeType() == EHoloPlayModeType::PlayMode_InSeparateWindow)
	{
		// Make sure we are in game play mode
		if (GEngine->GameViewport != nullptr)
		{
			ULocalPlayer* FirstLocalPlayerFromController = GEngine->GameViewport->GetWorld()->GetFirstLocalPlayerFromController();

			UE_LOG(HoloPlayLogInput, Verbose, TEXT(">> InputKey %s, FirstLocalPlayerFromController %p, ControllerId %d"), *Key.ToString(), FirstLocalPlayerFromController, ControllerId);

			if (FirstLocalPlayerFromController && FirstLocalPlayerFromController->PlayerController)
			{
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
				FInputKeyParams Params;
				Params.Key = Key;
				Params.Event = EventType;
				Params.Delta.X = AmountDepressed;
				Params.bIsGamepadOverride = bGamepad;

				bResult = FirstLocalPlayerFromController->PlayerController->InputKey(Params);
#else
				bResult = FirstLocalPlayerFromController->PlayerController->InputKey(Key, EventType, AmountDepressed, bGamepad);
#endif
			}

			// A gameviewport is always considered to have responded to a mouse buttons to avoid throttling
			if (!bResult && Key.IsMouseButton())
			{
				bResult = true;
			}
		}
	}

	return bResult;
}

bool FHoloPlayViewportClient::InputAxis(FViewport * InViewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples, bool bGamepad)
{
	if (IgnoreInput())
	{
		return false;
	}

	if (GWorld == nullptr || GEngine == nullptr || GEngine->GameViewport == nullptr || &GEngine->GameViewport->Viewport == nullptr)
	{
		return false;
	}

	bool bResult = false;

	// Don't allow mouse/joystick input axes while in PIE and the console has forced the cursor to be visible.  It's
	// just distracting when moving the mouse causes mouse look while you are trying to move the cursor over a button
	// in the editor!
	if (!(GEngine->GameViewport->Viewport->IsSlateViewport() && GEngine->GameViewport->Viewport->IsPlayInEditorViewport()) || GEngine->GameViewport->ViewportConsole == NULL || !GEngine->GameViewport->ViewportConsole->ConsoleActive())
	{
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
		//todo: since UE5.1 should override a different method, which will receive FInputKeyParams, and simply pass it to the console
		FInputDeviceId DeviceId = FInputDeviceId::CreateFromInternalId(ControllerId);
		FInputKeyParams Params;
		Params.Key = Key;
		Params.Delta = FVector(static_cast<double>(Delta), 0.0, 0.0);
		Params.NumSamples = NumSamples;
		Params.DeltaTime = DeltaTime;
		Params.bIsGamepadOverride = bGamepad;
#endif
		// route to subsystems that care
		if (GEngine->GameViewport->ViewportConsole != NULL)
		{
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
			bResult = GEngine->GameViewport->ViewportConsole->InputAxis(DeviceId, Key, Delta, DeltaTime, NumSamples, bGamepad);
#else
			bResult = GEngine->GameViewport->ViewportConsole->InputAxis(ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
#endif
		}
		if (!bResult)
		{
			ULocalPlayer* const TargetPlayer = GEngine->GetLocalPlayerFromControllerId(GEngine->GameViewport, ControllerId);
			if (TargetPlayer && TargetPlayer->PlayerController)
			{
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
				bResult = TargetPlayer->PlayerController->InputKey(Params);
#else
				bResult = TargetPlayer->PlayerController->InputAxis(Key, Delta, DeltaTime, NumSamples, bGamepad);
#endif
			}
		}

		// For PIE, let the next PIE window handle the input if none of our players did
		// (this allows people to use multiple controllers to control each window)
		if (InViewport->IsPlayInEditorViewport())
		{
			UGameViewportClient *NextViewport = GEngine->GetNextPIEViewport(GEngine->GameViewport);
			if (NextViewport)
			{
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
				bResult = NextViewport->InputAxis(InViewport, DeviceId, Key, Delta, DeltaTime, NumSamples, bGamepad);
#else
				bResult = NextViewport->InputAxis(InViewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
#endif
			}
		}

		if (InViewport->IsSlateViewport() && InViewport->IsPlayInEditorViewport())
		{
			// Absorb all keys so game input events are not routed to the Slate editor frame
			bResult = true;
		}
	}

	return bResult;
}

bool FHoloPlayViewportClient::InputChar(FViewport * InViewport, int32 ControllerId, TCHAR Character)
{
	return false;
}

bool FHoloPlayViewportClient::InputTouch(FViewport * InViewport, int32 ControllerId, uint32 Handle, ETouchType::Type Type, const FVector2D & TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	if (IgnoreInput())
	{
		return false;
	}

	if (GWorld == nullptr || GEngine == nullptr || GEngine->GameViewport == nullptr || &GEngine->GameViewport->Viewport == nullptr)
	{
		return false;
	}

	// route to subsystems that care
	bool bResult = false;
	if (GEngine->GameViewport->ViewportConsole)
	{
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
		FInputDeviceId DeviceId = FInputDeviceId::CreateFromInternalId(ControllerId);
		bResult = GEngine->GameViewport->ViewportConsole->InputTouch(DeviceId, Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);
#else
		bResult = GEngine->GameViewport->ViewportConsole->InputTouch(ControllerId, Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);
#endif
	}
	if (!bResult)
	{
		ULocalPlayer* const TargetPlayer = GEngine->GetLocalPlayerFromControllerId(GEngine->GameViewport, ControllerId);
		if (TargetPlayer && TargetPlayer->PlayerController)
		{
			bResult = TargetPlayer->PlayerController->InputTouch(Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);
		}
	}

	return bResult;
}

bool FHoloPlayViewportClient::InputMotion(FViewport * InViewport, int32 ControllerId, const FVector & Tilt, const FVector & RotationRate, const FVector & Gravity, const FVector & Acceleration)
{
	return false;
}

void FHoloPlayViewportClient::RedrawRequested(FViewport * InViewport)
{
	Viewport->Draw();
}

bool FHoloPlayViewportClient::GetRenderTargetScreenShot(TWeakObjectPtr<UTextureRenderTarget2D> TextureRenderTarget2D, TArray<FColor>& Bitmap, const FIntRect& ViewRect)
{
	// Read the contents of the viewport into an array.
	FReadSurfaceDataFlags ReadSurfaceDataFlags;
	ReadSurfaceDataFlags.SetLinearToGamma(false); // This is super important to disable this!

	bool bIsSuccess = false;
	FTextureRenderTargetResource* RenderTarget = TextureRenderTarget2D->GameThread_GetRenderTargetResource();
	if (RenderTarget->ReadPixels(Bitmap, ReadSurfaceDataFlags, ViewRect))
	{
		check(Bitmap.Num() == ViewRect.Area() || (Bitmap.Num() == TextureRenderTarget2D->SizeX * TextureRenderTarget2D->SizeY));
		for (FColor& color : Bitmap)
		{
			color.A = 255;
		}

		bIsSuccess = true;
	}

	return bIsSuccess;
}

//todo: unused function
static void ClipScreenshot(FIntVector& Size, FIntRect& SourceRect, TArray<FColor>& Bitmap)
{
	// Clip the bitmap to just the capture region if valid
	if (!SourceRect.IsEmpty())
	{
		FColor* const Data = Bitmap.GetData();
		const int32 OldWidth = Size.X;
		const int32 OldHeight = Size.Y;
		const int32 NewWidth = SourceRect.Width();
		const int32 NewHeight = SourceRect.Height();
		const int32 CaptureTopRow = SourceRect.Min.Y;
		const int32 CaptureLeftColumn = SourceRect.Min.X;

		for (int32 Row = 0; Row < NewHeight; Row++)
		{
			FMemory::Memmove(Data + Row * NewWidth, Data + (Row + CaptureTopRow) * OldWidth + CaptureLeftColumn, NewWidth * sizeof(*Data));
		}

		Bitmap.RemoveAt(NewWidth * NewHeight, OldWidth * OldHeight - NewWidth * NewHeight, false);
		Size = FIntVector(NewWidth, NewHeight, 0);
	}
}

void FHoloPlayViewportClient::ProcessScreenshotQuilt(UTextureRenderTarget2D* InQuiltRT)
{
	if (HoloPlayQuiltScreenshotRequest.IsValid())
	{
		if (HoloPlayQuiltScreenshotRequest->GetFilename().IsEmpty())
		{
			HoloPlayQuiltScreenshotRequest.Reset();
			return;
		}

		TArray<FColor> Bitmap;
		bool bScreenshotSuccessful = GetRenderTargetScreenShot(InQuiltRT, Bitmap);
		if ( bScreenshotSuccessful )
		{
			FIntVector Size( InQuiltRT->SizeX, InQuiltRT->SizeY, 0 );
			const UHoloPlaySettings* HoloPlaySettings = GetDefault<UHoloPlaySettings>();
			SaveScreenShot(Bitmap, Size, HoloPlayQuiltScreenshotRequest->GetFilename(), &HoloPlaySettings->HoloPlayScreenshotQuiltSettings);
		}

		// Notify about completion
		HoloPlayQuiltScreenshotRequest->ExecCallback();

		HoloPlayQuiltScreenshotRequest.Reset();
		OnScreenshotQuiltRequestProcessed().Broadcast();
	}
}

void FHoloPlayViewportClient::ProcessQuiltForMovie(UTextureRenderTarget2D* InQuiltRT)
{
	if (OnHoloPlayFrameReady.IsBound())
	{
		TArray<FColor> Bitmap;
		bool bScreenshotSuccessful = GetRenderTargetScreenShot(InQuiltRT, Bitmap);
		if (bScreenshotSuccessful)
		{
			OnHoloPlayFrameReady.Broadcast(Bitmap, InQuiltRT->SizeX, InQuiltRT->SizeY);
		}
	}
}

bool FHoloPlayViewportClient::ProcessScreenShotLenticular(FViewport * InViewport)
{
	if (HoloPlayLenticularScreenshotRequest.IsValid())
	{
		if (HoloPlayLenticularScreenshotRequest->GetFilename().IsEmpty())
		{
			HoloPlayLenticularScreenshotRequest.Reset();
			return false;
		}

		TArray<FColor> Bitmap;

		//todo: request screenshot from RenderTarget
		bool bScreenshotSuccessful = false;
		FIntVector Size(InViewport->GetSizeXY().X, InViewport->GetSizeXY().Y, 0);
		bScreenshotSuccessful = GetViewportScreenShot(InViewport, Bitmap);

		if (bScreenshotSuccessful)
		{
			for (FColor& color : Bitmap)
			{
				color.A = 255;
			}

			const UHoloPlaySettings* HoloPlaySettings = GetDefault<UHoloPlaySettings>();
			SaveScreenShot(Bitmap, Size, HoloPlayLenticularScreenshotRequest->GetFilename(), &HoloPlaySettings->HoloPlayLenticularScreenshotSettings);
		}

		HoloPlayLenticularScreenshotRequest.Reset();
		OnScreenshot3DRequestProcessed().Broadcast();

		return true;
	}

	return false;
}

void FHoloPlayViewportClient::ProcessScreenshot2D(TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlayCaptureComponent)
{
	if (HoloPlayScreenshot2DRequest.IsValid())
	{
		FString ScreenShotName = HoloPlayScreenshot2DRequest->GetFilename();

		if (ScreenShotName.IsEmpty())
		{
			HoloPlayScreenshot2DRequest.Reset();
			return;
		}

		int32 ScreenshotResolutionX = GetDefault<UHoloPlaySettings>()->HoloPlayScreenshot2DSettings.Resolution.X;
		int32 ScreenshotResolutionY = GetDefault<UHoloPlaySettings>()->HoloPlayScreenshot2DSettings.Resolution.Y;

		if (ScreenshotResolutionX <= 0 || ScreenshotResolutionY <= 0)
		{
			return;
		}

		// Render picture
		HoloPlayCaptureComponent->Render2DView(ScreenshotResolutionX, ScreenshotResolutionY);
		// grab the render target where picture was rendered
		UTextureRenderTarget2D* RenderTarget = HoloPlayCaptureComponent->GetTextureTarget2DRendering();

		TArray<FColor> Bitmap;
		bool bScreenshotSuccessful = GetRenderTargetScreenShot(RenderTarget, Bitmap);

		if (bScreenshotSuccessful)
		{
			FIntVector Size( RenderTarget->SizeX, RenderTarget->SizeY, 0 );
			const UHoloPlaySettings* HoloPlaySettings = GetDefault<UHoloPlaySettings>();
			SaveScreenShot(Bitmap, Size, HoloPlayScreenshot2DRequest->GetFilename(), &HoloPlaySettings->HoloPlayScreenshot2DSettings);
		}

		HoloPlayScreenshot2DRequest.Reset();
		OnScreenshot2DRequestProcessed().Broadcast();
	}
}

void FHoloPlayViewportClient::SaveScreenShot(const TArray<FColor>& Bitmap, const FIntVector& Size, const FString& InScreenShotName, const FHoloPlayScreenshotSettings* pScreenShotSettings)
{
	FString Extension = TEXT(".png");
	int32 Quality = 0;
	bool bUseJpg = pScreenShotSettings->UseJPG;
	if (bUseJpg)
	{
		Extension = TEXT(".jpg");
		Quality = pScreenShotSettings->JpegQuality;
	}

	FString ScreenShotName = InScreenShotName;
	if (!FPaths::GetExtension( ScreenShotName ).IsEmpty())
	{
		ScreenShotName = FPaths::GetBaseFilename(ScreenShotName, false);
		ScreenShotName += Extension;
	}

#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION >= 1
	FImageView ImageView(Bitmap.GetData(), Size.X, Size.Y);
	FImageUtils::SaveImageByExtension(*ScreenShotName, ImageView, Quality);
#else
	// Implement image saving directly
	IImageWrapperModule* ImageWrapperModule = FModuleManager::GetModulePtr<IImageWrapperModule>(TEXT("ImageWrapper"));
	if (!ensure( ImageWrapperModule ))
	{
		UE_LOG( HoloPlayLogInput, Verbose, TEXT( "Could not find image wrapper module, Screenshot aborted" ) );
		return;
	}
	EImageFormat imageFormat = EImageFormat::PNG;
	if (bUseJpg)
	{
		imageFormat = EImageFormat::JPEG;
	}

	TSharedPtr<IImageWrapper> NewImageWrapper = ImageWrapperModule->CreateImageWrapper( imageFormat );
	if (!ensureMsgf( NewImageWrapper.IsValid(), TEXT( "Unable to create an image wrapper for the desired format." ) ))
	{
		UE_LOG( HoloPlayLogInput, Verbose, TEXT( "Unable to create an image wrapper for the desired format., Screenshot aborted" ) );
		return;
	}
	NewImageWrapper->SetRaw( Bitmap.GetData(), Size.X * Size.Y * 4, Size.X, Size.Y, ERGBFormat::BGRA, 8 );

	TArray64<uint8> CompressedBitmap = NewImageWrapper->GetCompressed(Quality);
	FFileHelper::SaveArrayToFile( CompressedBitmap, *ScreenShotName );
#endif
}

EMouseCursor::Type FHoloPlayViewportClient::GetCursor(FViewport* InViewport, int32 X, int32 Y)
{
	return CurrentMouseCursor;
}

bool FHoloPlayViewportClient::IsFocused(FViewport* InViewport)
{
	return InViewport->HasFocus() || InViewport->HasMouseCapture();
}

void FHoloPlayViewportClient::LostFocus(FViewport* InViewport)
{
	CurrentMouseCursor = EMouseCursor::Default;
}

void FHoloPlayViewportClient::ReceivedFocus(FViewport* InViewport)
{
	CurrentMouseCursor = EMouseCursor::None;
}

bool FHoloPlayViewportClient::Exec(UWorld * InWorld, const TCHAR * Cmd, FOutputDevice & Ar)
{
	if (FParse::Command(&Cmd, TEXT("HoloPlay.LenticularScreenshot")))
	{
		return HandleLenticularScreenshotCommand(Cmd, Ar);
	}
	else if (FParse::Command(&Cmd, TEXT("HoloPlay.ScreenshotQuilt")))
	{
		return HandleScreenshotQuiltCommand(Cmd, Ar);
	}
	else if (FParse::Command(&Cmd, TEXT("HoloPlay.Screenshot2D")))
	{
		return HandleScreenshot2DCommand(Cmd, Ar);
	}
	else if (FParse::Command(&Cmd, TEXT("HoloPlay.Window")))
	{
		return HandleWindowCommand(Cmd, Ar);
	}
	else if (FParse::Command(&Cmd, TEXT("HoloPlay.Shader")))
	{
		return HandleShaderCommand(Cmd, Ar);
	}
	else if (FParse::Command(&Cmd, TEXT("HoloPlay.Scene")))
	{
		return HandleSceneCommand(Cmd, Ar);
	}
	else if (FParse::Command(&Cmd, TEXT("HoloPlay.Tilling")))
	{
		return HandleTillingCommand(Cmd, Ar);
	}
	else if (FParse::Command(&Cmd, TEXT("HoloPlay.Rendering")))
	{
		return HandleRenderingCommand(Cmd, Ar);
	}
	else
	{
		return false;
	}
}

bool FHoloPlayViewportClient::HandleLenticularScreenshotCommand(const TCHAR * Cmd, FOutputDevice & Ar)
{
	if (Viewport)
	{
		FString FileName;
		bool bAddFilenameSuffix = true;
		ParseScreenshotCommand(Cmd, FileName, bAddFilenameSuffix);

		return PrepareLenticularScreenshot(FileName, bAddFilenameSuffix);
	}
	return true;
}

bool FHoloPlayViewportClient::HandleScreenshotQuiltCommand(const TCHAR * Cmd, FOutputDevice & Ar)
{
	if (Viewport)
	{
		FString FileName;
		bool bAddFilenameSuffix = true;
		ParseScreenshotCommand(Cmd, FileName, bAddFilenameSuffix);

		return PrepareScreenshotQuilt(FileName, bAddFilenameSuffix);
	}
	return true;
}

bool FHoloPlayViewportClient::HandleScreenshot2DCommand(const TCHAR * Cmd, FOutputDevice & Ar)
{
	if (Viewport)
	{
		FString FileName;
		bool bAddFilenameSuffix = true;
		ParseScreenshotCommand(Cmd, FileName, bAddFilenameSuffix);

		return PrepareScreenshot2D(FileName, bAddFilenameSuffix);
	}
	return true;
}

bool FHoloPlayViewportClient::HandleWindowCommand(const TCHAR * Cmd, FOutputDevice & Ar)
{
	UHoloPlaySettings* HoloPlaySettings = GetMutableDefault<UHoloPlaySettings>();

	bool bWasHandled = false;

	if (FParse::Command(&Cmd, TEXT("ClientSize")))
	{
		uint32 X = 0;
		uint32 Y = 0; 
		ParseResolution(Cmd, X, Y);

		if (X > 0 && Y > 0)
		{
			HoloPlaySettings->HoloPlayWindowSettings.CustomWindowLocation.ClientSize = FIntPoint(X, Y);
		}

		// Restart player
		IHoloPlayRuntime::Get().RestartPlayer(HoloPlaySettings->HoloPlayWindowSettings.LastExecutedPlayModeType);

		bWasHandled = true;
	}
	if (FParse::Command(&Cmd, TEXT("PlacementMode")))
	{
		if (FString(Cmd).IsNumeric())
		{
			int32 NewVal = FCString::Atoi(*FString(Cmd));
			HoloPlaySettings->HoloPlayWindowSettings.PlacementMode = (EHoloPlayPlacement)NewVal;
			bWasHandled = true;
		}
	}

	if (bWasHandled)
	{
		HoloPlaySettings->HoloPlaySave();
	}

	return bWasHandled;

	return true;
}

bool FHoloPlayViewportClient::HandleShaderCommand(const TCHAR * Cmd, FOutputDevice & Ar)
{
	UHoloPlaySettings* HoloPlaySettings = GetMutableDefault<UHoloPlaySettings>();
	auto HoloPlayDisplayManager = IHoloPlayRuntime::Get().GetHoloPlayDisplayManager();
	FHoloPlayDisplayMetrics::FCalibration& Calibration = HoloPlayDisplayManager->GetCalibrationSettingsMutable();

	bool bWasHandled = true;
	if (FParse::Command(&Cmd, TEXT("QuiltMode")))
	{
		int32 NewVal = FCString::Atoi(*FString(Cmd));
		HoloPlaySettings->HoloPlayRenderingSettings.QuiltMode = (NewVal != 0);
	}
	else if (FParse::Command(&Cmd, TEXT("Pitch")))
	{
		float NewVal = FCString::Atof(*FString(Cmd));
		Calibration.Pitch = NewVal;
	}
	else if (FParse::Command(&Cmd, TEXT("Center")))
	{
		float NewVal = FCString::Atof(*FString(Cmd));
		Calibration.Center = NewVal;
	}
	else if (FParse::Command(&Cmd, TEXT("ViewCone")))
	{
		float NewVal = FCString::Atof(*FString(Cmd));
		Calibration.ViewCone = NewVal;
	}
	else if (FParse::Command(&Cmd, TEXT("DPI")))
	{
		float NewVal = FCString::Atof(*FString(Cmd));
		Calibration.DPI = NewVal;
	}
	else
	{
		bWasHandled = false;
	}

	if (bWasHandled)
	{
		HoloPlaySettings->HoloPlaySave();
	}

	return bWasHandled;
}

//todo: what's this?
bool FHoloPlayViewportClient::HandleSceneCommand(const TCHAR * Cmd, FOutputDevice & Ar)
{
	return true;
}

bool FHoloPlayViewportClient::HandleTillingCommand(const TCHAR* Cmd, FOutputDevice& Ar)
{
	UHoloPlaySceneCaptureComponent2D* GameHoloPlayCaptureComponent = HoloPlay::GetGameHoloPlayCaptureComponent().Get();

	if (GameHoloPlayCaptureComponent == nullptr)
	{
		UE_LOG(HoloPlayLogInput, Verbose, TEXT(">> HoloPlayCaptureComponent is not valid"));
		return false;
	}

	// todo: can request the enum member of EHoloPlayQualitySettings by name here, instead of parsing every single value individually
	EHoloPlayQualitySettings TilingSettings;
	if (FParse::Command(&Cmd, TEXT("Automatic")))
	{
		TilingSettings = EHoloPlayQualitySettings::Q_Automatic;
	}
    else if (FParse::Command(&Cmd, TEXT( "Portrait")))
    {
		TilingSettings = EHoloPlayQualitySettings::Q_Portrait;
    }
	else if (FParse::Command(&Cmd, TEXT("FourK")))
	{
		TilingSettings = EHoloPlayQualitySettings::Q_FourK;
	}
	else if (FParse::Command(&Cmd, TEXT("EightK")))
	{
		TilingSettings = EHoloPlayQualitySettings::Q_EightK;
	}
	else if (FParse::Command(&Cmd, TEXT("65inch")))
	{
		TilingSettings = EHoloPlayQualitySettings::Q_65_Inch;
	}
	else if (FParse::Command(&Cmd, TEXT("EightNineLegacy")))
	{
		TilingSettings = EHoloPlayQualitySettings::Q_EightPointNineLegacy;
	}
	else
	{
		UE_LOG(HoloPlayLogInput, Verbose, TEXT("Unknown tiling settings mode %s"), Cmd);
		return false;
	}

	GameHoloPlayCaptureComponent->SetTilingProperties(TilingSettings);

	UHoloPlaySettings* HoloPlaySettings = GetMutableDefault<UHoloPlaySettings>();
	HoloPlaySettings->HoloPlaySave();

	return true;
}

bool FHoloPlayViewportClient::HandleRenderingCommand(const TCHAR* Cmd, FOutputDevice& Ar)
{
	bool bWasHandled = true;

	if (FParse::Command(&Cmd, TEXT("Render2D")))
	{
		if (FString(Cmd).IsNumeric())
		{
			int32 NewVal = FCString::Atoi(*FString(Cmd));
			UHoloPlaySettings* HoloPlaySettings = GetMutableDefault<UHoloPlaySettings>();
			HoloPlaySettings->HoloPlayRenderingSettings.bRender2D = !!NewVal;
			HoloPlaySettings->HoloPlaySave();
		}
	}
	else
	{
		bWasHandled = false;
	}

	return bWasHandled;
}

void FHoloPlayViewportClient::ParseScreenshotCommand(const TCHAR * Cmd, FString& InName, bool& InSuffix)
{
	FString CmdString(Cmd);
	TArray<FString> Args;
	CmdString.ParseIntoArray(Args, TEXT(" "));
	if (Args.Num() > 1)
	{
		InName = Args[0];
	}
	else
	{
		InName = CmdString;
	}

	if (FParse::Param(Cmd, TEXT("nosuffix")))
	{
		InSuffix = false;
	}
}

bool FHoloPlayViewportClient::ParseResolution(const TCHAR * InResolution, uint32 & OutX, uint32 & OutY)
{
	//todo: refactor
	if (*InResolution)
	{
		FString CmdString(InResolution);
		CmdString.TrimStartAndEndInline();
		CmdString.ToLowerInline();

		//Retrieve the X dimensional value

		// Determine whether the user has entered a resolution and extract the Y dimension.
		FString YString;

		// Find separator between values (Example of expected format: 1280x768)
		const TCHAR* YValue = NULL;
		if (FCString::Strchr(*CmdString, 'x'))
		{
			YValue = const_cast<TCHAR*> (FCString::Strchr(*CmdString, 'x') + 1);
			YString = YValue;
			// Remove any whitespace from the end of the string
			YString = YString.TrimStartAndEnd();
		}

		// If the Y dimensional value exists then setup to use the specified resolution.
		if (YValue && YString.Len() > 0)
		{
			if (YString.IsNumeric())
			{
				uint32 X = FMath::Max(FCString::Atof(*CmdString), 0.0f);
				uint32 Y = FMath::Max(FCString::Atof(YValue), 0.0f);
				OutX = X;
				OutY = Y;
				return true;
			}
		}
	}
	return false;
}

bool FHoloPlayViewportClient::PrepareLenticularScreenshot(const FString& FileName, bool bAddFilenameSuffix)
{
	if (!HoloPlayLenticularScreenshotRequest.IsValid())
	{
		HoloPlayLenticularScreenshotRequest = MakeShareable(new FHoloPlayScreenshotRequest());
		HoloPlayLenticularScreenshotRequest->RequestScreenshot(FileName, bAddFilenameSuffix);
		return true;
	}
	return false;
}

void FHoloPlayViewportClient::TakeQuiltScreenshot(FHoloPlayScreenshotRequest::FCallback Callback)
{
	const UHoloPlaySettings* HoloPlaySettings = GetDefault<UHoloPlaySettings>();
	PrepareScreenshotQuilt(HoloPlaySettings->HoloPlayScreenshotQuiltSettings.FileName, true, Callback);
}

bool FHoloPlayViewportClient::PrepareScreenshotQuilt(const FString& FileName, bool bAddFilenameSuffix, FHoloPlayScreenshotRequest::FCallback Callback)
{
	if (!HoloPlayQuiltScreenshotRequest.IsValid())
	{
		HoloPlayQuiltScreenshotRequest = MakeShareable(new FHoloPlayScreenshotRequest());
		FHoloPlayScreenshotRequest::FQuiltSettings QuiltSettings;

		if (bAddFilenameSuffix)
		{
			// Get the HoloPlay component to see its tiling settings
			TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlayCaptureComponent = HoloPlay::GetGameHoloPlayCaptureComponent();
			if (HoloPlayCaptureComponent.IsValid())
			{
				const FHoloPlayTilingQuality& TilingValues = HoloPlayCaptureComponent->GetTilingValues();
				QuiltSettings.NumColumns = TilingValues.TilesX;
				QuiltSettings.NumRows = TilingValues.TilesY;
				QuiltSettings.Aspect = HoloPlayCaptureComponent->GetAspectRatio();
			}
		}
		HoloPlayQuiltScreenshotRequest->SetCompletedCallback(Callback);
		HoloPlayQuiltScreenshotRequest->RequestScreenshot(FileName, bAddFilenameSuffix, QuiltSettings);

		return true;
	}

	return false;
}

bool FHoloPlayViewportClient::PrepareScreenshot2D(const FString& FileName, bool bAddFilenameSuffix)
{
	if (!HoloPlayScreenshot2DRequest.IsValid())
	{
		HoloPlayScreenshot2DRequest = MakeShareable(new FHoloPlayScreenshotRequest());
		HoloPlayScreenshot2DRequest->RequestScreenshot(FileName, bAddFilenameSuffix);

		return true;
	}

	return false;
}

UTextureRenderTarget2D* FHoloPlayViewportClient::GetQuiltRT(TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlayCaptureComponent)
{
	const FHoloPlayTilingQuality& TilingValues = HoloPlayCaptureComponent->GetTilingValues();

	if (QuiltRT == nullptr)
	{
		QuiltRT = NewObject<UTextureRenderTarget2D>(GetTransientPackage(), UTextureRenderTarget2D::StaticClass());
		QuiltRT->AddToRoot();

		QuiltRT->ClearColor = FLinearColor::Red;
		QuiltRT->InitCustomFormat(TilingValues.QuiltW, TilingValues.QuiltH, PF_A16B16G16R16, false);
		QuiltRT->UpdateResourceImmediate();
	}

	// Resize Quilt texture
	if (TilingValues.QuiltW != QuiltRT->SizeX ||
		TilingValues.QuiltH != QuiltRT->SizeY)
	{
		QuiltRT->ResizeTarget(TilingValues.QuiltW, TilingValues.QuiltH);
		QuiltRT->UpdateResourceImmediate();
	}

	return QuiltRT;
}
