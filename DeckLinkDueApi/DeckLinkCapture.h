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

	int StartCapture(DECKLINK2_DEVICES device, SURFACE_ENGINE st);
	bool StopCapture();
	bool SetFrameCallback(FrameCallback p);
	bool SetVideoHandle(HWND p);
	void SetWindowSize(int x, int y, int width, int height);
	void SetPreviewVideo(bool preview);
	void Build_H264_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength);
	void Build_H264QS_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength);

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
	int BuildGraphs();
	int RunGraph();

	bool m_previewVideo;
	int m_enableDownGraph;

	DSGraphUtils  *m_ds;
	WCHAR m_multicastIpAddress[100];
	int m_multicastPort;
	WCHAR m_ipInterfaceAddress[100];

	int m_bitrate;
	int m_goplength;
};

