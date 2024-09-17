// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../../Source/HoloPlayRuntime/Public/Blueprints/HoloPlayLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoloPlayLibrary() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayLibrary();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlayLibrary_NoRegister();
	HOLOPLAYRUNTIME_API UClass* Z_Construct_UClass_UHoloPlaySettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HoloPlayRuntime();
// End Cross Module References
	DEFINE_FUNCTION(UHoloPlayLibrary::execGetHoloPlaySettings)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UHoloPlaySettings**)Z_Param__Result=UHoloPlayLibrary::GetHoloPlaySettings();
		P_NATIVE_END;
	}
	void UHoloPlayLibrary::StaticRegisterNativesUHoloPlayLibrary()
	{
		UClass* Class = UHoloPlayLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHoloPlaySettings", &UHoloPlayLibrary::execGetHoloPlaySettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics
	{
		struct HoloPlayLibrary_eventGetHoloPlaySettings_Parms
		{
			UHoloPlaySettings* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HoloPlayLibrary_eventGetHoloPlaySettings_Parms, ReturnValue), Z_Construct_UClass_UHoloPlaySettings_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "HoloPlay" },
		{ "Comment", "/**\n\x09 * @fn\x09static UHoloPlaySettings* UHoloPlayLibrary::GetHoloPlaySettings();\n\x09 *\n\x09 * @brief\x09Gets all HoloPlay runtime settings  \n\x09 *\n\x09 * @returns\x09Null if it fails, else the HoloPlay settings.\n\x09 */" },
		{ "DisplayName", "Get HoloPlay settings" },
		{ "ModuleRelativePath", "Public/Blueprints/HoloPlayLibrary.h" },
		{ "ToolTip", "@fn  static UHoloPlaySettings* UHoloPlayLibrary::GetHoloPlaySettings();\n\n@brief       Gets all HoloPlay runtime settings\n\n@returns     Null if it fails, else the HoloPlay settings." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHoloPlayLibrary, nullptr, "GetHoloPlaySettings", nullptr, nullptr, Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::HoloPlayLibrary_eventGetHoloPlaySettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::HoloPlayLibrary_eventGetHoloPlaySettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHoloPlayLibrary);
	UClass* Z_Construct_UClass_UHoloPlayLibrary_NoRegister()
	{
		return UHoloPlayLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UHoloPlayLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHoloPlayLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_HoloPlayRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UHoloPlayLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHoloPlayLibrary_GetHoloPlaySettings, "GetHoloPlaySettings" }, // 1716298110
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHoloPlayLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Blueprints/HoloPlayLibrary.h" },
		{ "ModuleRelativePath", "Public/Blueprints/HoloPlayLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHoloPlayLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHoloPlayLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHoloPlayLibrary_Statics::ClassParams = {
		&UHoloPlayLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHoloPlayLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UHoloPlayLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UHoloPlayLibrary()
	{
		if (!Z_Registration_Info_UClass_UHoloPlayLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHoloPlayLibrary.OuterSingleton, Z_Construct_UClass_UHoloPlayLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHoloPlayLibrary.OuterSingleton;
	}
	template<> HOLOPLAYRUNTIME_API UClass* StaticClass<UHoloPlayLibrary>()
	{
		return UHoloPlayLibrary::StaticClass();
	}
	UHoloPlayLibrary::UHoloPlayLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHoloPlayLibrary);
	UHoloPlayLibrary::~UHoloPlayLibrary() {}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Blueprints_HoloPlayLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Blueprints_HoloPlayLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHoloPlayLibrary, UHoloPlayLibrary::StaticClass, TEXT("UHoloPlayLibrary"), &Z_Registration_Info_UClass_UHoloPlayLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHoloPlayLibrary), 17091284U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Blueprints_HoloPlayLibrary_h_2510115546(TEXT("/Script/HoloPlayRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Blueprints_HoloPlayLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_HoloPlay_Source_HoloPlayRuntime_Public_Blueprints_HoloPlayLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
