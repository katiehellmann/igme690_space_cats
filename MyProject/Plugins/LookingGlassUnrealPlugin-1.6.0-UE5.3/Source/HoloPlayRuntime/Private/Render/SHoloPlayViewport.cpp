#include "Render/SHoloPlayViewport.h"

#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"

#include "Slate/SceneViewport.h"
#include "Widgets/SViewport.h"
#include "Widgets/SToolTip.h"

#include "Render/HoloPlayViewportClient.h"
#include "Misc/HoloPlayLog.h"
#include "IHoloPlayRuntime.h"

void SHoloPlayViewport::Construct(const FArguments& InArgs)
{
	// If add to main viewport should be false
	RenderDirectlyToWindow = InArgs._RenderDirectlyToWindow;

	// Create Viewport Widget
	Viewport = SNew(SViewport)
		.IsEnabled(true)
		.ShowEffectWhenDisabled(false)
		.RenderDirectlyToWindow(RenderDirectlyToWindow) // Make same like in Unity, it will be dark scene but same look 
		.EnableGammaCorrection(false) // FIX dark color, should be false. Whether or not to enable gamma correction.Doesn't apply when rendering directly to a backbuffer.
		.ReverseGammaCorrection(false)
		.EnableBlending(false)
		.EnableStereoRendering(false)
		.PreMultipliedAlpha(true)
		.IgnoreTextureAlpha(true);

	// Set console variables
	// TODO. Something with texture sampler. It happens when you create quilt texture. State
	// SamplerDesc.MaxAnisotropy = ComputeAnisotropyRT(Initializer.MaxAnisotropy);
	// D3D11State.cpp
	IConsoleManager& ConsoleMan = IConsoleManager::Get();
	static IConsoleVariable* MaxAnisotropy = ConsoleMan.FindConsoleVariable(TEXT("r.MaxAnisotropy"));
	static const int32 MaxAnisotropyVal = 0;
	MaxAnisotropy->Set(MaxAnisotropyVal);

	// Fix shadow rendering
	static IConsoleVariable* MaxCSMResolution = ConsoleMan.FindConsoleVariable(TEXT("r.Shadow.MaxCSMResolution"));
	static const int32 MaxCSMResolutionVal = 1024;
	MaxCSMResolution->Set(MaxCSMResolutionVal);

	// Create Viewport Client
	HoloPlayViewportClient = MakeShareable(new FHoloPlayViewportClient());

	// Create Scene Viewport
	SceneViewport = MakeShareable(new FSceneViewport(HoloPlayViewportClient.Get(), Viewport));

	// Set Viewport 
	HoloPlayViewportClient->Viewport = SceneViewport.Get();
	HoloPlayViewportClient->HoloPlaySceneViewport = SceneViewport.Get();

	// Assign SceneViewport to Viewport widget. Needed for rendering
	Viewport->SetViewportInterface(SceneViewport.ToSharedRef());

	// Assign Viewport widget for our custom PlayScene Viewport
	this->ChildSlot
		[
			Viewport.ToSharedRef()
		];

	// Resize viewport only if in MainViewport and in game mode	
	if (IHoloPlayRuntime::Get().GetCurrentHoloPlayModeType() == EHoloPlayModeType::PlayMode_InMainViewport && GEngine->GameViewport != nullptr)
	{
		UGameViewportClient* GameViewport = GEngine->GameViewport;
		FIntPoint Size = GameViewport->Viewport->GetSizeXY();
		if (Size.X > 0 && Size.Y > 0)
		{
			SceneViewport->UpdateViewportRHI(false, Size.X, Size.Y, GameViewport->GetWindow()->GetWindowMode(), PF_Unknown);
		}
	}
}

void SHoloPlayViewport::Tick(const FGeometry & AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	// Call FViewport each engine tick
	SceneViewport->Draw();
}
