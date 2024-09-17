#include "Managers/HoloPlayDisplayManager.h"

#include "HoloPlaySettings.h"

#include "Misc/HoloPlayLog.h"
#include "Game/HoloPlaySceneCaptureComponent2D.h"

#include "EngineUtils.h"
#include "Framework/Application/SlateApplication.h"
#include "Misc/FileHelper.h"
#include "Json.h"

#include "HoloPlayCore.h"
#include "IHoloPlayRuntime.h"

#if WITH_EDITOR
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Dialogs/Dialogs.h"
#endif

#define LOCTEXT_NAMESPACE "HoloPlay"

// Fully static class
struct FDisplayManagerHelper
{
	static TSharedPtr<FJsonObject> TryGetObjectField(FString& Descriptor, FString& FieldName)
	{
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Descriptor);
		if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
		{
			if (FieldName.Contains(TEXT(".")))
			{
				const TSharedPtr<FJsonObject>* JsonObjectPtr = &JsonObject;

				TArray<FString> FieldComponents;
				FieldName.ParseIntoArray(FieldComponents, TEXT("."));
				FieldName = FieldComponents.Pop();

				for (const FString& FieldComponent : FieldComponents)
				{
					if (!(*JsonObjectPtr)->TryGetObjectField(FieldComponent, JsonObjectPtr))
					{
						return nullptr;
					}
				}

				return *JsonObjectPtr;
			}
			else
			{
				return JsonObject;
			}
		}

		return nullptr;
	}

	static bool TryGetJsonField(FString Descriptor, FString FieldName, FString& Field)
	{
		TSharedPtr<FJsonObject> JsonObjectPtr = TryGetObjectField(Descriptor, FieldName);
		if (JsonObjectPtr.IsValid())
		{
			return JsonObjectPtr->TryGetStringField(FieldName, Field);
		}

		return false;
	}

	static bool TryGetJsonField(FString Descriptor, FString FieldName, double& Field)
	{
		TSharedPtr<FJsonObject> JsonObjectPtr = TryGetObjectField(Descriptor, FieldName);
		if (JsonObjectPtr.IsValid())
		{
			return JsonObjectPtr->TryGetNumberField(FieldName, Field);
		}

		return false;
	}

	static bool TryGetJsonField(FString Descriptor, FString FieldName, int32& Field)
	{
		TSharedPtr<FJsonObject> JsonObjectPtr = TryGetObjectField(Descriptor, FieldName);
		if (JsonObjectPtr.IsValid())
		{
			return JsonObjectPtr->TryGetNumberField(FieldName, Field);
		}

		return false;
	}

	static FString GetJson()
	{
		// Support display hot plug
		hpc_RefreshState();

		const int32 buffer_size = 4096;
		hpc_obj* hpc_objInst = hpc_MakeObject("{\"info\":{}}", 0, nullptr);
		
		hpc_obj* hpc_response;

		hpc_client_error hpc_result_code = hpc_SendBlocking(hpc_objInst, &hpc_response);

		if (hpc_result_code == hpc_CLIERR_NOERROR)
		{
			char buffer[buffer_size];
			size_t msg_size = hpc_GetStateAsJSON(buffer, buffer_size);
			// Return FString
			return FString(buffer);
		}
		else
		{
			// Print Log Messages and return empty string
			UE_LOG(LogTemp, Warning, TEXT("hpc_client_error %d"), (uint8) hpc_result_code);

			return "";
		}
	}

	static bool GetInfoMessage(bool& bIsServiceRunning)
	{
		// GetJson() is using blocking hpc_... function calls. If service is crashed or terminated, this function
		// will not return until the service is started again. "hpc_...MessagePipe" functions are not blocking, 
		// so we're using these to verify if it is safe to call other functions without hanging Unreal.
		hpc_TeardownMessagePipe();
		if (hpc_SetupMessagePipe() != 0)
		{
			bIsServiceRunning = false;
			UE_LOG(HoloPlayLogManagers, Error, TEXT("Unable to establish connection with HoloPlay service"));
			return false;
		}

		FString&& JsonText = GetJson();

		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonText);
		if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
		{
			UE_LOG(HoloPlayLogManagers, Error, TEXT("Parsing of Device information failed"));
			return false;
		}

		InfoMessage = JsonObject;
		if (!InfoMessage->TryGetNumberField("Error", HoloPlayCoreError) || HoloPlayCoreError != 0)
		{
			UE_LOG(HoloPlayLogManagers, Error, TEXT("HoloPlayCore Error: %d"), HoloPlayCoreError);
			return false;
		}
		if (!InfoMessage->TryGetStringField("Version", HoloPlayCoreVersion))
		{
			UE_LOG(HoloPlayLogManagers, Error, TEXT("HoloPlayCore Version Not Found"));
			return false;
		}
		if (!InfoMessage->TryGetArrayField("Devices", Devices))
		{
			UE_LOG(HoloPlayLogManagers, Error, TEXT("HoloPlayCore Devices Not Found"));
			return false;
		}

		// We won't get here only if service is not running, or if json data has malformed format
		bIsServiceRunning = true;
		return true;
	}

	static TSharedPtr<FJsonObject> GetDeviceForScreen(int ScreenIndex)
	{
		if (!Devices->IsValidIndex(ScreenIndex))
		{
			UE_LOG(HoloPlayLogManagers, Error, TEXT("Screen Index %d is not valid."), HoloPlayCoreError);
			return TSharedPtr<FJsonObject>();
		}
		TSharedPtr<FJsonValue> Device = (*Devices)[ScreenIndex];
		return Device->AsObject();
	}

	static TSharedPtr<FJsonObject> GetCalibrationForScreen(int ScreenIndex)
	{
		TSharedPtr<FJsonObject> Device = GetDeviceForScreen(ScreenIndex);
		if (Device.IsValid())
		{
			return Device->GetObjectField(TEXT("calibration"));
		}
		return TSharedPtr<FJsonObject>();
	}

	static TSharedPtr<FJsonValue> GetValueForField(int ScreenIndex, const FString& FieldName)
	{
		TSharedPtr<FJsonObject> Calibration = GetCalibrationForScreen(ScreenIndex);
		if (Calibration.IsValid())
		{
			TSharedPtr<FJsonObject> Field = Calibration->GetObjectField(FieldName);
			return Field->GetField<EJson::None>(TEXT("value"));
		}
		return TSharedPtr<FJsonValue>();
	}

	static int GetIntegerForField(int ScreenIndex, const FString& FieldName)
	{
		TSharedPtr<FJsonValue> Field = GetValueForField(ScreenIndex, FieldName);
		if (Field.IsValid())
		{
			return (int)Field->AsNumber();
		}
		return 0;

	}

	static float GetFloatForField(int ScreenIndex, const FString& FieldName)
	{
		TSharedPtr<FJsonValue> Field = GetValueForField(ScreenIndex, FieldName);
		if (Field.IsValid())
		{
			return (float)Field->AsNumber();
		}
		return 0;
	}

	static FString GetStringForField(int ScreenIndex, const FString& FieldName)
	{
		TSharedPtr<FJsonObject> Calibration = GetCalibrationForScreen(ScreenIndex);
		if (Calibration.IsValid())
		{
			return Calibration->GetStringField(FieldName);
		}
		return TEXT("");
	}

    static EHoloPlayDeviceType GetDeviceType( int ScreenIndex )
    {
		char Serial[128];
		hpc_GetDeviceSerial(ScreenIndex, Serial, UE_ARRAY_COUNT(Serial));

		if (FCStringAnsi::Stristr(Serial, "Looking Glass - Portrait") ||
			FCStringAnsi::Stristr(Serial, "PORT") ||
			FCStringAnsi::Stristr(Serial, "Portrait"))
		{
			return EHoloPlayDeviceType::Portrait;
		}

		if (FCStringAnsi::Stristr(Serial, "Looking Glass - 16\"") ||
			FCStringAnsi::Stristr(Serial, "LKG-A") ||
			FCStringAnsi::Stristr(Serial, "LKG-4K"))
		{
			return EHoloPlayDeviceType::_16in;
		}

		if (FCStringAnsi::Stristr(Serial, "Looking Glass - 32\"") ||
			FCStringAnsi::Stristr(Serial, "LKG-B") ||
			FCStringAnsi::Stristr(Serial, "LKG-8K"))
		{
			return EHoloPlayDeviceType::_32in;
		}

		if (FCStringAnsi::Stristr(Serial, "Looking Glass - 65\"") ||
			FCStringAnsi::Stristr(Serial, "LKG-D"))
		{
			return EHoloPlayDeviceType::_65in;
		}

		if (FCStringAnsi::Stristr(Serial, "Looking Glass - 8.9\"") ||
			FCStringAnsi::Stristr(Serial, "LKG-2K"))
		{
			return EHoloPlayDeviceType::_8_9inLegacy;
		}

		UE_LOG(HoloPlayLogManagers, Error, TEXT("Unknown LKG device by serial field! (serial = \"%s\")"), ANSI_TO_TCHAR(Serial));
		return EHoloPlayDeviceType::Portrait;
    }


	static int GetScreenWidth(int ScreenIndex)
	{
		return GetIntegerForField(ScreenIndex, "screenW");
	}

	static int GetScreenHeight(int ScreenIndex)
	{
		return GetIntegerForField(ScreenIndex, "screenH");
	}

	static float GetDPI(int ScreenIndex)
	{
		return GetFloatForField(ScreenIndex, "DPI");
	}

	static float GetViewCone(int ScreenIndex)
	{
		return GetFloatForField(ScreenIndex, "viewCone");
	}

	static float GetAspect(int ScreenIndex)
	{
		return GetFloatForField(ScreenIndex, "screenW") / GetFloatForField(ScreenIndex, "screenH");
	}

	static float GetPitch(int ScreenIndex)
	{
		return GetFloatForField(ScreenIndex, "pitch");
	}

	static float GetSlope(int ScreenIndex)
	{
		return GetFloatForField(ScreenIndex, "slope");
	}

	static float GetCenter(int ScreenIndex)
	{
		return GetFloatForField(ScreenIndex, "center");
	}

	static FString GetSerial(int ScreenIndex)
	{
		return  GetStringForField(ScreenIndex, "serial");
	}

	static FString GetLKGName(int ScreenIndex)
	{
		return  GetStringForField(ScreenIndex, "lkgName");
	}

	static int GetLKGcalIndex(int ScreenIndex)
	{
		//TODO: Is there only one calibration per device?
		return ScreenIndex;
	}

	static int GetLKGunityIndex(int ScreenIndex)
	{
		TSharedPtr<FJsonObject> Device = GetDeviceForScreen(ScreenIndex);
		if (Device.IsValid())
		{
			return Device->GetIntegerField(TEXT("index"));
		}
		return 0;
	}

	static int GetLKGxpos(int ScreenIndex)
	{
		TSharedPtr<FJsonObject> Device = GetDeviceForScreen(ScreenIndex);
		if (Device.IsValid())
		{
			TArray<TSharedPtr<FJsonValue>> WindowCoords = Device->GetArrayField("windowCoords");
			if (WindowCoords.Num() == 2)
			{
				return (int)WindowCoords[0]->AsNumber();
			}
			UE_LOG(HoloPlayLogManagers, Error, TEXT("Screen %d window coordinates not found or wrong size"), ScreenIndex);
		}
		return 0;
	}

	static int GetLKGypos(int ScreenIndex)
	{
		TSharedPtr<FJsonObject> Device = GetDeviceForScreen(ScreenIndex);
		if (Device.IsValid())
		{
			TArray<TSharedPtr<FJsonValue>> WindowCoords = Device->GetArrayField("windowCoords");
			if (WindowCoords.Num() == 2)
			{
				return (int)WindowCoords[1]->AsNumber();
			}
			UE_LOG(HoloPlayLogManagers, Error, TEXT("Screen %d window coordinates not found or wrong size"), ScreenIndex);
		}
		return 0;
	}

	static FString GetLKGdisplayName(int ScreenIndex)
	{
		TSharedPtr<FJsonObject> Device = GetDeviceForScreen(ScreenIndex);
		if (Device.IsValid())
		{
			return Device->GetStringField(TEXT("hwid"));
		}
		return TEXT("");
	}

	static int CalibrationCount()
	{
		return Devices->Num();
	}

	static int GetLKGcount()
	{
		return Devices->Num();
	}

	FDisplayManagerHelper() = delete;

private:
	static TSharedPtr<FJsonObject> InfoMessage;
	static const TArray<TSharedPtr<FJsonValue>>* Devices;
	static FString HoloPlayCoreVersion;
	static int32 HoloPlayCoreError;
};

TSharedPtr<FJsonObject> FDisplayManagerHelper::InfoMessage = TSharedPtr<FJsonObject>();
const TArray<TSharedPtr<FJsonValue>>* FDisplayManagerHelper::Devices = nullptr;
FString FDisplayManagerHelper::HoloPlayCoreVersion;
int32 FDisplayManagerHelper::HoloPlayCoreError;


void FHoloPlayDisplayMetrics::FCalibration::ReadForDevice(int32 i)
{
	DeviceType = FDisplayManagerHelper::GetDeviceType(i);
	ScreenWidth = FDisplayManagerHelper::GetScreenWidth(i);
	ScreenHeight = FDisplayManagerHelper::GetScreenHeight(i);
	DPI = FDisplayManagerHelper::GetDPI(i);
	ViewCone = FDisplayManagerHelper::GetViewCone(i);
	Aspect = FDisplayManagerHelper::GetAspect(i);
	Pitch = FDisplayManagerHelper::GetPitch(i);
	Slope = FDisplayManagerHelper::GetSlope(i);
	Center = FDisplayManagerHelper::GetCenter(i);

	float screenInches = ScreenWidth / DPI;
	float newPitch = Pitch * screenInches;
	//account for tilt in measuring pitch horizontally
	newPitch *= FMath::Cos(FMath::Atan(1.f / Slope));
	Pitch = newPitch;

	Slope = ScreenHeight / (ScreenWidth * Slope);

	Serial = FDisplayManagerHelper::GetSerial(i);
	LKGName = FDisplayManagerHelper::GetLKGName(i);
}


void FHoloPlayDisplayMetrics::FCalibration::MakeDefault()
{
	DeviceType = EHoloPlayDeviceType::Portrait;
    ScreenWidth = 1536;
    ScreenHeight = 2048;
    DPI = 324.0f;
    ViewCone = 40.0f;
    Aspect = 0.75f;
    Pitch = 246.860291f;
    Slope = -0.188230634f;
    Center = 0.542688072f;

    float screenInches = ScreenWidth / DPI;
    float newPitch = Pitch * screenInches;
    //account for tilt in measuring pitch horizontally
    newPitch *= FMath::Cos( FMath::Atan( 1.f / Slope ) );
    Pitch = newPitch;

    Slope = ScreenHeight / ( ScreenWidth * Slope );

    Serial = L"000";
    LKGName = "OfflinePortrait";
}


FHoloPlayDisplayMetrics::FDisplay::FDisplay(int i)
{
	LKGcalIndex = FDisplayManagerHelper::GetLKGcalIndex(i);
	LKGunityIndex = FDisplayManagerHelper::GetLKGunityIndex(i);
	LKGxpos = FDisplayManagerHelper::GetLKGxpos(i);
	LKGypos = FDisplayManagerHelper::GetLKGypos(i);

	LKGdisplayName = FDisplayManagerHelper::GetLKGdisplayName(i);
}

FHoloPlayDisplayManager::FHoloPlayDisplayManager()
	: bCoreInitialized(false)
	, bIsServiceRunning(false)
	, bInitialized(false)
{
}

FHoloPlayDisplayManager::~FHoloPlayDisplayManager()
{
}

bool FHoloPlayDisplayManager::Init()
{
	if (!FSlateApplication::IsInitialized())
	{
		return false;
	}

	// init a default calibration that will be used when there is no device connected
	DefaultCalibration.MakeDefault();

	// Get OS display settings
	auto PlatformApplication = FSlateApplication::Get().GetPlatformApplication();
	if (!PlatformApplication->OnDisplayMetricsChanged().IsBoundToObject(this))
	{
		PlatformApplication->OnDisplayMetricsChanged().AddRaw(this, &FHoloPlayDisplayManager::OnDisplayMetricsChanged);
	}
	PlatformApplication->GetInitialDisplayMetrics(DisplayMetrics);

	SetHoloPlayDisplaySettings();
	PrintDebugInfo();

	return true;
}

void FHoloPlayDisplayManager::Release()
{
	hpc_CloseApp();
}

bool FHoloPlayDisplayManager::OnStartPlayer(EHoloPlayModeType HoloPlayModeType)
{
	// Update HoloPlay Display Settings
	SetHoloPlayDisplaySettings();

	return true;
}

void FHoloPlayDisplayManager::OnStopPlayer()
{
}

bool FHoloPlayDisplayManager::SetHoloPlayDisplaySettings()
{
	const UHoloPlaySettings* HoloPlaySettings = GetDefault<UHoloPlaySettings>();
	int32 ScreenIndex = HoloPlaySettings->HoloPlayWindowSettings.ScreenIndex;

	// Connect with HoloPlay core if it is not done yet
	if (!InitializeHoloPlayCore())
	{
		// If we'll "return" here, we won't be able to see a quilt without a device. When continuing execution
		// here, we'll see a floating window with rendered picture on the main display.
	}

	FDisplayManagerHelper::GetInfoMessage(bIsServiceRunning);

	bool bShowWarningMessageBox = !bInitialized;
	bInitialized = true;

	// Initialize calibration with default values, in a case other setup will be failed
	Calibration = DefaultCalibration;

	if (bIsServiceRunning)
	{
		// Continue parsing only if calibration and display found
		HoloPlayDisplayMetrics.CalibrationCount = FDisplayManagerHelper::CalibrationCount();
		HoloPlayDisplayMetrics.LKGcount = FDisplayManagerHelper::GetLKGcount();

		// Get First all the time
		int32 TargetLookingGlass = -1;

		// Find device with specified ScreenIndex
		//todo: is there any point to do that in a loop, except printing other device's settings to log?
		for (int32 i = 0; i < HoloPlayDisplayMetrics.LKGcount; i++)
		{
			UE_LOG(HoloPlayLogManagers, Verbose, TEXT("ScreenIndex %d, GetLKGunityIndex(i) %d, GetLKGcalIndex(i) %d, i %d"), 
				ScreenIndex, FDisplayManagerHelper::GetLKGunityIndex(i), FDisplayManagerHelper::GetLKGcalIndex(i), i);

			if (ScreenIndex == i)
			{
				Calibration.ReadForDevice(FDisplayManagerHelper::GetLKGcalIndex(i));
				TargetLookingGlass = i;
			}
		}

#if WITH_EDITOR
		if (TargetLookingGlass < 0)
		{
            FText Title = LOCTEXT( "FailedToFindLKGDevice", "LLG Detection Failed" );
			if ( bShowWarningMessageBox )
			{
				FSuppressableWarningDialog::FSetupInfo Info(
					LOCTEXT( "FailedToFindDevice", "Failed to find a HoloPlay device, using Portrait settings as default." ),
					LOCTEXT("Warning", "Warning"),
					"Warning_HoloPlayDeviceNotFound");
				Info.ConfirmText = LOCTEXT( "OK", "OK");

				FSuppressableWarningDialog CompileErrors(Info);
				CompileErrors.ShowModal();
			}
			// Still show the notification, as the dialog could be suppressed
			FNotificationInfo Info( LOCTEXT( "Failed to find a HoloPlay device", "Failed to find a HoloPlay device" ) );
			TSharedPtr<SNotificationItem> NotificationItem = FSlateNotificationManager::Get().AddNotification( Info );
		}
#endif // WITH_EDITOR

		if (TargetLookingGlass >= 0)
		{
			Display = FHoloPlayDisplayMetrics::FDisplay( TargetLookingGlass );

			IHoloPlayRuntime& HoloPlayRuntime = IHoloPlayRuntime::Get();
			TArray<TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> >* ComponentArray = &HoloPlayRuntime.GameHoloPlayCaptureComponents;
#if WITH_EDITOR
			if (HoloPlayRuntime.EditorHoloPlayCaptureComponents.Num())
			{
				ComponentArray = &HoloPlayRuntime.EditorHoloPlayCaptureComponents;
			}
#endif

			// Update settings of all capture objects
			for (auto& It : *ComponentArray)
			{
				if (It.IsValid())
				{
					It->UpdateTilingProperties();
				}
			}
		}

		return true;
	}
	else
	{
		// Try to Load manually from the file on device's USB drive
		auto TryToLoad = [=](TCHAR Drive, FString& OutJsonCalibrationString) -> bool
		{
			OutJsonCalibrationString.Empty();

			FString SaveDirectory = FString::Printf(TEXT("%c:/LKG_calibration/visual.json"), Drive);
			if (FFileHelper::LoadFileToString(OutJsonCalibrationString, *SaveDirectory))
			{
				return true;
			}

			return false;
		};

		FString JsonCalibrationString;
		bool bIsHandled = false;
		FString Drives("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		for (int32 Index = 0; Index < Drives.Len(); ++Index)
		{
			if (TryToLoad(Drives[Index], JsonCalibrationString))
			{
				bIsHandled = true;
				break;
			}
		}

		if (bIsHandled)
		{
			double Pitch = 1;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "pitch.value", Pitch);
			double Slope = 1;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "slope.value", Slope);
			double Center = 1;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "center.value", Center);
			double ViewCone = 1;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "viewCone.value", ViewCone);
			double DPI = 1;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "DPI.value", DPI);
			double ScreenWidth = 1;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "screenW.value", ScreenWidth);
			double ScreenHeight = 1;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "screenH.value", ScreenHeight);
			int Model = 0;
			FDisplayManagerHelper::TryGetJsonField(JsonCalibrationString, "serial", Model);

			float screenInches = ScreenWidth / DPI;
			float newPitch = Pitch * screenInches;
			//account for tilt in measuring pitch horizontally
			newPitch *= FMath::Cos(FMath::Atan(1.f / Slope));

			// Apply Calibration
			Calibration.Pitch = newPitch;
			Calibration.Slope = ScreenHeight / (ScreenWidth * Slope);
			Calibration.Center = Center;
			Calibration.ViewCone = ViewCone;
			Calibration.DPI = DPI;
			Calibration.Aspect = ScreenWidth / ScreenHeight;
			Calibration.ScreenWidth = ScreenWidth;
			Calibration.ScreenHeight = ScreenHeight;
		}
	}

	return false;
}

void FHoloPlayDisplayManager::PrintDebugInfo()
{
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> DisplayMetrics --------------"));
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> HoloPlayDisplayMetrics --------------"));
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> CalibrationCount: %d"), HoloPlayDisplayMetrics.CalibrationCount);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> LKGcount: %d"), HoloPlayDisplayMetrics.LKGcount);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> ---------------------------------------------------- <<"));

	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> ScreenWidth: %d"), Calibration.ScreenWidth);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> ScreenHeight: %d"), Calibration.ScreenHeight);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> DPI: %f"), Calibration.DPI);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> ViewCone: %f"), Calibration.ViewCone);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> Aspect: %f"), Calibration.Aspect);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> Pitch: %f"), Calibration.Pitch);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> Slope: %f"), Calibration.Slope);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> Center: %f"), Calibration.Center);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> Serial: %s"), *Calibration.Serial);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> LKGName: %s"), *Calibration.LKGName);

	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> LKGcalIndex: %d"), Display.LKGcalIndex);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> LKGunityIndex: %d"), Display.LKGunityIndex);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> LKGxpos: %d"), Display.LKGxpos);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> LKGypos: %d"), Display.LKGypos);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> LKGdisplayName: %s"), *Display.LKGdisplayName);
	UE_LOG(HoloPlayLogManagers, Verbose, TEXT(">> ---------------------------------------------------- <<"));
}

void FHoloPlayDisplayManager::OnDisplayMetricsChanged(const FDisplayMetrics& InDisplayMetrics)
{
	// Ensure the following code will be executed in context of the main thread, and not in the message handler. Without
	// that, reconfiguring the display when device is connected or disconnected may cause assertions and/or crashes.
	AsyncTask(ENamedThreads::GameThread, [this, InDisplayMetrics]()
		{
			// Reload calibration only if amount of displays has been changed
			if (InDisplayMetrics.MonitorInfo.Num() != DisplayMetrics.MonitorInfo.Num())
			{
				SetHoloPlayDisplaySettings();
				PrintDebugInfo();
			}

			DisplayMetrics = InDisplayMetrics;
		});
}

bool FHoloPlayDisplayManager::InitializeHoloPlayCore()
{
	if (!bCoreInitialized)
	{
		//TODO: Should app name be pushed out to user?
#if WITH_EDITOR
		FString AppName = TEXT("UnrealEditor_");
#else
		FString AppName = TEXT("UnrealRuntime_");
#endif
		AppName += FApp::GetProjectName();
		hpc_client_error result = hpc_InitializeApp(TCHAR_TO_ANSI(*AppName), hpc_LICENSE_NONCOMMERCIAL);
		if (result != hpc_CLIERR_NOERROR)
		{
			UE_LOG(HoloPlayLogManagers, Error, TEXT("HoloPlay Core Initialization failed.  Error: %d"), result);
			return false;
		}

		bCoreInitialized = true;
	}
	return true;
}
