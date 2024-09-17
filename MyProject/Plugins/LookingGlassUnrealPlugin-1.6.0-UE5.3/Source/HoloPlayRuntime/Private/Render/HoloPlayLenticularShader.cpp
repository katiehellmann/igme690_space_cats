#include "Render/HoloPlayLenticularShader.h"

#include "Misc/HoloPlayLog.h"

#include "RHIStaticStates.h"
#include "RHIResources.h"

#if ENGINE_MAJOR_VERSION < 5

FVertexBufferRHIRef FHoloPlayLenticularShader::CreateTempHoloPlayVertexBuffer(FRHICommandListImmediate& RHICmdList, float ULeft, float URight, float VTop, float VBottom)
{
	FRHIResourceCreateInfo CreateInfo;
	FVertexBufferRHIRef VertexBufferRHI = RHICreateVertexBuffer(sizeof(FHoloPlayTextureVertex) * 4, BUF_Volatile, CreateInfo);
	void* VoidPtr = RHILockVertexBuffer(VertexBufferRHI, 0, sizeof(FHoloPlayTextureVertex) * 4, RLM_WriteOnly);

	FHoloPlayTextureVertex* Vertices = (FHoloPlayTextureVertex*)VoidPtr;
	Vertices[0].Position.Set(-1.0f, 1.0f, 1.0f, 1.0f); // Top Left
	Vertices[1].Position.Set(1.0f, 1.0f, 1.0f, 1.0f); // Top Right
	Vertices[2].Position.Set(-1.0f, -1.0f, 1.0f, 1.0f); // Bottom Left
	Vertices[3].Position.Set(1.0f, -1.0f, 1.0f, 1.0f); // Bottom Right

	Vertices[0].UV.Set(ULeft, VTop);
	Vertices[1].UV.Set(URight, VTop);
	Vertices[2].UV.Set(ULeft, VBottom);
	Vertices[3].UV.Set(URight, VBottom);
	RHIUnlockVertexBuffer(VertexBufferRHI);

	return VertexBufferRHI;
}

#else

FBufferRHIRef FHoloPlayLenticularShader::CreateTempHoloPlayVertexBuffer(FRHICommandListImmediate& RHICmdList, float ULeft, float URight, float VTop, float VBottom)
{
	FRHIResourceCreateInfo CreateInfo(TEXT("FHoloPlayLenticularShader"));
#if ENGINE_MINOR_VERSION < 3
	FBufferRHIRef VertexBufferRHI = RHICreateVertexBuffer(sizeof(FHoloPlayTextureVertex) * 4, BUF_Volatile, CreateInfo);
#else
	FBufferRHIRef VertexBufferRHI = RHICmdList.CreateVertexBuffer(sizeof(FHoloPlayTextureVertex) * 4, BUF_Volatile, CreateInfo);
#endif
	void* VoidPtr = RHICmdList.LockBuffer(VertexBufferRHI, 0, sizeof(FHoloPlayTextureVertex) * 4, RLM_WriteOnly);

	FHoloPlayTextureVertex* Vertices = (FHoloPlayTextureVertex*)VoidPtr;
	Vertices[0].Position.Set(-1.0f, 1.0f, 1.0f, 1.0f); // Top Left
	Vertices[1].Position.Set(1.0f, 1.0f, 1.0f, 1.0f); // Top Right
	Vertices[2].Position.Set(-1.0f, -1.0f, 1.0f, 1.0f); // Bottom Left
	Vertices[3].Position.Set(1.0f, -1.0f, 1.0f, 1.0f); // Bottom Right

	Vertices[0].UV.Set(ULeft, VTop);
	Vertices[1].UV.Set(URight, VTop);
	Vertices[2].UV.Set(ULeft, VBottom);
	Vertices[3].UV.Set(URight, VBottom);
	RHICmdList.UnlockBuffer(VertexBufferRHI);

	return VertexBufferRHI;
}

#endif

IMPLEMENT_SHADER_TYPE(, FHoloPlayLenticularShaderVS, TEXT("/Plugin/HoloPlay/Private/HoloPlayLenticularShader.usf"), TEXT("LenticularVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FHoloPlayLenticularShaderPS, TEXT("/Plugin/HoloPlay/Private/HoloPlayLenticularShader.usf"), TEXT("LenticularPS"), SF_Pixel);
