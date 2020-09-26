//////////////////////////////////////////////////////////////////////////
//
//	created:	2013/12/12
//	file name:	ehlss.h
//
//////////////////////////////////////////////////////////////////////////
//
//	Copyright (c) 2013 Elecard.
//	All rights are reserved.  Reproduction in whole or in part is prohibited
//	without the written consent of the copyright owner.
//
//	Elecard reserves the right to make changes without
//	notice at any time. Elecard makes no warranty, expressed,
//	implied or statutory, including but not limited to any implied
//	warranty of merchantability of fitness for any particular purpose,
//	or that the use will not infringe any third party patent, copyright
//	or trademark.
//
//	Elecard must not be liable for any loss or damage arising
//	from its use.
//
//////////////////////////////////////////////////////////////////////////
//
//	purpose: Elecard Hls Source properties GUIDs 
//
//////////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	GUID								    Type        Access      Available range		Default Val     Note
//

//	EHlsSource_Url						    VT_BSTR     R/W         ---				    "http://"	    URL to a playlist
//	EHlsSource_ConnectTimeout			    VT_UINT		R/W         [0..UINT_MAX]       10				Connect timeout in seconds
//	EHlsSource_DataTimeout				    VT_UINT     R/W         [0..UINT_MAX]       10				Data unavailability timeout in seconds
//  EHlsSource_MaxPlaylistUpdates		    VT_UINT		R/W         [0..UINT_MAX]       3			    Max playlist update attemps. Disabled if value is 0.
//	EHlsSource_MaxDownloadRate			    VT_UINT		R/W         [0..UINT_MAX]	    0				Max download rate limit. Disabled if value is 0.
//	EHlsSource_DownloadRate				    VT_UINT		R           [0..UINT_MAX]	    0				Download rate
//	EHlsSource_RealStreamBitrate		    VT_UINT		R           [0..UINT_MAX]	    0				Real stream bitrate
//  EHlsSource_StartPosition                VT_UINT     R/W         [0..100]            50              Playlist start position in percents
//  EHlsSource_CurrentMediaPlaylistBitrate  VT_UINT     R           [0..UINT_MAX]       0               Current media playlist bandwidth, that was specified in the master playlist
//  EHlsSource_MediaPlaylistIndex           VT_INT      R/W         [-1..INT_MAX]       -1              Allows to set specific media playlist. Auto mode is used if value is -1.

// {BCE2C6AF-A13A-4BDE-9C6B-72AF6229200C}
static const GUID EHlsSource_Url = 
{ 0xbce2c6af, 0xa13a, 0x4bde, { 0x9c, 0x6b, 0x72, 0xaf, 0x62, 0x29, 0x20, 0xc } };

// {6ABB76A4-2426-451B-AF25-94E80D79742F}
static const GUID EHlsSource_DataTimeout = 
{ 0x6abb76a4, 0x2426, 0x451b, { 0xaf, 0x25, 0x94, 0xe8, 0xd, 0x79, 0x74, 0x2f } };

// {5C2D7EB8-29F3-47C2-9A2D-DD9A3FD0D707}
static const GUID EHlsSource_ConnectTimeout = 
{ 0x5c2d7eb8, 0x29f3, 0x47c2, { 0x9a, 0x2d, 0xdd, 0x9a, 0x3f, 0xd0, 0xd7, 0x7 } };

// {F73BE3EB-52FE-4A83-96D2-1A51F72AEF9E}
static const GUID EHlsSource_MaxPlaylistUpdates = 
{ 0xf73be3eb, 0x52fe, 0x4a83, { 0x96, 0xd2, 0x1a, 0x51, 0xf7, 0x2a, 0xef, 0x9e } };

// {08F4B8EA-2240-4F7C-BEA4-B9C02013D8FE}
static const GUID EHlsSource_MaxDownloadRate =
{ 0x8f4b8ea, 0x2240, 0x4f7c, { 0xbe, 0xa4, 0xb9, 0xc0, 0x20, 0x13, 0xd8, 0xfe } };

// {AFEE31B9-7E72-4891-93B6-2F8644A6AE7D}
static const GUID EHlsSource_DownloadRate =
{ 0xafee31b9, 0x7e72, 0x4891, { 0x93, 0xb6, 0x2f, 0x86, 0x44, 0xa6, 0xae, 0x7d } };

// {948BB2FA-61B3-497B-9F4D-26FDC281B6E2}
static const GUID EHlsSource_RealStreamBitrate =
{ 0x948bb2fa, 0x61b3, 0x497b, { 0x9f, 0x4d, 0x26, 0xfd, 0xc2, 0x81, 0xb6, 0xe2 } };

// {7EA6A9D9-8693-435B-BB31-F13BD92AB22D}
static const GUID EHlsSource_StartPosition =
{ 0x7ea6a9d9, 0x8693, 0x435b, { 0xbb, 0x31, 0xf1, 0x3b, 0xd9, 0x2a, 0xb2, 0x2d } };

// {9C5CCA69-9849-4A89-9481-8322AC1C8899}
static const GUID EHlsSource_CurrentMediaPlaylistBitrate =
{ 0x9c5cca69, 0x9849, 0x4a89, { 0x94, 0x81, 0x83, 0x22, 0xac, 0x1c, 0x88, 0x99 } };

// {BBA7E3A5-D5FE-4908-808D-B21C12A78ED2}
static const GUID EHlsSource_MediaPlaylistIndex =
{ 0xbba7e3a5, 0xd5fe, 0x4908, { 0x80, 0x8d, 0xb2, 0x1c, 0x12, 0xa7, 0x8e, 0xd2 } };
