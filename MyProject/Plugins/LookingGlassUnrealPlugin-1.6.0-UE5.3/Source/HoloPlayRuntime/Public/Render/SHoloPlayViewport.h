#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SComboBox.h"

class SViewport;
class FSceneViewport;
class FHoloPlayViewportClient;
class FSceneViewport;

/**
 * @class	SHoloPlayViewport
 *
 * @brief	A HoloPlay viewport widget
 * 			This is for rendering 2D geometry to the Window
 */

class SHoloPlayViewport : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SHoloPlayViewport) 
		: _Content()
		, _RenderDirectlyToWindow(true)
	{ }
		SLATE_DEFAULT_SLOT(FArguments, Content)
		SLATE_ARGUMENT(bool, RenderDirectlyToWindow)
	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

	TSharedRef<FHoloPlayViewportClient> GetHoloPlayViewportClient() { return HoloPlayViewportClient.ToSharedRef();  }
	TSharedRef<FSceneViewport> GetSceneViewport() { return SceneViewport.ToSharedRef(); }

	/** SWidget interface */

	/**
	 * @fn	virtual void SHoloPlayViewport::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	 *
	 * @brief	Tick each engine tick, this is where we call FViewport::Draw() -->
	 * 			FPlaySceneViewportClient::Draw(...)
	 *
	 * @param	AllottedGeometry	The allotted geometry.
	 * @param	InCurrentTime   	The in current time.
	 * @param	InDeltaTime			The in delta time.
	 */

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;


private:
	TSharedPtr<SViewport> Viewport;
	TSharedPtr<FSceneViewport> SceneViewport;
	TSharedPtr<FHoloPlayViewportClient> HoloPlayViewportClient;

	bool RenderDirectlyToWindow;
};