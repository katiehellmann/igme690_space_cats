#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"

class FExtender;
class FToolBarBuilder;
class SWidget;
struct FSlateIcon;
class FUICommandList;

/**
 * @class	FHoloPlayToolbar
 *
 * @brief	HoloPlay Menu UI
 */

class FHoloPlayToolbar
{
public:
	FHoloPlayToolbar();
	~FHoloPlayToolbar();

private:
	void ExtendLevelEditorToolbar();
	void FillToolbar(FToolBarBuilder& ToolbarBuilder);

	/**
	 * @fn	static TSharedRef<SWidget> FHoloPlayToolbar::GenerateMenuContent(TSharedRef<FUICommandList> InCommandList);
	 *
	 * @brief	Generates a HoloPlay menu UI
	 *
	 * @param	InCommandList	List of in commands.
	 *
	 * @returns	The menu content.
	 */

	static TSharedRef<SWidget> GenerateMenuContent(TSharedRef<FUICommandList> InCommandList, TSharedPtr<FExtender> Extender);

	/**
	 * @fn	static FSlateIcon FHoloPlayToolbar::GetRepeatLastPlayIcon();
	 *
	 * @brief	Gets repeat last play icon
	 *
	 * @returns	The repeat last play icon.
	 */

	static FSlateIcon GetRepeatLastPlayIcon();
	static FText GetRepeatLastPlayName();
	static FText GetRepeatLastPlayToolTip();

private:
	TSharedPtr<FExtender> LevelToolbarExtender;
};
