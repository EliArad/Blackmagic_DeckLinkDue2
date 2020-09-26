////////////////////////////////////////////////////////////////////////////////
//
//    Copyright (c) 2009 Elecard Ltd.
//    All rights are reserved.  Reproduction in whole or in part is prohibited
//    without the written consent of the copyright owner.
//
//    Elecard reserves the right to make changes without
//    notice at any time. Elecard makes no warranty,
//    expressed, implied or statutory, including but not limited to any implied
//    warranty of merchantability of fitness for any particular purpose, or that
//    the use will not infringe any third party patent, copyright or trademark.
//    Elecard must not be liable for any loss or damage
//    arising from its use.
////////////////////////////////////////////////////////////////////////////////

#ifndef ELECARD_DESKTOP_CAPTURE_MODULECONFIG
#define ELECARD_DESKTOP_CAPTURE_MODULECONFIG

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	GUID								Type	Available range		Default Val		Note
//

// {BCAB3548-CF7D-4130-A9AF-2E31980096EC}
static const GUID EDC_CaptureVideo = 
{ 0xbcab3548, 0xcf7d, 0x4130, { 0xa9, 0xaf, 0x2e, 0x31, 0x98, 0x0, 0x96, 0xec } };

// {B7070D8C-8F37-4175-8406-73E58B4F1F9A}
static const GUID EDC_CaptureAudio = 
{ 0xb7070d8c, 0x8f37, 0x4175, { 0x84, 0x6, 0x73, 0xe5, 0x8b, 0x4f, 0x1f, 0x9a } };

// {5C6BF647-9730-45e8-9A37-F104E512EDBB}
static const GUID EDC_VideoCaptureMode = 
{ 0x5c6bf647, 0x9730, 0x45e8, { 0x9a, 0x37, 0xf1, 0x4, 0xe5, 0x12, 0xed, 0xbb } };

// {66DEC5FD-4E3C-459a-B4E0-BD34BF6435BB}
static const GUID EDC_VideoCaptureRect = 
{ 0x66dec5fd, 0x4e3c, 0x459a, { 0xb4, 0xe0, 0xbd, 0x34, 0xbf, 0x64, 0x35, 0xbb } };

// {97EF47A7-E178-45c2-BE70-85E25DFFEDBC}
static const GUID EDC_VideoCaptureWindow = 
{ 0x97ef47a7, 0xe178, 0x45c2, { 0xbe, 0x70, 0x85, 0xe2, 0x5d, 0xff, 0xed, 0xbc } };

// {A3B87489-F2E1-4c9f-AC89-A9F60510A028}
static const GUID EDC_VideoCaptureRate = 
{ 0xa3b87489, 0xf2e1, 0x4c9f, { 0xac, 0x89, 0xa9, 0xf6, 0x5, 0x10, 0xa0, 0x28 } };

// {5406A755-2DD9-4dab-9D5D-7576B649516E}
static const GUID EDC_AudioCaptureMode = 
{ 0x5406a755, 0x2dd9, 0x4dab, { 0x9d, 0x5d, 0x75, 0x76, 0xb6, 0x49, 0x51, 0x6e } };

// {68E4276D-72DA-4f83-A178-E0782FFC4CC1}
static const GUID EDC_AudioInputDevice = 
{ 0x68e4276d, 0x72da, 0x4f83, { 0xa1, 0x78, 0xe0, 0x78, 0x2f, 0xfc, 0x4c, 0xc1 } };

// {68F233FF-C0B5-4205-AAE6-FF7D25BF40E8}
static const GUID EDC_AudioInputLine = 
{ 0x68f233ff, 0xc0b5, 0x4205, { 0xaa, 0xe6, 0xff, 0x7d, 0x25, 0xbf, 0x40, 0xe8 } };

// {70581D66-D7B9-47b3-9EB4-805B96012AB5}
static const GUID EDC_AudioInputFormat = 
{ 0x70581d66, 0xd7b9, 0x47b3, { 0x9e, 0xb4, 0x80, 0x5b, 0x96, 0x1, 0x2a, 0xb5 } };

// {E4D34C30-C256-490c-A9EC-3A46D2B06455}
static const GUID EDC_AudioLineVolume = 
{ 0xe4d34c30, 0xc256, 0x490c, { 0xa9, 0xec, 0x3a, 0x46, 0xd2, 0xb0, 0x64, 0x55 } };

// {8009BDB2-7F18-43de-90E3-6964749A8ABA}
static const GUID EDC_AudioFrameTime = 
{ 0x8009bdb2, 0x7f18, 0x43de, { 0x90, 0xe3, 0x69, 0x64, 0x74, 0x9a, 0x8a, 0xba } };

namespace EDC
{
	enum VideoCaptureMode
	{
		CAPTURE_GDI            = 0,
		CAPTURE_DD,
		CAPTURE_DX,
		CAPTURE_MAG,
		CAPTURE_DUPLICATE,
	};

	enum AudioCaptureMode
	{
		CAPTURE_Wave            = 0,
		CAPTURE_DirectSound,
		CAPTURE_WSAPI
	};
}

#endif //ELECARD_DESKTOP_CAPTURE_MODULECONFIG
