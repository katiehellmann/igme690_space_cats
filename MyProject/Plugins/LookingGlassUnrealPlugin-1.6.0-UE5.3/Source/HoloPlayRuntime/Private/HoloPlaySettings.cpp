#include "HoloPlaySettings.h"
#include "IHoloPlayRuntime.h"
#include "Misc/HoloPlayLog.h"

#include "Engine/Engine.h"

#include "Runtime/Launch/Resources/Version.h"

void FHoloPlayRenderingSettings::UpdateVsync() const
{
	if (GEngine)
	{
		static const auto CVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.VSync"));
		bool CVarbVsync = CVar->GetValueOnGameThread() != 0;
		if (CVarbVsync == bVsync)
		{
			return;
		}

		if (bVsync)
		{
			new(GEngine->DeferredCommands) FString(TEXT("r.vsync 1"));
		}
		else
		{
			new(GEngine->DeferredCommands) FString(TEXT("r.vsync 0"));
		}
	}
}

FHoloPlayTilingQuality UHoloPlaySettings::GetTilingQualityFor(EHoloPlayQualitySettings TilingSettings) const
{
	FHoloPlayTilingQuality TilingValues;

	switch (TilingSettings)
	{
	case EHoloPlayQualitySettings::Q_Portrait:
		TilingValues = PortraitSettings;
		break;
	case EHoloPlayQualitySettings::Q_FourK:
		TilingValues = _16In_Settings;
		break;
	case EHoloPlayQualitySettings::Q_EightK:
		TilingValues = _32In_Settings;
		break;
	case EHoloPlayQualitySettings::Q_65_Inch:
		TilingValues = _65In_Settings;
		break;
	case EHoloPlayQualitySettings::Q_EightPointNineLegacy:
		TilingValues = _8_9inLegacy_Settings;
		break;
	case EHoloPlayQualitySettings::Q_Custom:
		TilingValues = CustomSettings;
		break;
	}

	// Finalize setup of TilingValues
	TilingValues.Setup();

	return TilingValues;
}

#if WITH_EDITOR
void UHoloPlaySettings::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property != nullptr)
	{
		FName PropertyName(PropertyChangedEvent.Property->GetFName());
		FName MemberPropertyName = (PropertyChangedEvent.MemberProperty != NULL) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;

		if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UHoloPlaySettings, CustomSettings))
		{
			// Changed custom values, recompute other fields
			CustomSettings.Setup();
		}
	}
}
#endif // WITH_EDITOR

void UHoloPlaySettings::HoloPlaySave()
{
	HoloPlayRenderingSettings.UpdateVsync();

#if WITH_EDITOR
	#if ENGINE_MAJOR_VERSION >= 5
	this->TryUpdateDefaultConfigFile();
	#else
	this->UpdateDefaultConfigFile();
#endif
#else
	this->SaveConfig();
#endif
}
