 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"

#include "HoloPlaySettings.generated.h"


/**
 * @enum	EHoloPlayModeType
 *
 * @brief	Values that represent HoloPlay mode types
 */

UENUM(BlueprintType, meta = (ScriptName = "HoloPlayPlayMode"))
enum class EHoloPlayModeType : uint8
{
	PlayMode_InSeparateWindow	UMETA(DisplayName = "In Separate Window"),
	PlayMode_InMainViewport		UMETA(DisplayName = "In Main Viewport")
};


// Tiling Quality Settings Enum (For UI)

/**
 * @enum	EHoloPlayQualitySettings
 *
 * @brief	Values that represent HoloPlay quality settings
 */

UENUM(BlueprintType, meta = (ScriptName = "HoloPlayQualitySettings"))
enum class EHoloPlayQualitySettings : uint8
{
	Q_Automatic 			UMETA(DisplayName = "Automatic"),
	Q_Portrait 				UMETA(DisplayName = "Portrait"),
	Q_FourK 				UMETA(DisplayName = "16 inch (4K)"),
	Q_EightK 				UMETA(DisplayName = "32 inch (8K)"),
	Q_65_Inch				UMETA(DisplayName = "65 inch"),
	Q_EightPointNineLegacy 	UMETA(DisplayName = "8.9 inch (Legacy)"),
	Q_Custom				UMETA(DisplayName = "Custom")
};


// Tiling Quality Settings Structure

/**
 * @struct	FHoloPlayTilingQuality
 *
 * @brief	A HoloPlay tiling quality.
 */

USTRUCT(BlueprintType)
struct FHoloPlayTilingQuality
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "TilingSettings", meta = (HideEditConditionToggle, EditCondition = "bTilingEditable", ClampMin = "1", ClampMax = "16", UIMin = "1", UIMax = "16"))
	int32 TilesX = 4;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "TilingSettings", meta = (HideEditConditionToggle, EditCondition = "bTilingEditable", ClampMin = "1", ClampMax = "160", UIMin = "1", UIMax = "16"))
	int32 TilesY = 8;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "TilingSettings", meta = (HideEditConditionToggle, EditCondition = "bTilingEditable", ClampMin = "512", ClampMax = "8192", UIMin = "512", UIMax = "8192"))
	int32 QuiltW = 2048;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "TilingSettings", meta = (HideEditConditionToggle, EditCondition = "bTilingEditable", ClampMin = "512", ClampMax = "8192", UIMin = "512", UIMax = "8192"))
	int32 QuiltH = 2048;

	// Aspect ratio of the camera. Value 0 has special meaning - the aspect will be taken from the device
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "TilingSettings", meta = (HideEditConditionToggle, EditCondition = "bTilingEditable", UIMin = "0.05", UIMax = "20"))
	float Aspect = 0.0f;

	// Hidden property used to enable/disable editing of other properties
	UPROPERTY()
	bool bTilingEditable = false;

	int32 TileSizeX = 0;

	int32 TileSizeY = 0;

	float PortionX = 0.f;

	float PortionY = 0.f;

	FString Text = TEXT("Default");

	FHoloPlayTilingQuality() {}

	FHoloPlayTilingQuality(FString InText, int InTilesX, int InTilesY, int InQuiltW, int InQuiltH, bool InEditable = false)
		: TilesX(InTilesX)
		, TilesY(InTilesY)
		, QuiltW(InQuiltW)
		, QuiltH(InQuiltH)
		, bTilingEditable(InEditable)
		, Text(InText)
	{
		Setup();
	}

	void Setup()
	{
		// Compute tile size, in pixels
		TileSizeX = QuiltW / TilesX;
		TileSizeY = QuiltH / TilesY;
		// Compute fraction of quilt which is used for rendering
		PortionX = (float)TilesX * TileSizeX / (float)QuiltW;
		PortionY = (float)TilesY * TileSizeY / (float)QuiltH;
	}

	int32 GetNumTiles() const
	{
		return TilesX * TilesY;
	}

	bool operator==(const FHoloPlayTilingQuality& Other) const
	{
		return TilesX == Other.TilesX && TilesY == Other.TilesY && QuiltW == Other.QuiltW && QuiltH == Other.QuiltH;
	}
};

UENUM(BlueprintType, meta=(ScriptName = "HoloPlayPlacement"))
enum class EHoloPlayPlacement : uint8
{
	Automatic			UMETA(DisplayName="Automatically place on device"),
	CustomWindow		UMETA(DisplayName="Specify display location"),
	AlwaysDebugWindow	UMETA(DisplayName="Always render in popup window")
};

USTRUCT(BlueprintType)
struct FHoloPlayWindowLocation
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Window")
	FIntPoint ClientSize;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Window")
	FIntPoint ScreenPosition;

	FHoloPlayWindowLocation()
		: ClientSize(2560, 1600)
		, ScreenPosition(2560, 0)
	{
	}

	FHoloPlayWindowLocation(FIntPoint InClientSize, FIntPoint InScreenPosition)
		: ClientSize(InClientSize)
		, ScreenPosition(InScreenPosition)
	{
	}
};

/**
 * @struct	FHoloPlayWindowSettings
 *
 * @brief	A HoloPlay window settings.
 */

USTRUCT(BlueprintType)
struct FHoloPlayWindowSettings
{
	GENERATED_BODY()

	// Where to place rendering window
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Window")
	EHoloPlayPlacement PlacementMode = EHoloPlayPlacement::Automatic;

	// Index of HoloPlay device where we'll render
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Window")
	int32 ScreenIndex = 0;

	// Location of device, use when automatic detection fails
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Window")
	FHoloPlayWindowLocation CustomWindowLocation;

	// Size and location of the debug window, which is used when device is not present
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Window")
	FHoloPlayWindowLocation DebugWindowLocation = FHoloPlayWindowLocation(FIntPoint(800, 800), FIntPoint(200, 200));

	// Create topmost debug window
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Window")
	bool bToptmostDebugWindow = false;

	UPROPERTY()
	EHoloPlayModeType LastExecutedPlayModeType = EHoloPlayModeType::PlayMode_InSeparateWindow;

	UPROPERTY()
	bool bLockInMainViewport = false;
};


/**
 * @struct	FHoloPlayScreenshotSettings
 *
 * @brief	A HoloPlay screenshot settings.
 */

USTRUCT(BlueprintType)
struct FHoloPlayScreenshotSettings
{
	GENERATED_BODY()

	// Prefix of the generated screenshot file name
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Screenshot Settings")
	FString FileName = "";

	// When true, screen shots will be saved as jpg files
	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Screenshot Settings" )
	bool UseJPG = false;

	// Quality of JPG screenshot
	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Screenshot Settings" )
	int JpegQuality = 0;

	// Hotkey used to activate this screenshot
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Screenshot Settings")
	FKey InputKey = EKeys::F9;

	// Resolution of the generated image file
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Screenshot Settings", Meta = (EditCondition = "bResolutionVisible", HideEditConditionToggle, EditConditionHides, ClampMin = "0", ClampMax = "10000", UIMin = "0", UIMax = "10000"))
	FIntPoint Resolution;

	// Hidden property used to control visibility of "Resolution" property
	UPROPERTY()
	bool bResolutionVisible = false;

	FHoloPlayScreenshotSettings() {}

	FHoloPlayScreenshotSettings(FString InFileName, FKey InInputKey, int32 InScreenshotResolutionX = 0, int32 InScreenshotResolutionY = 0)
	{
		FileName = InFileName;
		InputKey = InInputKey;
		Resolution.X = InScreenshotResolutionX;
		Resolution.Y = InScreenshotResolutionY;
		bResolutionVisible = (InScreenshotResolutionX | InScreenshotResolutionY) != 0;
	}
};


/**
 * @struct	FHoloPlayRenderingSettings
 *
 * @brief	A HoloPlay rendering settings.
 * 			Contains options for disable some part of rendering and manage rendering pipeline
 */

USTRUCT(BlueprintType)
struct FHoloPlayRenderingSettings
{
	GENERATED_BODY()

	// This property controls r.vsync engine's cvar
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Rendering")
	bool bVsync = true;

	// Render quilt instead of hologram
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Rendering")
	bool QuiltMode = false;

	// Render regular "2D" image instead of hologram
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Rendering")
	bool bRender2D = false;

	void UpdateVsync() const;
};


UENUM(BlueprintType, meta = (ScriptName = "HoloPlayPerformanceMode"))
enum class EHoloPlayPerformanceMode : uint8
{
	// Realtime hologram
	Realtime,
	// Realtime mode with switching to 2D when user is interacting in editor
	RealtimeAdaptive,
	// Render only when scene changed
	NonRealtime,
};

/**
 * @struct	FHoloPlayRenderingSettings
 *
 * @brief	A HoloPlay rendering settings.
 * 			Contains options for disable some part of rendering and manage rendering pipeline
 */

USTRUCT(BlueprintType)
struct FHoloPlayEditorSettings
{
	GENERATED_BODY()

	// Adaptive performance behavior in editor
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Editor Settings")
	EHoloPlayPerformanceMode PerformanceMode = EHoloPlayPerformanceMode::NonRealtime;

	// Delay in seconds, after which hologram will be updated in Non-Relatime mode when scene edited
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Editor Settings")
	float NonRealtimeUpdateDelay = 0.5f;

	// Log all http requests made by Blocks code
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "HoloPlay|Editor Settings")
	bool bDebugBlocksRequests = false;
};


/**
 * @class	UHoloPlaySettings
 *
 * @brief	All HoloPlay plugin settings
 */

UCLASS(config = Engine, defaultconfig)
class HOLOPLAYRUNTIME_API UHoloPlaySettings : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay", Meta = (ShowOnlyInnerProperties))
	FHoloPlayWindowSettings HoloPlayWindowSettings;

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Editor Settings", Meta = (ShowOnlyInnerProperties))
	FHoloPlayEditorSettings HoloPlayEditorSettings;

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Screenshot Settings", Meta = (DisplayName = "Lenticular Screenshot"))
	FHoloPlayScreenshotSettings HoloPlayLenticularScreenshotSettings = FHoloPlayScreenshotSettings("LenticularScreenshot", EKeys::F10);

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Screenshot Settings", Meta = (DisplayName = "Quilt Screenshot"))
	FHoloPlayScreenshotSettings HoloPlayScreenshotQuiltSettings = FHoloPlayScreenshotSettings("ScreenshotQuilt", EKeys::F9);

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Screenshot Settings", Meta = (DisplayName = "2D Screenshot"))
	FHoloPlayScreenshotSettings HoloPlayScreenshot2DSettings = FHoloPlayScreenshotSettings("Screenshot2D", EKeys::F8, 1280, 720);

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Tiling Settings", Meta = (DisplayName = "Automatic"))
	FHoloPlayTilingQuality AutomaticSettings = FHoloPlayTilingQuality("Automatic", 8, 6, 3360, 3360); // Aspect is unknown

    UPROPERTY( BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Tiling Settings", Meta = ( DisplayName = "LookingGlass - Portrait" ) )
    FHoloPlayTilingQuality PortraitSettings = FHoloPlayTilingQuality( "Portrait", 8, 6, 3360, 3360 ); // Aspect 0.75

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Tiling Settings", Meta = (DisplayName = "LookingGlass - 16\" (4K)"))
	FHoloPlayTilingQuality _16In_Settings = FHoloPlayTilingQuality("4K Res", 5, 9, 4096, 4096); // Aspect 1.77777

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Tiling Settings", Meta = (DisplayName = "LookingGlass - 32\" (8K)"))
	FHoloPlayTilingQuality _32In_Settings = FHoloPlayTilingQuality("8K Res", 5, 9, 8192, 8192); // Aspect 1.77777

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Tiling Settings", Meta = (DisplayName = "LookingGlass - 65\""))
	FHoloPlayTilingQuality _65In_Settings = FHoloPlayTilingQuality("65 Inch", 8, 9, 8192, 8192); // Aspect 1.77777

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Tiling Settings", Meta = (DisplayName = "LookingGlass - 8.9\" (Legacy)"))
	FHoloPlayTilingQuality _8_9inLegacy_Settings = FHoloPlayTilingQuality("Extra Low", 5, 9, 4096, 4096); // Aspect 1.6

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay|Tiling Settings", Meta = (DisplayName = "Custom"))
	FHoloPlayTilingQuality CustomSettings = FHoloPlayTilingQuality( "Custom", 8, 6, 3360, 3360, true ); // Aspect is custom

	UPROPERTY(BlueprintReadOnly, GlobalConfig, EditAnywhere, Category = "HoloPlay", Meta = (ShowOnlyInnerProperties))
	FHoloPlayRenderingSettings HoloPlayRenderingSettings;

	UHoloPlaySettings()
	{
	}

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	FHoloPlayTilingQuality GetTilingQualityFor(EHoloPlayQualitySettings TilingSettings) const;

	/**
	 * @fn	virtual void UHoloPlaySettings::PostEngineInit() const;
	 *
	 * @brief	Called after engine initialized
	 */
	virtual void PostEngineInit() const
	{
		HoloPlayRenderingSettings.UpdateVsync();
	}

	/**
	 * @fn	void UHoloPlaySettings::HoloPlaySave()
	 *
	 * @brief	Custom UObject save
	 * 			in case of Build it will be save in Saved folder in Editor it will be stored in the Default config folder
	 */
	void HoloPlaySave();
};

UCLASS(config = Engine)
class HOLOPLAYRUNTIME_API UHoloPlayLaunchSettings : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Settings", GlobalConfig, VisibleAnywhere)
	int LaunchCounter = 0;
};
