
#include "HoloPlayEditorStyle.h"

#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"

TSharedPtr< FSlateStyleSet > FHoloPlayEditorStyle::StyleInstance = NULL;

void FHoloPlayEditorStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FHoloPlayEditorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FHoloPlayEditorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("HoloPlayStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);
const FVector2D Icon60x40(60.0f, 40.0f);
const FVector2D Icon30x20(30.0f, 20.0f);
const FVector2D Icon60x60(60.0f, 60.0f);

TSharedRef< FSlateStyleSet > FHoloPlayEditorStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("HoloPlayStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("HoloPlay")->GetBaseDir() / TEXT("Resources"));

	Style->Set("HoloPlay.RepeatLastPlay", new IMAGE_BRUSH("HoloPlayOpenWindow_60_40", Icon60x40));
	Style->Set("HoloPlay.RepeatLastPlay.Small", new IMAGE_BRUSH("HoloPlayOpenWindow_60_40", Icon30x20));

	Style->Set("HoloPlay.OpenWindow", new IMAGE_BRUSH(TEXT("HoloPlayOpenWindow_60_40"), Icon60x40));
	Style->Set("HoloPlay.CloseWindow", new IMAGE_BRUSH(TEXT("HoloPlayCloseWindow_60_40"), Icon60x40));
	Style->Set("HoloPlay.OpenSettings", new IMAGE_BRUSH(TEXT("HoloPlayOpenSettings_60_40"), Icon60x40));

	Style->Set("HoloPlay.PlayInHoloPlayWindow", new IMAGE_BRUSH("HoloPlayOpenWindow_60_40", Icon60x40));
	Style->Set("HoloPlay.OpenHoloPlayWindow.Small", new IMAGE_BRUSH("HoloPlayOpenWindow_60_40", Icon30x20));
	Style->Set("HoloPlay.PlayInMainViewport", new IMAGE_BRUSH("HoloPlayInMainViewport_60_40", Icon60x40));
	Style->Set("HoloPlay.PlayInMainViewport.Small", new IMAGE_BRUSH("HoloPlayInMainViewport_60_40", Icon30x20));

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FHoloPlayEditorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FHoloPlayEditorStyle::Get()
{
	return *StyleInstance;
}
