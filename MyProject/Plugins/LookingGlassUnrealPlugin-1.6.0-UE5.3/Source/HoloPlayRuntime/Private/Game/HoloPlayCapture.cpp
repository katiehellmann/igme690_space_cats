// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/HoloPlayCapture.h"

#include "Game/HoloPlaySceneCaptureComponent2D.h"
#include "GameFramework/SpringArmComponent.h"

#include "Misc/HoloPlayLog.h"

struct FHoloPlayCustomVersion
{
	enum Type
	{
		// Before any version changes were made in the plugin
		BeforeCustomVersionWasAdded = 0,

		// Moved most of the code to UHoloPlaySceneCaptureComponent2D
		MovedFunctionalityToComponent = 1,

		// -----<new versions can be added above this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne - 1
	};

	// The GUID for this custom version number
	const static FGuid GUID;

private:
	FHoloPlayCustomVersion() {}
};

const FGuid FHoloPlayCustomVersion::GUID(0xD5E9D981, 0xD59D4CB9, 0x81B18E40, 0xB789E2B0);

// Register the custom version with core
FCustomVersionRegistration GRegisterHoloPlayCustomVersion(FHoloPlayCustomVersion::GUID, FHoloPlayCustomVersion::LatestVersion, TEXT("HoloPlayVer"));


// Sets default values
AHoloPlayCapture::AHoloPlayCapture()
{
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->bDoCollisionTest = false;

	RenderCamera = CreateDefaultSubobject<UHoloPlaySceneCaptureComponent2D>(TEXT("RenderCamera"));
	RenderCamera->SetupAttachment(CameraSpringArm);

	// Subscribe to RenderCamera updates. PostEditChangeProperty() does work only when
	// user is editing its property when Actor is selected. When RenderCamera component
	// is selected, PostEditChangeProperty is called only for component.
	RenderCamera->OnHoloPlayObjectChanged.BindLambda([this](UHoloPlaySceneCaptureComponent2D* Component)
		{
			UpdateCameraPosition();
		});

	// Initialize child component positions
	UpdateCameraPosition();
}

void AHoloPlayCapture::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

#if WITH_EDITORONLY_DATA
	Ar.UsingCustomVersion(FHoloPlayCustomVersion::GUID);

	if (Ar.IsLoading() && Ar.CustomVer(FHoloPlayCustomVersion::GUID) < FHoloPlayCustomVersion::MovedFunctionalityToComponent)
	{
		LoadLegacyProperties();
	}
#endif // WITH_EDITORONLY_DATA
}

#if WITH_EDITORONLY_DATA

void AHoloPlayCapture::LoadLegacyProperties()
{
	RenderCamera->Size = Size_DEPRECATED;
	RenderCamera->NearClipFactor = NearClipFactor_DEPRECATED;
	RenderCamera->bUseFarClipPlane = bUseFarClipPlane_DEPRECATED;
	RenderCamera->FarClipFactor = FarClipFactor_DEPRECATED;
	RenderCamera->FOV = FOV_DEPRECATED;
	RenderCamera->OverrideQuiltTexture2D = OverrideQuiltTexture2D_DEPRECATED;
	RenderCamera->bSingleViewMode = bSingleViewMode_DEPRECATED;
	RenderCamera->TilingQuality = TilingQuality_DEPRECATED;
	RenderCamera->TilingValues = TilingValues_DEPRECATED;
}

#endif // WITH_EDITORONLY_DATA

#if WITH_EDITOR

void AHoloPlayCapture::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	// Code is disabled, handling editor property changes via RenderCamera->OnHoloPlayObjectChanged
/*
	if (PropertyChangedEvent.Property != nullptr)
	{
		FName PropertyName = PropertyChangedEvent.Property->GetFName();

		if (PropertyName == GET_MEMBER_NAME_CHECKED(AHoloPlayCapture, RenderCamera))
		{
			UpdateCameraPosition();
		}
	}
*/
}

#endif // WITH_EDITOR

void AHoloPlayCapture::UpdateCameraPosition()
{
	float CamDistance = RenderCamera->GetCameraDistance();
	CameraSpringArm->TargetArmLength = CamDistance;
#if WITH_EDITOR
	if (GIsEditor && CameraSpringArm->IsRegistered())
	{
		// In editor, changing "Size" property with slider may cause a lot of flicker.
		// Explicitly updating CameraSpringArm component resolves the issue.
		CameraSpringArm->TickComponent(0, ELevelTick::LEVELTICK_All, nullptr);
	}
#endif // WITH_EDITOR
}
