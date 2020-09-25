#include "stdafx.h"
#include "DeckLinkCapture.h"

int DeviceNotification();
 


DeckLinkCapture::DeckLinkCapture()
{

	pFrameCallback = nullptr;
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	
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


bool DeckLinkCapture::StartCapture()
{


	DeviceNotification();
	 
	while (deckLink2 == NULL)
	{
		Sleep(500);
	}


	CComPtr<IDeckLink> deckLink(deckLink2);

	CComPtr<DeckLinkDevice>		newDevice;

	try
	{
		newDevice.Attach(new DeckLinkDevice(deckLink));
	}
	catch (...)
	{
		// Device does not have IDeckLinkInput interface, eg it is a DeckLink Mini Monitor
		return false;
	}

	// Initialise new DeckLinkDevice object
	if (!newDevice->init())
		return false;

	// Register profile callback with newly added device's profile manager
	CComQIPtr<IDeckLinkProfileManager> profileManager(newDevice->getDeckLinkInstance());
	if (profileManager)
		profileManager->SetCallback(m_profileCallback);


	m_previewWindow.Attach(new PreviewWindow());
	if (m_previewWindow->init() == false)
	{
		
	}

	m_previewWindow->SetFrameCallback(pFrameCallback);
	m_previewWindow->SetVideoHandle(pVideoHandle);

	if (newDevice)
	{
		if (newDevice->startCapture(BMDDisplayMode::bmdModeNTSC , m_previewWindow, true) == true)
		{
			return true;
		}
		else
		{
			m_selectedDevice->stopCapture();
			return false;				
		}
	}
}

bool DeckLinkCapture::StopCapture()
{
	if (m_selectedDevice)
		m_selectedDevice->stopCapture();

	return true;
}


bool DeckLinkCapture::SetFrameCallback(FrameCallback p)
{
	pFrameCallback = p;
	return true;
}

void DeckLinkCapture::SetVideoHandle(HWND p)
{
	pVideoHandle = p;
	if (m_previewWindow != nullptr)
		m_previewWindow->SetVideoHandle(p);

}
void DeckLinkCapture::SetWindowSize(int x, int y, int width, int height)
{
	if (m_previewWindow != nullptr)
		m_previewWindow->SetWindowSize(x, y, width, height);
}


