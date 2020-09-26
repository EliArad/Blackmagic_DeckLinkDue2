 
#ifdef DECLINK_API_EXPORTS
#define DECLINK_API_EXPORTS __declspec(dllexport)
#else
#define DECLINK_API_EXPORTS __declspec(dllimport)
#endif

#include "Common.h"

#ifdef __cplusplus
extern "C" {
#endif 

	DECLINK_API_EXPORTS bool  DL2_StartCapture(DECKLINK2_DEVICES device, SURFACE_ENGINE st);
	DECLINK_API_EXPORTS bool  DL2_StopCapture();
	DECLINK_API_EXPORTS bool  DL2_SetFrameCallback(FrameCallback p);
	DECLINK_API_EXPORTS void  DL2_SetVideoHandle(HWND p);
	DECLINK_API_EXPORTS void  DL2_SetWindowSize(int x, int y, int width, int height);
	DECLINK_API_EXPORTS void  DL2_SetPreviewVideo(bool preview);

#ifdef __cplusplus
}
#endif 



