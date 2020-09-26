#pragma once

#define LIVE_FILTER_NAME TEXT("Bauotech DeckLink Due2 Source Filter")
#define LIVE_OUTPIN_NAME L"Out"

 

// {7102AE91-2434-445B-8276-5995EB968D5C}
static const GUID IID_ILiveSource =
{ 0x7102ae91, 0x2434, 0x445b,{ 0x82, 0x76, 0x59, 0x95, 0xeb, 0x96, 0x8d, 0x5c } };

 
// {017F358E-2E3F-44E7-ABA4-F6891C88E10F}
static const GUID CLSID_CLiveSource =
{ 0x17f358e, 0x2e3f, 0x44e7,{ 0xab, 0xa4, 0xf6, 0x89, 0x1c, 0x88, 0xe1, 0xf } };


DECLARE_INTERFACE_(ILiveSource, IUnknown)
{
	// Adds bitmap to the video sequence
	STDMETHOD(AddFrame)(HBITMAP hBmp) PURE;

	// Adds pixel data buffer to the video sequence
	STDMETHOD(AddFrame)(BYTE* pBuffer, DWORD size) PURE;

	// Set the video frame info.
	// Default value is width = 704, height = 576 (4CIF) and 32 bits per pixel
	STDMETHOD(SetBitmapInfo)(BITMAPINFOHEADER& bInfo) PURE;

	// Set the expected frame rate of the video.
	// Value should be in range of [0,30]
	// Default value is 0
	STDMETHOD(SetFrameRate)(int frameRate) PURE;
};