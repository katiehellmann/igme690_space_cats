#include "Misc/HoloPlayHelpers.h"
#include "HoloPlayRuntime.h"
#include "MovieSceneCaptureModule.h"

IMovieSceneCaptureInterface* HoloPlay::GetMovieSceneCapture()
{
#if 0
	// Find the UMovieSceneCapture object.
	// It is always created in transient package, and with the same name.
	// Reference: FMovieSceneCaptureModule::CreateMovieSceneCapture, FSequencer::RenderMovieInternal:
	UMovieSceneCapture* MovieSceneCapture = FindObject<UMovieSceneCapture>((UObject*)GetTransientPackage(), *UMovieSceneCapture::MovieSceneCaptureUIName.ToString());
//	if (MovieSceneCapture != nullptr && MovieSceneCapture->bCaptiring)
	return MovieSceneCapture;
#else
	IMovieSceneCaptureInterface* ActiveCapture = IMovieSceneCaptureModule::Get().GetFirstActiveMovieSceneCapture();
	return ActiveCapture;
#endif
}

TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlay::GetGameHoloPlayCaptureComponent()
{
	IHoloPlayRuntime& HoloPlayRuntime = IHoloPlayRuntime::Get();
	TArray<TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> >* ComponentArray = &HoloPlayRuntime.GameHoloPlayCaptureComponents;
#if WITH_EDITOR
	if (HoloPlayRuntime.EditorHoloPlayCaptureComponents.Num())
	{
		ComponentArray = &HoloPlayRuntime.EditorHoloPlayCaptureComponents;
	}
#endif
	// Refine the array - remove possibly dead components
	for (int32 Index = (*ComponentArray).Num() - 1; Index >= 0; Index--)
	{
		if ((*ComponentArray)[Index].Get() == nullptr)
		{
			ComponentArray->RemoveAt(Index);
		}
	}
	// Return the first component, as it's intended to be the active one
	return ComponentArray->Num() ? (*ComponentArray)[0] : nullptr;
}
