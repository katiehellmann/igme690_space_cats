#pragma once

#include "Widgets/SWindow.h"
#include "HoloPlaySettings.h"
#include "Engine/EngineBaseTypes.h"

class SHoloPlayViewport;
class UTextureRenderTarget2D;
class UHoloPlaySceneCaptureComponent2D;
class FHoloPlayDisplayManager;
class FHoloPlayCommandLineManager;
class FViewport;

/**
 * @class	IHoloPlayPlayer
 *
 * @brief	A HoloPlay player interface. Should be implemented at all children
 */

//todo: strange class, used only as parent for IHoloPlayRuntime
class IHoloPlayPlayer
{
public:
	virtual ~IHoloPlayPlayer() {}

	/**
	 * @fn	virtual void IHoloPlayPlayer::StartPlayer(EHoloPlayModeType HoloPlayModeType) = 0;
	 *
	 * @brief	Starts a HoloPlay player
	 *
	 * @param	HoloPlayModeType	Type of the HoloPlay mode.
	 */

	virtual void StartPlayer(EHoloPlayModeType HoloPlayModeType) = 0;

	/**
	 * @fn	virtual void IHoloPlayPlayer::StopPlayer() = 0;
	 *
	 * @brief	Stops a HoloPlay player
	 */

	virtual void StopPlayer() = 0;

	/**
	 * @fn	virtual void IHoloPlayPlayer::RestartPlayer(EHoloPlayModeType HoloPlayModeType) = 0;
	 *
	 * @brief	Restart HoloPlay player
	 *
	 * @param	HoloPlayModeType	Type of the HoloPlay mode.
	 */

	virtual void RestartPlayer(EHoloPlayModeType HoloPlayModeType) = 0;

	/**
	 * @fn	virtual bool IHoloPlayPlayer::IsPlaying()
	 *
	 * @brief	Query if this HoloPlay is playing
	 *
	 * @returns	True if playing, false if not.
	 */

	virtual bool IsPlaying() { return bIsPlaying; }

	/**
	 * @fn	virtual bool IHoloPlayPlayer::IsDestroyWindowRequested()
	 *
	 * @brief	Query if this object is destroy window requested
	 *
	 * @returns	True if destroy window requested, false if not.
	 */

	virtual bool IsDestroyWindowRequested() { return bIsDestroyWindowRequested; }

	/**
	 * @fn	virtual bool IHoloPlayPlayer::IsStandaloneGame()
	 *
	 * @brief	Query if engine instance is standalone game
	 *
	 * @returns	True if standalone game, false if not.
	 */

	virtual bool IsStandaloneGame() { return bIsStandaloneGame; }

	/**
	 * @fn	virtual bool IHoloPlayPlayer::IsGameMode()
	 *
	 * @brief	Query if engine instance is game mode
	 *
	 * @returns	True if game mode, false if not.
	 */

	virtual bool IsGameMode() { return bIsGameMode; }

	/**
	 * @fn	virtual bool IHoloPlayPlayer::IsCaptureStandaloneMovie()
	 *
	 * @brief	Query if engine instance is capture standalone movie
	 *
	 * @returns	True if capture standalone movie, false if not.
	 */

	virtual bool IsCaptureStandaloneMovie() { return bIsCaptureStandaloneMovie; }

	/**
	 * @fn	virtual EHoloPlayModeType IHoloPlayPlayer::GetCurrentHoloPlayModeType()
	 *
	 * @brief	Gets current HoloPlay mode type
	 *
	 * @returns	The current HoloPlay mode type.
	 */

	virtual EHoloPlayModeType GetCurrentHoloPlayModeType() { return CurrentHoloPlayModeType; }

	/**
	 * @fn	virtual TSharedPtr<FHoloPlayDisplayManager> IHoloPlayPlayer::GetHoloPlayDisplayManager() = 0;
	 *
	 * @brief	Gets HoloPlay display manager
	 *
	 * @returns	The HoloPlay display manager.
	 */

	virtual TSharedPtr<FHoloPlayDisplayManager> GetHoloPlayDisplayManager() = 0;

	/**
	 * @fn	virtual TSharedPtr<FHoloPlayCommandLineManager> IHoloPlayPlayer::GetHoloPlayCommandLineManager() = 0;
	 *
	 * @brief	Gets HoloPlay command line manager
	 *
	 * @returns	The HoloPlay command line manager.
	 */

	virtual TSharedPtr<FHoloPlayCommandLineManager> GetHoloPlayCommandLineManager() = 0;

	DECLARE_MULTICAST_DELEGATE_SixParams(FOnHoloPlayInputKey, FViewport*, int32, FKey, EInputEvent, float, bool);
	/**
	 * @fn	virtual FOnHoloPlayInputKey& IHoloPlayPlayer::OnHoloPlayInputKeyDelegate() = 0;
	 *
	 * @brief	Broadcast HoloPlay viewport input event 
	 *
	 * @returns Input delegate
	 */
	virtual FOnHoloPlayInputKey& OnHoloPlayInputKeyDelegate() = 0;

	TSharedPtr<SHoloPlayViewport> GetHoloPlayViewport()
	{
		return HoloPlayViewport;
	}

protected:

	/**
	 * @fn	virtual void IHoloPlayPlayer::OnWindowClosed(const TSharedRef<SWindow>& Window)
	 *
	 * @brief	Executes the window closed action
	 *
	 * @param	Window	The window.
	 */

	virtual void OnWindowClosed(const TSharedRef<SWindow>& Window) {};

protected:
	bool bIsPlaying = false;
	bool bIsDestroyWindowRequested = false;
	bool bIsStandaloneGame = false;
	bool bIsGameMode = false;
	bool bLockInMainViewport = false;

	bool bIsCaptureStandaloneMovie = false;
	EHoloPlayModeType CurrentHoloPlayModeType = EHoloPlayModeType::PlayMode_InSeparateWindow;

	TSharedPtr<SWindow> HoloPlayWindow = nullptr;
	TSharedPtr<SHoloPlayViewport> HoloPlayViewport = nullptr;

	FOnWindowClosed OnWindowClosedDelegate;

public:
#if WITH_EDITOR
	TArray<TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> > EditorHoloPlayCaptureComponents;
#endif
	TArray<TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> > GameHoloPlayCaptureComponents;
};
