#pragma once

#include <strsafe.h>
#include <dshow.h>
#include <atlbase.h>


#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x) { if (x) { x->Release(); x = NULL; } }
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(x) { delete x; x = NULL; }
#endif

#ifndef CHECK_HR
#define CHECK_HR(hr) if (FAILED(hr)) { goto done; }
#endif

enum PlaybackState
{
	STATE_RUNNING,
	STATE_PAUSED,
	STATE_STOPPED,
	STATE_CLOSED
};


MIDL_INTERFACE("7102AE91-2434-445B-8276-5995EB968D5C")
ILiveSource : public IUnknown
{


	virtual HRESULT STDMETHODCALLTYPE AddFrame(HBITMAP hBmp) PURE;
	virtual HRESULT STDMETHODCALLTYPE AddFrame(BYTE* pBuffer, DWORD size) PURE;
	virtual HRESULT STDMETHODCALLTYPE SetBitmapInfo(BITMAPINFOHEADER& bInfo) PURE;
	virtual HRESULT STDMETHODCALLTYPE SetFrameRate(int frameRate) PURE;

};

MIDL_INTERFACE("3645E33E-25DE-4B6B-A377-B9486659C560")
IBoutechUDPMulticastSender: public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE ConfigureMulticastSender(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress) PURE;
};


class DSGraphUtils
{
public:
	DSGraphUtils();
	~DSGraphUtils();
	

	void Close();
	HRESULT Build_H264_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength);
	HRESULT Build_H264QS_TransportMux_Network(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress, unsigned int bitrate, int goplength);
	HRESULT Play(int tries = 1);
	HRESULT Pause();
	HRESULT Stop();

	CComPtr<ILiveSource> GetLiveSourceInterface()
	{
		return pFrameLiveSourceInterface;
	}

private:
	CComPtr<IFilterGraph2> pGraph2;
	CComPtr<IGraphBuilder> m_pGraph;
	CComPtr<IMediaControl> m_pControl;
	CComPtr<IMediaEventEx> m_pEvent;
	CComPtr<IMediaSeeking> m_pSeek;

	CComPtr<ILiveSource> pFrameLiveSourceInterface;

	PlaybackState m_state;
	PlaybackState GetPlaybackState() const { return m_state; }
	HRESULT InitializeGraph();
	void    TearDownGraph();
	HWND			m_hwndEvent;	// Window to receive events
	UINT			m_EventMsg;		// Windows message for graph events

	bool m_abort;

	CComPtr<IBaseFilter> pFrameSourceFilter;
	CComPtr<IBaseFilter> pVideoEncoder;
	CComPtr<IBaseFilter> pElecardMpegMux;
	CComPtr<IBaseFilter> pRemoteClientSender;
	CComPtr<IBaseFilter> pColorSpaceConverter2;
	
	
	

private:

	HRESULT RemoveFilter(IBaseFilter *pFilter);
	HRESULT DisconnectPin(IPin *pPin);

	HRESULT AddFrameRowSourceFilter();

	HRESULT AddFilterByCLSID(
		IGraphBuilder *pGraph,          // Pointer to the Filter Graph Manager.
		const GUID& clsid,              // CLSID of the filter to create.
		IBaseFilter **ppF,              // Receives a pointer to the filter.
		LPCWSTR wszName = NULL          // A name for the filter (can be NULL).
	);

	HRESULT SetNotifyEvent(HWND handle);
	HRESULT AddElecardAVCEncoder(unsigned int bitrate, int goplength);
	HRESULT AddElecardAVCQSEncoder(unsigned int bitrate, int goplength);
	HRESULT SetElecardEncoderParameter(int bitrate, int maxBitrate, int maxGopLength);
	HRESULT AddElecardColorSpaceConverter2();
	HRESULT ActivateFilter(IBaseFilter *filter);
	HRESULT GetPin(IBaseFilter *pFilter, PIN_DIRECTION PinDir, IPin **ppPin, int num = 0);
	IPin *GetPin(IBaseFilter *Filter, CString PinName, PIN_DIRECTION  direction);
	HRESULT AddElecardMux();
	HRESULT AddMulticastNetwordSender(const WCHAR *IpAddress, const int port, const WCHAR *IpInterfaceAddress);

};

