#include "stdafx.h"
#include "DSGraphUtils.h"


DSGraphUtils::DSGraphUtils()
{

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

	CComPtr<ILiveSource> pFrameLiveSourceInterface;
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

HRESULT DSGraphUtils::Build_H264_TransportMux_Network()
{
	HRESULT hr = S_OK;

	if ((hr = InitializeGraph()) != S_OK)
		return hr;

	hr = AddFrameRowSourceFilter();
	if (hr != S_OK)
		return hr;

	return hr;
}