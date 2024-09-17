#pragma once

#include "CoreMinimal.h"
#include "Misc/CoreMisc.h"

#include "HoloPlaySettings.h"

#include "Widgets/SWindow.h"
#include "Runtime/Launch/Resources/Version.h"
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 2
#include "ViewportClient.h"
#else
#include "UnrealClient.h"
#endif

class UTextureRenderTarget2D;
class UHoloPlaySceneCaptureComponent2D;
class FViewport;
class FSceneViewport;

DECLARE_MULTICAST_DELEGATE(FOnHoloPlayScreenshotRequestProcessed);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnHoloPlayFrameReady, const TArray<FColor>& /* Buffer */, int32 /* Width */, int32 /* Height */);

/**
 * @struct	FHoloPlayScreenshotRequest
 *
 * @brief	Request screenshot on Draw Loop
 */

struct FHoloPlayScreenshotRequest
{
	using FCallback = TFunction<void(const FString&)>;

	struct FQuiltSettings
	{
		int32 NumColumns = 0;
		int32 NumRows = 0;
		float Aspect = 0.0f;
	};

	/**
	 * @fn	void RequestScreenshot(const FString& InFilename, bool bAddFilenameSuffix);
	 *
	 * @brief	Requests a new screenshot with a specific filename
	 *
	 * @param	InFilename		  	The filename to use.
	 * @param	bAddFilenameSuffix	Whether an auto-generated unique suffix should be added to the
	 * 								supplied filename.
	 */

	void RequestScreenshot(const FString& InFilename, bool bAddFilenameSuffix, FQuiltSettings InQuiltSettings = FQuiltSettings());

	void SetCompletedCallback(FCallback InCallback)
	{
		OnCompleted = InCallback;
	}

	/**
	 * @fn	const FString& GetFilename()
	 *
	 * @brief	Gets the filename
	 *
	 * @returns	The filename of the next screenshot.
	 */

	const FString& GetFilename() { return Filename; }

	/**
	 * @fn	void CreateViewportScreenShotFilename(FString& InOutFilename);
	 *
	 * @brief	Creates a new screenshot filename from the passed in filename template
	 *
	 * @param [in,out]	InOutFilename	Filename of the in out file.
	 */

	void CreateViewportScreenShotFilename(FString& InOutFilename);

	void ExecCallback()
	{
		if (OnCompleted)
		{
			OnCompleted(Filename);
		}
	}

protected:
	// Filename of the saved bitmap
	FString Filename;
	// Current quilt settings, used to encode them to the filename
	FQuiltSettings QuiltSettings;
	// Callback which is executed when screenshot is done
	FCallback OnCompleted;
};

/**
 * @class	FHoloPlayViewportClient
 *
 * @brief	The viewport's client processes input received by the viewport, and draws the viewport.
 */

class FHoloPlayViewportClient : public FViewportClient, public FSelfRegisteringExec
{
public:
	FHoloPlayViewportClient();
	~FHoloPlayViewportClient();

	/** FViewportClient interface */

	/**
	 * @fn	virtual void FHoloPlayViewportClient::Draw(FViewport* Viewport, FCanvas* Canvas) override;
	 *
	 * @brief	Execute Draw each tick This is the place for issue draw cumments and start rendering
	 *
	 * @param [in,out]	Viewport	If non-null, the viewport.
	 * @param [in,out]	Canvas  	If non-null, the canvas.
	 */

	virtual void Draw(FViewport* Viewport, FCanvas* Canvas) override;

	/**
	 * @fn	virtual bool FHoloPlayViewportClient::InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.0f, bool bGamepad = false) override;
	 *
	 * @brief	Check a key event received by the viewport. If the viewport client uses the event, it
	 * 			should return true to consume it.
	 *
	 * @param [in,out]	Viewport	   	- The viewport which the key event is from.
	 * @param 		  	ControllerId   	- The controller which the key event is from.
	 * @param 		  	Key			   	- The name of the key which an event occured for.
	 * @param 		  	Event		   	- The type of event which occured.
	 * @param 		  	AmountDepressed	(Optional) - For analog keys, the depression percent.
	 * @param 		  	bGamepad	   	(Optional) - input came from gamepad (ie xbox controller)
	 *
	 * @returns	True to consume the key event, false to pass it on.
	 */

	virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed = 1.0f, bool bGamepad = false) override;

	/**
	 * @fn	virtual bool FHoloPlayViewportClient::InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override;
	 *
	 * @brief	Check an axis movement received by the viewport. If the viewport client uses the
	 * 			movement, it should return true to consume it.
	 *
	 * @param [in,out]	Viewport		- The viewport which the axis movement is from.
	 * @param 		  	ControllerId	- The controller which the axis movement is from.
	 * @param 		  	Key				- The name of the axis which moved.
	 * @param 		  	Delta			- The axis movement delta.
	 * @param 		  	DeltaTime   	- The time since the last axis update.
	 * @param 		  	NumSamples  	(Optional) - The number of device samples that contributed to
	 * 									this Delta, useful for things like smoothing.
	 * @param 		  	bGamepad		(Optional) - input came from gamepad (ie xbox controller)
	 *
	 * @returns	True to consume the axis movement, false to pass it on.
	 */

	//todo: should override a different method since UE5.1
	virtual bool InputAxis(FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples = 1, bool bGamepad = false) override;

	virtual bool InputChar(FViewport* Viewport, int32 ControllerId, TCHAR Character) override;
	virtual bool InputTouch(FViewport* Viewport, int32 ControllerId, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;
	virtual bool InputMotion(FViewport* Viewport, int32 ControllerId, const FVector& Tilt, const FVector& RotationRate, const FVector& Gravity, const FVector& Acceleration) override;

	/**
	 * @fn	virtual UWorld* FHoloPlayViewportClient::GetWorld() const override
	 *
	 * @brief	Gets the world
	 *
	 * @returns	Null if it fails, else the world.
	 */

	virtual UWorld* GetWorld() const override { return nullptr; }

	/**
	 * @fn	virtual void FHoloPlayViewportClient::RedrawRequested(FViewport* Viewport) override;
	 *
	 * @brief	Request FViewport redraw
	 *
	 * @param [in,out]	Viewport	If non-null, the viewport.
	 */

	virtual void RedrawRequested(FViewport* Viewport) override;

	// This function is virtual just for inter-module access
	virtual void TakeQuiltScreenshot(FHoloPlayScreenshotRequest::FCallback Callback = FHoloPlayScreenshotRequest::FCallback());

	// Override the viewport's ProcessScreenShots method to inject our code to handle lenticular screenshot (when the rendering is completed)
	virtual bool ProcessScreenShots(FViewport* InViewport) override
	{
		return ProcessScreenShotLenticular(InViewport);
	}

	/**
	 * @fn	virtual EMouseCursor::Type FHoloPlayViewportClient::GetCursor(FViewport* Viewport, int32 X, int32 Y) override;
	 *
	 * @brief	Retrieves the cursor that should be displayed by the OS
	 *
	 * @param [in,out]	Viewport	the viewport that contains the cursor.
	 * @param 		  	X			the x position of the cursor.
	 * @param 		  	Y			the Y position of the cursor.
	 *
	 * @returns	the cursor that the OS should display.
	 */

	virtual EMouseCursor::Type GetCursor(FViewport* Viewport, int32 X, int32 Y) override;

	/**
	 * @fn	virtual bool FHoloPlayViewportClient::IsFocused(FViewport* Viewport) override;
	 *
	 * @brief	Query if 'Viewport' is focused
	 *
	 * @param [in,out]	Viewport	If non-null, the viewport.
	 *
	 * @returns	True if focused, false if not.
	 */

	virtual bool IsFocused(FViewport* Viewport) override;

	/**
	 * @fn	virtual void FHoloPlayViewportClient::LostFocus(FViewport* Viewport) override;
	 *
	 * @brief	Viewport lost focus
	 *
	 * @param [in,out]	Viewport	If non-null, the viewport.
	 */

	virtual void LostFocus(FViewport* Viewport) override;

	/**
	 * @fn	virtual void FHoloPlayViewportClient::ReceivedFocus(FViewport* Viewport) override;
	 *
	 * @brief	Viewport received focus
	 *
	 * @param [in,out]	Viewport	If non-null, the viewport.
	 */

	virtual void ReceivedFocus(FViewport* Viewport) override;

	FOnHoloPlayScreenshotRequestProcessed& OnScreenshot3DRequestProcessed()
	{
		return Screenshot3DProcessedDelegate;
	}

	FOnHoloPlayScreenshotRequestProcessed& OnScreenshotQuiltRequestProcessed()
	{
		return ScreenshotQuiltProcessedDelegate;
	}

	FOnHoloPlayScreenshotRequestProcessed& OnScreenshot2DRequestProcessed()
	{
		return Screenshot2DProcessedDelegate;
	}

	/**
	 * @fn	void FHoloPlayViewportClient::SetViewportWindow(TSharedPtr< SWindow > InWindow)
	 *
	 * @brief	Sets viewport window
	 *
	 * @param	InWindow	The in window.
	 */

	void SetViewportWindow(TSharedPtr< SWindow > InWindow)
	{
		Window = InWindow;
	}

	/**
	 * @fn	void FHoloPlayViewportClient::SetIgnoreInput(bool Ignore)
	 *
	 * @brief	Set whether to ignore input.
	 *
	 * @param	Ignore	True to ignore.
	 */

	void SetIgnoreInput(bool Ignore)
	{
		bIgnoreInput = Ignore;
	}

	/**
	 * @fn	virtual bool FHoloPlayViewportClient::IgnoreInput() override
	 *
	 * @brief	Check whether we should ignore input.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	virtual bool IgnoreInput() override
	{
		return bIgnoreInput;
	}

	/**
	 * @fn	TSharedPtr< SWindow > FHoloPlayViewportClient::GetWindow()
	 *
	 * @brief	Returns access to this viewport's Slate window
	 *
	 * @returns	The window.
	 */

	TSharedPtr< SWindow > GetWindow()
	{
		return Window.Pin();
	}

private:

	/**
	 * @fn	virtual bool FHoloPlayViewportClient::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;
	 *
	 * @brief	Exec console commands
	 *
	 * @param [in,out]	InWorld	If non-null, the in world.
	 * @param 		  	Cmd	   	The command.
	 * @param [in,out]	Ar	   	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;

	void Render2DView(UHoloPlaySceneCaptureComponent2D* CaptureComponent, const FViewport* Viewport);

	void RenderToQuilt(UHoloPlaySceneCaptureComponent2D* CaptureComponent);

	void RenderQuiltToLenticular(UHoloPlaySceneCaptureComponent2D* HoloPlayCaptureComponent, const FViewport* Viewport, bool bForceQuiltMode);

	/**
	 * @fn	bool FHoloPlayViewportClient::HandleLenticularScreenshotCommand(const TCHAR* Cmd, FOutputDevice& Ar);
	 *
	 * @brief	Handles the lenticular screenshot command
	 *
	 * @param 		  	Cmd	The command.
	 * @param [in,out]	Ar 	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool HandleLenticularScreenshotCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	/**
	 * @fn	bool FHoloPlayViewportClient::HandleScreenshotQuiltCommand(const TCHAR* Cmd, FOutputDevice& Ar);
	 *
	 * @brief	Handles the screenshot quilt command
	 *
	 * @param 		  	Cmd	The command.
	 * @param [in,out]	Ar 	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool HandleScreenshotQuiltCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	/**
	 * @fn	bool FHoloPlayViewportClient::HandleScreenshot2DCommand(const TCHAR* Cmd, FOutputDevice& Ar);
	 *
	 * @brief	Handles the screenshot 2D command
	 *
	 * @param 		  	Cmd	The command.
	 * @param [in,out]	Ar 	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool HandleScreenshot2DCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	/**
	 * @fn	bool FHoloPlayViewportClient::HandleWindowCommand(const TCHAR* Cmd, FOutputDevice& Ar);
	 *
	 * @brief	Handles the window command
	 *
	 * @param 		  	Cmd	The command.
	 * @param [in,out]	Ar 	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool HandleWindowCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	/**
	 * @fn	bool FHoloPlayViewportClient::HandleShaderCommand(const TCHAR* Cmd, FOutputDevice& Ar);
	 *
	 * @brief	Handles the shader command
	 *
	 * @param 		  	Cmd	The command.
	 * @param [in,out]	Ar 	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool HandleShaderCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	/**
	 * @fn	bool FHoloPlayViewportClient::HandleSceneCommand(const TCHAR* Cmd, FOutputDevice& Ar);
	 *
	 * @brief	Handles the scene command
	 *
	 * @param 		  	Cmd	The command.
	 * @param [in,out]	Ar 	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool HandleSceneCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	/**
	 * @fn	bool FHoloPlayViewportClient::HandleTillingCommand(const TCHAR* Cmd, FOutputDevice& Ar);
	 *
	 * @brief	Handles the tilling command
	 *
	 * @param 		  	Cmd	The command.
	 * @param [in,out]	Ar 	The archive.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */
	bool HandleTillingCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	bool HandleRenderingCommand(const TCHAR* Cmd, FOutputDevice& Ar);

	bool PrepareLenticularScreenshot(const FString& FileName, bool bAddFilenameSuffix);
	bool PrepareScreenshotQuilt(const FString& FileName, bool bAddFilenameSuffix, FHoloPlayScreenshotRequest::FCallback Callback = FHoloPlayScreenshotRequest::FCallback());
	bool PrepareScreenshot2D(const FString& FileName, bool bAddFilenameSuffix);

	/**
	 * @fn	void FHoloPlayViewportClient::ParseScreenshotCommand(const TCHAR * Cmd, FString& InName, bool& InSuffix);
	 *
	 * @brief	Parse screenshot console command
	 *
	 * @param 		  	Cmd			The command.
	 * @param [in,out]	InName  	Name of the in.
	 * @param [in,out]	InSuffix	True to in suffix.
	 */

	void ParseScreenshotCommand(const TCHAR * Cmd, FString& InName, bool& InSuffix);

	/**
	 * @fn	static bool FHoloPlayViewportClient::ParseResolution(const TCHAR* InResolution, uint32& OutX, uint32& OutY);
	 *
	 * @brief	Parse resolution console command
	 *
	 * @param 		  	InResolution 	The in resolution.
	 * @param [in,out]	OutX		 	The out x coordinate.
	 * @param [in,out]	OutY		 	The out y coordinate.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	static bool ParseResolution(const TCHAR* InResolution, uint32& OutX, uint32& OutY);

	/**
	 * @fn	virtual void FHoloPlayViewportClient::ProcessScreenShotLenticular(FViewport* Viewport) override;
	 *
	 * @brief	Process the lenticular screen shots
	 *
	 * @param [in,out]	Viewport	If non-null, the viewport.
	 */

	bool ProcessScreenShotLenticular(FViewport* Viewport);

	void ProcessScreenshotQuilt(UTextureRenderTarget2D* QuiltRT);

	// Pass quilt as FBitmap to movie capture
	void ProcessQuiltForMovie(UTextureRenderTarget2D* QuiltRT);

	/**
	 * @fn	bool FHoloPlayViewportClient::GetRenderTargetScreenShot(TWeakObjectPtr<UTextureRenderTarget2D> TextureRenderTarget2D, TArray<FColor>& Bitmap, const FIntRect& ViewRect = FIntRect());
	 *
	 * @brief	Gets render target screen in bytes array on CPU
	 *
	 * @param 		  	TextureRenderTarget2D	The texture render target 2D.
	 * @param [in,out]	Bitmap				 	The bitmap.
	 * @param 		  	ViewRect			 	(Optional) The view rectangle.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool GetRenderTargetScreenShot(TWeakObjectPtr<UTextureRenderTarget2D> TextureRenderTarget2D, TArray<FColor>& Bitmap, const FIntRect& ViewRect = FIntRect());

	void ProcessScreenshot2D(TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlayCaptureComponent);

	/**
	 * @fn	UTextureRenderTarget2D* FHoloPlayViewportClient::GetQuiltRT(TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlayCaptureComponent);
	 *
	 * @brief	Gets quilt render target texture
	 *
	 * @param	HoloPlayCapture	The HoloPlay capture.
	 *
	 * @returns	Null if it fails, else the quilt right.
	 */

	UTextureRenderTarget2D* GetQuiltRT(TWeakObjectPtr<UHoloPlaySceneCaptureComponent2D> HoloPlayCaptureComponent);

	void SaveScreenShot(const TArray<FColor>& Bitmap, const FIntVector& Size, const FString& ScreenShotName, const FHoloPlayScreenshotSettings* pScreenShotSettings);

#if WITH_EDITOR
	// Event handlers for noticing level editor viewport redraws
	void OnRedrawAllViewports();
	void OnRedrawViewport(bool bInvalidateHitProxies);
#endif

private:
	FOnHoloPlayScreenshotRequestProcessed Screenshot3DProcessedDelegate;
	FOnHoloPlayScreenshotRequestProcessed ScreenshotQuiltProcessedDelegate;
	FOnHoloPlayScreenshotRequestProcessed Screenshot2DProcessedDelegate;

	TSharedPtr<FHoloPlayScreenshotRequest> HoloPlayLenticularScreenshotRequest;
	TSharedPtr<FHoloPlayScreenshotRequest> HoloPlayQuiltScreenshotRequest;
	TSharedPtr<FHoloPlayScreenshotRequest> HoloPlayScreenshot2DRequest;

	/** Whether or not to ignore input */
	bool bIgnoreInput;

	EMouseCursor::Type CurrentMouseCursor;

	UTextureRenderTarget2D* QuiltRT;

	// Information about last rendered scene, used for EHoloPlayPerformanceMode::NonRealtime
	UHoloPlaySceneCaptureComponent2D* LastRenderedComponent;
	double LastViewportUpdateTime;
	bool bLastModeWas2D;

public:
	/** Slate window associated with this viewport client.  The same window may host more than one viewport client. */
	TWeakPtr<SWindow> Window;

	/** The platform-specific viewport which this viewport client is attached to. */
	FViewport* Viewport;

	FSceneViewport* HoloPlaySceneViewport;

	// Callback for passing rendered frames outside of FViewportClient
	static FOnHoloPlayFrameReady OnHoloPlayFrameReady;
};
