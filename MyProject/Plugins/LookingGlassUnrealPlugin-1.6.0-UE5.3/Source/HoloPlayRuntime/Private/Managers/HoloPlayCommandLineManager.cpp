#include "Managers/HoloPlayCommandLineManager.h"
#include "HoloPlaySettings.h"
#include "Misc/HoloPlayLog.h"
#include "IHoloPlayRuntime.h"

#include "Runtime/Core/Public/Misc/CommandLine.h"


FHoloPlayCommandLineManager::FHoloPlayCommandLineManager()
{
}

FHoloPlayCommandLineManager::~FHoloPlayCommandLineManager()
{
}

bool FHoloPlayCommandLineManager::Init()
{
	UHoloPlaySettings* HoloPlaySettings = GetMutableDefault<UHoloPlaySettings>();

	uint32 WindowType = 0;
	uint32 LastExecutedPlayModeType = 0;
	uint32 LockInMainViewport = 0;
	uint32 PlacementInHoloPlay = 0;
	uint32 ScreenIndex = 0;
	uint32 QuiltMode = 0;

	int ShouldSave = 0;

	if (FParse::Value(FCommandLine::Get(), TEXT("hp_playmodetype="), LastExecutedPlayModeType))
	{
		HoloPlaySettings->HoloPlayWindowSettings.LastExecutedPlayModeType = static_cast<EHoloPlayModeType>(LastExecutedPlayModeType);
		ShouldSave++;
	}

	if (FParse::Value(FCommandLine::Get(), TEXT("hp_lockinmainviewport="), LockInMainViewport))
	{
		HoloPlaySettings->HoloPlayWindowSettings.bLockInMainViewport = !!LockInMainViewport;
		ShouldSave++;
	}

	if (FParse::Value(FCommandLine::Get(), TEXT("hp_playcement="), PlacementInHoloPlay))
	{
		//todo: validate, or use enum names here
		HoloPlaySettings->HoloPlayWindowSettings.PlacementMode = (EHoloPlayPlacement)PlacementInHoloPlay;
		ShouldSave++;
	}

	if (FParse::Value(FCommandLine::Get(), TEXT("hp_screenindex="), ScreenIndex))
	{
		HoloPlaySettings->HoloPlayWindowSettings.ScreenIndex = ScreenIndex;
		ShouldSave++;
	}

	if (FParse::Value(FCommandLine::Get(), TEXT("hp_quiltmode="), QuiltMode))
	{
		HoloPlaySettings->HoloPlayRenderingSettings.QuiltMode = (QuiltMode != 0);
		ShouldSave++;
	}

	if (ShouldSave > 0)
	{
		HoloPlaySettings->HoloPlaySave();
	}

	return true;
}
