#include "LiveSource.h"
#include "Utils.h"

CLiveSource::CLiveSource(LPUNKNOWN pUnk, HRESULT* phr)
	: CBaseFilter(LIVE_FILTER_NAME, pUnk, &m_critSec, CLSID_CLiveSource)
{
	m_pOutputPin = new CLiveSourceStream(this, &m_critSec, phr); 

	if (phr)
	{
		if (m_pOutputPin == NULL)
			*phr = E_OUTOFMEMORY;
		else
			*phr = S_OK;
	}  
}

CLiveSource::~CLiveSource(void)
{
	delete m_pOutputPin;
}

int CLiveSource::GetPinCount()
{
	CAutoLock cAutoLock(&m_critSec);

	return 1;
}

CBasePin* CLiveSource::GetPin(int n)
{
	CAutoLock cAutoLock(&m_critSec);

	return m_pOutputPin;
}

CUnknown* WINAPI CLiveSource::CreateInstance(LPUNKNOWN pUnk, HRESULT *phr)
{
	CUnknown* pNewFilter = new CLiveSource(pUnk, phr);

	if (phr)
	{
		if (pNewFilter == NULL) 
			*phr = E_OUTOFMEMORY;
		else
			*phr = S_OK;
	}

	return pNewFilter;
}

STDMETHODIMP CLiveSource::NonDelegatingQueryInterface(REFIID riid, void **ppv)
{
	CheckPointer(ppv, E_POINTER);

	if(riid == IID_ILiveSource) 
	{
		return GetInterface((ILiveSource*) m_pOutputPin, ppv);
	} 
	else if(riid == IID_IAMPushSource)
	{
		return GetInterface((IAMPushSource*) m_pOutputPin, ppv);
	}
	else if(riid == IID_IAMFilterMiscFlags)
	{
		return GetInterface((IAMFilterMiscFlags*) this, ppv);
	}
	else 
	{
		return CBaseFilter::NonDelegatingQueryInterface(riid, ppv);
	}
}


//=============================================================================



CLiveSourceStream::CLiveSourceStream(CBaseFilter *pFilter, CCritSec *pLock, HRESULT *phr)
	: CBaseOutputPin(LIVE_FILTER_NAME, pFilter, pLock, phr, LIVE_OUTPIN_NAME),
	m_frameRate(0), m_rtFrameRate(0), m_lastFrame(0)
{
	m_bmpInfo.biSize = sizeof(BITMAPINFOHEADER);
	m_bmpInfo.biCompression = BI_RGB;
	m_bmpInfo.biBitCount = 32;
	m_bmpInfo.biHeight = 1080;
	m_bmpInfo.biWidth = 1920;
	m_bmpInfo.biPlanes = 1;
	m_bmpInfo.biSizeImage = GetBitmapSize(&m_bmpInfo);	
	m_bmpInfo.biClrImportant = 0;
	m_bmpInfo.biClrUsed = 0;
	m_bmpInfo.biXPelsPerMeter = 0;
	m_bmpInfo.biYPelsPerMeter = 0;
	m_pintype = 1;
}

CLiveSourceStream::~CLiveSourceStream()
{

}

HRESULT CLiveSourceStream::CheckMediaType(const CMediaType* pmt)
{
	CheckPointer(pmt, E_POINTER);

	return S_OK;

	if(pmt->majortype != MEDIATYPE_Video)
	{
		return E_INVALIDARG;
	}
	if(pmt->subtype != GetBitmapSubtype(&m_bmpInfo))
	{
		return E_INVALIDARG;
	}
	if(pmt->formattype != FORMAT_VideoInfo) 
	{
		return E_INVALIDARG; 
	}

	return S_OK;
}


HRESULT CLiveSourceStream::GetMediaType(int iPosition, CMediaType* pmt)
{
	CAutoLock cAutoLock(m_pLock);

	if(iPosition < 0)
	{
		return E_INVALIDARG;
	}

	if(iPosition >= 1)
	{
		return VFW_S_NO_MORE_ITEMS;
	}

	VIDEOINFOHEADER* vih = (VIDEOINFOHEADER*)pmt->AllocFormatBuffer(sizeof(VIDEOINFOHEADER));
	if(!vih)
	{
		return E_OUTOFMEMORY;
	}

	vih->bmiHeader = m_bmpInfo;
	if(m_frameRate != 0)
	{
		vih->AvgTimePerFrame = UNITS / m_frameRate;
	}
	else
	{
		vih->AvgTimePerFrame = 0;
	}

	if (m_pintype == 1)
	{
		pmt->SetFormat((BYTE*)vih, sizeof(VIDEOINFOHEADER));
		pmt->SetType(&MEDIATYPE_Video);
		pmt->SetFormatType(&FORMAT_VideoInfo);
		pmt->SetTemporalCompression(FALSE);

		const GUID SubTypeGUID = GetBitmapSubtype(&m_bmpInfo);
		pmt->SetSubtype(&SubTypeGUID);
		pmt->SetSampleSize(m_bmpInfo.biSizeImage);
	} else 
	if (m_pintype == 0)
	{

		pmt->SetFormat((BYTE*)vih, sizeof(VIDEOINFOHEADER));
		pmt->SetType(&MEDIATYPE_Video);
		pmt->SetFormatType(&FORMAT_VideoInfo);
		pmt->SetTemporalCompression(FALSE);
		pmt->SetSubtype(&MEDIASUBTYPE_UYVY);

		vih->AvgTimePerFrame = FPS_2997;
		vih->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		vih->bmiHeader.biWidth = 1920;
		vih->bmiHeader.biHeight = 1080;
		vih->bmiHeader.biPlanes = 1;
		vih->bmiHeader.biBitCount = 16;// 16;
		vih->bmiHeader.biCompression = 'YVYU';
		vih->bmiHeader.biSizeImage = pmt->lSampleSize = vih->bmiHeader.biWidth * vih->bmiHeader.biHeight * vih->bmiHeader.biBitCount / 8;
		vih->dwBitRate = vih->bmiHeader.biSizeImage * (DWORD)((float)UNITS / vih->AvgTimePerFrame) * 8;

	}
	
	return S_OK;
}

HRESULT CLiveSourceStream::DecideBufferSize(IMemAllocator *pAlloc, ALLOCATOR_PROPERTIES *ppropInputRequest)
{
	CheckPointer(pAlloc,E_POINTER);
	CheckPointer(ppropInputRequest,E_POINTER);

	CAutoLock cAutoLock(m_pLock);
	HRESULT hr = NOERROR;

	ppropInputRequest->cBuffers = 1;
	ppropInputRequest->cbBuffer = m_bmpInfo.biSizeImage;

	ASSERT(ppropInputRequest->cbBuffer);

	ALLOCATOR_PROPERTIES Actual;
	hr = pAlloc->SetProperties(ppropInputRequest,&Actual);
	if(FAILED(hr))
	{
		return hr;
	}

	if(Actual.cbBuffer < ppropInputRequest->cbBuffer)
	{
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CLiveSourceStream::SetBitmapInfo(BITMAPINFOHEADER& bInfo)
{
	if(bInfo.biHeight == 0 || bInfo.biWidth == 0 || bInfo.biBitCount == 0)
	{
		return E_INVALIDARG;
	}

	m_bmpInfo = bInfo;
	return S_OK;
}

STDMETHODIMP CLiveSourceStream::AddFrame(HBITMAP hBmp)
{
	CAutoLock cAutoLock(m_pLock);

	int iSize = 0;
	IMediaSample* pSample = NULL;
	BYTE* pData = NULL;

	HRESULT hr = GetMediaSample(&pSample);
	if(FAILED(hr))
	{
		return hr;
	}

	hr = pSample->GetPointer(&pData);
	if(FAILED(hr))
	{
		pSample->Release();
		return hr;
	}

	hr = GetPixelData(hBmp, &pData, &iSize);
	if(FAILED(hr))
	{
		pSample->Release();
		return hr;
	}

	hr = pSample->SetActualDataLength(iSize);
	if(FAILED(hr))
	{
		pSample->Release();
		return hr;
	}

	hr = pSample->SetSyncPoint(TRUE);
	if(FAILED(hr))
	{
		pSample->Release();
		return hr;
	}
	
	hr = this->Deliver(pSample);
	pSample->Release();

	return hr;
}

STDMETHODIMP CLiveSourceStream::AddFrame(BYTE* pBuffer, DWORD size)
{
	CAutoLock cAutoLock(m_pLock);

	if(size > m_bmpInfo.biSizeImage)
	{
		return E_INVALIDARG;
	}

	IMediaSample* pSample = NULL;
	BYTE* pData = NULL;

	HRESULT hr = GetMediaSample(&pSample);
	if(FAILED(hr))
	{
		return hr;
	}

	hr = pSample->GetPointer(&pData);
	if(FAILED(hr))
	{
		pSample->Release();
		return hr;
	}

	memcpy(pData, pBuffer, size);

	hr = pSample->SetActualDataLength(size);
	if(FAILED(hr))
	{
		pSample->Release();
		return hr;
	}

	hr = pSample->SetSyncPoint(TRUE);
	if(FAILED(hr))
	{
		pSample->Release();
		return hr;
	}
	
	hr = this->Deliver(pSample);
	pSample->Release();

	return hr;
}

HRESULT CLiveSourceStream::GetMediaSample(IMediaSample** ppSample)
{
	REFERENCE_TIME rtStart = m_lastFrame;
	m_lastFrame += m_rtFrameRate;

	return this->GetDeliveryBuffer(ppSample, &rtStart, &m_lastFrame, 0);
}

STDMETHODIMP CLiveSourceStream::SetFrameRate(int frameRate)
{
	if(frameRate < 0 || frameRate > 30)
	{
		return E_INVALIDARG;
	}

	m_frameRate = frameRate;
	m_rtFrameRate = UNITS / m_frameRate;
	return S_OK;
}

HRESULT CLiveSourceStream::GetPixelData(HBITMAP hBmp, BYTE** ppData, int* pSize)
{
	ASSERT(hBmp);

	BITMAP bmp = {0};
	int res = ::GetObject(hBmp, sizeof(BITMAP), &bmp);
	if(res != sizeof(BITMAP))
	{
		return E_FAIL;
	}

	if(bmp.bmBitsPixel != m_bmpInfo.biBitCount ||
		bmp.bmHeight != m_bmpInfo.biHeight ||
		bmp.bmWidth != m_bmpInfo.biWidth)
	{
		return E_INVALIDARG;
	}

	*pSize = bmp.bmWidthBytes * bmp.bmHeight;
	memcpy(*ppData, bmp.bmBits, *pSize);

	return S_OK;
}

STDMETHODIMP CLiveSourceStream::GetMaxStreamOffset(REFERENCE_TIME *prtMaxOffset)
{
	*prtMaxOffset = 0;
	return S_OK;
} 

STDMETHODIMP CLiveSourceStream::GetPushSourceFlags(ULONG *pFlags)
{ 
	*pFlags = 0;
	return S_OK;
}

STDMETHODIMP CLiveSourceStream::GetStreamOffset(REFERENCE_TIME *prtOffset)
{
	*prtOffset = 0;
	return S_OK;
} 

STDMETHODIMP CLiveSourceStream::SetMaxStreamOffset(REFERENCE_TIME rtMaxOffset)
{
	return E_NOTIMPL;
}

STDMETHODIMP CLiveSourceStream::SetPushSourceFlags(ULONG Flags)
{
	return E_NOTIMPL;
} 

STDMETHODIMP CLiveSourceStream::SetStreamOffset(REFERENCE_TIME rtOffset)
{
	return E_NOTIMPL;
} 

STDMETHODIMP CLiveSourceStream::GetLatency(REFERENCE_TIME *prtLatency)
{ 
	*prtLatency = m_rtFrameRate;
	return S_OK;
}

STDMETHODIMP CLiveSourceStream::Notify(IBaseFilter * pSender, Quality q)
{
	if(q.Proportion <= 0)
	{
		m_rtFrameRate = 1000;        
	}
	else
	{
		m_rtFrameRate = m_rtFrameRate * 1000 / q.Proportion;
		if(m_rtFrameRate > 1000)
		{
			m_rtFrameRate = 1000;    
		}
		else if(m_rtFrameRate < 30)
		{
			m_rtFrameRate = 30;      
		}
	}

	if(q.Late > 0)
	{
		m_rtFrameRate += q.Late;
	}

	return S_OK;
}