#include "stdafx.h"
#include "DeckLinkCapture.h"

int DeviceNotification();
 


DeckLinkCapture::DeckLinkCapture()
{
	m_previewVideo = true;
	pFrameCallback = nullptr;
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	m_enableDownGraph = 0;
	m_ds = NULL;
	
}


DeckLinkCapture::~DeckLinkCapture()
{
}



void DeckLinkCapture::AddDevice(CComPtr<IDeckLink>& deckLink)
{
	/*
	CComPtr<DeckLinkDevice>		newDevice;

	try
	{
		newDevice.Attach(new DeckLinkDevice(deckLink));
	}
	catch (...)
	{
		// Device does not have IDeckLinkInput interface, eg it is a DeckLink Mini Monitor
		return;
	}

	// Initialise new DeckLinkDevice object
	if (!newDevice->init())
		return;

	// Register profile callback with newly added device's profile manager
	CComQIPtr<IDeckLinkProfileManager> profileManager(newDevice->getDeckLinkInstance());
	if (profileManager)
		profileManager->SetCallback(m_profileCallback);

	// Store input device to map to maintain reference
	m_inputDevices[deckLink] = std::move(newDevice);
	RefreshInputDeviceList();
	*/
}


extern IDeckLink* deckLink1;
extern IDeckLink* deckLink2;
extern IDeckLink* deckLink3;
extern IDeckLink* deckLink4;


int DeckLinkCapture::StartCapture(DECKLINK2_DEVICES device, SURFACE_ENGINE st)
{


	DeviceNotification();
	 
	IDeckLink* tmpdeckLink = NULL;

	if (device == DECKLINK2_DEVICES::DEVICE1)
	{
		while (deckLink1 == NULL)
		{
			Sleep(500);
		}
		tmpdeckLink = deckLink1;
	}

	if (device == DECKLINK2_DEVICES::DEVICE2)
	{
		while (deckLink2 == NULL)
		{
			Sleep(500);
		}
		tmpdeckLink = deckLink2;
	}

	if (device == DECKLINK2_DEVICES::DEVICE3)
	{
		while (deckLink3 == NULL)
		{
			Sleep(500);
		}
		tmpdeckLink = deckLink3;
	}


	if (device == DECKLINK2_DEVICES::DEVICE4)
	{
		while (deckLink4 == NULL)
		{
			Sleep(500);
		}
		tmpdeckLink = deckLink4;
	}

	CComPtr<IDeckLink> deckLink(tmpdeckLink);

	CComPtr<DeckLinkDevice>		newDevice;

	try
	{
		newDevice.Attach(new DeckLinkDevice(deckLink));
	}
	catch (...)
	{
		// Device does not have IDeckLinkInput interface, eg it is a DeckLink Mini Monitor
		return -232;
	}

	// Initialise new DeckLinkDevice object
	if (!newDevice->init())
		return -2832;

	// Register profile callback with newly added device's profile manager
	CComQIPtr<IDeckLinkProfileManager> profileManager(newDevice->getDeckLinkInstance());
	if (profileManager)
		profileManager->SetCallback(m_profileCallback);


	m_selectedDevice = newDevice;
	if (st == SURFACE_ENGINE::OPENGL)
	{
		m_previewWindowGL.Attach(new PreviewWindowGL());
		if (m_previewWindowGL->init() == false)
		{

		}
		m_previewWindowGL->SetFrameCallback(pFrameCallback);
		m_previewWindowGL->SetVideoHandle(pVideoHandle);

		int res;
		if ((res = BuildGraphs()) < 0)
			return res;

		if (newDevice)
		{
			if (m_ds != NULL && m_enableDownGraph > 0)
			{
				m_previewWindowDX9->SetSourceFilter(m_ds->GetLiveSourceInterface());
			}

			if (newDevice->startCapture(BMDDisplayMode::bmdModeNTSC, m_previewWindowGL, true) == true)
			{
				if ((res = RunGraph()) < 0)
					return res;
				return 1;
			}
			else
			{
				m_selectedDevice->stopCapture();
				return -394;
			}
		}
	}
	else 
	if (st == SURFACE_ENGINE::DX9)
	{
		m_previewWindowDX9.Attach(new PreviewWindowDX9());
		if (m_previewWindowDX9->init() == false)
		{

		}
		m_previewWindowDX9->SetFrameCallback(pFrameCallback);
		m_previewWindowDX9->SetVideoHandle(pVideoHandle);

		int res;
		if ((res = BuildGraphs()) < 0)
			return res;

		if (newDevice)
		{

			if (m_ds != NULL && m_enableDownGraph > 0)
			{
				m_previewWindowDX9->SetSourceFilter(m_ds->GetLiveSourceInterface());
			}

			if (newDevice->startCapture(BMDDisplayMode::bmdModeNTSC, m_previewWindowDX9, true) == true)
			{
				if ((res = RunGraph()) < 0)
					return res;
				return 1;
			}
			else
			{
				m_selectedDevice->stopCapture();
				return -39424;
			}
		}
	}
}

bool DeckLinkCapture::StopCapture()
{
	if (m_selectedDevice)
		m_selectedDevice->stopCapture();

	if (m_ds != NULL)
	{
		m_ds->Close();
	}

	return true;
}


bool DeckLinkCapture::SetFrameCallback(FrameCallback p)
{
	pFrameCallback = p;
	return true;
}

bool DeckLinkCapture::SetVideoHandle(HWND p)
{
	pVideoHandle = p;
	if (m_previewWindowGL != nullptr)
		return m_previewWindowGL->SetVideoHandle(p);

	if (m_previewWindowDX9 != nullptr)
		return m_previewWindowDX9->SetVideoHandle(p);

	return false;

}
void DeckLinkCapture::SetWindowSize(int x, int y, int width, int height)
{
	if (m_previewWindowGL != nullptr)
		m_previewWindowGL->SetWindowSize(x, y, width, height);
}

void DeckLinkCapture::SetPreviewVideo(bool preview)
{
	m_previewVideo = preview;

	if (m_previewWindowDX9 != nullptr)
		m_previewWindowDX9->SetPreviewVideo(preview);

}

void DeckLinkCapture::Build_H264_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength)
{
	m_enableDownGraph = 1;

	wcscpy(m_multicastIpAddress, IpAddress);
	m_multicastPort = port;
	wcscpy(m_ipInterfaceAddress, IpInterfaceAddress);
	
	m_bitrate = bitrate;
	m_goplength = goplength;

}

void DeckLinkCapture::Build_H264QS_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength)
{
	m_enableDownGraph = 2;

	wcscpy(m_multicastIpAddress, IpAddress);
	m_multicastPort = port;
	wcscpy(m_ipInterfaceAddress, IpInterfaceAddress);

	m_bitrate = bitrate;
	m_goplength = goplength;

}

int DeckLinkCapture::BuildGraphs()
{
	if (m_enableDownGraph > 0)
	{
		m_ds = new DSGraphUtils();
		if (m_enableDownGraph == 1)
			return m_ds->Build_H264_TransportMux_Network(m_multicastIpAddress, m_multicastPort, m_ipInterfaceAddress, m_bitrate , m_goplength);

		if (m_enableDownGraph == 2)
			return m_ds->Build_H264QS_TransportMux_Network(m_multicastIpAddress, m_multicastPort, m_ipInterfaceAddress, m_bitrate, m_goplength);
	}
	return 1;
}
 
int DeckLinkCapture::RunGraph()
{
	if (m_enableDownGraph > 0)
	{
		return m_ds->Play();
	}
	return 1;
}