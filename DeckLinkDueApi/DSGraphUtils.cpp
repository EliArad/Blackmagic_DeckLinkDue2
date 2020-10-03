#include "stdafx.h"
#include "DSGraphUtils.h"
#include "ecommon.h"
#include "ModuleConfig_h.h"
#include "empegmux.h"
#include "eqsenc.h"
#include "eavcenc.h"
#include "ecsc2.h"



DSGraphUtils::DSGraphUtils()
{
	m_state = STATE_STOPPED;
	m_abort = false;
}


DSGraphUtils::~DSGraphUtils()
{
}


HRESULT DSGraphUtils::InitializeGraph()
{
	HRESULT hr = S_OK;

	TearDownGraph();
	m_abort = false;

	 
	// Use its member function CoCreateInstance to
	// create the COM object and obtain the IGraphBuilder pointer.
	//hr = m_pGraph.CoCreateInstance(CLSID_FilterGraph);

	// Create the Filter Graph Manager.
	hr = CoCreateInstance(
		CLSID_FilterGraph,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder,
		(void**)&m_pGraph
	);



	// Query for graph interfaces.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IMediaControl, (void**)&m_pControl);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IMediaEventEx, (void**)&m_pEvent);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
	}
	 
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	// Add the video renderer to the graph
	if (SUCCEEDED(hr))
	{

	}

#if 0 
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IBasicAudio, (void**)&m_pAudio);
	}
#endif 
	

	return hr;
}

HRESULT DSGraphUtils::SetNotifyEvent(HWND handle)
{
	m_hwndEvent = handle;
	// Set up event notification.
	
	HRESULT hr = m_pEvent->SetNotifyWindow((OAHWND)m_hwndEvent, m_EventMsg, NULL);

	return hr;
}

void DSGraphUtils::TearDownGraph()
{
	// Stop sending event messages
	if (m_pEvent)
	{
		m_pEvent->SetNotifyWindow((OAHWND)NULL, NULL, NULL);
	}
	 
	m_state = STATE_CLOSED;
	  
}

void DSGraphUtils::Close()
{
	m_abort = true;
	Sleep(1000);

	Stop();

	if (m_pGraph == NULL)
		return;

#if 0 
	if (m_pVideo != NULL)
		m_pVideo->FinalizeGraph(m_pGraph);
#endif 


	// Enumerate the filters in the graph.
	CComPtr<IEnumFilters> pEnum = NULL;
	HRESULT hr = m_pGraph->EnumFilters(&pEnum);
	if (SUCCEEDED(hr))
	{
		IBaseFilter *pFilter = NULL;
		while (S_OK == pEnum->Next(1, &pFilter, NULL))
		{
			FILTER_INFO FilterInfo;
			hr = pFilter->QueryFilterInfo(&FilterInfo);
			// Remove the filter.
			//m_pGraph->RemoveFilter(pFilter);
			RemoveFilter(pFilter);
			// Reset the enumerator.
			pEnum->Reset();
			pFilter->Release();
		}
		//pEnum->Release();
	}

	TearDownGraph();

	CoUninitialize();

}


HRESULT DSGraphUtils::DisconnectPin(IPin *pPin)
{
	if (!m_pGraph || !pPin)
	{
		return E_POINTER;
	}

	HRESULT hr = S_OK;
	IPin *pPinTo = NULL;

	hr = pPin->ConnectedTo(&pPinTo);
	if (hr == VFW_E_NOT_CONNECTED)
	{
		// This pin is not connected.
		return S_OK; // no-op
	}

	// Disconnect the first pin.

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->Disconnect(pPin);
	}
	if (SUCCEEDED(hr))
	{
		// Disconnect the other pin.
		hr = m_pGraph->Disconnect(pPinTo);
	}

	SAFE_RELEASE(pPinTo);
	return hr;
}


HRESULT DSGraphUtils::RemoveFilter(IBaseFilter *pFilter)
{
	if (!m_pGraph || !pFilter)
	{
		return E_POINTER;
	}

	HRESULT hr = S_OK;
	IEnumPins *pEnum = NULL;
	IPin *pPin = NULL;

	CHECK_HR(hr = pFilter->EnumPins(&pEnum));

	// Disconnect all the pins
	while (S_OK == pEnum->Next(1, &pPin, 0))
	{
		CHECK_HR(hr = DisconnectPin(pPin));
		SAFE_RELEASE(pPin);
	}

	CHECK_HR(hr = m_pGraph->RemoveFilter(pFilter));

done:
	SAFE_RELEASE(pPin);
	SAFE_RELEASE(pEnum);
	return hr;
}

HRESULT DSGraphUtils::AddFrameRowSourceFilter()
{

	// {7102AE91-2434-445B-8276-5995EB968D5C}
	static const GUID IID_ILiveSource =
	{ 0x7102ae91, 0x2434, 0x445b,{ 0x82, 0x76, 0x59, 0x95, 0xeb, 0x96, 0x8d, 0x5c } };


	// {017F358E-2E3F-44E7-ABA4-F6891C88E10F}
	static const GUID CLSID_CLiveSource =
	{ 0x17f358e, 0x2e3f, 0x44e7,{ 0xab, 0xa4, 0xf6, 0x89, 0x1c, 0x88, 0xe1, 0xf } };


	HRESULT hr = AddFilterByCLSID(m_pGraph, CLSID_CLiveSource, &pFrameSourceFilter, L"Frame Live Source Filter");
	if (FAILED(hr))
	{
		return -5918227;
	}

	// {CF24BB08-37C8-44BD-9A12-683B118F290A}
	static const GUID IID_IBoutechLiveSource =
	{ 0xcf24bb08, 0x37c8, 0x44bd,{ 0x9a, 0x12, 0x68, 0x3b, 0x11, 0x8f, 0x29, 0xa } };

	
	hr = pFrameSourceFilter->QueryInterface(IID_ILiveSource, (void **)&pFrameLiveSourceInterface);
 
	 

	return hr;

}

///////////////////////////////////////////////////////////////////////
// Name: AddFilterByCLSID
// Desc: Create a filter by CLSID and add it to the graph.
///////////////////////////////////////////////////////////////////////

HRESULT DSGraphUtils::AddFilterByCLSID(
	IGraphBuilder *pGraph,          // Pointer to the Filter Graph Manager.
	const GUID& clsid,              // CLSID of the filter to create.
	IBaseFilter **ppF,              // Receives a pointer to the filter.
	LPCWSTR wszName	           // A name for the filter (can be NULL).
)
{
	if (!pGraph || !ppF)
	{
		return E_POINTER;
	}

	*ppF = 0;

	IBaseFilter *pFilter = NULL;
	HRESULT hr = S_OK;

	CHECK_HR(hr = CoCreateInstance(
		clsid,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IBaseFilter,
		(void**)&pFilter));

	CHECK_HR(hr = pGraph->AddFilter(pFilter, wszName));

	*ppF = pFilter;
	(*ppF)->AddRef();

done:
	SAFE_RELEASE(pFilter);
	return hr;
}

HRESULT DSGraphUtils::Build_H264_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength)
{
	HRESULT hr = S_OK;

	if ((hr = InitializeGraph()) != S_OK)
		return hr;

	hr = AddFrameRowSourceFilter();
	if (hr != S_OK)
		return hr;
	 

	hr = AddElecardAVCEncoder(bitrate, goplength);
	if (hr != S_OK)
		return hr;

	PIN_INFO pininfo;
	CComPtr<IPin> pEncoderInPin;
	GetPin(pVideoEncoder, PIN_DIRECTION::PINDIR_INPUT, &pEncoderInPin);
	hr = pEncoderInPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -18332;
	}

	 
	CComPtr<IPin> pFrameSourceOutPin;
	GetPin(pFrameSourceFilter, PIN_DIRECTION::PINDIR_OUTPUT, &pFrameSourceOutPin);
	hr = pFrameSourceOutPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -18132;
	}

	hr = pGraph2->Connect(pFrameSourceOutPin, pEncoderInPin);
	if (FAILED(hr))
	{
		return -172123;
	}

	hr = AddElecardMux();


	CComPtr<IPin> pMuxInPin;
	CComPtr<IPin> pMuxOutPin;
	GetPin(pElecardMpegMux, PIN_DIRECTION::PINDIR_INPUT, &pMuxInPin);
	hr = pMuxInPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -127767;
	}

	GetPin(pElecardMpegMux, PIN_DIRECTION::PINDIR_OUTPUT, &pMuxOutPin);
	hr = pMuxOutPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -12137;
	}
  
	CComPtr<IPin> pEncoderOutPin;
	GetPin(pVideoEncoder, PIN_DIRECTION::PINDIR_OUTPUT, &pEncoderOutPin);
	hr = pEncoderOutPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -12318;
	}

	hr = pGraph2->Connect(pEncoderOutPin, pMuxInPin);
	if (FAILED(hr))
	{
		return -17322;
	}

	 
	hr = AddMulticastNetwordSender(IpAddress, port, IpInterfaceAddress);
	if (FAILED(hr))
	{
		return -57322;
	}


	CComPtr<IPin> pSenderInPin;
	GetPin(pRemoteClientSender, PIN_DIRECTION::PINDIR_INPUT, &pSenderInPin);
	hr = pSenderInPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -16647;
	}

	hr = pGraph2->Connect(pMuxOutPin, pSenderInPin);
	if (FAILED(hr))
	{
		return -1723251;
	} 


	m_state = STATE_STOPPED;

	return hr;
}

HRESULT DSGraphUtils::AddMulticastNetwordSender(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress)
{
	// {FF3FCECA-C9D9-4f11-9E76-B571BC8565B5}
	static const GUID CLSID_BoutechMulticastNetworkSender =
	{ 0xBA3fce19, 0xF9d9, 0x4f12,{ 0x4e, 0x56, 0x65, 0x71, 0xbc, 0x85, 0x15, 0x25 } };

	HRESULT hr = AddFilterByCLSID(m_pGraph, CLSID_BoutechMulticastNetworkSender, &pRemoteClientSender, L"Multicast network sender");
	if (FAILED(hr))
	{
		return -591822;
	}

	// {3645E33E-25DE-4B6B-A377-B9486659C560}
	static const GUID IID_IBoutechUDPMulticastSender =
	{ 0x3645e33e, 0x25de, 0x4b6b,{ 0xa3, 0x77, 0xb9, 0x48, 0x66, 0x59, 0xc5, 0x60 } };

	CComPtr<IBoutechUDPMulticastSender> pClientIface;
	hr = pRemoteClientSender->QueryInterface(IID_IBoutechUDPMulticastSender, (void**)&pClientIface);
	if (FAILED(hr))
		return -62324;


	pClientIface->ConfigureMulticastSender(IpAddress, port, NULL);

	return hr;
}

HRESULT DSGraphUtils::AddElecardAVCEncoder(unsigned int bitrate, int goplength)
{

	static const GUID CLSID_AVCEncoder =
	{ 0xe09edec9, 0x5e3, 0x4aaa,{ 0x95, 0x54, 0x14, 0x9f, 0x94, 0xc2, 0x47, 0x80 } };

	HRESULT hr = AddFilterByCLSID(m_pGraph, CLSID_AVCEncoder, &pVideoEncoder, L"Elecard AVC Video Encoder");
	if (FAILED(hr))
	{
		return -19025;
	}

	ActivateFilter(pVideoEncoder);

	if ((hr = SetElecardEncoderParameter(bitrate, 0, goplength)) != S_OK)
	{
		return hr;
	} 

	return hr;
}

HRESULT DSGraphUtils::SetElecardEncoderParameter(int bitrate, int maxBitrate, int maxGopLength)
{
	HRESULT hr = S_OK;
	CComQIPtr<IModuleConfig> mc_video_encoder(pVideoEncoder);
	CComVariant varEncBitrate;
	varEncBitrate.vt = VT_INT;
	varEncBitrate.intVal = bitrate;
	hr = mc_video_encoder->SetValue(&EMC_BITRATE_AVG, &varEncBitrate);

	if (maxBitrate == 0)
		maxBitrate = bitrate * 3 / 2;


	CComVariant varEncMaxBitrate;
	varEncMaxBitrate.vt = VT_INT;
	varEncMaxBitrate.intVal = maxBitrate;
	hr = mc_video_encoder->SetValue(&EMC_BITRATE_MAX, &varEncMaxBitrate);
	if (FAILED(hr))
	{
		return -376292;
	}



	static const GUID EMC_GOP_MIN_LENGTH =
	{ 0x3bf71658, 0x5ed5, 0x4bbc,{ 0x99, 0xf8, 0xdf, 0x5, 0x1a, 0x66, 0xd0, 0x4b } };

	CComVariant varminGopLength;
	varminGopLength.vt = VT_INT;
	varminGopLength.intVal = 1;
	hr = mc_video_encoder->SetValue(&EMC_GOP_MIN_LENGTH, &varminGopLength);
	if (FAILED(hr))
	{
		return -376293;
	}



	CComVariant varmaxGopLength;
	varmaxGopLength.vt = VT_INT;
	varmaxGopLength.intVal = maxGopLength;
	hr = mc_video_encoder->SetValue(&EMC_GOP_MAX_LENGTH, &varmaxGopLength);
	if (FAILED(hr))
	{
		return -376294;
	}


	hr = mc_video_encoder->CommitChanges(NULL);
	if (FAILED(hr))
	{
		return -376295;
	}

	return hr;
}

HRESULT DSGraphUtils::ActivateFilter(IBaseFilter *filter)
{

	//b9d44b32-d34a-11e8-86ff-003048592e16
	static const GUID KEY_GUID = { 0xb9d44b32, 0xd34a, 0x11e8,{ 0x86, 0xFF,  0x00 , 0x30 ,0x48 ,0x59 ,0x2e, 0x16 } };

	HRESULT hr = S_OK;

	IModuleConfig* IMC;
	hr = filter->QueryInterface(&IMC);
	if (SUCCEEDED(hr))
	{
		hr = IMC->SetValue(&KEY_GUID, NULL);
		IMC->Release();
	}
	return hr;

}

HRESULT DSGraphUtils::GetPin(IBaseFilter *pFilter, PIN_DIRECTION PinDir, IPin **ppPin, int num)
{
	IEnumPins *pEnum = NULL;
	IPin *     pPin = NULL;
	HRESULT    hr;

	if (ppPin == NULL)
	{
		return E_POINTER;
	}

	int count = 0;

	hr = pFilter->EnumPins(&pEnum);
	if (FAILED(hr))
	{
		return hr;
	}
	while (pEnum->Next(1, &pPin, 0) == S_OK)
	{
		PIN_DIRECTION PinDirThis;
		hr = pPin->QueryDirection(&PinDirThis);
		if (FAILED(hr))
		{
			SAFE_RELEASE(pPin);
			SAFE_RELEASE(pEnum);
			return hr;
		}
		if (PinDir == PinDirThis && count == num)
		{
			// Found a match. Return the IPin pointer to the caller.
			*ppPin = pPin;
			SAFE_RELEASE(pEnum);
			return S_OK;
		}
		if (PinDir == PinDirThis)
			count++;
		// Release the pin for the next time through the loop.
		SAFE_RELEASE(pPin);
	}
	// No more pins. We did not find a match.
	SAFE_RELEASE(pPin);
	SAFE_RELEASE(pEnum);
	return E_FAIL;
}

IPin *DSGraphUtils::GetPin(IBaseFilter *Filter, CString PinName, PIN_DIRECTION  direction)
{

	IEnumPins     *pEnumPins;
	ULONG          ul;
	PIN_DIRECTION  pd;
	CString pin_name = L"";
	int counter = 0;
	HRESULT hr = Filter->EnumPins(&pEnumPins);
	PIN_INFO    pin_info;
	IPin *requestedPin = NULL;
	while ((pin_name != PinName) && (counter != 50)) {
		// Get the Sigma Splitter video output pin
		hr = pEnumPins->Next(1, &requestedPin, &ul);
		if ((S_OK != hr) && (0 == ul))
			return NULL;
		requestedPin->QueryDirection(&pd);
		if (pd == direction) {
			const_cast<IPin*>(requestedPin)->QueryPinInfo(&pin_info);
			pin_info.pFilter->Release();
			pin_name = pin_info.achName;
		}
		counter++;
	}
	pEnumPins->Release();

	return requestedPin;
}

HRESULT DSGraphUtils::AddElecardMux()
{
	// {0FD7F9F6-747D-46cf-AC0B-FA9DAE4F6299}
	static const GUID CLSID_EMPEGMUXER = {
		0xfd7f9f6, 0x747d, 0x46cf,{ 0xac, 0xb, 0xfa, 0x9d, 0xae, 0x4f, 0x62, 0x99 } };


	HRESULT hr = AddFilterByCLSID(m_pGraph, CLSID_EMPEGMUXER, &pElecardMpegMux, L"Elecard MPEG2 Mux");
	if (FAILED(hr))
	{
		return -511212;
	}
	CComVariant var;
	CComQIPtr<IModuleConfig> mcMuxer(pElecardMpegMux);


	//if (enableLiveMode == true)
	{
		var.vt = VT_INT; var.intVal = 1;
		hr = mcMuxer->SetValue(&EMUX_LiveMode, &var);
		if (FAILED(hr))
		{
			return -51982;
		}
	}

	//if (enableLowDelay == true)
	{
		var.vt = VT_INT; var.intVal = 1;
		hr = mcMuxer->SetValue(&EMUX_TS_LowDelay, &var);
		if (FAILED(hr))
		{
			return -51983;
		}
	}
	//if (enableLowDelay == true || enableLiveMode == true)
	hr = mcMuxer->CommitChanges(0);
	if (FAILED(hr))
	{
		return -511242;
	}

	return hr;
}


HRESULT DSGraphUtils::Play(int tries)
{
	if (m_state != STATE_PAUSED && m_state != STATE_STOPPED)
	{
		return -78292;
	}

	HRESULT hr;
	for (int i = 0; i < tries; i++)
	{
		hr = m_pControl->Run();
		if (hr == S_OK)
			break;
	}
	if (FAILED(hr))
	{
		return -6656;
	}

	if (SUCCEEDED(hr))
	{
		m_state = STATE_RUNNING;
	}

	return hr;
}

HRESULT DSGraphUtils::Pause()
{
	if (m_state != STATE_RUNNING)
	{
		return VFW_E_WRONG_STATE;
	}


	HRESULT hr = m_pControl->Pause();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_PAUSED;
	}

	return hr;
}


HRESULT DSGraphUtils::Stop()
{
	if (m_state != STATE_RUNNING && m_state != STATE_PAUSED)
	{
		return VFW_E_WRONG_STATE;
	}

	HRESULT hr = m_pControl->Stop();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	return hr;
}



HRESULT DSGraphUtils::Build_H264QS_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength)
{
	HRESULT hr = S_OK;

	if ((hr = InitializeGraph()) != S_OK)
		return hr;

	hr = AddFrameRowSourceFilter();
	if (hr != S_OK)
		return hr;
	 
	PIN_INFO pininfo;
	CComPtr<IPin> pFrameSourceOutPin;
	GetPin(pFrameSourceFilter, PIN_DIRECTION::PINDIR_OUTPUT, &pFrameSourceOutPin);
	hr = pFrameSourceOutPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -19132;
	}
	 

	hr = AddElecardColorSpaceConverter2();
	if (hr != S_OK)
		return hr;
	 
	CComPtr<IPin> pSpaceConverterInPin;
	GetPin(pColorSpaceConverter2, PIN_DIRECTION::PINDIR_INPUT, &pSpaceConverterInPin);
	hr = pSpaceConverterInPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -193376;
	}


	hr = pGraph2->Connect(pFrameSourceOutPin, pSpaceConverterInPin);
	if (FAILED(hr))
	{
		return -192123;
	}


	CComPtr<IPin> pSpaceConverterOutPin;
	GetPin(pColorSpaceConverter2, PIN_DIRECTION::PINDIR_OUTPUT, &pSpaceConverterOutPin);
	hr = pSpaceConverterOutPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -193376;
	}
	

	hr = AddElecardAVCQSEncoder(bitrate, goplength);
	if (hr != S_OK)
		return hr;

	 
	CComPtr<IPin> pEncoderInPin;
	GetPin(pVideoEncoder, PIN_DIRECTION::PINDIR_INPUT, &pEncoderInPin);
	hr = pEncoderInPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -19332;
	}
	 

	hr = pGraph2->Connect(pSpaceConverterOutPin, pEncoderInPin);
	if (FAILED(hr))
	{
		return -193322;
	}


	CComPtr<IPin> pEncoderOutPin;
	GetPin(pVideoEncoder, PIN_DIRECTION::PINDIR_OUTPUT, &pEncoderOutPin);
	hr = pEncoderOutPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -11318;
	}

	
	hr = AddElecardMux();


	CComPtr<IPin> pMuxInPin;
	CComPtr<IPin> pMuxOutPin;
	GetPin(pElecardMpegMux, PIN_DIRECTION::PINDIR_INPUT, &pMuxInPin);
	hr = pMuxInPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -1547767;
	}

	hr = pGraph2->Connect(pEncoderOutPin, pMuxInPin);
	if (FAILED(hr))
	{
		return -12322;
	}
	 

	GetPin(pElecardMpegMux, PIN_DIRECTION::PINDIR_OUTPUT, &pMuxOutPin);
	hr = pMuxOutPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -171137;
	}

	 

	hr = AddMulticastNetwordSender(IpAddress, port, IpInterfaceAddress);
	if (FAILED(hr))
	{
		return -153112;
	}


	CComPtr<IPin> pSenderInPin;
	GetPin(pRemoteClientSender, PIN_DIRECTION::PINDIR_INPUT, &pSenderInPin);
	hr = pSenderInPin->QueryPinInfo(&pininfo);
	pininfo.pFilter->Release();
	if (FAILED(hr))
	{
		return -14447;
	}

	hr = pGraph2->Connect(pMuxOutPin, pSenderInPin);
	if (FAILED(hr))
	{
		return -10023251;
	}


	m_state = STATE_STOPPED;

	return hr;
}

 
HRESULT DSGraphUtils::AddElecardAVCQSEncoder(unsigned int bitrate, int goplength)
{

	HRESULT hr = AddFilterByCLSID(m_pGraph, CLSID_EQSVideoEncoder_AVC, &pVideoEncoder, L"Elecard AVC Video Encoder");
	if (FAILED(hr))
	{
		return -19025;
	}

	ActivateFilter(pVideoEncoder);

	if ((hr = SetElecardEncoderParameter(bitrate, 0, goplength)) != S_OK)
	{
		return hr;
	}

	return hr;
}

HRESULT DSGraphUtils::AddElecardColorSpaceConverter2()
{

	HRESULT hr = AddFilterByCLSID(m_pGraph, CLSID_ECSC2, &pColorSpaceConverter2, L"Elecard Color Space Converter 2");
	if (FAILED(hr))
	{
		return -1925;
	}
	 
	CComQIPtr<IModuleConfig> mc_spaceConverter(pColorSpaceConverter2);
	CComVariant varEncBitrate;
	varEncBitrate.vt = VT_INT;
	varEncBitrate.intVal = ECSC::SubTypes::eNV12;
	hr = mc_spaceConverter->SetValue(&CSC_FIX_OUTPUT_MEDIA_TYPE, &varEncBitrate);
	if (FAILED(hr))
	{
		return -19254;
	}
	 

	return hr;

}