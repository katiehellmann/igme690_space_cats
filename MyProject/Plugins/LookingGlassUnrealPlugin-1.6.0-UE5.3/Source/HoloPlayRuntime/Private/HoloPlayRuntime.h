// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IHoloPlayRuntime.h"

#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"

class FViewport;

class FHoloPlayDisplayManager;
class FHoloPlayCommandLineManager;
class FHoloPlayLaunchManager;
class IHoloPlayManager;
class ISequencer;

#define WITH_HOLOPLAYCORE
/**
 * @class	FHoloPlayLoader
 *
 * @brief	A HoloPlay DLL loader.
 */

class FHoloPlayLoader
{
public:

	/**
	 * @fn	bool FHoloPlayLoader::LoadDLL()
	 *
	 * @brief	Loads the HoloPlay calibration DLL. This is required only for working in Editor and Building Game
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool LoadDLL(const FString& PluginBaseDir)
	{
#if defined(WITH_HOLOPLAYCORE)
		FString HoloPlayName = "HoloPlayCore";
#else
		FString HoloPlayName = "HoloPlay";
#endif
		FString PlatformName;
		FString HoloPlayDll;
#if PLATFORM_WINDOWS
		PlatformName = "Win64";
		HoloPlayDll = HoloPlayName + TEXT(".dll");
#elif PLATFORM_LINUX
		PlatformName = "linux64";
#elif PLATFORM_MAC
		PlatformName = "osx";
#endif // PLATFORM_WINDOWS

		// Pick the DLL from plugin's binaries directory (copied there from Build.cs using "RuntimeDependencies" function)
		FString DllPath = FPaths::Combine(PluginBaseDir, TEXT("Binaries"), PlatformName);

		FPlatformProcess::PushDllDirectory(*DllPath);
		FString DllFilePath = FPaths::Combine(DllPath, HoloPlayDll);
		HoloPlayDLL = FPlatformProcess::GetDllHandle(*DllFilePath);
		FPlatformProcess::PopDllDirectory(*DllPath);

		return HoloPlayDLL != nullptr;
	}

	/**
	 * @fn	bool FHoloPlayLoader::ReleaseDLL()
	 *
	 * @brief	Releases the HoloPlay calibration DLL
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool ReleaseDLL()
	{
		if (HoloPlayDLL != nullptr)
		{
			FPlatformProcess::FreeDllHandle(HoloPlayDLL);

			return true;
		}

		return false;
	}

protected:
	void* HoloPlayDLL = nullptr;
};

/**
 * @class	FHoloPlayRuntimeModule
 *
 * @brief	A HoloPlay runtime module.
 * 			This is Main runtime plugin module
 */

class FHoloPlayRuntimeModule : public IHoloPlayRuntime
{
public:
	FHoloPlayRuntimeModule();
	virtual ~FHoloPlayRuntimeModule();

	/**
	 * @fn	virtual void FHoloPlayRuntimeModule::StartupModule() override;
	 *
	 * @brief	Startup module, called on engine LoadingPhase
	 */

	virtual void StartupModule() override;

	/**
	 * @fn	virtual void FHoloPlayRuntimeModule::ShutdownModule() override;
	 *
	 * @brief	Shutdown module
	 */

	virtual void ShutdownModule() override;

	/**
	 * @fn	virtual void FHoloPlayRuntimeModule::StartPlayer(EHoloPlayModeType HoloPlayModeType) override;
	 *
	 * @brief	Starts a HoloPlay player
	 *
	 * @param	HoloPlayModeType	Type of the HoloPlay mode.
	 */

	virtual void StartPlayer(EHoloPlayModeType HoloPlayModeType) override;

	/**
	 * @fn	virtual void FHoloPlayRuntimeModule::StopPlayer() override;
	 *
	 * @brief	Stops a HoloPlay player
	 */

	virtual void StopPlayer() override;

	/**
	 * @fn	virtual void FHoloPlayRuntimeModule::RestartPlayer(EHoloPlayModeType HoloPlayModeType) override;
	 *
	 * @brief	Restart HoloPlay player
	 *
	 * @param	HoloPlayModeType	Type of the HoloPlay mode.
	 */

	virtual void RestartPlayer(EHoloPlayModeType HoloPlayModeType) override;

	/**
	 * @fn	virtual TSharedPtr<FHoloPlayDisplayManager> FHoloPlayRuntimeModule::GetHoloPlayDisplayManager() override;
	 *
	 * @brief	Gets HoloPlay display manager
	 * 			It is provided calibration data from the device
	 *
	 * @returns	The HoloPlay display manager.
	 */

	virtual TSharedPtr<FHoloPlayDisplayManager> GetHoloPlayDisplayManager() override;

	/**
	 * @fn	virtual TSharedPtr<FHoloPlayCommandLineManager> FHoloPlayRuntimeModule::GetHoloPlayCommandLineManager() override;
	 *
	 * @brief	Gets HoloPlay command line manager
	 *
	 * @returns	The HoloPlay command line manager.
	 */

	virtual TSharedPtr<FHoloPlayCommandLineManager> GetHoloPlayCommandLineManager() override;

	virtual FOnHoloPlayInputKey& OnHoloPlayInputKeyDelegate() override { return OnHoloPlayInputKey; }

#if WITH_EDITOR
	virtual bool HasActiveSequencers() override;
#endif

private:

	/**
	 * @fn	void FHoloPlayRuntimeModule::StartPlayerSeparateProccess();
	 *
	 * @brief	Starts player should be called when game is running in separate process or in the build
	 */

	void StartPlayerSeparateProccess();

	/**
	 * @fn	virtual void FHoloPlayRuntimeModule::OnWindowClosed(const TSharedRef<SWindow>& Window);
	 *
	 * @brief	Executes the window closed action
	 *
	 * @param	Window	The window.
	 */

	virtual void OnWindowClosed(const TSharedRef<SWindow>& Window);

	/**
	 * @fn	void FHoloPlayRuntimeModule::OnGameViewportCloseRequested(FViewport* InViewport);
	 *
	 * @brief	Executes the game viewport close requested action
	 *
	 * @param [in,out]	InViewport	If non-null, the in viewport.
	 */

	void OnGameViewportCloseRequested(FViewport* InViewport);

	/**
	 * @fn	void FHoloPlayRuntimeModule::OnPostEngineInit();
	 *
	 * @brief	Executes the post engine initialize action
	 * 			GEngine global should be exists
	 */

	void OnPostEngineInit();

	/**
	 * @fn	void FHoloPlayRuntimeModule::OnGameViewportCreated();
	 *
	 * @brief	Executes the game viewport created action
	 * 			GEngine->GameViewport should be exists
	 */

	void OnGameViewportCreated();

	/**
	 * @fn	void FHoloPlayRuntimeModule::InitAllManagers();
	 *
	 * @brief	Initializes all managers (Display, Console, etc)
	 */

	void InitAllManagers();

	void OnSequencerCreated(TSharedRef<ISequencer> InSequencer);

private:
	TSharedPtr<FHoloPlayDisplayManager> HoloPlayDisplayManager;
	TSharedPtr<FHoloPlayCommandLineManager> HoloPlayCommandLineManager;
	TSharedPtr<FHoloPlayLaunchManager> HoloPlayLaunchManager;
	bool bSeparateProccessPlayerStarded = false;

	FHoloPlayLoader HoloPlayLoader;
	FCriticalSection HoloPlayCritialSection;

	TArray<TSharedPtr<IHoloPlayManager>> Managers;
	bool bIsManagerInit = false;

#if WITH_EDITOR
	// Sequences which were captured with OnSequencerCreated()
	TArray<TWeakPtr<ISequencer>> Sequencers;
#endif

	// Delegates
	FOnHoloPlayInputKey OnHoloPlayInputKey;
#if WITH_EDITOR
	FDelegateHandle OnSequencerCreatedHandle;
#endif
};
