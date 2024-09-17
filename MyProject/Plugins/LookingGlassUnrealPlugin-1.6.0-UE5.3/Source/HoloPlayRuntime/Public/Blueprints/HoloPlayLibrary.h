// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HoloPlayLibrary.generated.h"

class UHoloPlaySettings;

/**
 * 
 */
UCLASS()

/**
 * @class	UHoloPlayLibrary
 *
 * @brief	HoloPlay blueprint libaray
 * 			For static access to davice data from any blueprins
 */

class HOLOPLAYRUNTIME_API UHoloPlayLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintCallable, meta = (DisplayName = "Get HoloPlay settings"), Category = "HoloPlay")

	/**
	 * @fn	static UHoloPlaySettings* UHoloPlayLibrary::GetHoloPlaySettings();
	 *
	 * @brief	Gets all HoloPlay runtime settings  
	 *
	 * @returns	Null if it fails, else the HoloPlay settings.
	 */

	static UHoloPlaySettings* GetHoloPlaySettings();

};

