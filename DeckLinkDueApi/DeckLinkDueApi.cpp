// DeckLinkDueApi.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DeckLinkCapture.h"
 
DeckLinkCapture  *pCapture[4] = { NULL,NULL,NULL,NULL };
 

FrameCallback pFrameCallback;

DECLINK_API_EXPORTS int DL2_StartCapture(int id,DECKLINK2_DEVICES device, SURFACE_ENGINE st)
{
	if (pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

	return pCapture[id]->StartCapture(device, st);

}
DECLINK_API_EXPORTS bool DL2_StopCapture(int id)
{
	 
	if (pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

	return pCapture[id]->StopCapture();

}


DECLINK_API_EXPORTS bool DL2_SetFrameCallback(int id,FrameCallback p)
{
	if(pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

	return pCapture[id]->SetFrameCallback(p);

}

DECLINK_API_EXPORTS void  DL2_SetVideoHandle(int id,HWND p)
{
	if (pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

	pCapture[id]->SetVideoHandle(p);

}


DECLINK_API_EXPORTS void  DL2_SetWindowSize(int id, int x, int y, int width, int height)
{
	if (pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

	pCapture[id]->SetWindowSize(x, y, width, height);

}

DECLINK_API_EXPORTS void DL2_SetPreviewVideo(int id, bool preview)
{

	if (pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

    pCapture[id]->SetPreviewVideo(preview);

}


DECLINK_API_EXPORTS void DL2_Build_H264_TransportMux_Network(int id, const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength)
{

	if (pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

	pCapture[id]->Build_H264_TransportMux_Network(IpAddress, port, IpInterfaceAddress, bitrate, goplength);

}

DECLINK_API_EXPORTS void DL2_Build_H264QS_TransportMux_Network(int id, const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength)
{

	if (pCapture[id] == NULL)
		pCapture[id] = new DeckLinkCapture();

	pCapture[id]->Build_H264QS_TransportMux_Network(IpAddress, port, IpInterfaceAddress, bitrate, goplength);

}
