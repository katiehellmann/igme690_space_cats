#pragma once

#include "CoreMinimal.h"
#include "Managers/IHoloPlayManager.h"

/**
 * @class	FHoloPlayCommandLineManager
 *
 * @brief	Manager for HoloPlay command lines.
 */

class FHoloPlayCommandLineManager : public IHoloPlayManager
{
public:
	FHoloPlayCommandLineManager();
	virtual ~FHoloPlayCommandLineManager();
	/** IHoloPlayManager Interface */

	/**
	 * @fn	virtual bool FHoloPlayCommandLineManager::Init() override;
	 *
	 * @brief	Initializes this Manager class
	 *
	 * @returns	True if it Initializes successful , false if it fails.
	 */

	virtual bool Init() override;
	/** IHoloPlayManager Interface */
};