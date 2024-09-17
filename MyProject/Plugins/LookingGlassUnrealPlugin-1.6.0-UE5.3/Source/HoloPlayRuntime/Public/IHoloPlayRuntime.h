 #pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"

#include "IHoloPlayPlayer.h"

class IHoloPlayRuntime;

extern IHoloPlayRuntime* GHoloPlayRuntime;

//-------------------------------------------------------------------------------------------------
// IHoloPlayRuntime Module
//-------------------------------------------------------------------------------------------------

/**
 * @class	IHoloPlayRuntime
 *
 * @brief	The public interface to this module.  In most cases, this interface is only public to
 * 			sibling modules within this plugin.
 */

class IHoloPlayRuntime : public IModuleInterface, public IHoloPlayPlayer
{
public:

	/**
	 * @fn	static inline IHoloPlayRuntime& IHoloPlayRuntime::Get()
	 *
	 * @brief	Singleton-like access to this module's interface.  This is just for convenience!
	 * 			Beware of calling this during the shutdown phase, though.  Your module might have
	 * 			been unloaded already.
	 *
	 * @returns	Returns singleton instance, loading the module on demand if needed.
	 */

	static inline IHoloPlayRuntime& Get()
	{
		return FModuleManager::LoadModuleChecked< IHoloPlayRuntime >("HoloPlayRuntime");
	}

	/**
	 * @fn	static inline bool IHoloPlayRuntime::IsAvailable()
	 *
	 * @brief	Checks to see if this module is loaded and ready.  It is only valid to call Get() if
	 * 			IsAvailable() returns true.
	 *
	 * @returns	True if the module is loaded and ready to use.
	 */

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("HoloPlayRuntime");
	}

#if WITH_EDITOR
	// Returns true if sequencer window is open
	virtual bool HasActiveSequencers()
	{
		return false;
	}
#endif
};
