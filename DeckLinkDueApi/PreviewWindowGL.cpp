
#include "stdafx.h"
#include <gl/gl.h>
#include "PreviewWindowGL.h"

PreviewWindowGL::PreviewWindowGL() :
	m_refCount(1), 
	m_deckLinkScreenPreviewHelper(nullptr), 
	m_openGLctx(nullptr),
	m_previewBoxWidth(0),
	m_previewBoxHeight(0)
{
	 
	m_init = false;
	pFrameCallback = nullptr;
}

PreviewWindowGL::~PreviewWindowGL()
{

	pFrameCallback = NULL;
	if (m_openGLctx)
	{
		wglDeleteContext(m_openGLctx);
		m_openGLctx = nullptr;
	}
	 
}

bool PreviewWindowGL::init()
{
	  

	// Create the DeckLink screen preview helper
	if (CoCreateInstance(CLSID_CDeckLinkGLScreenPreviewHelper, NULL, CLSCTX_ALL, IID_IDeckLinkGLScreenPreviewHelper, (void**)&m_deckLinkScreenPreviewHelper) != S_OK)
		return false;

	return true;
} 

bool PreviewWindowGL::InitOpenGL()
{
	PIXELFORMATDESCRIPTOR	pixelFormatDesc;
	int						pixelFormat;
	bool					result = false;


	if (m_init == true)
		return true;

	//
	// Here, we create an OpenGL context attached to the screen preview box
	// so we can use it later on when we need to draw preview frames.
	 
	// Ensure the preview box DC uses ARGB pixel format
	ZeroMemory(&pixelFormatDesc, sizeof(pixelFormatDesc));
	pixelFormatDesc.nSize = sizeof(pixelFormatDesc);
	pixelFormatDesc.nVersion = 1;
	pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDesc.cColorBits = 32;
	pixelFormatDesc.cDepthBits = 16;
	pixelFormatDesc.cAlphaBits = 8;
	pixelFormatDesc.iLayerType = PFD_MAIN_PLANE;
	pixelFormat = ChoosePixelFormat(pWindowHDC, &pixelFormatDesc);
	if (SetPixelFormat(pWindowHDC, pixelFormat, &pixelFormatDesc) == false)
		return false;

	// Create OpenGL rendering context
	m_openGLctx = wglCreateContext(pWindowHDC);
	if (m_openGLctx == nullptr)
		return false;

	// Make the new OpenGL context the current rendering context so
	// we can initialise the DeckLink preview helper
	if (wglMakeCurrent(pWindowHDC, m_openGLctx) == FALSE)
		return false;

	if (m_deckLinkScreenPreviewHelper->InitializeGL() == S_OK)
		result = true;


	// Reset the OpenGL rendering context
	wglMakeCurrent(nullptr, nullptr);

	m_init = true;
	return result;
}

void PreviewWindowGL::SetFrameCallback(FrameCallback p)
{
	pFrameCallback = p;
}

bool PreviewWindowGL::SetVideoHandle(HWND p)
{
	pWindowHDC = GetDC(p);
	InitOpenGL();

	return true;
}

HRESULT PreviewWindowGL::QueryInterface(REFIID iid, LPVOID *ppv)
{
	HRESULT result = E_NOINTERFACE;

	if (ppv == nullptr)
		return E_INVALIDARG;

	// Initialise the return result
	*ppv = nullptr;

	// Obtain the IUnknown interface and compare it the provided REFIID
	if (iid == IID_IUnknown)
	{
		*ppv = this;
		AddRef();
		result = S_OK;
	}
	else if (iid == IID_IDeckLinkScreenPreviewCallback)
	{
		*ppv = static_cast<IDeckLinkScreenPreviewCallback*>(this);
		AddRef();
		result = S_OK;

	}

	return result;
}

ULONG PreviewWindowGL::AddRef()
{
	return ++m_refCount;
}

ULONG PreviewWindowGL::Release()
{
	ULONG newRefValue = --m_refCount;
	if (newRefValue == 0)
		delete this;

	return newRefValue;
}



HRESULT	PreviewWindowGL::DrawFrame(IDeckLinkVideoFrame* theFrame)
{
 
	// First, pass the frame to the DeckLink screen preview helper
	m_deckLinkScreenPreviewHelper->SetFrame(theFrame);
	int width = theFrame->GetWidth();
	int height = theFrame->GetHeight();
	
	if (width != 1920)
		return S_OK;
	 
	 
	if (pFrameCallback != nullptr)
	{
		BMDPixelFormat pif = theFrame->GetPixelFormat();

		void* videoPixels;
		theFrame->GetBytes(&videoPixels);
		 
		pFrameCallback((uint8_t *)videoPixels, width, height, pif);
	}
	 

	if (m_openGLctx != nullptr)
	{
		// Then set the OpenGL rendering context to the one we created before
		wglMakeCurrent(pWindowHDC, m_openGLctx);

		// and let the helper take care of the drawing
		m_deckLinkScreenPreviewHelper->PaintGL();

		// Last, reset the OpenGL rendering context
		wglMakeCurrent(nullptr, nullptr);
	}
	 
	return S_OK;
}

void PreviewWindowGL::SetWindowSize(int x, int y, int width, int height)
{
	
	glViewport(0, 0, width, height);
	 
}
