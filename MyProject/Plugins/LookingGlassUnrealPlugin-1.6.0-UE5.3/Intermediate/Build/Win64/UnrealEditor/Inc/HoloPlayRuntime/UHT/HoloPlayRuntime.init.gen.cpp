// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoloPlayRuntime_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_HoloPlayRuntime;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_HoloPlayRuntime()
	{
		if (!Z_Registration_Info_UPackage__Script_HoloPlayRuntime.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/HoloPlayRuntime",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x4402CD7F,
				0x74720201,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_HoloPlayRuntime.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_HoloPlayRuntime.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_HoloPlayRuntime(Z_Construct_UPackage__Script_HoloPlayRuntime, TEXT("/Script/HoloPlayRuntime"), Z_Registration_Info_UPackage__Script_HoloPlayRuntime, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4402CD7F, 0x74720201));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
