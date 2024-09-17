#pragma once

#include "Stats/Stats.h"

DECLARE_STATS_GROUP(TEXT("HoloPlay_RenderThread"), STATGROUP_HoloPlay_RenderThread, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("CopyToQuiltShader"), STAT_CopyToQuiltShader_RenderThread, STATGROUP_HoloPlay_RenderThread);
DECLARE_CYCLE_STAT(TEXT("RenderLenticularShader"), STAT_RenderLenticularShader_RenderThread, STATGROUP_HoloPlay_RenderThread);


DECLARE_STATS_GROUP(TEXT("HoloPlay_GameThread"), STATGROUP_HoloPlay_GameThread, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("Draw"), STAT_Draw_GameThread, STATGROUP_HoloPlay_GameThread);
DECLARE_CYCLE_STAT(TEXT("CaptureScene"), STAT_CaptureScene_GameThread, STATGROUP_HoloPlay_GameThread);
DECLARE_CYCLE_STAT(TEXT("DrawDebugParameters"), STAT_DrawDebugParameters_GameThread, STATGROUP_HoloPlay_GameThread);
