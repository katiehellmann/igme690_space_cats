#pragma once

#include "CoreMinimal.h"

// Plugin-wide log categories
#if UE_BUILD_SHIPPING
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogBlueprints, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogGame, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogManagers, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogPlayer, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogRender, Warning, Warning);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogInput, Warning, Warning);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogSettings, Warning, Warning);
#else
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogBlueprints, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogGame, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogManagers, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogPlayer, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogRender, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogInput, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(HoloPlayLogSettings, Log, All);
#endif

#if UE_BUILD_SHIPPING
#define DISPLAY_HOLOPLAY_FUNC_TRACE(cat) ;
#else
#if PLATFORM_WINDOWS
#define DISPLAY_HOLOPLAY_FUNC_TRACE(cat)  UE_LOG(cat, VeryVerbose, TEXT(">> %s"), ANSI_TO_TCHAR(__FUNCTION__))
#else
#define DISPLAY_CLUSTER_FUNC_TRACE(cat) ;
#endif // PLATFORM_WINDOWS
#endif // UE_BUILD_SHIPPING

