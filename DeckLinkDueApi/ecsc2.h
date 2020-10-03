//////////////////////////////////////////////////////////////////////////
//
//	created:	2007/02/09
//	file name:	ecsc2.h
//
//////////////////////////////////////////////////////////////////////////
//
//	Copyright (c) 2007 Elecard Ltd.
//	All rights are reserved.  Reproduction in whole or in part is prohibited
//	without the written consent of the copyright owner.
//
//	Elecard Ltd. reserves the right to make changes without
//	notice at any time. Elecard Ltd. makes no warranty, expressed,
//	implied or statutory, including but not limited to any implied
//	warranty of merchantability of fitness for any particular purpose,
//	or that the use will not infringe any third party patent, copyright
//	or trademark.
//
//	Elecard Ltd. must not be liable for any loss or damage arising
//	from its use.
//
//////////////////////////////////////////////////////////////////////////
//
//	author:  Andrey Serebrennikov
//	
//	purpose: The definition of Elecard Color Space Converter 2 filter's GUID and GUIDs of its parameters
//
//////////////////////////////////////////////////////////////////////////

#ifndef __ECSC2_HEADER__
#define __ECSC2_HEADER__


//////////////////////////////////////////////////////////////////////////
//	Filter GUIDs
//////////////////////////////////////////////////////////////////////////


// {5DB7637A-F0DA-4fc7-9E45-341C0C8386B4}
static const GUID CLSID_ECSC2 = 
{ 0x5db7637a, 0xf0da, 0x4fc7, { 0x9e, 0x45, 0x34, 0x1c, 0xc, 0x83, 0x86, 0xb4 } };

// {7E3116DB-2078-4f86-95F5-ADFECFB498C1}
static const GUID CLSID_ECSC2_AboutPropertyPage = 
{ 0x7e3116db, 0x2078, 0x4f86, { 0x95, 0xf5, 0xad, 0xfe, 0xcf, 0xb4, 0x98, 0xc1 } };

// {0886F6D8-BE73-4589-A575-9ECD99007879}
static const GUID CLSID_ECSC2_MainPropertyPage = 
{ 0x886f6d8, 0xbe73, 0x4589, { 0xa5, 0x75, 0x9e, 0xcd, 0x99, 0x0, 0x78, 0x79 } };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	GUID							Value Type	     Available range				Default Value			Note
//
//	CSC_FIX_INPUT_MEDIA_TYPE			VT_UI4		 [0x00000000 - 0xFFFFFFFF]		 0x00000000			Specifies the four character code (FOURCC) of the input media type.
///																										(Use value "0" for connecting on any suitable media type.)
//	CSC_FIX_OUTPUT_MEDIA_TYPE			VT_UI4		 [0x00000000 - 0xFFFFFFFF]       0x00000000			Specifies the four character code (FOURCC) of the output media type.
///																										(Use value "0" for connecting on any suitable media type.)
//  CSC_MATRIX_COEFFICIENTS             VT_UI4		 [0x00000000 - 0xFFFFFFFF]       0x00000000			Specifies the matrix coefficients used for rbg <=> yuv convertion
///
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// {2B58E1BA-19DA-4baa-9A9F-F9677F18C6D0}
static const GUID CSC_FIX_OUTPUT_MEDIA_TYPE = 
{ 0x2b58e1ba, 0x19da, 0x4baa, { 0x9a, 0x9f, 0xf9, 0x67, 0x7f, 0x18, 0xc6, 0xd0 } };

// {595D3585-21B1-4056-B0C7-2D7E4A9BD006}
static const GUID CSC_FIX_INPUT_MEDIA_TYPE = 
{ 0x595d3585, 0x21b1, 0x4056, { 0xb0, 0xc7, 0x2d, 0x7e, 0x4a, 0x9b, 0xd0, 0x6 } };

// {b7f93b3d-6bef-451f-b537-f6427b8efc7b}
static const GUID CSC_MATRIX_COEFFICIENTS = 
{ 0xb7f93b3d, 0x6bef, 0x451f, { 0xb5, 0x37, 0xf6, 0x42, 0x7b, 0x8e, 0xfc, 0x7b } };

namespace ECSC
{
	enum SubTypes {eANY, eYUY2 = 0x32595559, eYUYV = 0x56595559, eUYVY = 0x59565955, eYVYU = 0x55595659, eYV12 = 0x32315659, eI420 = 0x30323449, eIYUV = 0x56555949, eYV16 = 0x7c63d475, eRGB24 = 0xe436eb7d, eRGB32 = 0xe436eb7e, eARGB32 = 0x773c9ac0, eA2R10G10B10 = 0x2f8bb76d, eA2B10G10R10 = 0x576f7893, eP010 = 0x30313050, eP210 = 0x30313250, eE010 = 0x30313045, eE210 = 0x30313245, eY210 = 0x30313259, ev210 = 0x30313276, eNV12 = 0x3231564E, eNV21 = 0x3132564E};
	
	enum MType
	{
		yuy2_vh2, yuy2_vh, yuyv_vh2, yuyv_vh, uyvy_vh2, uyvy_vh, yvyu_vh2, yvyu_vh, yv16_vh2, yv16_vh, yv12_vh2, yv12_vh, i420_vh2, i420_vh, iyuv_vh2, iyuv_vh, rgb32_vh2, rgb32_vh, rgb24_vh2, rgb24_vh, p010_vh2, p010_vh, p210_vh2, p210_vh, e010_vh2, e010_vh, e210_vh2, e210_vh, y210_vh2, y210_vh, v210_vh2, v210_vh, nv12_vh2, nv12_vh, nv21_vh2, nv21_vh, argb32_vh2, argb32_vh, a2r10g10b10_vh, a2r10g10b10_vh2, a2b10g10r10_vh, a2b10g10r10_vh2, out_of_types, any_type
	};

	enum MatrixCoefficients
	{
		BT_601 = 0, BT_709_1125 = 1, BT_709_1250 = 2
	};
}



#endif