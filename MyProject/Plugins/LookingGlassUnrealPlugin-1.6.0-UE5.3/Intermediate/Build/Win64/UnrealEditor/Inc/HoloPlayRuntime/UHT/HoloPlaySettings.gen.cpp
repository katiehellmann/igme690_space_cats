// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/HoloPlayRuntime/Public/HoloPlaySettings.h"
#include "InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoloPlaySettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayLaunchSettings();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayLaunchSettings_NoRegister();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlaySettings();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlaySettings_NoRegister();
	HOLOPLAYRUNTIME_API UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType();
	HOLOPLAYRUNTIME_API UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode();
	HOLOPLAYRUNTIME_API UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement();
	HOLOPLAYRUNTIME_API UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayEditorSettings();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayRenderingSettings();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayTilingQuality();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayWindowLocation();
	HOLOPLAYRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayWindowSettings();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	UPackage* Z_Construct_UPackage__Script_HoloPlayRuntime();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHoloPlayModeType;
	static UEnum* EHoloPlayModeType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayModeType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EHoloPlayModeType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("EHoloPlayModeType"));
		}
		return Z_Registration_Info_UEnum_EHoloPlayModeType.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UEnum* StaticEnum<EHoloPlayModeType>()
	{
		return EHoloPlayModeType_StaticEnum();
	}
	struct Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::Enumerators[] = {
		{ "EHoloPlayModeType::PlayMode_InSeparateWindow", (int64)EHoloPlayModeType::PlayMode_InSeparateWindow },
		{ "EHoloPlayModeType::PlayMode_InMainViewport", (int64)EHoloPlayModeType::PlayMode_InMainViewport },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * @enum\x09""EHoloPlayModeType\n *\n * @brief\x09Values that represent HoloPlay mode types\n */" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "PlayMode_InMainViewport.DisplayName", "In Main Viewport" },
		{ "PlayMode_InMainViewport.Name", "EHoloPlayModeType::PlayMode_InMainViewport" },
		{ "PlayMode_InSeparateWindow.DisplayName", "In Separate Window" },
		{ "PlayMode_InSeparateWindow.Name", "EHoloPlayModeType::PlayMode_InSeparateWindow" },
		{ "ScriptName", "HoloPlayPlayMode" },
		{ "ToolTip", "@enum       EHoloPlayModeType\n\n@brief      Values that represent HoloPlay mode types" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		"EHoloPlayModeType",
		"EHoloPlayModeType",
		Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayModeType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHoloPlayModeType.InnerSingleton, Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EHoloPlayModeType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHoloPlayQualitySettings;
	static UEnum* EHoloPlayQualitySettings_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayQualitySettings.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EHoloPlayQualitySettings.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("EHoloPlayQualitySettings"));
		}
		return Z_Registration_Info_UEnum_EHoloPlayQualitySettings.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UEnum* StaticEnum<EHoloPlayQualitySettings>()
	{
		return EHoloPlayQualitySettings_StaticEnum();
	}
	struct Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::Enumerators[] = {
		{ "EHoloPlayQualitySettings::Q_Automatic", (int64)EHoloPlayQualitySettings::Q_Automatic },
		{ "EHoloPlayQualitySettings::Q_Portrait", (int64)EHoloPlayQualitySettings::Q_Portrait },
		{ "EHoloPlayQualitySettings::Q_FourK", (int64)EHoloPlayQualitySettings::Q_FourK },
		{ "EHoloPlayQualitySettings::Q_EightK", (int64)EHoloPlayQualitySettings::Q_EightK },
		{ "EHoloPlayQualitySettings::Q_65_Inch", (int64)EHoloPlayQualitySettings::Q_65_Inch },
		{ "EHoloPlayQualitySettings::Q_EightPointNineLegacy", (int64)EHoloPlayQualitySettings::Q_EightPointNineLegacy },
		{ "EHoloPlayQualitySettings::Q_Custom", (int64)EHoloPlayQualitySettings::Q_Custom },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * @enum\x09""EHoloPlayQualitySettings\n *\n * @brief\x09Values that represent HoloPlay quality settings\n */" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "Q_65_Inch.DisplayName", "65 inch" },
		{ "Q_65_Inch.Name", "EHoloPlayQualitySettings::Q_65_Inch" },
		{ "Q_Automatic.DisplayName", "Automatic" },
		{ "Q_Automatic.Name", "EHoloPlayQualitySettings::Q_Automatic" },
		{ "Q_Custom.DisplayName", "Custom" },
		{ "Q_Custom.Name", "EHoloPlayQualitySettings::Q_Custom" },
		{ "Q_EightK.DisplayName", "32 inch (8K)" },
		{ "Q_EightK.Name", "EHoloPlayQualitySettings::Q_EightK" },
		{ "Q_EightPointNineLegacy.DisplayName", "8.9 inch (Legacy)" },
		{ "Q_EightPointNineLegacy.Name", "EHoloPlayQualitySettings::Q_EightPointNineLegacy" },
		{ "Q_FourK.DisplayName", "16 inch (4K)" },
		{ "Q_FourK.Name", "EHoloPlayQualitySettings::Q_FourK" },
		{ "Q_Portrait.DisplayName", "Portrait" },
		{ "Q_Portrait.Name", "EHoloPlayQualitySettings::Q_Portrait" },
		{ "ScriptName", "HoloPlayQualitySettings" },
		{ "ToolTip", "@enum       EHoloPlayQualitySettings\n\n@brief      Values that represent HoloPlay quality settings" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		"EHoloPlayQualitySettings",
		"EHoloPlayQualitySettings",
		Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayQualitySettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHoloPlayQualitySettings.InnerSingleton, Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayQualitySettings_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EHoloPlayQualitySettings.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality;
class UScriptStruct* FHoloPlayTilingQuality::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHoloPlayTilingQuality, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("HoloPlayTilingQuality"));
	}
	return Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality.OuterSingleton;
}
template<> HOLOPLAYRUNTIME_API UScriptStruct* StaticStruct<FHoloPlayTilingQuality>()
{
	return FHoloPlayTilingQuality::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TilesX_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TilesX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TilesY_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TilesY;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_QuiltW_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_QuiltW;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_QuiltH_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_QuiltH;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Aspect_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Aspect;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bTilingEditable_MetaData[];
#endif
		static void NewProp_bTilingEditable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bTilingEditable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * @struct\x09""FHoloPlayTilingQuality\n *\n * @brief\x09""A HoloPlay tiling quality.\n */" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "@struct     FHoloPlayTilingQuality\n\n@brief      A HoloPlay tiling quality." },
	};
#endif
	void* Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHoloPlayTilingQuality>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesX_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "ClampMax", "16" },
		{ "ClampMin", "1" },
		{ "EditCondition", "bTilingEditable" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "UIMax", "16" },
		{ "UIMin", "1" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesX = { "TilesX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayTilingQuality, TilesX), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesX_MetaData), Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesX_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesY_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "ClampMax", "160" },
		{ "ClampMin", "1" },
		{ "EditCondition", "bTilingEditable" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "UIMax", "16" },
		{ "UIMin", "1" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesY = { "TilesY", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayTilingQuality, TilesY), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesY_MetaData), Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesY_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltW_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "ClampMax", "8192" },
		{ "ClampMin", "512" },
		{ "EditCondition", "bTilingEditable" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "UIMax", "8192" },
		{ "UIMin", "512" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltW = { "QuiltW", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayTilingQuality, QuiltW), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltW_MetaData), Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltW_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltH_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "ClampMax", "8192" },
		{ "ClampMin", "512" },
		{ "EditCondition", "bTilingEditable" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "UIMax", "8192" },
		{ "UIMin", "512" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltH = { "QuiltH", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayTilingQuality, QuiltH), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltH_MetaData), Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltH_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_Aspect_MetaData[] = {
		{ "Category", "TilingSettings" },
		{ "Comment", "// Aspect ratio of the camera. Value 0 has special meaning - the aspect will be taken from the device\n" },
		{ "EditCondition", "bTilingEditable" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Aspect ratio of the camera. Value 0 has special meaning - the aspect will be taken from the device" },
		{ "UIMax", "20" },
		{ "UIMin", "0.05" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_Aspect = { "Aspect", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayTilingQuality, Aspect), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_Aspect_MetaData), Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_Aspect_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_bTilingEditable_MetaData[] = {
		{ "Comment", "// Hidden property used to enable/disable editing of other properties\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Hidden property used to enable/disable editing of other properties" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_bTilingEditable_SetBit(void* Obj)
	{
		((FHoloPlayTilingQuality*)Obj)->bTilingEditable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_bTilingEditable = { "bTilingEditable", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayTilingQuality), &Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_bTilingEditable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_bTilingEditable_MetaData), Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_bTilingEditable_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_TilesY,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltW,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_QuiltH,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_Aspect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewProp_bTilingEditable,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		&NewStructOps,
		"HoloPlayTilingQuality",
		Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::PropPointers),
		sizeof(FHoloPlayTilingQuality),
		alignof(FHoloPlayTilingQuality),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayTilingQuality()
	{
		if (!Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality.InnerSingleton, Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHoloPlayPlacement;
	static UEnum* EHoloPlayPlacement_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayPlacement.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EHoloPlayPlacement.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("EHoloPlayPlacement"));
		}
		return Z_Registration_Info_UEnum_EHoloPlayPlacement.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UEnum* StaticEnum<EHoloPlayPlacement>()
	{
		return EHoloPlayPlacement_StaticEnum();
	}
	struct Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::Enumerators[] = {
		{ "EHoloPlayPlacement::Automatic", (int64)EHoloPlayPlacement::Automatic },
		{ "EHoloPlayPlacement::CustomWindow", (int64)EHoloPlayPlacement::CustomWindow },
		{ "EHoloPlayPlacement::AlwaysDebugWindow", (int64)EHoloPlayPlacement::AlwaysDebugWindow },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::Enum_MetaDataParams[] = {
		{ "AlwaysDebugWindow.DisplayName", "Always render in popup window" },
		{ "AlwaysDebugWindow.Name", "EHoloPlayPlacement::AlwaysDebugWindow" },
		{ "Automatic.DisplayName", "Automatically place on device" },
		{ "Automatic.Name", "EHoloPlayPlacement::Automatic" },
		{ "BlueprintType", "true" },
		{ "CustomWindow.DisplayName", "Specify display location" },
		{ "CustomWindow.Name", "EHoloPlayPlacement::CustomWindow" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ScriptName", "HoloPlayPlacement" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		"EHoloPlayPlacement",
		"EHoloPlayPlacement",
		Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayPlacement.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHoloPlayPlacement.InnerSingleton, Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EHoloPlayPlacement.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation;
class UScriptStruct* FHoloPlayWindowLocation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHoloPlayWindowLocation, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("HoloPlayWindowLocation"));
	}
	return Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation.OuterSingleton;
}
template<> HOLOPLAYRUNTIME_API UScriptStruct* StaticStruct<FHoloPlayWindowLocation>()
{
	return FHoloPlayWindowLocation::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ClientSize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ClientSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHoloPlayWindowLocation>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ClientSize_MetaData[] = {
		{ "Category", "Window" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ClientSize = { "ClientSize", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayWindowLocation, ClientSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ClientSize_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ClientSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "Category", "Window" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayWindowLocation, ScreenPosition), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ScreenPosition_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ScreenPosition_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ClientSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewProp_ScreenPosition,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		&NewStructOps,
		"HoloPlayWindowLocation",
		Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::PropPointers),
		sizeof(FHoloPlayWindowLocation),
		alignof(FHoloPlayWindowLocation),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayWindowLocation()
	{
		if (!Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation.InnerSingleton, Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings;
class UScriptStruct* FHoloPlayWindowSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHoloPlayWindowSettings, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("HoloPlayWindowSettings"));
	}
	return Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings.OuterSingleton;
}
template<> HOLOPLAYRUNTIME_API UScriptStruct* StaticStruct<FHoloPlayWindowSettings>()
{
	return FHoloPlayWindowSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_PlacementMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlacementMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_PlacementMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ScreenIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomWindowLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CustomWindowLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DebugWindowLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DebugWindowLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bToptmostDebugWindow_MetaData[];
#endif
		static void NewProp_bToptmostDebugWindow_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bToptmostDebugWindow;
		static const UECodeGen_Private::FBytePropertyParams NewProp_LastExecutedPlayModeType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LastExecutedPlayModeType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_LastExecutedPlayModeType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLockInMainViewport_MetaData[];
#endif
		static void NewProp_bLockInMainViewport_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLockInMainViewport;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * @struct\x09""FHoloPlayWindowSettings\n *\n * @brief\x09""A HoloPlay window settings.\n */" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "@struct     FHoloPlayWindowSettings\n\n@brief      A HoloPlay window settings." },
	};
#endif
	void* Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHoloPlayWindowSettings>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_PlacementMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_PlacementMode_MetaData[] = {
		{ "Category", "HoloPlay|Window" },
		{ "Comment", "// Where to place rendering window\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Where to place rendering window" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_PlacementMode = { "PlacementMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayWindowSettings, PlacementMode), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPlacement, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_PlacementMode_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_PlacementMode_MetaData) }; // 4153234612
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_ScreenIndex_MetaData[] = {
		{ "Category", "HoloPlay|Window" },
		{ "Comment", "// Index of HoloPlay device where we'll render\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Index of HoloPlay device where we'll render" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_ScreenIndex = { "ScreenIndex", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayWindowSettings, ScreenIndex), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_ScreenIndex_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_ScreenIndex_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_CustomWindowLocation_MetaData[] = {
		{ "Category", "HoloPlay|Window" },
		{ "Comment", "// Location of device, use when automatic detection fails\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Location of device, use when automatic detection fails" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_CustomWindowLocation = { "CustomWindowLocation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayWindowSettings, CustomWindowLocation), Z_Construct_UScriptStruct_FHoloPlayWindowLocation, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_CustomWindowLocation_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_CustomWindowLocation_MetaData) }; // 455513470
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_DebugWindowLocation_MetaData[] = {
		{ "Category", "HoloPlay|Window" },
		{ "Comment", "// Size and location of the debug window, which is used when device is not present\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Size and location of the debug window, which is used when device is not present" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_DebugWindowLocation = { "DebugWindowLocation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayWindowSettings, DebugWindowLocation), Z_Construct_UScriptStruct_FHoloPlayWindowLocation, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_DebugWindowLocation_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_DebugWindowLocation_MetaData) }; // 455513470
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bToptmostDebugWindow_MetaData[] = {
		{ "Category", "HoloPlay|Window" },
		{ "Comment", "// Create topmost debug window\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Create topmost debug window" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bToptmostDebugWindow_SetBit(void* Obj)
	{
		((FHoloPlayWindowSettings*)Obj)->bToptmostDebugWindow = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bToptmostDebugWindow = { "bToptmostDebugWindow", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayWindowSettings), &Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bToptmostDebugWindow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bToptmostDebugWindow_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bToptmostDebugWindow_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_LastExecutedPlayModeType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_LastExecutedPlayModeType_MetaData[] = {
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_LastExecutedPlayModeType = { "LastExecutedPlayModeType", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayWindowSettings, LastExecutedPlayModeType), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayModeType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_LastExecutedPlayModeType_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_LastExecutedPlayModeType_MetaData) }; // 323938412
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bLockInMainViewport_MetaData[] = {
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bLockInMainViewport_SetBit(void* Obj)
	{
		((FHoloPlayWindowSettings*)Obj)->bLockInMainViewport = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bLockInMainViewport = { "bLockInMainViewport", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayWindowSettings), &Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bLockInMainViewport_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bLockInMainViewport_MetaData), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bLockInMainViewport_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_PlacementMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_PlacementMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_ScreenIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_CustomWindowLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_DebugWindowLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bToptmostDebugWindow,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_LastExecutedPlayModeType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_LastExecutedPlayModeType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewProp_bLockInMainViewport,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		&NewStructOps,
		"HoloPlayWindowSettings",
		Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::PropPointers),
		sizeof(FHoloPlayWindowSettings),
		alignof(FHoloPlayWindowSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayWindowSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings.InnerSingleton, Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings;
class UScriptStruct* FHoloPlayScreenshotSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("HoloPlayScreenshotSettings"));
	}
	return Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings.OuterSingleton;
}
template<> HOLOPLAYRUNTIME_API UScriptStruct* StaticStruct<FHoloPlayScreenshotSettings>()
{
	return FHoloPlayScreenshotSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UseJPG_MetaData[];
#endif
		static void NewProp_UseJPG_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_UseJPG;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JpegQuality_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_JpegQuality;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputKey_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InputKey;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Resolution_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Resolution;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bResolutionVisible_MetaData[];
#endif
		static void NewProp_bResolutionVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bResolutionVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * @struct\x09""FHoloPlayScreenshotSettings\n *\n * @brief\x09""A HoloPlay screenshot settings.\n */" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "@struct     FHoloPlayScreenshotSettings\n\n@brief      A HoloPlay screenshot settings." },
	};
#endif
	void* Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHoloPlayScreenshotSettings>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_FileName_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "Comment", "// Prefix of the generated screenshot file name\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Prefix of the generated screenshot file name" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayScreenshotSettings, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_FileName_MetaData), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_FileName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_UseJPG_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "Comment", "// When true, screen shots will be saved as jpg files\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "When true, screen shots will be saved as jpg files" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_UseJPG_SetBit(void* Obj)
	{
		((FHoloPlayScreenshotSettings*)Obj)->UseJPG = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_UseJPG = { "UseJPG", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayScreenshotSettings), &Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_UseJPG_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_UseJPG_MetaData), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_UseJPG_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_JpegQuality_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "Comment", "// Quality of JPG screenshot\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Quality of JPG screenshot" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_JpegQuality = { "JpegQuality", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayScreenshotSettings, JpegQuality), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_JpegQuality_MetaData), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_JpegQuality_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_InputKey_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "Comment", "// Hotkey used to activate this screenshot\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Hotkey used to activate this screenshot" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_InputKey = { "InputKey", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayScreenshotSettings, InputKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_InputKey_MetaData), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_InputKey_MetaData) }; // 46000949
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_Resolution_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "ClampMax", "10000" },
		{ "ClampMin", "0" },
		{ "Comment", "// Resolution of the generated image file\n" },
		{ "EditCondition", "bResolutionVisible" },
		{ "EditConditionHides", "" },
		{ "HideEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Resolution of the generated image file" },
		{ "UIMax", "10000" },
		{ "UIMin", "0" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_Resolution = { "Resolution", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayScreenshotSettings, Resolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_Resolution_MetaData), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_Resolution_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_bResolutionVisible_MetaData[] = {
		{ "Comment", "// Hidden property used to control visibility of \"Resolution\" property\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Hidden property used to control visibility of \"Resolution\" property" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_bResolutionVisible_SetBit(void* Obj)
	{
		((FHoloPlayScreenshotSettings*)Obj)->bResolutionVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_bResolutionVisible = { "bResolutionVisible", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayScreenshotSettings), &Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_bResolutionVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_bResolutionVisible_MetaData), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_bResolutionVisible_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_FileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_UseJPG,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_JpegQuality,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_InputKey,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_Resolution,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewProp_bResolutionVisible,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		&NewStructOps,
		"HoloPlayScreenshotSettings",
		Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::PropPointers),
		sizeof(FHoloPlayScreenshotSettings),
		alignof(FHoloPlayScreenshotSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings.InnerSingleton, Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings;
class UScriptStruct* FHoloPlayRenderingSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHoloPlayRenderingSettings, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("HoloPlayRenderingSettings"));
	}
	return Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings.OuterSingleton;
}
template<> HOLOPLAYRUNTIME_API UScriptStruct* StaticStruct<FHoloPlayRenderingSettings>()
{
	return FHoloPlayRenderingSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bVsync_MetaData[];
#endif
		static void NewProp_bVsync_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVsync;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_QuiltMode_MetaData[];
#endif
		static void NewProp_QuiltMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_QuiltMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRender2D_MetaData[];
#endif
		static void NewProp_bRender2D_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRender2D;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * @struct\x09""FHoloPlayRenderingSettings\n *\n * @brief\x09""A HoloPlay rendering settings.\n * \x09\x09\x09""Contains options for disable some part of rendering and manage rendering pipeline\n */" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "@struct     FHoloPlayRenderingSettings\n\n@brief      A HoloPlay rendering settings.\n                    Contains options for disable some part of rendering and manage rendering pipeline" },
	};
#endif
	void* Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHoloPlayRenderingSettings>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bVsync_MetaData[] = {
		{ "Category", "HoloPlay|Rendering" },
		{ "Comment", "// This property controls r.vsync engine's cvar\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "This property controls r.vsync engine's cvar" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bVsync_SetBit(void* Obj)
	{
		((FHoloPlayRenderingSettings*)Obj)->bVsync = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bVsync = { "bVsync", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayRenderingSettings), &Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bVsync_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bVsync_MetaData), Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bVsync_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_QuiltMode_MetaData[] = {
		{ "Category", "HoloPlay|Rendering" },
		{ "Comment", "// Render quilt instead of hologram\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Render quilt instead of hologram" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_QuiltMode_SetBit(void* Obj)
	{
		((FHoloPlayRenderingSettings*)Obj)->QuiltMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_QuiltMode = { "QuiltMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayRenderingSettings), &Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_QuiltMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_QuiltMode_MetaData), Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_QuiltMode_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bRender2D_MetaData[] = {
		{ "Category", "HoloPlay|Rendering" },
		{ "Comment", "// Render regular \"2D\" image instead of hologram\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Render regular \"2D\" image instead of hologram" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bRender2D_SetBit(void* Obj)
	{
		((FHoloPlayRenderingSettings*)Obj)->bRender2D = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bRender2D = { "bRender2D", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayRenderingSettings), &Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bRender2D_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bRender2D_MetaData), Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bRender2D_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bVsync,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_QuiltMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewProp_bRender2D,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		&NewStructOps,
		"HoloPlayRenderingSettings",
		Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::PropPointers),
		sizeof(FHoloPlayRenderingSettings),
		alignof(FHoloPlayRenderingSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayRenderingSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings.InnerSingleton, Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHoloPlayPerformanceMode;
	static UEnum* EHoloPlayPerformanceMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayPerformanceMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EHoloPlayPerformanceMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("EHoloPlayPerformanceMode"));
		}
		return Z_Registration_Info_UEnum_EHoloPlayPerformanceMode.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UEnum* StaticEnum<EHoloPlayPerformanceMode>()
	{
		return EHoloPlayPerformanceMode_StaticEnum();
	}
	struct Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::Enumerators[] = {
		{ "EHoloPlayPerformanceMode::Realtime", (int64)EHoloPlayPerformanceMode::Realtime },
		{ "EHoloPlayPerformanceMode::RealtimeAdaptive", (int64)EHoloPlayPerformanceMode::RealtimeAdaptive },
		{ "EHoloPlayPerformanceMode::NonRealtime", (int64)EHoloPlayPerformanceMode::NonRealtime },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "NonRealtime.Comment", "// Render only when scene changed\n" },
		{ "NonRealtime.Name", "EHoloPlayPerformanceMode::NonRealtime" },
		{ "NonRealtime.ToolTip", "Render only when scene changed" },
		{ "Realtime.Comment", "// Realtime hologram\n" },
		{ "Realtime.Name", "EHoloPlayPerformanceMode::Realtime" },
		{ "Realtime.ToolTip", "Realtime hologram" },
		{ "RealtimeAdaptive.Comment", "// Realtime mode with switching to 2D when user is interacting in editor\n" },
		{ "RealtimeAdaptive.Name", "EHoloPlayPerformanceMode::RealtimeAdaptive" },
		{ "RealtimeAdaptive.ToolTip", "Realtime mode with switching to 2D when user is interacting in editor" },
		{ "ScriptName", "HoloPlayPerformanceMode" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		"EHoloPlayPerformanceMode",
		"EHoloPlayPerformanceMode",
		Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode()
	{
		if (!Z_Registration_Info_UEnum_EHoloPlayPerformanceMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHoloPlayPerformanceMode.InnerSingleton, Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EHoloPlayPerformanceMode.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings;
class UScriptStruct* FHoloPlayEditorSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHoloPlayEditorSettings, (UObject*)Z_Construct_UPackage__Script_HoloPlayRuntime(), TEXT("HoloPlayEditorSettings"));
	}
	return Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings.OuterSingleton;
}
template<> HOLOPLAYRUNTIME_API UScriptStruct* StaticStruct<FHoloPlayEditorSettings>()
{
	return FHoloPlayEditorSettings::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_PerformanceMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PerformanceMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_PerformanceMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NonRealtimeUpdateDelay_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NonRealtimeUpdateDelay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebugBlocksRequests_MetaData[];
#endif
		static void NewProp_bDebugBlocksRequests_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugBlocksRequests;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * @struct\x09""FHoloPlayRenderingSettings\n *\n * @brief\x09""A HoloPlay rendering settings.\n * \x09\x09\x09""Contains options for disable some part of rendering and manage rendering pipeline\n */" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "@struct     FHoloPlayRenderingSettings\n\n@brief      A HoloPlay rendering settings.\n                    Contains options for disable some part of rendering and manage rendering pipeline" },
	};
#endif
	void* Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHoloPlayEditorSettings>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_PerformanceMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_PerformanceMode_MetaData[] = {
		{ "Category", "HoloPlay|Editor Settings" },
		{ "Comment", "// Adaptive performance behavior in editor\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Adaptive performance behavior in editor" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_PerformanceMode = { "PerformanceMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayEditorSettings, PerformanceMode), Z_Construct_UEnum_HoloPlayRuntime_EHoloPlayPerformanceMode, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_PerformanceMode_MetaData), Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_PerformanceMode_MetaData) }; // 1977722606
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_NonRealtimeUpdateDelay_MetaData[] = {
		{ "Category", "HoloPlay|Editor Settings" },
		{ "Comment", "// Delay in seconds, after which hologram will be updated in Non-Relatime mode when scene edited\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Delay in seconds, after which hologram will be updated in Non-Relatime mode when scene edited" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_NonRealtimeUpdateDelay = { "NonRealtimeUpdateDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHoloPlayEditorSettings, NonRealtimeUpdateDelay), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_NonRealtimeUpdateDelay_MetaData), Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_NonRealtimeUpdateDelay_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_bDebugBlocksRequests_MetaData[] = {
		{ "Category", "HoloPlay|Editor Settings" },
		{ "Comment", "// Log all http requests made by Blocks code\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Log all http requests made by Blocks code" },
	};
#endif
	void Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_bDebugBlocksRequests_SetBit(void* Obj)
	{
		((FHoloPlayEditorSettings*)Obj)->bDebugBlocksRequests = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_bDebugBlocksRequests = { "bDebugBlocksRequests", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHoloPlayEditorSettings), &Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_bDebugBlocksRequests_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_bDebugBlocksRequests_MetaData), Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_bDebugBlocksRequests_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_PerformanceMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_PerformanceMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_NonRealtimeUpdateDelay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewProp_bDebugBlocksRequests,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
		nullptr,
		&NewStructOps,
		"HoloPlayEditorSettings",
		Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::PropPointers),
		sizeof(FHoloPlayEditorSettings),
		alignof(FHoloPlayEditorSettings),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FHoloPlayEditorSettings()
	{
		if (!Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings.InnerSingleton, Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings.InnerSingleton;
	}
	void UHoloPlaySettings::StaticRegisterNativesUHoloPlaySettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlaySettings);
	UClass* Z_Construct_UClass_UHoloPlaySettings_NoRegister()
	{
		return UHoloPlaySettings::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlaySettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoloPlayWindowSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HoloPlayWindowSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoloPlayEditorSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HoloPlayEditorSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoloPlayLenticularScreenshotSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HoloPlayLenticularScreenshotSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoloPlayScreenshotQuiltSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HoloPlayScreenshotQuiltSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoloPlayScreenshot2DSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HoloPlayScreenshot2DSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutomaticSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AutomaticSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PortraitSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PortraitSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp__16In_Settings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp__16In_Settings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp__32In_Settings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp__32In_Settings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp__65In_Settings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp__65In_Settings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp__8_9inLegacy_Settings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp__8_9inLegacy_Settings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CustomSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoloPlayRenderingSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_HoloPlayRenderingSettings;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlaySettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * @class\x09UHoloPlaySettings\n *\n * @brief\x09""All HoloPlay plugin settings\n */" },
		{ "IncludePath", "HoloPlaySettings.h" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "@class      UHoloPlaySettings\n\n@brief      All HoloPlay plugin settings" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayWindowSettings_MetaData[] = {
		{ "Category", "HoloPlay" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayWindowSettings = { "HoloPlayWindowSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, HoloPlayWindowSettings), Z_Construct_UScriptStruct_FHoloPlayWindowSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayWindowSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayWindowSettings_MetaData) }; // 1695287641
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayEditorSettings_MetaData[] = {
		{ "Category", "HoloPlay|Editor Settings" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayEditorSettings = { "HoloPlayEditorSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, HoloPlayEditorSettings), Z_Construct_UScriptStruct_FHoloPlayEditorSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayEditorSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayEditorSettings_MetaData) }; // 2335848689
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayLenticularScreenshotSettings_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "DisplayName", "Lenticular Screenshot" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayLenticularScreenshotSettings = { "HoloPlayLenticularScreenshotSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, HoloPlayLenticularScreenshotSettings), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayLenticularScreenshotSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayLenticularScreenshotSettings_MetaData) }; // 1581807122
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshotQuiltSettings_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "DisplayName", "Quilt Screenshot" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshotQuiltSettings = { "HoloPlayScreenshotQuiltSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, HoloPlayScreenshotQuiltSettings), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshotQuiltSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshotQuiltSettings_MetaData) }; // 1581807122
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshot2DSettings_MetaData[] = {
		{ "Category", "HoloPlay|Screenshot Settings" },
		{ "DisplayName", "2D Screenshot" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshot2DSettings = { "HoloPlayScreenshot2DSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, HoloPlayScreenshot2DSettings), Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshot2DSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshot2DSettings_MetaData) }; // 1581807122
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_AutomaticSettings_MetaData[] = {
		{ "Category", "HoloPlay|Tiling Settings" },
		{ "DisplayName", "Automatic" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_AutomaticSettings = { "AutomaticSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, AutomaticSettings), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_AutomaticSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_AutomaticSettings_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_PortraitSettings_MetaData[] = {
		{ "Category", "HoloPlay|Tiling Settings" },
		{ "Comment", "// Aspect is unknown\n" },
		{ "DisplayName", "LookingGlass - Portrait" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Aspect is unknown" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_PortraitSettings = { "PortraitSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, PortraitSettings), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_PortraitSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_PortraitSettings_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__16In_Settings_MetaData[] = {
		{ "Category", "HoloPlay|Tiling Settings" },
		{ "Comment", "// Aspect 0.75\n" },
		{ "DisplayName", "LookingGlass - 16\" (4K)" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Aspect 0.75" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__16In_Settings = { "_16In_Settings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, _16In_Settings), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__16In_Settings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__16In_Settings_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__32In_Settings_MetaData[] = {
		{ "Category", "HoloPlay|Tiling Settings" },
		{ "Comment", "// Aspect 1.77777\n" },
		{ "DisplayName", "LookingGlass - 32\" (8K)" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Aspect 1.77777" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__32In_Settings = { "_32In_Settings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, _32In_Settings), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__32In_Settings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__32In_Settings_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__65In_Settings_MetaData[] = {
		{ "Category", "HoloPlay|Tiling Settings" },
		{ "Comment", "// Aspect 1.77777\n" },
		{ "DisplayName", "LookingGlass - 65" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Aspect 1.77777" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__65In_Settings = { "_65In_Settings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, _65In_Settings), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__65In_Settings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__65In_Settings_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__8_9inLegacy_Settings_MetaData[] = {
		{ "Category", "HoloPlay|Tiling Settings" },
		{ "Comment", "// Aspect 1.77777\n" },
		{ "DisplayName", "LookingGlass - 8.9\" (Legacy)" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Aspect 1.77777" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__8_9inLegacy_Settings = { "_8_9inLegacy_Settings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, _8_9inLegacy_Settings), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__8_9inLegacy_Settings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__8_9inLegacy_Settings_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_CustomSettings_MetaData[] = {
		{ "Category", "HoloPlay|Tiling Settings" },
		{ "Comment", "// Aspect 1.6\n" },
		{ "DisplayName", "Custom" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ToolTip", "Aspect 1.6" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_CustomSettings = { "CustomSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, CustomSettings), Z_Construct_UScriptStruct_FHoloPlayTilingQuality, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_CustomSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_CustomSettings_MetaData) }; // 2767888229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayRenderingSettings_MetaData[] = {
		{ "Category", "HoloPlay" },
		{ "Comment", "// Aspect is custom\n" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
		{ "ShowOnlyInnerProperties", "" },
		{ "ToolTip", "Aspect is custom" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayRenderingSettings = { "HoloPlayRenderingSettings", nullptr, (EPropertyFlags)0x0010000000044015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlaySettings, HoloPlayRenderingSettings), Z_Construct_UScriptStruct_FHoloPlayRenderingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayRenderingSettings_MetaData), Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayRenderingSettings_MetaData) }; // 399620593
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoloPlaySettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayWindowSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayEditorSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayLenticularScreenshotSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshotQuiltSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayScreenshot2DSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_AutomaticSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_PortraitSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__16In_Settings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__32In_Settings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__65In_Settings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp__8_9inLegacy_Settings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_CustomSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlaySettings_Statics::NewProp_HoloPlayRenderingSettings,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlaySettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlaySettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlaySettings_Statics::ClassParams = {
		&UHoloPlaySettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UHoloPlaySettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlaySettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlaySettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHoloPlaySettings()
	{
		if (!Z_Registration_Info_UClass_UHoloPlaySettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlaySettings.OuterSingleton, Z_Construct_UClass_UHoloPlaySettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlaySettings.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlaySettings>()
	{
		return UHoloPlaySettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlaySettings);
	UHoloPlaySettings::~UHoloPlaySettings() {}
	void UHoloPlayLaunchSettings::StaticRegisterNativesUHoloPlayLaunchSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlayLaunchSettings);
	UClass* Z_Construct_UClass_UHoloPlayLaunchSettings_NoRegister()
	{
		return UHoloPlayLaunchSettings::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlayLaunchSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LaunchCounter_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LaunchCounter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HoloPlaySettings.h" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::NewProp_LaunchCounter_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/HoloPlaySettings.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::NewProp_LaunchCounter = { "LaunchCounter", nullptr, (EPropertyFlags)0x0010000000064015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHoloPlayLaunchSettings, LaunchCounter), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::NewProp_LaunchCounter_MetaData), Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::NewProp_LaunchCounter_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::NewProp_LaunchCounter,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlayLaunchSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::ClassParams = {
		&UHoloPlayLaunchSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UHoloPlayLaunchSettings()
	{
		if (!Z_Registration_Info_UClass_UHoloPlayLaunchSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlayLaunchSettings.OuterSingleton, Z_Construct_UClass_UHoloPlayLaunchSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlayLaunchSettings.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlayLaunchSettings>()
	{
		return UHoloPlayLaunchSettings::StaticClass();
	}
	UHoloPlayLaunchSettings::UHoloPlayLaunchSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlayLaunchSettings);
	UHoloPlayLaunchSettings::~UHoloPlayLaunchSettings() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::EnumInfo[] = {
		{ EHoloPlayModeType_StaticEnum, TEXT("EHoloPlayModeType"), &Z_Registration_Info_UEnum_EHoloPlayModeType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 323938412U) },
		{ EHoloPlayQualitySettings_StaticEnum, TEXT("EHoloPlayQualitySettings"), &Z_Registration_Info_UEnum_EHoloPlayQualitySettings, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1613864522U) },
		{ EHoloPlayPlacement_StaticEnum, TEXT("EHoloPlayPlacement"), &Z_Registration_Info_UEnum_EHoloPlayPlacement, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4153234612U) },
		{ EHoloPlayPerformanceMode_StaticEnum, TEXT("EHoloPlayPerformanceMode"), &Z_Registration_Info_UEnum_EHoloPlayPerformanceMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1977722606U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::ScriptStructInfo[] = {
		{ FHoloPlayTilingQuality::StaticStruct, Z_Construct_UScriptStruct_FHoloPlayTilingQuality_Statics::NewStructOps, TEXT("HoloPlayTilingQuality"), &Z_Registration_Info_UScriptStruct_HoloPlayTilingQuality, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHoloPlayTilingQuality), 2767888229U) },
		{ FHoloPlayWindowLocation::StaticStruct, Z_Construct_UScriptStruct_FHoloPlayWindowLocation_Statics::NewStructOps, TEXT("HoloPlayWindowLocation"), &Z_Registration_Info_UScriptStruct_HoloPlayWindowLocation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHoloPlayWindowLocation), 455513470U) },
		{ FHoloPlayWindowSettings::StaticStruct, Z_Construct_UScriptStruct_FHoloPlayWindowSettings_Statics::NewStructOps, TEXT("HoloPlayWindowSettings"), &Z_Registration_Info_UScriptStruct_HoloPlayWindowSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHoloPlayWindowSettings), 1695287641U) },
		{ FHoloPlayScreenshotSettings::StaticStruct, Z_Construct_UScriptStruct_FHoloPlayScreenshotSettings_Statics::NewStructOps, TEXT("HoloPlayScreenshotSettings"), &Z_Registration_Info_UScriptStruct_HoloPlayScreenshotSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHoloPlayScreenshotSettings), 1581807122U) },
		{ FHoloPlayRenderingSettings::StaticStruct, Z_Construct_UScriptStruct_FHoloPlayRenderingSettings_Statics::NewStructOps, TEXT("HoloPlayRenderingSettings"), &Z_Registration_Info_UScriptStruct_HoloPlayRenderingSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHoloPlayRenderingSettings), 399620593U) },
		{ FHoloPlayEditorSettings::StaticStruct, Z_Construct_UScriptStruct_FHoloPlayEditorSettings_Statics::NewStructOps, TEXT("HoloPlayEditorSettings"), &Z_Registration_Info_UScriptStruct_HoloPlayEditorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHoloPlayEditorSettings), 2335848689U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHoloPlaySettings, UHoloPlaySettings::StaticClass, TEXT("UHoloPlaySettings"), &Z_Registration_Info_UClass_UHoloPlaySettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlaySettings), 1559760972U) },
		{ Z_Construct_UClass_UHoloPlayLaunchSettings, UHoloPlayLaunchSettings::StaticClass, TEXT("UHoloPlayLaunchSettings"), &Z_Registration_Info_UClass_UHoloPlayLaunchSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlayLaunchSettings), 1882590828U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_1382770788(TEXT("/Script/HoloPlayRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_HoloPlaySettings_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
