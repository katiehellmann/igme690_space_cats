#pragma once

#include "HoloPlayEditorStyle.h"

#include "HoloPlaySettings.h"

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

class FUICommandList;
class FUICommandInfo;

/**
 * @class	FHoloPlayToolbarCommand
 *
 * @brief	Handles Unreal Engine HoloPlay editor commands
 */

class FHoloPlayToolbarCommand : public TCommands<FHoloPlayToolbarCommand>
{
public:
	FHoloPlayToolbarCommand();

	/**
	 * @fn	virtual void FHoloPlayToolbarCommand::RegisterCommands() override;
	 *
	 * @brief	Registers the commands for Unreal Engine
	 */

	virtual void RegisterCommands() override;

private:
	static void RepeatLastPlay_Clicked();
	static bool RepeatLastPlay_CanExecute();

	static void PlayInHoloPlayWindow_Clicked();
	static void CloseHoloPlayWindow_Clicked();
	static void OpenHoloPlaySettings_Clicked();
	static void PlayInMainViewport_Clicked();

	static void OpenBlocksUI_Clicked();

	static bool PlayInModeIsChecked(EHoloPlayModeType PlayMode);

	static void OnTogglePlayInQuiltMode();
	static bool OnIsPlayInQuiltModeEnabled();

	static void OnTogglePlayIn2DMode();
	static bool OnIsPlayIn2DModeEnabled();

	static void OnToggleLockInMainViewport();
	static bool OnIsLockInMainViewport();	

	// Window placement
	static void SetPlacementMode(EHoloPlayPlacement PlacementMode);
	static bool IsPlacementMode(EHoloPlayPlacement PlacementMode);

	// Rendering performance modes
	static void SetPerformanceMode(EHoloPlayPerformanceMode Mode);
	static bool IsPerformanceMode(EHoloPlayPerformanceMode Mode);

	static bool IsPlaying();
	static bool IsNotPlaying();

	static bool CanExecutePlayInMainViewport();
	static bool CanExecutePlayInHoloPlayWindow();
	static bool CanExecuteCloseInHoloPlayWindow();

public:
	static int32 GetCurrentHoloPlayDisplayIndex();
	static void SetCurrentHoloPlayDisplayIndex(int32 Index, ETextCommit::Type CommitInfo);

	static void SetLastExecutedPlayMode(EHoloPlayModeType PlayMode);
	static const TSharedRef <FUICommandInfo> GetLastPlaySessionCommand();

public:
	TSharedPtr<FUICommandList>		CommandActionList;

	TSharedPtr<FUICommandInfo>		RepeatLastPlay;
	TSharedPtr<FUICommandInfo>		PlayInHoloPlayWindow;
	TSharedPtr<FUICommandInfo>		CloseHoloPlayWindow;
	TSharedPtr<FUICommandInfo>		OpenHoloPlaySettings;
	TSharedPtr<FUICommandInfo>		PlayInMainViewport;
	TSharedPtr<FUICommandInfo>		PlayInQuiltMode;
	TSharedPtr<FUICommandInfo>		PlayIn2DMode;
	TSharedPtr<FUICommandInfo>		LockInMainViewport;
	// Window placement
	TSharedPtr<FUICommandInfo>		PlacementInHoloPlayAuto;
	TSharedPtr<FUICommandInfo>		PlacementInHoloPlayCustomWindow;
	TSharedPtr<FUICommandInfo>		PlacementInHoloPlayDebug;
	// Rendering performance modes
	TSharedPtr<FUICommandInfo>		RealtimeMode;
	TSharedPtr<FUICommandInfo>		AdaptiveMode;
	TSharedPtr<FUICommandInfo>		NonRealtimeMode;
	// Blocks
	TSharedPtr<FUICommandInfo>		OpenBlocksUI;
};