#pragma once

#include "DeckLinkDueApi.h"
#include <algorithm>
#include <vector>
#include "DeckLinkDevice.h"
#include "ProfileCallback.h"
#include "DeckLinkDeviceDiscovery.h"
#include "PreviewWindowGL.h"
#include "PreviewWindowDX9.h"
#include "Common.h"




class DeckLinkCapture
{
public:
	DeckLinkCapture();
	~DeckLinkCapture();

	bool StartCapture(DECKLINK2_DEVICES device, SURFACE_ENGINE st);
	bool StopCapture();
	bool SetFrameCallback(FrameCallback p);
	bool SetVideoHandle(HWND p);
	void SetWindowSize(int x, int y, int width, int height);
	void SetPreviewVideo(bool preview);


private:

	HWND pVideoHandle;
	FrameCallback pFrameCallback;
	CComPtr<DeckLinkDevice>				m_selectedDevice;
	BMDVideoConnection					m_selectedInputConnection;
	CComPtr<DeckLinkDeviceDiscovery>	m_deckLinkDiscovery;
	CComPtr<ProfileCallback>			m_profileCallback;
	CComPtr<PreviewWindowGL>			m_previewWindowGL;
	CComPtr<PreviewWindowDX9>			m_previewWindowDX9;

	void AddDevice(CComPtr<IDeckLink>& deckLink);

	bool m_previewVideo;

};

