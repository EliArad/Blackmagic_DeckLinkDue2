// DeckLinkDueApi.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DeckLinkCapture.h"
 
DeckLinkCapture  *pCapture = NULL;
 

FrameCallback pFrameCallback;

DECLINK_API_EXPORTS int DL2_StartCapture(DECKLINK2_DEVICES device, SURFACE_ENGINE st)
{
	if (pCapture == NULL)
		pCapture = new DeckLinkCapture();

	return pCapture->StartCapture(device, st);

}
DECLINK_API_EXPORTS bool DL2_StopCapture()
{
	 
	if (pCapture == NULL)
		pCapture = new DeckLinkCapture();

	return pCapture->StopCapture();

}


DECLINK_API_EXPORTS bool DL2_SetFrameCallback(FrameCallback p)
{
	if(pCapture == NULL)
		pCapture = new DeckLinkCapture();

	return pCapture->SetFrameCallback(p);

}

DECLINK_API_EXPORTS void  DL2_SetVideoHandle(HWND p)
{
	if (pCapture == NULL)
		pCapture = new DeckLinkCapture();

	pCapture->SetVideoHandle(p);

}


DECLINK_API_EXPORTS void  DL2_SetWindowSize(int x, int y, int width, int height)
{
	if (pCapture == NULL)
		pCapture = new DeckLinkCapture();

	pCapture->SetWindowSize(x, y, width, height);

}

DECLINK_API_EXPORTS void DL2_SetPreviewVideo(bool preview)
{

	if (pCapture == NULL)
		pCapture = new DeckLinkCapture();

    pCapture->SetPreviewVideo(preview);

}


DECLINK_API_EXPORTS void DL2_Build_H264_TransportMux_Network()
{

	if (pCapture == NULL)
		pCapture = new DeckLinkCapture();

	pCapture->Build_H264_TransportMux_Network();

}