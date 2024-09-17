#pragma once

#include "CoreMinimal.h"
#include "ShaderParameters.h"
#include "Shader.h"
#include "GlobalShader.h"
#include "UniformBuffer.h"
#include "ShaderParameterUtils.h"
#include "ShaderParameterStruct.h"
#include "PipelineStateCache.h"
#include "Containers/DynamicRHIResourceArray.h"

#include "Runtime/Launch/Resources/Version.h"

/**
 * @struct	FHoloPlayTextureVertex
 *
 * @brief	A HoloPlay texture vertex.
 * 			Containts Position and UV data
 */

struct FHoloPlayTextureVertex
{
#if ENGINE_MAJOR_VERSION < 5
	FVector4 Position;
	FVector2D UV;
#else
	FVector4f Position;
	FVector2f UV;
#endif
};

/**
 * @class	FHoloPlayVertexBuffer
 *
 * @brief	We define our vertex declaration to let us get our UV coords into the shader
 */

class FHoloPlayVertexBuffer : public FVertexBuffer
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;

	/**
	 * @fn	virtual void FHoloPlayVertexBuffer::InitRHI() override
	 *
	 * @brief	Initializes the rhi Vertex Buffers
	 */

#if ENGINE_MAJOR_VERSION < 5 || ENGINE_MINOR_VERSION < 3
	virtual void InitRHI() override
#else
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
#endif
	{
		FVertexDeclarationElementList Elements;
		uint32 Stride = sizeof(FHoloPlayTextureVertex);
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FHoloPlayTextureVertex, Position), VET_Float4, 0, Stride));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FHoloPlayTextureVertex, UV), VET_Float2, 1, Stride));
		VertexDeclarationRHI = PipelineStateCache::GetOrCreateVertexDeclaration(Elements);
	}

	/**
	 * @fn	virtual void FHoloPlayVertexBuffer::ReleaseRHI() override
	 *
	 * @brief	Releases the Vertex Buffers
	 */

	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

/**
 * @class	FHoloPlayIndexBuffer
 *
 * @brief	HoloPlay index buffer
 */

class FHoloPlayIndexBuffer : public FIndexBuffer
{
public:

	/**
	 * @fn	void FHoloPlayIndexBuffer::InitRHI() override
	 *
	 * @brief	Initialize the RHI for this rendering resource
	 */

#if ENGINE_MAJOR_VERSION < 5 || ENGINE_MINOR_VERSION < 3
	virtual void InitRHI() override
#else
	virtual void InitRHI(FRHICommandListBase& RHICmdList) override
#endif
	{
		// Indices 0 - 5 are used for rendering a quad. Indices 6 - 8 are used for triangle optimization.
		const uint16 Indices[] = { 0, 1, 2, 2, 1, 3, 0, 4, 5 };

		TResourceArray<uint16, INDEXBUFFER_ALIGNMENT> IndexBuffer;
		uint32 NumIndices = UE_ARRAY_COUNT(Indices);
		IndexBuffer.AddUninitialized(NumIndices);
		FMemory::Memcpy(IndexBuffer.GetData(), Indices, NumIndices * sizeof(uint16));

		// Create index buffer. Fill buffer with initial data upon creation
#if ENGINE_MAJOR_VERSION < 5
		FRHIResourceCreateInfo CreateInfo(&IndexBuffer);
#else
		FRHIResourceCreateInfo CreateInfo(TEXT("FHoloPlayIndexBuffer"), &IndexBuffer);
	#if ENGINE_MINOR_VERSION < 3
		IndexBufferRHI = RHICreateIndexBuffer(sizeof(uint16), IndexBuffer.GetResourceDataSize(), BUF_Static, CreateInfo);
	#else
		IndexBufferRHI = RHICmdList.CreateIndexBuffer(sizeof(uint16), IndexBuffer.GetResourceDataSize(), BUF_Static, CreateInfo);
	#endif
#endif
	}
};

// Lenticular vertex shader params
BEGIN_SHADER_PARAMETER_STRUCT(FVertexLenticularConstantParameters, )
END_SHADER_PARAMETER_STRUCT()

// Lenticular pixel shader params
BEGIN_SHADER_PARAMETER_STRUCT(FPixelLenticularConstantParameters,)
	SHADER_PARAMETER_TEXTURE(Texture2D, InputTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, InputTextureSampler)

	SHADER_PARAMETER(float, pitch)
	SHADER_PARAMETER(float, slope)
	SHADER_PARAMETER(float, center)
	SHADER_PARAMETER(float, subp)
#if ENGINE_MAJOR_VERSION < 5
	SHADER_PARAMETER(FVector4, tile)
	SHADER_PARAMETER(FVector2D, viewPortion)
	SHADER_PARAMETER(FVector4, aspect)
#else
	SHADER_PARAMETER(FVector4f, tile)
	SHADER_PARAMETER(FVector2f, viewPortion)
	SHADER_PARAMETER(FVector4f, aspect)
#endif
	SHADER_PARAMETER(int, QuiltMode)
	SHADER_PARAMETER(int, FlipYTexCoords)
	SHADER_PARAMETER(float, Gamma)
END_SHADER_PARAMETER_STRUCT()

/**
 * @class	FHoloPlayLenticularShader
 *
 * @brief	A HoloPlay lenticular shader.
 * 			Parent shader
 */

class FHoloPlayLenticularShader : public FGlobalShader
{
	//DECLARE_EXPORTED_SHADER_TYPE(FHoloPlayLenticularShader, Global, /*HOLOPLAYRUNTIME_API*/);
public:
	FHoloPlayLenticularShader() = default;
	FHoloPlayLenticularShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer)
	{
	}

public:

	/**
	 * @fn	static bool FHoloPlayLenticularShader::ShouldCache(EShaderPlatform Platform)
	 *
	 * @brief	Determine if we should cache
	 *
	 * @param	Platform	The platform.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	static bool ShouldCache(EShaderPlatform Platform)
	{
		return true;
	}

	/**
	 * @fn	static bool FHoloPlayLenticularShader::ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	 *
	 * @brief	Useful when adding a permutation of a particular shader
	 *
	 * @param	Parameters	Options for controlling the operation.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}

	/**
	 * @fn	static FVertexBufferRHIRef FHoloPlayLenticularShader::CreateTempHoloPlayVertexBuffer(float ULeft = 0.0f, float URight = 1.0f, float VTop = 0.0f, float VBottom = 1.0f);
	 *
	 * @brief	Creates temporary HoloPlay vertex buffer
	 * 			It create and bind vertex buffer on GPU
	 *
	 * @param	ULeft  	(Optional) The left.
	 * @param	URight 	(Optional) The right.
	 * @param	VTop   	(Optional) The top.
	 * @param	VBottom	(Optional) The bottom.
	 *
	 * @returns	The new HoloPlay vertex buffer.
	 */
#if ENGINE_MAJOR_VERSION < 5
	static FVertexBufferRHIRef CreateTempHoloPlayVertexBuffer(FRHICommandListImmediate& RHICmdList, float ULeft = 0.0f, float URight = 1.0f, float VTop = 0.0f, float VBottom = 1.0f);
#else
	static FBufferRHIRef CreateTempHoloPlayVertexBuffer(FRHICommandListImmediate& RHICmdList, float ULeft = 0.0f, float URight = 1.0f, float VTop = 0.0f, float VBottom = 1.0f);
#endif
};

/**
 * @class	FHoloPlayLenticularShaderVS
 *
 * @brief	CPP implementation HoloPlay Lenticular Vertex shader. This class cannot be inherited..
 */


class FHoloPlayLenticularShaderVS : public FHoloPlayLenticularShader
{
	DECLARE_GLOBAL_SHADER(FHoloPlayLenticularShaderVS);
	SHADER_USE_PARAMETER_STRUCT(FHoloPlayLenticularShaderVS, FHoloPlayLenticularShader);

	using FParameters = FVertexLenticularConstantParameters;
};

/**
 * @class	FHoloPlayLenticularShaderPS
 *
 * @brief	CPP implementation HoloPlay Lenticular Vertex shader. This class cannot be inherited..
 */

class FHoloPlayLenticularShaderPS final : public FHoloPlayLenticularShader
{
	DECLARE_GLOBAL_SHADER(FHoloPlayLenticularShaderPS);
	SHADER_USE_PARAMETER_STRUCT(FHoloPlayLenticularShaderPS, FHoloPlayLenticularShader);

	using FParameters = FPixelLenticularConstantParameters;
};