// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "HoloPlaySettings.h"

#include "RHI.h"
#include "Components/SceneCaptureComponent.h"

class FViewport;
class FTextureRenderTargetResource;
class FTextureResource;

namespace HoloPlay
{
	/**
	 * @struct	FRenderContext
	 *
	 * @brief	A render context.
	 * 			Structure for copy from Game Thread to Render Thread for rendering
	 */

	struct FLenticularRenderContext
	{
		const FViewport* Viewport;
		const FTextureRenderTargetResource* QuiltTargetResource;
		FHoloPlayTilingQuality TilingValues;
		const FTextureResource* OverrideQuiltResource;
		bool bQuiltMode;
	};

	struct FCopyToQuiltRenderContext
	{
		const FTextureRenderTargetResource* QuiltTargetResource;
		FHoloPlayTilingQuality TilingValues;
		const FTextureResource* TilingTextureResource;
		int32 CurrentViewIndex;
		int32 ViewInfoIndex;
		int32 TotalViews;
		int32 ViewRows;
		int32 ViewColumns;
		FSceneCaptureViewInfo CaptureViewInfo;
	};

	struct FRender2DViewContext
	{
		const FViewport* Viewport;
		const FTextureResource* TextureTarget2DResourse;
	};

	void Render2DView_RenderThread(FRHICommandListImmediate& RHICmdList, const FRender2DViewContext& Context);


	/**
	 * @fn	void CopyToQuiltShader_RenderThread(FRHICommandListImmediate& RHICmdList, const FRenderContext& Context, int CurrentView);
	 *
	 * @brief	Copies to quilt
	 * 			It is copy one by one texture to the quilt render target from tiling texture
	 *
	 * @param [in,out]	RHICmdList 	List of rhi commands.
	 * @param 		  	Context	   	The context.
	 * @param 		  	ViewIndex	The current view.
	 */

	void CopyToQuiltShader_RenderThread(FRHICommandListImmediate& RHICmdList, const FCopyToQuiltRenderContext& Context);

	/**
	 * @fn	void RenderLenticularShader_RenderThread(FRHICommandListImmediate& RHICmdList, const FRenderContext& Context);
	 *
	 * @brief	Execute Lenticular with screen calibration data
	 *
	 * @param [in,out]	RHICmdList	List of rhi commands.
	 * @param 		  	Context   	The context.
	 */

	void RenderLenticularShader_RenderThread(FRHICommandListImmediate& RHICmdList, const FLenticularRenderContext& Context);
}
