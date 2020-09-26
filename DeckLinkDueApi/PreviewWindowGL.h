#pragma once

#include <atomic>
#include "DeckLinkAPI_h.h"
#include "Common.h"



class PreviewWindowGL : public IDeckLinkScreenPreviewCallback
{
public:
	PreviewWindowGL();
	virtual ~PreviewWindowGL();

	// Initialise members and OpenGL rendering context
	bool						init();

	// IUnknown
	HRESULT STDMETHODCALLTYPE	QueryInterface(REFIID iid, LPVOID *ppv) override;
	ULONG	STDMETHODCALLTYPE	AddRef() override;
	ULONG	STDMETHODCALLTYPE	Release() override;

	// IDeckLinkScreenPreviewCallback
	HRESULT STDMETHODCALLTYPE	DrawFrame(IDeckLinkVideoFrame* theFrame) override;

	FrameCallback pFrameCallback;
 

	void SetWindowSize(int x, int y, int width, int height);
	void SetFrameCallback(FrameCallback p);
	bool SetVideoHandle(HWND p);

	 
	
private:
	std::atomic<ULONG>						m_refCount;
	CComPtr<IDeckLinkGLScreenPreviewHelper>	m_deckLinkScreenPreviewHelper;
	HGLRC									m_openGLctx;
	HDC										pWindowHDC;
	LONG									m_previewBoxWidth;
	LONG									m_previewBoxHeight;

	bool									InitOpenGL();

	bool									m_init;

	 

};

