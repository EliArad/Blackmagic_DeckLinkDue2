#include <streams.h>
#include <initguid.h>
#include <olectl.h>
#include <dllsetup.h>

#include "IAddFrame.h"
#include "LiveSource.h"

// Media Types
const AMOVIESETUP_MEDIATYPE sudPinTypes[] =
{
	&MEDIATYPE_Video,
	&MEDIASUBTYPE_NULL
};

// Pins
const AMOVIESETUP_PIN psudPin =
{
	LIVE_OUTPIN_NAME,    // Pin string name
	FALSE, 				 // Is it rendered
	TRUE, 				 // Is it an output
	FALSE, 				 // Can we have none
	FALSE, 				 // Can we have many
	&CLSID_NULL, 		 // Connects to filter
	NULL, 				 // Connects to pin
	1, 					 // Number of types
	&sudPinTypes[0] 	 // Pin Media types
};

// Filters
const AMOVIESETUP_FILTER liveSource =
{
	&CLSID_CLiveSource,   // Filter CLSID
	LIVE_FILTER_NAME, 	  // String name
	MERIT_DO_NOT_USE, 	  // Filter merit
	1, 					  // Number pins
	&psudPin			  // Pin details
};

// Templates
CFactoryTemplate g_Templates[] =
{
	LIVE_FILTER_NAME,
	&CLSID_CLiveSource,
	CLiveSource::CreateInstance,
	NULL,
	&liveSource
};

int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);

STDAPI DllRegisterServer()
{
	return AMovieDllRegisterServer2(TRUE);
}

STDAPI DllUnregisterServer()
{
	return AMovieDllRegisterServer2(FALSE);
}


//
// DllEntryPoint
//
extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE, ULONG, LPVOID);

BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD  dwReason,
	LPVOID lpReserved)
{
	return DllEntryPoint((HINSTANCE)(hModule), dwReason, lpReserved);
}