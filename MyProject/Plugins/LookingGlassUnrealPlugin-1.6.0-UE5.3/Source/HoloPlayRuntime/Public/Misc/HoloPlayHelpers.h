#pragma once

#include "CoreMinimal.h"

class UHoloPlaySceneCaptureComponent2D;
class IMovieSceneCaptureInterface;

namespace HoloPlay
{
	/**
	 * @fn	UMovieSceneCapture* GetMovieSceneCapture();
	 *
	 * @brief	Gets movie scene capture
	 * 			It is using for check movie capture during capturing video
	 *
	 * @returns	Null if it fails, else the movie scene capture.
	 */

	HOLOPLAYRUNTIME_API IMovieSceneCaptureInterface* GetMovieSceneCapture();

	HOLOPLAYRUNTIME_API TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> GetGameHoloPlayCaptureComponent();
};
