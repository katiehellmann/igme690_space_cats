#include "HoloPlayEditor.h"

#include "HoloPlayEditorStyle.h"
#include "HoloPlayEditorCommands.h"
#include "HoloPlayToolbar.h"

#include "IHoloPlayRuntime.h"
#include "Misc/HoloPlayHelpers.h"
#include "HoloPlaySettings.h"
#include "Game/HoloPlaySceneCaptureComponent2D.h"

#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"
#include "LevelEditor.h"

#include "Engine/GameViewportClient.h"
#include "Editor.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FHoloPlayEditorModule"

void FHoloPlayEditorModule::StartupModule()
{
	// Initialize play button ui style
	FHoloPlayEditorStyle::Initialize();
	FHoloPlayEditorStyle::ReloadTextures();

	// Add HoloPlayToolbar section
	FHoloPlayToolbarCommand::Register();
	HoloPlayToolbar = MakeShareable(new FHoloPlayToolbar);

	// Add settings to project settings
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FHoloPlayEditorModule::AddEditorSettings);
	GetMutableDefault<UHoloPlaySettings>()->AddToRoot();

	UGameViewportClient::OnViewportCreated().AddRaw(this, &FHoloPlayEditorModule::OnPIEViewportStarted);
	FEditorDelegates::EndPIE.AddRaw(this, &FHoloPlayEditorModule::OnEndPIE);

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.OnActorSelectionChanged().AddRaw(this, &FHoloPlayEditorModule::OnEditorSelectionChanged);
}

void FHoloPlayEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FHoloPlayEditorStyle::Shutdown();

	// Release Toolbar
	HoloPlayToolbar.Reset();

	// Release editor settings
	RemoveEditorSettings();

	// Stop player if running
	IHoloPlayRuntime::Get().StopPlayer();

	if (FModuleManager::Get().IsModuleLoaded("LevelEditor"))
	{
		FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditorModule.OnActorSelectionChanged().RemoveAll(this);
	}
}

// Check MagicLeapHMD settings loading
void FHoloPlayEditorModule::AddEditorSettings()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule)
	{
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "HoloPlay",
			LOCTEXT("HoloPlaySettingsName", "HoloPlay Plugin"),
			LOCTEXT("HoloPlaySettingsDescription", "Configure the HoloPlay plug-in."),
			GetMutableDefault<UHoloPlaySettings>()
		);

		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FHoloPlayEditorModule::OnSettingsSaved);
		}
	}
}

void FHoloPlayEditorModule::RemoveEditorSettings()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "HoloPlay");
	}
}

bool FHoloPlayEditorModule::OnSettingsSaved()
{
	UHoloPlaySettings* HoloPlaySettings = GetMutableDefault<UHoloPlaySettings>();
	bool ResaveSettings = true;

	if (ResaveSettings)
	{
		HoloPlaySettings->HoloPlaySave();
	}

	return true;
}

void FHoloPlayEditorModule::OnPIEViewportStarted()
{
	if ((HoloPlay::GetMovieSceneCapture() != nullptr && HoloPlay::GetGameHoloPlayCaptureComponent() != nullptr)
		|| GetDefault<UHoloPlaySettings>()->HoloPlayWindowSettings.bLockInMainViewport)
	{
		// Just in case, stop existing player, as we'll probably change settings
		IHoloPlayRuntime::Get().StopPlayer();
		// Indicate that we should stop a player when this PIE session ends
		bShouldStopPlaying = true;
		// Start player for video capture, rendering capture to the main viewport
		IHoloPlayRuntime::Get().StartPlayer(EHoloPlayModeType::PlayMode_InMainViewport);
	}
}

void FHoloPlayEditorModule::OnEndPIE(bool bIsSimulating)
{
	if (bShouldStopPlaying)
	{
		// Video capture has been initiated, we should stop player, because we've started it
		bShouldStopPlaying = false;
		IHoloPlayRuntime::Get().StopPlayer();
	}
}

void FHoloPlayEditorModule::OnEditorSelectionChanged(const TArray<UObject*>& NewSelection, bool bForceRefresh)
{
	if (NewSelection.Num() == 1)
	{
		AActor* Actor = Cast<AActor>(NewSelection[0]);
		if (Actor != nullptr)
		{
			UHoloPlaySceneCaptureComponent2D* CaptureComponent = Actor->FindComponentByClass<UHoloPlaySceneCaptureComponent2D>();
			if (CaptureComponent)
			{
				// Make the selected component first, so it will be activated in HoloPlayRuntime
				IHoloPlayRuntime::Get().EditorHoloPlayCaptureComponents.Remove(CaptureComponent);
				IHoloPlayRuntime::Get().EditorHoloPlayCaptureComponents.Insert(CaptureComponent, 0);
			}
		}
	}
}

FHoloPlayBlocksInterface& FHoloPlayEditorModule::GetBlocksInterface()
{
	return BlocksInterface;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHoloPlayEditorModule, HoloPlayEditor)
