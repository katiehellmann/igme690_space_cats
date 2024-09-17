#pragma once

#include "Managers/IHoloPlayManager.h"

#include "CoreMinimal.h"
#include "GenericPlatform/GenericApplication.h"

enum class EHoloPlayDeviceType
{
	Portrait = 0,
	_16in = 1,
	_32in = 2,
	_65in = 3,
	_8_9inLegacy = 4
};

/**
 * @struct	FHoloPlayDisplayMetrics
 *
 * @brief	A HoloPlay display metrics.
 */

struct FHoloPlayDisplayMetrics
{
	/**
	 * @struct	FDisplay
	 *
	 * @brief	A display calibration parameters
	 */

	struct FCalibration
	{
		EHoloPlayDeviceType  DeviceType = EHoloPlayDeviceType::Portrait;
		int32 ScreenWidth = 0;
		int32 ScreenHeight = 0;
		float DPI = 0.f;
		float ViewCone = 0.f;
		float Aspect = 0.f;
		float Pitch = 0.f;
		float Slope = 0.f;
		float Center = 0.f;
		FString Serial;
		FString LKGName;

		void ReadForDevice(int32 i);

		void MakeDefault();
	};

	/**
	 * @struct	FDisplay
	 *
	 * @brief	HoloPlay display information
	 */

	struct FDisplay
	{
		int32 LKGcalIndex = 0;
		int32 LKGunityIndex = 0;
		int32 LKGxpos = 0;
		int32 LKGypos = 0;
		FString LKGdisplayName;

		FDisplay(){}
		FDisplay(int i);
	};

	int32 CalibrationCount = 0;
	int32 LKGcount = 0;
};

/**
 * @class	FHoloPlayDisplayManager
 *
 * @brief	Manager for HoloPlay displays.
 */

class FHoloPlayDisplayManager : public IHoloPlayManager
{
public:
	FHoloPlayDisplayManager();
	virtual ~FHoloPlayDisplayManager();

	/** IHoloPlayManager Interface */

	/**
	 * @fn	virtual bool FHoloPlayDisplayManager::Init()
	 *
	 * @brief	Initializes this Manager class
	 *
	 * @returns	True if it Initializes successful , false if it fails.
	 */

	virtual bool Init() override;

	/**
	 * @fn	virtual void FHoloPlayDisplayManager::Release() override;
	 *
	 * @brief	Releases Manager and all resources
	 */

	virtual void Release() override;

	/**
	 * @fn	virtual bool FHoloPlayDisplayManager::OnStartPlayer(EHoloPlayModeType HoloPlayModeType) override;
	 *
	 * @brief	Executes the start player action
	 *
	 * @param	HoloPlayModeType	Type of the HoloPlay mode.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	virtual bool OnStartPlayer(EHoloPlayModeType HoloPlayModeType) override;

	/**
	 * @fn	virtual void FHoloPlayDisplayManager::OnStopPlayer() override;
	 *
	 * @brief	Executes the stop player action
	 */

	virtual void OnStopPlayer() override;

	/**
	 * @fn	void FHoloPlayDisplayManager::PrintDebugInfo();
	 *
	 * @brief	Print all calibration variable to console
	 */

	void PrintDebugInfo();

	/**
	 * @fn	const FHoloPlayDisplayMetrics& FHoloPlayDisplayManager::GetHoloPlayDisplayMetrics()
	 *
	 * @brief	Gets HoloPlay display metrics
	 *
	 * @returns	The HoloPlay display metrics.
	 */

	const FHoloPlayDisplayMetrics& GetHoloPlayDisplayMetrics() { return HoloPlayDisplayMetrics; }

	/**
	 * @fn	const FHoloPlayDisplayMetrics::FCalibration& FHoloPlayDisplayManager::GetCalibrationSettings()
	 *
	 * @brief	Gets calibration settings
	 *
	 * @returns	The calibration settings.
	 */
	const FHoloPlayDisplayMetrics::FCalibration& GetCalibrationSettings() { return Calibration; }

	FHoloPlayDisplayMetrics::FCalibration& GetCalibrationSettingsMutable() { return Calibration; }

	const FDisplayMetrics& GetDisplayMetrics() { return DisplayMetrics; }

	/**
	 * @fn	const FHoloPlayDisplayMetrics::FDisplay& FHoloPlayDisplayManager::GetDisplaySettings()
	 *
	 * @brief	Gets display settings
	 *
	 * @returns	The display settings.
	 */

	const FHoloPlayDisplayMetrics::FDisplay& GetDisplaySettings() { return Display; }


private:

	/**
	 * @fn	bool FHoloPlayDisplayManager::SetHoloPlayDisplaySettings();
	 *
	 * @brief	Set the HoloPlay display settings
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool SetHoloPlayDisplaySettings();

	/**
	 * @fn	void FHoloPlayDisplayManager::OnDisplayMetricsChanged(const FDisplayMetrics& DisplayMetrics);
	 *
	 * @brief	Executes the display metrics changed action
	 *
	 * @param	DisplayMetrics	The display metrics.
	 */

	void OnDisplayMetricsChanged(const FDisplayMetrics& DisplayMetrics);

	bool InitializeHoloPlayCore();

private:
	FDisplayMetrics DisplayMetrics;
	FHoloPlayDisplayMetrics HoloPlayDisplayMetrics;

	FHoloPlayDisplayMetrics::FCalibration Calibration;
	FHoloPlayDisplayMetrics::FDisplay Display;

	FHoloPlayDisplayMetrics::FCalibration DefaultCalibration;

	// Set to true when hpc_InitializeApp() was successful. Could be 'false' is HoloPlay service is not running.
	bool bCoreInitialized;
	// Just informational variable indicating if service is running or not.
	bool bIsServiceRunning;
	// Set to 'true' when HoloPlay display settings were acquired at least once.
	bool bInitialized;
};