// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/HoloPlayRuntime/Public/Game/HoloPlayCapture.h"
#include "../../../Source/HoloPlayRuntime/Public/HoloPlaySettings.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoloPlayCapture() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_AHoloPlayCapture();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_AHoloPlayCapture_NoRegister();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_NoRegister();
	HOLOPLAYRUNTIME_API UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayTilingQuality();
	UPackage* Z_Construct_UPackage__Script_HoloPlayRuntime();
// End Cross Module References
	void AHoloPlayCapture::StaticRegisterNativesAHoloPlayCapture()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHoloPlayCapture);
	UClass* Z_Construct_UClass_AHoloPlayCapture_NoRegister()
	{
		return AHoloPlayCapture::StaticClass();
	}
	struct Z_Construct_UClass_AHoloPlayCapture_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverrideQuiltTexture2D_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverrideQuiltTexture2D;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSingleViewMode_MetaData[];
#endif
		static void NewProp_bSingleViewMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSingleViewMode;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TilingQuality_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TilingQuality_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TilingQuality;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TilingValues_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TilingValues;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraSpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraSpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderCamera;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHoloPlayCapture_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::Class_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "HideCategories", "Actor LOD Cooking Rendering Replication Input" },
		{ "IncludePath", "Game/HoloPlayCapture.h" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_Size_MetaData[] = {
		{ "Comment", "// Legacy properties, moved to UHoloPlaySceneCaptureComponent2D. Here for backwards compatibility.\n" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
		{ "ToolTip", "Legacy properties, moved to UHoloPlaySceneCaptureComponent2D. Here for backwards compatibility." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, Size_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_Size_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_Size_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_NearClipFactor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_NearClipFactor = { "NearClipFactor", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, NearClipFactor_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_NearClipFactor_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_NearClipFactor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bUseFarClipPlane_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	void Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bUseFarClipPlane_SetBit(void* Obj)
	{
		((AHoloPlayCapture*)Obj)->bUseFarClipPlane_DEPRECATED = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bUseFarClipPlane = { "bUseFarClipPlane", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AHoloPlayCapture), &Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bUseFarClipPlane_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bUseFarClipPlane_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bUseFarClipPlane_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FarClipFactor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FarClipFactor = { "FarClipFactor", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, FarClipFactor_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FarClipFactor_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FarClipFactor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FOV_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FOV = { "FOV", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, FOV_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FOV_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FOV_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_OverrideQuiltTexture2D_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_OverrideQuiltTexture2D = { "OverrideQuiltTexture2D", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, OverrideQuiltTexture2D_DEPRECATED), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_OverrideQuiltTexture2D_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_OverrideQuiltTexture2D_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bSingleViewMode_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	void Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bSingleViewMode_SetBit(void* Obj)
	{
		((AHoloPlayCapture*)Obj)->bSingleViewMode_DEPRECATED = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bSingleViewMode = { "bSingleViewMode", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AHoloPlayCapture), &Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bSingleViewMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bSingleViewMode_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bSingleViewMode_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingQuality_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingQuality_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingQuality = { "TilingQuality", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, TilingQuality_DEPRECATED), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingQuality_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingQuality_MetaData) }; // 1613864522
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingValues_MetaData[] = {
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingValues = { "TilingValues", nullptr, (EPropertyFlags)0x0020080820000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, TilingValues_DEPRECATED), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingValues_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingValues_MetaData) }; // 2767888229
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_CameraSpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CameraActor" },
		{ "Comment", "// Component which controls distance of camera from actor's location. Actor's location matches the camera focus point.\n// Note: we're not using \"VisibleAnywhere\" meta tag here to hide component's properties in editor\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
		{ "ToolTip", "Component which controls distance of camera from actor's location. Actor's location matches the camera focus point.\nNote: we're not using \"VisibleAnywhere\" meta tag here to hide component's properties in editor" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_CameraSpringArm = { "CameraSpringArm", nullptr, (EPropertyFlags)0x004000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, CameraSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_CameraSpringArm_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_CameraSpringArm_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_RenderCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CameraActor" },
		{ "Comment", "// The primary component in this actor, render camera\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayCapture.h" },
		{ "ToolTip", "The primary component in this actor, render camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_RenderCamera = { "RenderCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHoloPlayCapture, RenderCamera), Z_Construct_UClass_UHoloPlaySceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_RenderCamera_MetaData), Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_RenderCamera_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHoloPlayCapture_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_NearClipFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bUseFarClipPlane,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FarClipFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_FOV,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_OverrideQuiltTexture2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_bSingleViewMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingQuality_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingQuality,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_TilingValues,
#endif // WITH_EDITORONLY_DATA
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_CameraSpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHoloPlayCapture_Statics::NewProp_RenderCamera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHoloPlayCapture_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHoloPlayCapture>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHoloPlayCapture_Statics::ClassParams = {
		&AHoloPlayCapture::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AHoloPlayCapture_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::Class_MetaDataParams), Z_Construct_UClass_AHoloPlayCapture_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHoloPlayCapture_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AHoloPlayCapture()
	{
		if (!Z_Registration_Info_UClass_AHoloPlayCapture.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHoloPlayCapture.OuterSingleton, Z_Construct_UClass_AHoloPlayCapture_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHoloPlayCapture.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<AHoloPlayCapture>()
	{
		return AHoloPlayCapture::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHoloPlayCapture);
	AHoloPlayCapture::~AHoloPlayCapture() {}
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(AHoloPlayCapture)
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayCapture_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayCapture_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHoloPlayCapture, AHoloPlayCapture::StaticClass, TEXT("AHoloPlayCapture"), &Z_Registration_Info_UClass_AHoloPlayCapture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHoloPlayCapture), 120965450U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayCapture_h_4169906899(TEXT("/Script/HoloPlayRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayCapture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayCapture_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
