// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprints/HoloPlayLibrary.h"
#include "Misc/HoloPlayLog.h"

#include "HoloPlaySettings.h"


UHoloPlaySettings* UHoloPlayLibrary::GetHoloPlaySettings()
{
	return DuplicateObject(GetDefault<UHoloPlaySettings>(), nullptr);
}