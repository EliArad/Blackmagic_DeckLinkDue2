/*/////////////////////////////////////////////////////////////////////////////
//
//    Elecard QuickSync video Decoder.
//
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2015 Elecard Ltd.
//  All rights are reserved.  Reproduction in  whole or in  part is prohibited
//  without the written consent of the copyright owner.
//
//  Elecard Ltd.  reserves the  right to  make changes  without notice  at any
//  time.  Elecard Ltd. makes no  warranty,  expressed, implied  or statutory,
//  including but not  limited to any  implied  warranty of merchantability of
//  fitness for any particular purpose, or that the use  will not infringe any
//  third party patent, copyright or trademark.
//
//  Elecard Ltd. must  not be liable  for any loss or  damage arising from its
//  use.
//
/////////////////////////////////////////////////////////////////////////////*/

#ifndef __ELECARD_QS_VIDEO_DECODER_INC__
#define __ELECARD_QS_VIDEO_DECODER_INC__

// {A162E197-280F-452F-BCF7-6A19913DD8A4}
static const GUID CLSID_QsVideoDecoder_MP2 = 
{ 0xa162e197, 0x280f, 0x452f, { 0xbc, 0xf7, 0x6a, 0x19, 0x91, 0x3d, 0xd8, 0xa4 } };

// {DEA21EFE-FABA-4C87-9C03-E1BC9715E254}
static const GUID CLSID_QsVideoDecoder_AboutPP_MP2 = 
{ 0xdea21efe, 0xfaba, 0x4c87, { 0x9c, 0x3, 0xe1, 0xbc, 0x97, 0x15, 0xe2, 0x54 } };

// {1B5C19C6-178C-4CD9-B894-434BA912BC73}
static const GUID CLSID_QsVideoDecoder_SettingsPP_MP2 = 
{ 0x1b5c19c6, 0x178c, 0x4cd9, { 0xb8, 0x94, 0x43, 0x4b, 0xa9, 0x12, 0xbc, 0x73 } };


// {AD74102B-7D3D-43FC-9DFF-C1087EAC485A}
static const GUID CLSID_QsVideoDecoder_AVC = 
{ 0xad74102b, 0x7d3d, 0x43fc, { 0x9d, 0xff, 0xc1, 0x8, 0x7e, 0xac, 0x48, 0x5a } };

// {2F67834A-50DE-4DF5-B5C2-8A535E2238EA}
static const GUID CLSID_QsVideoDecoder_AboutPP_AVC = 
{ 0x2f67834a, 0x50de, 0x4df5, { 0xb5, 0xc2, 0x8a, 0x53, 0x5e, 0x22, 0x38, 0xea } };

// {B45F93F8-3875-4530-87B9-53F15D6323B5}
static const GUID CLSID_QsVideoDecoder_SettingsPP_AVC = 
{ 0xb45f93f8, 0x3875, 0x4530, { 0x87, 0xb9, 0x53, 0xf1, 0x5d, 0x63, 0x23, 0xb5 } };


// {6D888149-DA34-4AF8-8011-3D50B440F065}
static const GUID CLSID_QsVideoDecoder_HEVC = 
{ 0x6d888149, 0xda34, 0x4af8, { 0x80, 0x11, 0x3d, 0x50, 0xb4, 0x40, 0xf0, 0x65 } };

// {92BDC06E-DADD-4E98-9760-9CF080F19096}
static const GUID CLSID_QsVideoDecoder_AboutPP_HEVC = 
{ 0x92bdc06e, 0xdadd, 0x4e98, { 0x97, 0x60, 0x9c, 0xf0, 0x80, 0xf1, 0x90, 0x96 } };

// {69CC0AB3-88DE-4CC9-BCD5-92B3FF127D66}
static const GUID CLSID_QsVideoDecoder_SettingsPP_HEVC = 
{ 0x69cc0ab3, 0x88de, 0x4cc9, { 0xbc, 0xd5, 0x92, 0xb3, 0xff, 0x12, 0x7d, 0x66 } };

#endif	// __ELECARD_QS_VIDEO_DECODER_INC__
