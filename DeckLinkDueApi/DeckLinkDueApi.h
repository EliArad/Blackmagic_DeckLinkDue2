 
#ifdef DECLINK_API_EXPORTS
#define DECLINK_API_EXPORTS __declspec(dllexport)
#else
#define DECLINK_API_EXPORTS __declspec(dllimport)
#endif

#include "Common.h"

#ifdef __cplusplus
extern "C" {
#endif 

	DECLINK_API_EXPORTS int   DL2_StartCapture(int id,DECKLINK2_DEVICES device, SURFACE_ENGINE st);
	DECLINK_API_EXPORTS bool  DL2_StopCapture(int id);
	DECLINK_API_EXPORTS bool  DL2_SetFrameCallback(int id, FrameCallback p);
	DECLINK_API_EXPORTS void  DL2_SetVideoHandle(int id, HWND p);
	DECLINK_API_EXPORTS void  DL2_SetWindowSize(int id, int x, int y, int width, int height);
	DECLINK_API_EXPORTS void  DL2_SetPreviewVideo(int id, bool preview);
	DECLINK_API_EXPORTS void  DL2_Build_H264_TransportMux_Network(int id, const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength);
	DECLINK_API_EXPORTS void  DL2_Build_H264QS_TransportMux_Network(int id, const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength);

#ifdef __cplusplus
}
#endif 



