// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/HoloPlayRuntime/Public/Sequencer/HoloPlayProtocol.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoloPlayProtocol() {}
// Cross Module References
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayProtocol();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayProtocol_AVI();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayProtocol_AVI_NoRegister();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayProtocol_NoRegister();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayProtocol_PNG();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayProtocol_PNG_NoRegister();
	HOLOPLAYRUNTIME_API UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings();
	MOVIESCENECAPTURE_API UClass* Z_Construct_UClass_UMovieSceneImageCaptureProtocolBase();
	UPackage* Z_Construct_UPackage__Script_HoloPlayRuntime();
// End Cross Module References
	void UHoloPlayProtocol::StaticRegisterNativesUHoloPlayProtocol()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlayProtocol);
	UClass* Z_Construct_UClass_UHoloPlayProtocol_NoRegister()
	{
		return UHoloPlayProtocol::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlayProtocol_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_TilingSettings_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TilingSettings_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TilingSettings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlayProtocol_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMovieSceneImageCaptureProtocolBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayProtocol_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// Reference: UFrameGrabberProtocol. Base class for capture protocol for sequencer.\n" },
		{ "IncludePath", "Sequencer/HoloPlayProtocol.h" },
		{ "ModuleRelativePath", "Public/Sequencer/HoloPlayProtocol.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Reference: UFrameGrabberProtocol. Base class for capture protocol for sequencer." },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UHoloPlayProtocol_Statics::NewProp_TilingSettings_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayProtocol_Statics::NewProp_TilingSettings_MetaData[] = {
		{ "Category", "LookingGlass" },
		{ "Comment", "// Resolution and tiling settings of the generated image/video sequence\n" },
		{ "ModuleRelativePath", "Public/Sequencer/HoloPlayProtocol.h" },
		{ "ToolTip", "Resolution and tiling settings of the generated image/video sequence" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UHoloPlayProtocol_Statics::NewProp_TilingSettings = { "TilingSettings", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayProtocol, TilingSettings), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_Statics::NewProp_TilingSettings_MetaData), Z_Construct_UClass_UHoloPlayProtocol_Statics::NewProp_TilingSettings_MetaData) }; // 1613864522
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoloPlayProtocol_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayProtocol_Statics::NewProp_TilingSettings_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayProtocol_Statics::NewProp_TilingSettings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlayProtocol_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlayProtocol>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlayProtocol_Statics::ClassParams = {
		&UHoloPlayProtocol::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UHoloPlayProtocol_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_Statics::PropPointers),
		0,
		0x000004A5u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlayProtocol_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHoloPlayProtocol()
	{
		if (!Z_Registration_Info_UClass_UHoloPlayProtocol.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlayProtocol.OuterSingleton, Z_Construct_UClass_UHoloPlayProtocol_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlayProtocol.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlayProtocol>()
	{
		return UHoloPlayProtocol::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlayProtocol);
	UHoloPlayProtocol::~UHoloPlayProtocol() {}
	void UHoloPlayProtocol_PNG::StaticRegisterNativesUHoloPlayProtocol_PNG()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlayProtocol_PNG);
	UClass* Z_Construct_UClass_UHoloPlayProtocol_PNG_NoRegister()
	{
		return UHoloPlayProtocol_PNG::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompressionQuality_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CompressionQuality;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UHoloPlayProtocol,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// Reference: UImageSequenceProtocol + UCompressedImageSequenceProtocol\n" },
		{ "DisplayName", "LookingGlass Image Sequence (png)" },
		{ "IncludePath", "Sequencer/HoloPlayProtocol.h" },
		{ "ModuleRelativePath", "Public/Sequencer/HoloPlayProtocol.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Reference: UImageSequenceProtocol + UCompressedImageSequenceProtocol" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::NewProp_CompressionQuality_MetaData[] = {
		{ "Category", "ImageSettings" },
		{ "ClampMax", "100" },
		{ "ClampMin", "1" },
		{ "Comment", "/** Level of compression to apply to the image, between 1 (worst quality, best compression) and 100 (best quality, worst compression)*/" },
		{ "ModuleRelativePath", "Public/Sequencer/HoloPlayProtocol.h" },
		{ "ToolTip", "Level of compression to apply to the image, between 1 (worst quality, best compression) and 100 (best quality, worst compression)" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::NewProp_CompressionQuality = { "CompressionQuality", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayProtocol_PNG, CompressionQuality), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::NewProp_CompressionQuality_MetaData), Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::NewProp_CompressionQuality_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::NewProp_CompressionQuality,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlayProtocol_PNG>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::ClassParams = {
		&UHoloPlayProtocol_PNG::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::PropPointers),
		0,
		0x000004A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHoloPlayProtocol_PNG()
	{
		if (!Z_Registration_Info_UClass_UHoloPlayProtocol_PNG.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlayProtocol_PNG.OuterSingleton, Z_Construct_UClass_UHoloPlayProtocol_PNG_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlayProtocol_PNG.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlayProtocol_PNG>()
	{
		return UHoloPlayProtocol_PNG::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlayProtocol_PNG);
	UHoloPlayProtocol_PNG::~UHoloPlayProtocol_PNG() {}
	void UHoloPlayProtocol_AVI::StaticRegisterNativesUHoloPlayProtocol_AVI()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlayProtocol_AVI);
	UClass* Z_Construct_UClass_UHoloPlayProtocol_AVI_NoRegister()
	{
		return UHoloPlayProtocol_AVI::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseCompression_MetaData[];
#endif
		static void NewProp_bUseCompression_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCompression;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompressionQuality_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CompressionQuality;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UHoloPlayProtocol,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// Reference: UVideoCaptureProtocol\n" },
		{ "DisplayName", "LookingGlass Video Sequence (avi)" },
		{ "IncludePath", "Sequencer/HoloPlayProtocol.h" },
		{ "ModuleRelativePath", "Public/Sequencer/HoloPlayProtocol.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Reference: UVideoCaptureProtocol" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_bUseCompression_MetaData[] = {
		{ "Category", "VideoSettings" },
		{ "Comment", "/** ~End UHoloPlayProtocol implementation */" },
		{ "ModuleRelativePath", "Public/Sequencer/HoloPlayProtocol.h" },
		{ "ToolTip", "~End UHoloPlayProtocol implementation" },
	};
#endif
	void Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_bUseCompression_SetBit(void* Obj)
	{
		((UHoloPlayProtocol_AVI*)Obj)->bUseCompression = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_bUseCompression = { "bUseCompression", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UHoloPlayProtocol_AVI), &Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_bUseCompression_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_bUseCompression_MetaData), Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_bUseCompression_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_CompressionQuality_MetaData[] = {
		{ "Category", "VideoSettings" },
		{ "ClampMax", "100" },
		{ "ClampMin", "1" },
		{ "EditCondition", "bUseCompression" },
		{ "ModuleRelativePath", "Public/Sequencer/HoloPlayProtocol.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_CompressionQuality = { "CompressionQuality", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayProtocol_AVI, CompressionQuality), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_CompressionQuality_MetaData), Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_CompressionQuality_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_bUseCompression,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::NewProp_CompressionQuality,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlayProtocol_AVI>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::ClassParams = {
		&UHoloPlayProtocol_AVI::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::PropPointers),
		0,
		0x000004A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHoloPlayProtocol_AVI()
	{
		if (!Z_Registration_Info_UClass_UHoloPlayProtocol_AVI.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlayProtocol_AVI.OuterSingleton, Z_Construct_UClass_UHoloPlayProtocol_AVI_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlayProtocol_AVI.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlayProtocol_AVI>()
	{
		return UHoloPlayProtocol_AVI::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlayProtocol_AVI);
	UHoloPlayProtocol_AVI::~UHoloPlayProtocol_AVI() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Sequencer_HoloPlayProtocol_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Sequencer_HoloPlayProtocol_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHoloPlayProtocol, UHoloPlayProtocol::StaticClass, TEXT("UHoloPlayProtocol"), &Z_Registration_Info_UClass_UHoloPlayProtocol, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlayProtocol), 3685479883U) },
		{ Z_Construct_UClass_UHoloPlayProtocol_PNG, UHoloPlayProtocol_PNG::StaticClass, TEXT("UHoloPlayProtocol_PNG"), &Z_Registration_Info_UClass_UHoloPlayProtocol_PNG, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlayProtocol_PNG), 3915169197U) },
		{ Z_Construct_UClass_UHoloPlayProtocol_AVI, UHoloPlayProtocol_AVI::StaticClass, TEXT("UHoloPlayProtocol_AVI"), &Z_Registration_Info_UClass_UHoloPlayProtocol_AVI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlayProtocol_AVI), 856727669U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Sequencer_HoloPlayProtocol_h_2126584662(TEXT("/Script/HoloPlayRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Sequencer_HoloPlayProtocol_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Sequencer_HoloPlayProtocol_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
