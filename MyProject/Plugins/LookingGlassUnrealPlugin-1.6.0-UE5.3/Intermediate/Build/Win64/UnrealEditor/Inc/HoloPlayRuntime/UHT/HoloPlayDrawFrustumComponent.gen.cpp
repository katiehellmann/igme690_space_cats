// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/HoloPlayRuntime/Public/Game/HoloPlayDrawFrustumComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoloPlayDrawFrustumComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayDrawFrustumComponent();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayDrawFrustumComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HoloPlayRuntime();
// End Cross Module References
	void UHoloPlayDrawFrustumComponent::StaticRegisterNativesUHoloPlayDrawFrustumComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlayDrawFrustumComponent);
	UClass* Z_Construct_UClass_UHoloPlayDrawFrustumComponent_NoRegister()
	{
		return UHoloPlayDrawFrustumComponent::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumMidDist_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrustumMidDist;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FrustumColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumLineThickness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrustumLineThickness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MidFrustumColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MidFrustumColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MidPlaneLineLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MidPlaneLineLength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MidLineThickness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MidLineThickness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrustumAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumAspectRatio_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrustumAspectRatio;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumStartDist_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrustumStartDist;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrustumEndDist_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrustumEndDist;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VerticalAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalAngle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimitiveComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * @class\x09UHoloPlayDrawFrustumComponent\n *\n * @brief\x09Utility component for drawing a view frustum. Origin is at the component location,\n * \x09\x09\x09""frustum points down position X axis.\n */" },
		{ "HideCategories", "Mobility VirtualTexture Trigger" },
		{ "IncludePath", "Game/HoloPlayDrawFrustumComponent.h" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "@class      UHoloPlayDrawFrustumComponent\n\n@brief      Utility component for drawing a view frustum. Origin is at the component location,\n                    frustum points down position X axis." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumMidDist_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Distance to HoloPlay Draw Plane. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Distance to HoloPlay Draw Plane." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumMidDist = { "FrustumMidDist", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, FrustumMidDist), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumMidDist_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumMidDist_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumColor_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Color to draw the wireframe frustum. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Color to draw the wireframe frustum." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumColor = { "FrustumColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, FrustumColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumColor_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumLineThickness_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Line Thickness for Frustum. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Line Thickness for Frustum." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumLineThickness = { "FrustumLineThickness", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, FrustumLineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumLineThickness_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumLineThickness_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidFrustumColor_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Color to draw the HoloPlayPlane. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Color to draw the HoloPlayPlane." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidFrustumColor = { "MidFrustumColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, MidFrustumColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidFrustumColor_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidFrustumColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidPlaneLineLength_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Line Length for Mid Plane. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Line Length for Mid Plane." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidPlaneLineLength = { "MidPlaneLineLength", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, MidPlaneLineLength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidPlaneLineLength_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidPlaneLineLength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidLineThickness_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Line Thickness for Mid Plane. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Line Thickness for Mid Plane." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidLineThickness = { "MidLineThickness", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, MidLineThickness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidLineThickness_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidLineThickness_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAngle_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Angle of longest dimension of view shape.\n\x09  * If the angle is 0 then an orthographic projection is used */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Angle of longest dimension of view shape.\nIf the angle is 0 then an orthographic projection is used" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAngle = { "FrustumAngle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, FrustumAngle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAngle_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAngle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAspectRatio_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Ratio of horizontal size over vertical size. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Ratio of horizontal size over vertical size." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAspectRatio = { "FrustumAspectRatio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, FrustumAspectRatio), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAspectRatio_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAspectRatio_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumStartDist_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Distance from origin to start drawing the frustum. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Distance from origin to start drawing the frustum." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumStartDist = { "FrustumStartDist", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, FrustumStartDist), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumStartDist_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumStartDist_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumEndDist_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Distance from origin to stop drawing the frustum. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Distance from origin to stop drawing the frustum." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumEndDist = { "FrustumEndDist", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, FrustumEndDist), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumEndDist_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumEndDist_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_VerticalAngle_MetaData[] = {
		{ "Category", "DrawFrustumComponent" },
		{ "Comment", "/** Vertical Angle for Vertical Offset. */" },
		{ "ModuleRelativePath", "Public/Game/HoloPlayDrawFrustumComponent.h" },
		{ "ToolTip", "Vertical Angle for Vertical Offset." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_VerticalAngle = { "VerticalAngle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayDrawFrustumComponent, VerticalAngle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_VerticalAngle_MetaData), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_VerticalAngle_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumMidDist,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumLineThickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidFrustumColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidPlaneLineLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_MidLineThickness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumAspectRatio,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumStartDist,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_FrustumEndDist,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::NewProp_VerticalAngle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlayDrawFrustumComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::ClassParams = {
		&UHoloPlayDrawFrustumComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::PropPointers),
		0,
		0x00A000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHoloPlayDrawFrustumComponent()
	{
		if (!Z_Registration_Info_UClass_UHoloPlayDrawFrustumComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlayDrawFrustumComponent.OuterSingleton, Z_Construct_UClass_UHoloPlayDrawFrustumComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlayDrawFrustumComponent.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlayDrawFrustumComponent>()
	{
		return UHoloPlayDrawFrustumComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlayDrawFrustumComponent);
	UHoloPlayDrawFrustumComponent::~UHoloPlayDrawFrustumComponent() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayDrawFrustumComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayDrawFrustumComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHoloPlayDrawFrustumComponent, UHoloPlayDrawFrustumComponent::StaticClass, TEXT("UHoloPlayDrawFrustumComponent"), &Z_Registration_Info_UClass_UHoloPlayDrawFrustumComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlayDrawFrustumComponent), 2735494498U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayDrawFrustumComponent_h_1442626851(TEXT("/Script/HoloPlayRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayDrawFrustumComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Game_HoloPlayDrawFrustumComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
