#pragma once

#include "DeckLinkDueApi.h"
#include <algorithm>
#include <vector>
#include "DeckLinkDevice.h"
#include "ProfileCallback.h"
#include "DeckLinkDeviceDiscovery.h"
#include "PreviewWindow.h"
#include "Common.h"




class DeckLinkCapture
{
public:
	DeckLinkCapture();
	~DeckLinkCapture();

	bool StartCapture();
	bool StopCapture();
	bool SetFrameCallback(FrameCallback p);
	void SetVideoHandle(HWND p);
	void SetWindowSize(int x, int y, int width, int height);


private:

	HWND pVideoHandle;
	FrameCallback pFrameCallback;
	CComPtr<DeckLinkDevice>				m_selectedDevice;
	BMDVideoConnection					m_selectedInputConnection;
	CComPtr<DeckLinkDeviceDiscovery>	m_deckLinkDiscovery;
	CComPtr<ProfileCallback>			m_profileCallback;
	CComPtr<PreviewWindow>	m_previewWindow;

	void AddDevice(CComPtr<IDeckLink>& deckLink);

};

