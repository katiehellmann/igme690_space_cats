#pragma once

#include "CoreMinimal.h"
#include "HoloPlaySettings.h"
#include "Tickable.h"

/**
 * @class	IHoloPlayManager
 *
 * @brief	Managers Interface, should be implemented at all children
 */

class IHoloPlayManager : public FTickableGameObject
{
public:

	/**
	 * @fn	virtual IHoloPlayManager::~IHoloPlayManager() = 0
	 *
	 * @brief	Destructor
	 */

	virtual ~IHoloPlayManager() = 0
	{ }

	/**
	 * @fn	virtual bool IHoloPlayManager::Init()
	 *
	 * @brief	Initializes this Manager class
	 *
	 * @returns	True if it Initializes successful , false if it fails.
	 */

	virtual bool Init() { return true; }

	/**
	 * @fn	virtual void IHoloPlayManager::Release()
	 *
	 * @brief	Releases Manager and all resources
	 */

	virtual void Release() { }

	/**
	 * @fn	virtual bool IHoloPlayManager::OnStartPlayer(EHoloPlayModeType HoloPlayModeType)
	 *
	 * @brief	Executes the start player action
	 *
	 * @param	HoloPlayModeType	Type of the HoloPlay mode.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	virtual bool OnStartPlayer(EHoloPlayModeType HoloPlayModeType) { return true; }

	/**
	 * @fn	virtual void IHoloPlayManager::OnStopPlayer()
	 *
	 * @brief	Executes the stop player action
	 */

	virtual void OnStopPlayer() {}

	// FTickableGameObject interface
	virtual void Tick(float DeltaTime) override {};

	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UMIDIDeviceManager, STATGROUP_Tickables);
	}
	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}
	virtual bool IsTickableInEditor() const
	{
		return true;
	}
};