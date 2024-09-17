#include "Managers/HoloPlayLaunchManager.h"

#include "HoloPlaySettings.h"

#include "Misc/HoloPlayLog.h"

#include "Runtime/Core/Public/Misc/CommandLine.h"


FHoloPlayLaunchManager::FHoloPlayLaunchManager()
{
}

FHoloPlayLaunchManager::~FHoloPlayLaunchManager()
{
}

bool FHoloPlayLaunchManager::Init()
{
	UHoloPlaySettings* HoloPlaySettings = GetMutableDefault<UHoloPlaySettings>();
	UHoloPlayLaunchSettings* HoloPlayLaunchSettings = GetMutableDefault<UHoloPlayLaunchSettings>();

// First run at the build
#if WITH_EDITOR
#else
	if (0 == HoloPlayLaunchSettings->LaunchCounter)
	{
		HoloPlaySettings->HoloPlayWindowSettings.bLockInMainViewport = true;
		HoloPlaySettings->HoloPlaySave();
	}
#endif

	// Increament Launch Conter
	HoloPlayLaunchSettings->LaunchCounter++;

	// Save Launch Config
	HoloPlayLaunchSettings->SaveConfig();

	return true;
}
