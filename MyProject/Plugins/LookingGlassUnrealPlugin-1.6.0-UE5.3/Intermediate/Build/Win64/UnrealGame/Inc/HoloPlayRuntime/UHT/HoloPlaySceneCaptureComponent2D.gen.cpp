// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/HoloPlayRuntime/Public/Game/HoloPlaySceneCaptureComponent2D.h"
#include "../../../Source/HoloPlayRuntime/Public/HoloPlaySettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoloPlaySceneCaptureComponent2D() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_NoRegister();
	HOLOPLAYRUNTIME_API UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayTilingQuality();
	UPackage* Z_Construct_UPackage__Script_HoloPlayRuntime();
// End Cross Module References
	DEFINE_FUNCTION(UHoloPlaySceneCaptureComponent2D::execSetActiveCaptureComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetActiveCaptureComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHoloPlaySceneCaptureComponent2D::execSetSize)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_InSize);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSize(Z_Param_InSize);
		P_NATIVE_END;
	}
	void UHoloPlaySceneCaptureComponent2D::StaticRegisterNativesUHoloPlaySceneCaptureComponent2D()
	{
		UClass* Class = UHoloPlaySceneCaptureComponent2D::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetActiveCaptureComponent", &UHoloPlaySceneCaptureComponent2D::execSetActiveCaptureComponent },
			{ "SetSize", &UHoloPlaySceneCaptureComponent2D::execSetSize },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "HoloPlay" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D, nullptr, "SetActiveCaptureComponent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics
	{
		struct HoloPlaySceneCaptureComponent2D_eventSetSize_Parms
		{
			float InSize;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InSize;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::NewProp_InSize = { "InSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HoloPlaySceneCaptureComponent2D_eventSetSize_Parms, InSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::NewProp_InSize,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "Category", "HoloPlay" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D, nullptr, "SetSize", nullptr, nullptr, Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::HoloPlaySceneCaptureComponent2D_eventSetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::HoloPlaySceneCaptureComponent2D_eventSetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlaySceneCaptureComponent2D);
	UClass* Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_NoRegister()
	{
		return UHoloPlaySceneCaptureComponent2D::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Size;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NearClipFactor_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NearClipFactor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseFarClipPlane_MetaData[];
#endif
		static void NewProp_bUseFarClipPlane_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseFarClipPlane;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FarClipFactor_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FarClipFactor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FOV_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FOV;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSingleViewMode_MetaData[];
#endif
		static void NewProp_bSingleViewMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSingleViewMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverrideQuiltTexture2D_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverrideQuiltTexture2D;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TilingQuality_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TilingQuality_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TilingQuality;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TilingValues_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TilingValues;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideDOF_MetaData[];
#endif
		static void NewProp_bOverrideDOF_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideDOF;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DOFAdjust_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DOFAdjust;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DepthOfFieldFstop_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthOfFieldFstop;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebugFocusPlane_MetaData[];
#endif
		static void NewProp_bDrawDebugFocusPlane_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebugFocusPlane;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableMotionBlur_MetaData[];
#endif
		static void NewProp_bEnableMotionBlur_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableMotionBlur;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextureTarget2DRendering_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TextureTarget2DRendering;
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FrustumColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MidPlaneFrustumColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MidPlaneFrustumColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MidPlaneLineLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MidPlaneLineLength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MidLineThickness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MidLineThickness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumLineThickness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrustumLineThickness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DebugFocusPlaneColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DebugFocusPlaneColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FocusPlaneVisualizationMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FocusPlaneVisualizationMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FocusPlaneVisualizationMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FocusPlaneVisualizationMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DebugFocusPlaneComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DebugFocusPlaneComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DebugFocusPlaneMID_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DebugFocusPlaneMID;
#endif // WITH_EDITORONLY_DATA
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneCaptureComponent2D,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetActiveCaptureComponent, "SetActiveCaptureComponent" }, // 1887805623
		{ &Z_Construct_UFunction_UHoloPlaySceneCaptureComponent2D_SetSize, "SetSize" }, // 2766371317
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Rendering" },
		{ "Comment", "/**\n * Capture looking glass multi views\n */" },
		{ "HideCategories", "Collision Object Physics SceneComponent Projection Collision Object Physics SceneComponent Collision Object Physics SceneComponent Mobility Trigger PhysicsVolume" },
		{ "IncludePath", "Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Capture looking glass multi views" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_Size_MetaData[] = {
		{ "BlueprintSetter", "SetSize" },
		{ "Category", "CaptureSettings" },
		{ "ClampMin", "0.1" },
		{ "Comment", "// Vertical size of the capture region in Unreal units (cm)\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Vertical size of the capture region in Unreal units (cm)" },
		{ "UIMax", "2000.0" },
		{ "UIMin", "0.1" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, Size), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_Size_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_Size_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_NearClipFactor_MetaData[] = {
		{ "Category", "CaptureSettings" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_NearClipFactor = { "NearClipFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, NearClipFactor), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_NearClipFactor_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_NearClipFactor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bUseFarClipPlane_MetaData[] = {
		{ "Category", "CaptureSettings" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	void Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bUseFarClipPlane_SetBit(void* Obj)
	{
		((UHoloPlaySceneCaptureComponent2D*)Obj)->bUseFarClipPlane = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bUseFarClipPlane = { "bUseFarClipPlane", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHoloPlaySceneCaptureComponent2D), &Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bUseFarClipPlane_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bUseFarClipPlane_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bUseFarClipPlane_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FarClipFactor_MetaData[] = {
		{ "Category", "CaptureSettings" },
		{ "EditCondition", "bUseFarClipPlane" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FarClipFactor = { "FarClipFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, FarClipFactor), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FarClipFactor_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FarClipFactor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FOV_MetaData[] = {
		{ "Category", "CaptureSettings" },
		{ "ClampMax", "90.0" },
		{ "ClampMin", "8.0" },
		{ "Comment", "// Horizontal field of view angle of the camera\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Horizontal field of view angle of the camera" },
		{ "UIMax", "90.0" },
		{ "UIMin", "8.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FOV = { "FOV", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, FOV), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FOV_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FOV_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bSingleViewMode_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "Comment", "// When disabled, the plugin will render 8 pictures at a time. Enable it if you're experiencing issues with rendering (e.g. out of VRAM problem), with a cost of slower performance.\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "When disabled, the plugin will render 8 pictures at a time. Enable it if you're experiencing issues with rendering (e.g. out of VRAM problem), with a cost of slower performance." },
	};
#endif
	void Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bSingleViewMode_SetBit(void* Obj)
	{
		((UHoloPlaySceneCaptureComponent2D*)Obj)->bSingleViewMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bSingleViewMode = { "bSingleViewMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHoloPlaySceneCaptureComponent2D), &Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bSingleViewMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bSingleViewMode_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bSingleViewMode_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_OverrideQuiltTexture2D_MetaData[] = {
		{ "Category", "QuiltSettings" },
		{ "Comment", "// A static replacement for Quilt image.\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "A static replacement for Quilt image." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_OverrideQuiltTexture2D = { "OverrideQuiltTexture2D", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, OverrideQuiltTexture2D), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_OverrideQuiltTexture2D_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_OverrideQuiltTexture2D_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingQuality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingQuality_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "Comment", "// Customizable Tiling Settings\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Customizable Tiling Settings" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingQuality = { "TilingQuality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, TilingQuality), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingQuality_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingQuality_MetaData) }; // 1613864522
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingValues_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingValues = { "TilingValues", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, TilingValues), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingValues_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingValues_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bOverrideDOF_MetaData[] = {
		{ "Category", "PostProcessing" },
		{ "Comment", "// Force Depth of Field effect to be focused on HoloPlayCapture location\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Force Depth of Field effect to be focused on HoloPlayCapture location" },
	};
#endif
	void Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bOverrideDOF_SetBit(void* Obj)
	{
		((UHoloPlaySceneCaptureComponent2D*)Obj)->bOverrideDOF = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bOverrideDOF = { "bOverrideDOF", nullptr, (EPropertyFlags)0x0010000200000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHoloPlaySceneCaptureComponent2D), &Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bOverrideDOF_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bOverrideDOF_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bOverrideDOF_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DOFAdjust_MetaData[] = {
		{ "Category", "PostProcessing" },
		{ "Comment", "// Distance adjustment for OverrideDOF mode\n" },
		{ "editcondition", "bOverrideDOF" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Distance adjustment for OverrideDOF mode" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DOFAdjust = { "DOFAdjust", nullptr, (EPropertyFlags)0x0010000200000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, DOFAdjust), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DOFAdjust_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DOFAdjust_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DepthOfFieldFstop_MetaData[] = {
		{ "Category", "PostProcessing" },
		{ "ClampMax", "32.0" },
		{ "ClampMin", "0.1" },
		{ "Comment", "// Focal depth for OverrideDOF mode. Lower values makes more blurry images\n" },
		{ "DisplayName", "Aperture (DoF strength)" },
		{ "editcondition", "bOverrideDOF" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Focal depth for OverrideDOF mode. Lower values makes more blurry images" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DepthOfFieldFstop = { "DepthOfFieldFstop", nullptr, (EPropertyFlags)0x0010000200000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, DepthOfFieldFstop), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DepthOfFieldFstop_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DepthOfFieldFstop_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bDrawDebugFocusPlane_MetaData[] = {
		{ "Category", "PostProcessing" },
		{ "Comment", "// True to draw a translucent plane at the current focus depth, for easy tweaking.\n" },
		{ "editcondition", "bOverrideDOF" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "True to draw a translucent plane at the current focus depth, for easy tweaking." },
	};
#endif
	void Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bDrawDebugFocusPlane_SetBit(void* Obj)
	{
		((UHoloPlaySceneCaptureComponent2D*)Obj)->bDrawDebugFocusPlane = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bDrawDebugFocusPlane = { "bDrawDebugFocusPlane", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHoloPlaySceneCaptureComponent2D), &Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bDrawDebugFocusPlane_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bDrawDebugFocusPlane_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bDrawDebugFocusPlane_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bEnableMotionBlur_MetaData[] = {
		{ "Category", "PostProcessing" },
		{ "Comment", "// Allow to render motion blur based on PostProcessingVolume settings\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Allow to render motion blur based on PostProcessingVolume settings" },
	};
#endif
	void Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bEnableMotionBlur_SetBit(void* Obj)
	{
		((UHoloPlaySceneCaptureComponent2D*)Obj)->bEnableMotionBlur = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bEnableMotionBlur = { "bEnableMotionBlur", nullptr, (EPropertyFlags)0x0010000200000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHoloPlaySceneCaptureComponent2D), &Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bEnableMotionBlur_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bEnableMotionBlur_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bEnableMotionBlur_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TextureTarget2DRendering_MetaData[] = {
		{ "Comment", "/** Render target for 2D rendering camera. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Render target for 2D rendering camera." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TextureTarget2DRendering = { "TextureTarget2DRendering", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, TextureTarget2DRendering), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TextureTarget2DRendering_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TextureTarget2DRendering_MetaData) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumColor_MetaData[] = {
		{ "Category", "CaptureSettings|Visual" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumColor = { "FrustumColor", nullptr, (EPropertyFlags)0x0010000800000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, FrustumColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumColor_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneFrustumColor_MetaData[] = {
		{ "Category", "CaptureSettings|Visual" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneFrustumColor = { "MidPlaneFrustumColor", nullptr, (EPropertyFlags)0x0010000800000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, MidPlaneFrustumColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneFrustumColor_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneFrustumColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneLineLength_MetaData[] = {
		{ "Category", "CaptureSettings|Visual" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// MidPlane Line Length for Frustum Component\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "MidPlane Line Length for Frustum Component" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneLineLength = { "MidPlaneLineLength", nullptr, (EPropertyFlags)0x0010000800000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, MidPlaneLineLength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneLineLength_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneLineLength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidLineThickness_MetaData[] = {
		{ "Category", "CaptureSettings|Visual" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// MidPlane Line Thickness for Frustum Component\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "MidPlane Line Thickness for Frustum Component" },
		{ "UIMax", "10.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidLineThickness = { "MidLineThickness", nullptr, (EPropertyFlags)0x0010000800000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, MidLineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidLineThickness_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidLineThickness_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumLineThickness_MetaData[] = {
		{ "Category", "CaptureSettings|Visual" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "// Frustum Line Thickness for Frustum Component\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Frustum Line Thickness for Frustum Component" },
		{ "UIMax", "10.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumLineThickness = { "FrustumLineThickness", nullptr, (EPropertyFlags)0x0010000800000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, FrustumLineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumLineThickness_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumLineThickness_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneColor_MetaData[] = {
		{ "Category", "CaptureSettings|Visual" },
		{ "Comment", "// For customizing the focus plane color, in case the default doesn't show up well in your scene.\n" },
		{ "EditCondition", "bDrawDebugFocusPlane" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "For customizing the focus plane color, in case the default doesn't show up well in your scene." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneColor = { "DebugFocusPlaneColor", nullptr, (EPropertyFlags)0x0010000800000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, DebugFocusPlaneColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneColor_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMesh_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMesh = { "FocusPlaneVisualizationMesh", nullptr, (EPropertyFlags)0x0040000800002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, FocusPlaneVisualizationMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMesh_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMaterial_MetaData[] = {
		{ "Comment", "/** Material used for debug focus plane visualization */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Material used for debug focus plane visualization" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMaterial = { "FocusPlaneVisualizationMaterial", nullptr, (EPropertyFlags)0x0040000800002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, FocusPlaneVisualizationMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMaterial_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneComponent_MetaData[] = {
		{ "Comment", "/** Component for the debug focus plane visualization */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Component for the debug focus plane visualization" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneComponent = { "DebugFocusPlaneComponent", nullptr, (EPropertyFlags)0x0040000800082008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, DebugFocusPlaneComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneComponent_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneMID_MetaData[] = {
		{ "Comment", "/** Dynamic material instance for the debug focus plane visualization */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlaySceneCaptureComponent2D.h" },
		{ "ToolTip", "Dynamic material instance for the debug focus plane visualization" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneMID = { "DebugFocusPlaneMID", nullptr, (EPropertyFlags)0x0040000800002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySceneCaptureComponent2D, DebugFocusPlaneMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneMID_MetaData), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneMID_MetaData) };
#endif // WITH_EDITORONLY_DATA
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_NearClipFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bUseFarClipPlane,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FarClipFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FOV,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bSingleViewMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_OverrideQuiltTexture2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingQuality_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingQuality,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TilingValues,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bOverrideDOF,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DOFAdjust,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DepthOfFieldFstop,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bDrawDebugFocusPlane,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_bEnableMotionBlur,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_TextureTarget2DRendering,
#if WITH_EDITORONLY_DATA
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneFrustumColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidPlaneLineLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_MidLineThickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FrustumLineThickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_FocusPlaneVisualizationMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::NewProp_DebugFocusPlaneMID,
#endif // WITH_EDITORONLY_DATA
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlaySceneCaptureComponent2D>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::ClassParams = {
		&UHoloPlaySceneCaptureComponent2D::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::PropPointers),
		0,
		0x00B010A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D()
	{
		if (!Z_Registration_Info_UClass_UHoloPlaySceneCaptureComponent2D.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlaySceneCaptureComponent2D.OuterSingleton, Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlaySceneCaptureComponent2D.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlaySceneCaptureComponent2D>()
	{
		return UHoloPlaySceneCaptureComponent2D::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlaySceneCaptureComponent2D);
	UHoloPlaySceneCaptureComponent2D::~UHoloPlaySceneCaptureComponent2D() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlaySceneCaptureComponent2D_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlaySceneCaptureComponent2D_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D, UHoloPlaySceneCaptureComponent2D::StaticClass, TEXT("UHoloPlaySceneCaptureComponent2D"), &Z_Registration_Info_UClass_UHoloPlaySceneCaptureComponent2D, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlaySceneCaptureComponent2D), 545177696U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlaySceneCaptureComponent2D_h_226511689(TEXT("/Script/HoloPlayRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlaySceneCaptureComponent2D_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlaySceneCaptureComponent2D_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
