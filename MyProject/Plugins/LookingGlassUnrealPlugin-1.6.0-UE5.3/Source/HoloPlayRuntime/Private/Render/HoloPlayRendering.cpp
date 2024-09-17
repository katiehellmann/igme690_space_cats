#include "Render/HoloPlayRendering.h"
#include "Render/HoloPlayLenticularShader.h"
#include "Game/HoloPlaySceneCaptureComponent2D.h"

#include "IHoloPlayRuntime.h"
#include "Managers/HoloPlayDisplayManager.h"
#include "Misc/HoloPlayLog.h"

#include "GlobalShader.h"
#include "PipelineStateCache.h"
#include "RHIStaticStates.h"
#include "TextureResource.h"
#include "ScreenRendering.h"
#include "CommonRenderResources.h"

#include "Runtime/Launch/Resources/Version.h"


/** Vertex declaration for the 2D screen rectangle. */
static TGlobalResource<FHoloPlayVertexBuffer> GHoloPlayVertexDeclaration;
static TGlobalResource<FHoloPlayIndexBuffer> GHoloPlayIndexDeclaration;

void HoloPlay::Render2DView_RenderThread(FRHICommandListImmediate& RHICmdList, const FRender2DViewContext& Context)
{
	check(IsInRenderingThread());

	// Set render target ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	FRHIRenderPassInfo RPInfo(Context.Viewport->GetRenderTargetTexture(), ERenderTargetActions::Load_Store);
	RHICmdList.BeginRenderPass(RPInfo, TEXT("Render2DView_RenderThread"));


	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);

	const auto FeatureLevel = GMaxRHIFeatureLevel;
	auto ShaderMap = GetGlobalShaderMap(FeatureLevel);
	TShaderMapRef<FScreenVS> VertexShader(ShaderMap);
	TShaderMapRef<FScreenPS> PixelShader(ShaderMap);

	GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
	GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
	GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;

#if ENGINE_MAJOR_VERSION >= 5
	SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
#else
	SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
#endif

	PixelShader->SetParameters(RHICmdList, TStaticSamplerState<SF_Bilinear>::GetRHI(), Context.TextureTarget2DResourse->TextureRHI);

	float U = 0.f;
	float V = 0.f;
	float SizeU = 1.f;
	float SizeV = 1.f;

	const FName RendererModuleName("Renderer");
	IRendererModule* RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);

	RendererModule->DrawRectangle(
		RHICmdList,
		0, 0,
		Context.Viewport->GetSizeXY().X, Context.Viewport->GetSizeXY().Y,
		U, V,
		SizeU, SizeV,
		FIntPoint(Context.Viewport->GetSizeXY().X, Context.Viewport->GetSizeXY().Y),
		FIntPoint(1, 1),
		VertexShader,
		EDRF_Default);

	RHICmdList.EndRenderPass();
}

void HoloPlay::CopyToQuiltShader_RenderThread(FRHICommandListImmediate& RHICmdList, const FCopyToQuiltRenderContext& Context)
{
	check(IsInRenderingThread());

	SCOPED_DRAW_EVENTF(RHICmdList, Scene, TEXT("CopyToQuiltShader_RenderThread ViewIndex %d_%d_%d"), Context.CurrentViewIndex, Context.ViewInfoIndex, Context.TotalViews);
	DISPLAY_HOLOPLAY_FUNC_TRACE(HoloPlayLogRender)

	const FHoloPlayTilingQuality& TilingValues = Context.TilingValues;

	// Set Render targets ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	FRHIRenderPassInfo RPInfo(Context.QuiltTargetResource->GetRenderTargetTexture(), ERenderTargetActions::Load_Store);
	RHICmdList.BeginRenderPass(RPInfo, TEXT("CopyToQuiltShader_RenderThread"));

	// Set Viewport for tiling ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int32 RI = TilingValues.GetNumTiles() - Context.CurrentViewIndex - 1;
	int32 X = (Context.CurrentViewIndex % TilingValues.TilesX) * TilingValues.TileSizeX;
	int32 Y = (RI / TilingValues.TilesX) * TilingValues.TileSizeY;

	// The padding is necessary because the shader takes y from the opposite spot as this does
	int32 PaddingY = TilingValues.QuiltH - TilingValues.TilesY * TilingValues.TileSizeY;
	FVector2D Min(X, Y + PaddingY);
	FVector2D Max(Min.X + TilingValues.TileSizeX, Min.Y + TilingValues.TileSizeY);

	UE_LOG(HoloPlayLogRender, Verbose, TEXT("CurrentView %d, Min %s Max %s"), Context.CurrentViewIndex, *Min.ToString(), *Max.ToString());


	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);

	// Get shaders. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	const auto FeatureLevel = GMaxRHIFeatureLevel;
	auto ShaderMap = GetGlobalShaderMap(FeatureLevel);
	TShaderMapRef<FScreenVS> VertexShader(ShaderMap);
	TShaderMapRef<FScreenPS> PixelShader(ShaderMap);

	// Set the graphic pipeline state. START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
	GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
	GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;

#if ENGINE_MAJOR_VERSION >= 5
	SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
#else
	SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
#endif
	// Set the graphic pipeline state. END --------------------------------------

	// Update shader parameters and resources parameters. START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	PixelShader->SetParameters(RHICmdList, TStaticSamplerState<SF_Bilinear>::GetRHI(), Context.TilingTextureResource->TextureRHI);
	float U = 0.f;
	float V = 0.f;
	float SizeU = 1.f;
	float SizeV = 1.f;
	FHoloPlayRenderingConfig::CalculateViewRect(U, V, SizeU, SizeV, Context.ViewRows, Context.ViewColumns, Context.TotalViews, Context.ViewInfoIndex);
	// Update shader parameters and resources parameters. END --------------------------------------

	// Issue Indexed draw call ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	const FName RendererModuleName("Renderer");
	IRendererModule* RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
	RendererModule->DrawRectangle(
		RHICmdList,
		Min.X, Min.Y,
		Max.X - Min.X, Max.Y - Min.Y,
		U, V,
		SizeU, SizeV,
		FIntPoint(Context.QuiltTargetResource->GetRenderTargetTexture()->GetSizeX(), Context.QuiltTargetResource->GetRenderTargetTexture()->GetSizeY()),
		FIntPoint(1, 1),
		VertexShader,
		EDRF_Default);

	RHICmdList.EndRenderPass();
}

void HoloPlay::RenderLenticularShader_RenderThread(FRHICommandListImmediate & RHICmdList, const FLenticularRenderContext& Context)
{
	check(IsInRenderingThread());

	SCOPED_DRAW_EVENTF(RHICmdList, Scene, TEXT("RenderLenticularShader_RenderThread"));
	DISPLAY_HOLOPLAY_FUNC_TRACE(HoloPlayLogRender)

	FTexture2DRHIRef RenderTargetTexture = Context.Viewport->GetRenderTargetTexture();

	auto TilingValues = Context.TilingValues;
	float Aspect = (float)Context.Viewport->GetSizeXY().X / (float)Context.Viewport->GetSizeXY().Y;

	if (!RenderTargetTexture.IsValid())
	{
		return;
	}

	// Set render target ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	FRHIRenderPassInfo RPInfo(Context.Viewport->GetRenderTargetTexture(), ERenderTargetActions::Load_Store);
	RHICmdList.BeginRenderPass(RPInfo, TEXT("RenderLenticularShader_RenderThread"));

	// Set viewport ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	RHICmdList.SetViewport(0, 0, 0.f, RenderTargetTexture->GetSizeX(), RenderTargetTexture->GetSizeY(), 1.f);

	// Get shaders. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	const auto FeatureLevel = GMaxRHIFeatureLevel;
	FGlobalShaderMap* ShaderMap = GetGlobalShaderMap(FeatureLevel);
	TShaderMapRef< FHoloPlayLenticularShaderVS > VertexShader(ShaderMap);
	TShaderMapRef< FHoloPlayLenticularShaderPS > PixelShader(ShaderMap);

	// Set the graphic pipeline state. START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	FGraphicsPipelineStateInitializer GraphicsPSOInit;
	RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
	GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
	GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
	GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
	GraphicsPSOInit.PrimitiveType = PT_TriangleList;
	GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GHoloPlayVertexDeclaration.VertexDeclarationRHI;
	GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

#if ENGINE_MAJOR_VERSION >= 5
	SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
#else
	SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
#endif
	// Set the graphic pipeline state. END --------------------------------------

	// Update shader uniform parameters. START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	FPixelLenticularConstantParameters PixelHoloPlayCP;
	{
		auto HoloPlayDisplayManager = IHoloPlayRuntime::Get().GetHoloPlayDisplayManager();
		const FHoloPlayDisplayMetrics::FCalibration& Calibration = HoloPlayDisplayManager->GetCalibrationSettings();
		const bool FlipImageX = false;
		const bool FlipYTexCoords = true;

		PixelHoloPlayCP.pitch = Calibration.Pitch;
		PixelHoloPlayCP.slope = Calibration.Slope;
		PixelHoloPlayCP.center = Calibration.Center;
		PixelHoloPlayCP.Gamma = 1.0f;

		float Subp = 1.f / (Calibration.ScreenWidth * 3.f);
		Subp *= FlipImageX ? -1 : 1;
		PixelHoloPlayCP.subp = Subp;

		PixelHoloPlayCP.tile.Set(
			TilingValues.TilesX,
			TilingValues.TilesY,
			TilingValues.GetNumTiles(),
			TilingValues.TilesX * TilingValues.TilesY
		);
		PixelHoloPlayCP.viewPortion.Set(
			TilingValues.PortionX,
			TilingValues.PortionY
		);
		PixelHoloPlayCP.aspect.Set(
			// Note: aspect in shader is always the same now
			Aspect,
			Aspect, // (HoloPlaySettings->HoloPlayRenderingSettings.bUseCustomAspect == false) ? Aspect : CustomAspect,
			0, // Overscan
			0
		);

		UE_LOG(HoloPlayLogRender, Verbose, TEXT("pitch %f, slope %f, center %f, subp %f, tile %s, viewPortion %s, aspect %s"),
			PixelHoloPlayCP.pitch, PixelHoloPlayCP.slope, PixelHoloPlayCP.center,  PixelHoloPlayCP.subp,
			*PixelHoloPlayCP.tile.ToString(), *PixelHoloPlayCP.viewPortion.ToString(), *PixelHoloPlayCP.aspect.ToString());

		PixelHoloPlayCP.QuiltMode = Context.bQuiltMode;
		PixelHoloPlayCP.FlipYTexCoords = (int32)FlipYTexCoords;
	}
	// Update shader uniform parameters. END --------------------------------------

	// Update shader parameters and resources parameters. START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (Context.OverrideQuiltResource != nullptr)
	{
		PixelHoloPlayCP.InputTexture = Context.OverrideQuiltResource->TextureRHI;
		PixelHoloPlayCP.InputTextureSampler = Context.OverrideQuiltResource->SamplerStateRHI;
		// Shader expects a linear-space texture, so adjust gamma when texture is sRGB.
		PixelHoloPlayCP.Gamma = (Context.OverrideQuiltResource->bSRGB) ? 1.0f / 2.2f : 1.0f;
	}
	else if (Context.QuiltTargetResource != nullptr)
	{
		PixelHoloPlayCP.InputTexture = Context.QuiltTargetResource->TextureRHI;
		PixelHoloPlayCP.InputTextureSampler = Context.QuiltTargetResource->SamplerStateRHI;
	}
	else
	{
		checkf(false, TEXT("No Quilt Texture for the Lenticular shader"));
	}

	SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), PixelHoloPlayCP);
	// Update shader parameters and resources parameters. END --------------------------------------

	// Set geometry START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	auto VertexBufferRHI = FHoloPlayLenticularShader::CreateTempHoloPlayVertexBuffer(RHICmdList, 0.f, 1.f, 1.f, 0.f);
	RHICmdList.SetStreamSource(0, VertexBufferRHI, 0);
	// Set geometry END --------------------------------------

	// Issue Indexed draw call ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	RHICmdList.DrawIndexedPrimitive(
		GHoloPlayIndexDeclaration.IndexBufferRHI,
		/*BaseVertexIndex=*/ 0,
		/*MinIndex=*/ 0,
		/*NumVertices=*/ 4,
		/*StartIndex=*/ 0,
		/*NumPrimitives=*/ 2,
		/*NumInstances=*/ EDRF_Default
	);

	RHICmdList.EndRenderPass();
}