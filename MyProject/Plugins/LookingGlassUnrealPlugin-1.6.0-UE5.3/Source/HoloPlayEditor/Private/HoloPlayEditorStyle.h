#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

/**
 * @class	FHoloPlayEditorStyle
 *
 * @brief	A HoloPlay editor style.
 * 			Loading UI resources
 */

class FHoloPlayEditorStyle
{
public:

	static void Initialize();

	static void Shutdown();

	/**
	 * @fn	static void FHoloPlayEditorStyle::ReloadTextures();
	 *
	 * @brief	reloads textures used by slate renderer
	 */

	static void ReloadTextures();

	/**
	 * @fn	static const ISlateStyle& FHoloPlayEditorStyle::Get();
	 *
	 * @brief	Gets the get
	 *
	 * @returns	The Slate style set for the Shooter game.
	 */

	static const ISlateStyle& Get();

	static FName GetStyleSetName();

private:
	static TSharedRef< class FSlateStyleSet > Create();

private:
	static TSharedPtr< class FSlateStyleSet > StyleInstance;
};