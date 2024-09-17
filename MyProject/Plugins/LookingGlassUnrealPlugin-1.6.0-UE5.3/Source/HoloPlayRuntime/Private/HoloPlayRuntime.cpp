#include "HoloPlayRuntime.h"
#include "HoloPlaySettings.h"

#include "Render/SHoloPlayViewport.h"

#include "Render/HoloPlayViewportClient.h"

#include "Game/HoloPlayCapture.h"

#include "Misc/HoloPlayHelpers.h"
#include "Misc/HoloPlayLog.h"

#include "Managers/HoloPlayDisplayManager.h"
#include "Managers/HoloPlayCommandLineManager.h"
#include "Managers/HoloPlayLaunchManager.h"

#include "Slate/SceneViewport.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/GameUserSettings.h"
#include "UnrealEngine.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ShaderCore.h"
#include "Engine/GameEngine.h"

#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Settings/LevelEditorPlaySettings.h"
#include "ISequencerModule.h"
#endif

#define LOCTEXT_NAMESPACE "FHoloPlayRuntimeModule"

IHoloPlayRuntime* GHoloPlayRuntime = nullptr;

FHoloPlayRuntimeModule::FHoloPlayRuntimeModule()
{
	GHoloPlayRuntime = this;
}

FHoloPlayRuntimeModule::~FHoloPlayRuntimeModule()
{
	GHoloPlayRuntime = nullptr;
}

void FHoloPlayRuntimeModule::StartupModule()
{
	FString PluginBaseDir = IPluginManager::Get().FindPlugin(TEXT("HoloPlay"))->GetBaseDir();
	FString PluginShaderDir = FPaths::Combine(PluginBaseDir, TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/HoloPlay"), PluginShaderDir);

	// Create all managers
	Managers.Add(HoloPlayLaunchManager = MakeShareable(new FHoloPlayLaunchManager()));
	Managers.Add(HoloPlayCommandLineManager = MakeShareable(new FHoloPlayCommandLineManager()));
	Managers.Add(HoloPlayDisplayManager = MakeShareable(new FHoloPlayDisplayManager()));

	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FHoloPlayRuntimeModule::OnPostEngineInit);
	UGameViewportClient::OnViewportCreated().AddRaw(this, &FHoloPlayRuntimeModule::OnGameViewportCreated);

#if WITH_EDITOR
	// Register function which will capture events of creating sequencer. We'll need to get access to the Sequencer
	// module here, and in 5.1 this will cause the crash, as something in the engine is not initialized at a time of
	// loading this plugin. So, we'll delay this till the engine initialization completed.
	FCoreDelegates::OnPostEngineInit.AddLambda([this]()
		{
			ISequencerModule& SequencerModule = FModuleManager::Get().LoadModuleChecked<ISequencerModule>("Sequencer");
			OnSequencerCreatedHandle = SequencerModule.RegisterOnSequencerCreated(
				FOnSequencerCreated::FDelegate::CreateRaw(this, &FHoloPlayRuntimeModule::OnSequencerCreated));
		});
#endif // WITH_EDITOR

	HoloPlayLoader.LoadDLL(PluginBaseDir);
}

void FHoloPlayRuntimeModule::ShutdownModule()
{
#if WITH_EDITOR
	ISequencerModule* SequencerModulePtr = FModuleManager::Get().GetModulePtr<ISequencerModule>("Sequencer");
	if (SequencerModulePtr)
	{
		SequencerModulePtr->UnregisterOnSequencerCreated(OnSequencerCreatedHandle);
	}
#endif

	// Release all managers
	for (auto Mng : Managers)
	{
		Mng->Release();
		Mng.Reset();
	}
	Managers.Empty();

	// Release HoloPlayCore.dll when all manager were destroyed
	HoloPlayLoader.ReleaseDLL();
}

#if WITH_EDITOR

// This is only the valid way of knowing if any sequencer is open: to hook RegisterOnSequencerCreated and remember objects as
// weak pointers. When sequencer is closed, no event is called, however we can validate weak pointer to see if sequencer is still alive.
void FHoloPlayRuntimeModule::OnSequencerCreated(TSharedRef<ISequencer> InSequencer)
{
	Sequencers.Add(TWeakPtr<ISequencer>(InSequencer));
}

bool FHoloPlayRuntimeModule::HasActiveSequencers()
{
	while (Sequencers.IsValidIndex(0))
	{
		if (Sequencers[0].IsValid())
		{
			return true;
		}
		// Cleanup dead pointers
		Sequencers.RemoveAt(0);
	}
	return false;
}

#endif // WITH_EDITOR

void FHoloPlayRuntimeModule::StartPlayer(EHoloPlayModeType HoloPlayModeType)
{
	DISPLAY_HOLOPLAY_FUNC_TRACE(HoloPlayLogPlayer);

	const EAutoCenter AutoCenter = EAutoCenter::None;
	EWindowMode::Type WindowType = EWindowMode::Fullscreen;
	bool RenderDirectlyToWindowInSeparateWindow = true;

	if (bIsPlaying == false)
	{
		// Set Current HoloPlayModeType
		CurrentHoloPlayModeType = HoloPlayModeType;
		auto HoloPlaySettings = GetDefault<UHoloPlaySettings>();
		bLockInMainViewport = HoloPlaySettings->HoloPlayWindowSettings.bLockInMainViewport || HoloPlayModeType == EHoloPlayModeType::PlayMode_InMainViewport;

		// Start all managers
		{
			bool Result = true;
			auto it = Managers.CreateIterator();
			while(Result && it)
			{
				Result = Result && (*it)->OnStartPlayer(CurrentHoloPlayModeType);
				++it;
			}

			if (!Result)
			{
				UE_LOG(HoloPlayLogPlayer, Verbose, TEXT("Error during StartPlayer managers"));
			}
		}

		const FHoloPlayWindowSettings& WindowSettings = HoloPlaySettings->HoloPlayWindowSettings;

		switch (HoloPlayModeType)
		{
		case EHoloPlayModeType::PlayMode_InSeparateWindow:
		{
			bIsDestroyWindowRequested = false;

			// Fix resizing of rendering texture ourside of the editor
			// Always grow scene render targets outside of the editor.
			if (!GIsEditor)
			{
				IConsoleManager& ConsoleMan = IConsoleManager::Get();

				static IConsoleVariable* CVarSceneTargetsResizeMethodForceOverride = ConsoleMan.FindConsoleVariable(TEXT("r.SceneRenderTargetResizeMethodForceOverride"));
				static const int32 SceneTargetsResizeMethodForceOverrideVal = 1;
				CVarSceneTargetsResizeMethodForceOverride->Set(SceneTargetsResizeMethodForceOverrideVal);

				static IConsoleVariable* CVarSceneRenderTargetResizeMethod = ConsoleMan.FindConsoleVariable(TEXT("r.SceneRenderTargetResizeMethod"));
				static const int32 SceneRenderTargetResizeMethodVal = 2;
				CVarSceneRenderTargetResizeMethod->Set(SceneRenderTargetResizeMethodVal);
			}

			bool bUseBorderlessWindow = true;

			static FWindowStyle BorderlessStyle = FWindowStyle::GetDefault();
			BorderlessStyle
				.SetActiveTitleBrush(FSlateNoResource())
				.SetInactiveTitleBrush(FSlateNoResource())
				.SetFlashTitleBrush(FSlateNoResource())
				.SetOutlineBrush(FSlateNoResource())
				.SetBorderBrush(FSlateNoResource())
				.SetBackgroundBrush(FSlateNoResource())
				.SetChildBackgroundBrush(FSlateNoResource());

			FVector2D ClientSize;
			FVector2D ScreenPosition;

			EHoloPlayPlacement PlacementMode = WindowSettings.PlacementMode;
			if (PlacementMode == EHoloPlayPlacement::Automatic && GetHoloPlayDisplayManager()->GetHoloPlayDisplayMetrics().CalibrationCount == 0)
			{
				// No devices found, replace "Automatic" mode with "AlwaysDebugWindow"
				PlacementMode = EHoloPlayPlacement::AlwaysDebugWindow;
			}

			bool bUseOSWindowBorder = true;

			switch (PlacementMode)
			{
				case EHoloPlayPlacement::Automatic:
					{
						const auto& DisplaySettings = GetHoloPlayDisplayManager()->GetDisplaySettings();
						const auto& CalibrationSettings = GetHoloPlayDisplayManager()->GetCalibrationSettings();

						ClientSize.X = CalibrationSettings.ScreenWidth;
						ClientSize.Y = CalibrationSettings.ScreenHeight;

						ScreenPosition.X = DisplaySettings.LKGxpos;
						ScreenPosition.Y = DisplaySettings.LKGypos;
					}
					break;

				case EHoloPlayPlacement::CustomWindow:
					ClientSize = WindowSettings.CustomWindowLocation.ClientSize;
					ScreenPosition = WindowSettings.CustomWindowLocation.ScreenPosition;
					break;

				case EHoloPlayPlacement::AlwaysDebugWindow:
				default:
					ClientSize = WindowSettings.DebugWindowLocation.ClientSize;
					ScreenPosition = WindowSettings.DebugWindowLocation.ScreenPosition;
					// Use borders only for debug window
					bUseBorderlessWindow = false;
					// When using OS border, window can't be set as "topmost" (limitations of SWindow)
					bUseOSWindowBorder = false;
					WindowType = EWindowMode::Windowed;
					break;
			}

			HoloPlayWindow = SNew(SWindow)
				.Type(EWindowType::GameWindow)
				.Style(bUseBorderlessWindow ? &BorderlessStyle : &FCoreStyle::Get().GetWidgetStyle<FWindowStyle>("Window"))
				.ClientSize(ClientSize)
				.AdjustInitialSizeAndPositionForDPIScale(false)
				.Title(FText::FromString(TEXT("HoloPlay Window")))
				.FocusWhenFirstShown(true)
				.ScreenPosition(ScreenPosition)
				.UseOSWindowBorder(bUseOSWindowBorder)
				.CreateTitleBar(!bUseBorderlessWindow)
				.LayoutBorder(bUseBorderlessWindow ? FMargin(0) : FMargin(5, 5, 5, 5))
				.AutoCenter(AutoCenter)
				.SaneWindowPlacement(AutoCenter == EAutoCenter::None)
				.SizingRule(ESizingRule::UserSized)
				.IsTopmostWindow(!bUseBorderlessWindow && WindowSettings.bToptmostDebugWindow);

			// 1. Add new window
			const bool bShowImmediately = false;
			FSlateApplication::Get().AddWindow(HoloPlayWindow.ToSharedRef(), bShowImmediately);

			// 2. Set window mode
			// Do not set fullscreen mode here
			// The window mode will be set properly later
			if (WindowType == EWindowMode::Fullscreen)
			{
				HoloPlayWindow->SetWindowMode(EWindowMode::WindowedFullscreen);
			}
			else
			{
				HoloPlayWindow->SetWindowMode(WindowType);
			}

			// 3. Show window
			// No need to show window in off-screen rendering mode as it does not render to screen
			if (FSlateApplication::Get().IsRenderingOffScreen())
			{
				FSlateApplicationBase::Get().GetRenderer()->CreateViewport(HoloPlayWindow.ToSharedRef());
			}
			else
			{
				HoloPlayWindow->ShowWindow();
			}

			// 4. Tick now to force a redraw of the window and ensure correct fullscreen application
			FSlateApplication::Get().Tick();

			// 5. Add viewport to window
			// Create and assign viewport for Window. It could be with rendering directly to separate window or not if UE4 window, not native OS
			if (!bUseOSWindowBorder && !bUseBorderlessWindow)
			{
				RenderDirectlyToWindowInSeparateWindow = false;
			}

			HoloPlayViewport = SNew(SHoloPlayViewport).RenderDirectlyToWindow(RenderDirectlyToWindowInSeparateWindow);
			HoloPlayViewport->GetHoloPlayViewportClient()->SetViewportWindow(HoloPlayWindow);
			HoloPlayWindow->SetContent(HoloPlayViewport.ToSharedRef());
			HoloPlayWindow->SlatePrepass();

			if (WindowType != HoloPlayWindow->GetWindowMode())
			{
				HoloPlayWindow->SetWindowMode(WindowType);
				HoloPlayWindow->ReshapeWindow(ScreenPosition, ClientSize);
				FVector2D NewViewportSize = HoloPlayWindow->GetViewportSize();
				HoloPlayViewport->GetSceneViewport()->UpdateViewportRHI(false, NewViewportSize.X, NewViewportSize.Y, WindowType, PF_Unknown);
				HoloPlayViewport->GetSceneViewport()->Invalidate();

				// Resize backbuffer
				FVector2D NewBackbufferSize = HoloPlayWindow->IsMirrorWindow() ? ClientSize : NewViewportSize;
				FSlateApplicationBase::Get().GetRenderer()->UpdateFullscreenState(HoloPlayWindow.ToSharedRef(), NewBackbufferSize.X, NewBackbufferSize.Y);
			}

			// 6. Add window delegates
			OnWindowClosedDelegate.BindRaw(this, &FHoloPlayRuntimeModule::OnWindowClosed);
			HoloPlayWindow->SetOnWindowClosed(OnWindowClosedDelegate);

			break;
		}
		case EHoloPlayModeType::PlayMode_InMainViewport:
		{
			if (GEngine->GameViewport)
			{
				bool bRenderDirectlyToWindow = (GIsEditor) ? false : true;

				TSharedPtr<SWindow> GameViewportWindow = GEngine->GameViewport->GetWindow();
				FString WindowTitle = GameViewportWindow->GetTitle().ToString();

				if (WindowSettings.PlacementMode == EHoloPlayPlacement::Automatic)
				{
					FVector2D ClientSize;
					FVector2D ScreenPosition;

					const auto& DisplaySettings = GetHoloPlayDisplayManager()->GetDisplaySettings();
					const auto& CalibrationSettings = GetHoloPlayDisplayManager()->GetCalibrationSettings();

					ClientSize.X = CalibrationSettings.ScreenWidth;
					ClientSize.Y = CalibrationSettings.ScreenHeight;

					ScreenPosition.X = DisplaySettings.LKGxpos;
					ScreenPosition.Y = DisplaySettings.LKGypos;

					bool bRequesWindowAutoPlacement = false;

					struct Local
					{
						static void RequestResolutionChange(const FVector2D& InClientSize, const FVector2D InScreenPosition, TSharedPtr<SWindow> Window)
						{
							bool bNewModeApplied = false;
							auto WindowMode = Window->GetWindowMode();

							UGameEngine* GameEngine = Cast<UGameEngine>(GEngine);
							if (GameEngine)
							{
								UGameUserSettings* UserSettings = GameEngine->GetGameUserSettings();
								if (UserSettings != nullptr)
								{
									UserSettings->SetScreenResolution(FIntPoint(InClientSize.X, InClientSize.Y));
									UserSettings->SetFullscreenMode(WindowMode);
									UserSettings->ConfirmVideoMode();
									UserSettings->ApplySettings(false);
									bNewModeApplied = true;
								}
							}

							if (!bNewModeApplied)
							{
								FSystemResolution::RequestResolutionChange(InClientSize.X, InClientSize.Y, Window->GetWindowMode());
							}

							Window->ReshapeWindow(InScreenPosition, InClientSize);
						}
					};
#if WITH_EDITOR
					auto LastExecutedPlayModeType = GetDefault<ULevelEditorPlaySettings>()->LastExecutedPlayModeType;

					// If Movie capturing
					if ((HoloPlay::GetMovieSceneCapture() != nullptr) || bIsCaptureStandaloneMovie)
					{
						bRenderDirectlyToWindow = false;
					}
					// Check placement if bIsStandaloneGame or bIsGameMode
					else if (bIsStandaloneGame || bIsGameMode)
					{
						Local::RequestResolutionChange(ClientSize, ScreenPosition, GameViewportWindow);
					}

					//  if Editor Floating window
					else if (LastExecutedPlayModeType == EPlayModeType::PlayMode_InEditorFloating)
					{
						FMargin Border = GameViewportWindow->GetWindowBorderSize();
						ScreenPosition.X -= Border.Left;
						ClientSize.X += Border.Left + Border.Right;
						ScreenPosition.Y -= Border.Top;
						ClientSize.Y += Border.Top + Border.Bottom;

						GameViewportWindow->ReshapeWindow(ScreenPosition, ClientSize);
					}
#else
					{
						Local::RequestResolutionChange(ClientSize, ScreenPosition, GameViewportWindow);
					}
#endif
				}
				GEngine->GameViewport->OnCloseRequested().AddRaw(this, &FHoloPlayRuntimeModule::OnGameViewportCloseRequested);

				// Create and assign viewport to window
				HoloPlayViewport = SNew(SHoloPlayViewport).RenderDirectlyToWindow(bRenderDirectlyToWindow);
				HoloPlayViewport->GetHoloPlayViewportClient()->SetViewportWindow(GEngine->GameViewport->GetWindow());

				GEngine->GameViewport->AddViewportWidgetContent(
					HoloPlayViewport.ToSharedRef()
				);

				GEngine->GameViewport->bDisableWorldRendering = true;
			}
			break;
		}
		default:
			return;
		}

		bIsPlaying = true;
	}
}

void FHoloPlayRuntimeModule::StopPlayer()
{
	DISPLAY_HOLOPLAY_FUNC_TRACE(HoloPlayLogPlayer);

	if (bIsPlaying == true)
	{
		// Stop all managers
		for (auto Mng : Managers)
		{
			Mng->OnStopPlayer();
		}

		auto PlayModeType = CurrentHoloPlayModeType;

		// Stop PlayInStandalon first
		if (bIsStandaloneGame || bIsCaptureStandaloneMovie || bLockInMainViewport)
		{
			PlayModeType = EHoloPlayModeType::PlayMode_InMainViewport;
		}

		switch (PlayModeType)
		{
		case EHoloPlayModeType::PlayMode_InSeparateWindow:
		{
			if (bIsDestroyWindowRequested == false)
			{
				bIsDestroyWindowRequested = true;

				if (FSlateApplication::IsInitialized())
				{
					HoloPlayWindow->RequestDestroyWindow();
				}
				else
				{
					HoloPlayWindow->DestroyWindowImmediately();
				}

				// Stop player
				OnWindowClosedDelegate.Unbind();

				HoloPlayViewport.Reset();
				HoloPlayWindow.Reset();
			}

			break;
		}
		case EHoloPlayModeType::PlayMode_InMainViewport:
		{
			if (GEngine->GameViewport)
			{
				GEngine->GameViewport->bDisableWorldRendering = false;
				GEngine->GameViewport->RemoveViewportWidgetContent(
					HoloPlayViewport.ToSharedRef()
				);

				HoloPlayViewport.Reset();
			}

			break;
		}
		default:
			return;
		}

		bIsPlaying = false;
	}
}

void FHoloPlayRuntimeModule::RestartPlayer(EHoloPlayModeType HoloPlayModeType)
{
	StopPlayer();
	StartPlayer(HoloPlayModeType);
}

void FHoloPlayRuntimeModule::OnWindowClosed(const TSharedRef<SWindow>& Window)
{
	StopPlayer();
}

void FHoloPlayRuntimeModule::OnGameViewportCloseRequested(FViewport* InViewport)
{
	StopPlayer();
}

TSharedPtr<FHoloPlayDisplayManager> FHoloPlayRuntimeModule::GetHoloPlayDisplayManager()
{
	return HoloPlayDisplayManager;
}

TSharedPtr<FHoloPlayCommandLineManager> FHoloPlayRuntimeModule::GetHoloPlayCommandLineManager()
{
	return HoloPlayCommandLineManager;
}

void FHoloPlayRuntimeModule::StartPlayerSeparateProccess()
{
	auto HoloPlaySettings = GetDefault<UHoloPlaySettings>();
	bLockInMainViewport = HoloPlaySettings->HoloPlayWindowSettings.bLockInMainViewport;
	auto LastExecutedPlayModeType = bLockInMainViewport ? EHoloPlayModeType::PlayMode_InMainViewport : HoloPlaySettings->HoloPlayWindowSettings.LastExecutedPlayModeType;

#if WITH_EDITOR
	// Try to parse if this is standalone mode
	{
		FString StandaloneSessionName = "Play in Standalone Game";
		bIsStandaloneGame = FApp::GetSessionName() == StandaloneSessionName;
		if (bIsStandaloneGame)
		{
			StartPlayer(EHoloPlayModeType::PlayMode_InMainViewport);
			return;
		}
	}

	// Try to parse separate process in capture scene
	{
		FString CaptureStandaloneMovie;
		// Try to read screen model from command line
		FParse::Value(FCommandLine::Get(), TEXT("-MovieSceneCaptureManifest="), CaptureStandaloneMovie);

		bIsCaptureStandaloneMovie = !CaptureStandaloneMovie.IsEmpty();
		if (bIsCaptureStandaloneMovie)
		{
			StartPlayer(EHoloPlayModeType::PlayMode_InMainViewport);
			return;
		}
	}

	// Play in editor game mode
	{
		
		bool OnOff = true;
		bIsGameMode = FParse::Bool(FCommandLine::Get(), TEXT("-game"), OnOff);
		if (bIsGameMode)
		{
			StartPlayer(LastExecutedPlayModeType);
			return;
		}
	}

#else
	StartPlayer(LastExecutedPlayModeType);
#endif
}

void FHoloPlayRuntimeModule::OnPostEngineInit()
{
	// Init all managers
	InitAllManagers();

	// Init all settings
	GetDefault<UHoloPlaySettings>()->PostEngineInit();
}

void FHoloPlayRuntimeModule::OnGameViewportCreated()
{
	if (!GIsEditor)
	{
		// We're in game mode
		if (ensureMsgf(bSeparateProccessPlayerStarded == false, TEXT("StartPlayer in separate proccess was already called")))
		{
			// Init all managers
			InitAllManagers();

			StartPlayerSeparateProccess();
			bSeparateProccessPlayerStarded = true;
		}
	}
}

void FHoloPlayRuntimeModule::InitAllManagers()
{
	if (bIsManagerInit == false)
	{
		bIsManagerInit = true;

		bool Result = true;
		auto it = Managers.CreateIterator();
		while (Result && it)
		{
			Result = Result && (*it)->Init();
			++it;
		}

		if (!Result)
		{
			UE_LOG(HoloPlayLogPlayer, Verbose, TEXT("Error during initialize managers"));
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHoloPlayRuntimeModule, HoloPlayRuntime)