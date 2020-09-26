//////////////////////////////////////////////////////////////////////////
//
//	created:	2005/09/01
//	file name:	enwr.h
//
//////////////////////////////////////////////////////////////////////////
//
//	Copyright (c) 2005 Elecard Ltd.
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
//	author:  Ilya Seliverstov <krez@elecard.net.ru>
//			 Viktor Ladochkin <ladoch@elecard.net.ru>
//			 Grigoriy Melnikov <Grigory.Melnikov@elecard.ru>
//	
//	purpose: Elecard NWRenderer decription header
//
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//	GUID					Value Type	Available range		Default Value
//////////////////////////////////////////////////////////////////////////
//	ENR_payload				VT_INT		0 - 5				2
//	ENR_transport			VT_INT		0 - 3				1
//	ENR_fixed_ports			VT_INT		0, 1				0
//	ENR_port				VT_INT		0 - 65535			10200
//	ENR_port_video			VT_INT		0 - 65535			10201
//	ENR_port_audio			VT_INT		0 - 65535			10301
//	ENR_port_bifs			VT_INT		0 - 65535			10401
//	ENR_destination			VT_BSTR							"234.5.5.5"
//	ENR_interface			VT_BSTR							""
//	ENR_connection_speed	VT_INT							100000000
//	ENR_ttl					VT_INT		1 - 255				64
//	ENR_av_ssrc				VT_INT							0
//	ENR_video_ssrc			VT_INT							0
//	ENR_audio_ssrc			VT_INT							0
//	ENR_max_bit_rate		VT_INT							0
//	ENR_max_video_bit_rate	VT_INT							0
//	ENR_max_audio_bit_rate	VT_INT							0
//	ENR_max_rtcp_bit_rate	VT_INT							600
//	ENR_sync_point			VT_INT		0, 1				1
//	ENR_max_upd_size		VT_INT		200 - 65535			65535
//	ENR_broadcast_mode		VT_INT		0, 1				1
//	ENR_buffer_size			VT_INT		65535 - 67107840	2097152
//	ENR_buffer_mode			VT_INT		0 - 2				0
//  ENR_time_source			VT_INT		0 - 2				1
//	ENR_synchronization		VT_INT		0, 1				0
//  ENR_ts_packets			VT_INT		1 - 100				7		
//	ENR_repeat_mode			VT_INT		0, 1				1
//	ENR_restore_dts			VT_INT		0, 1				0
//	ENR_enable_sap			VT_INT		0, 1				1
//	ENR_enable_rtcp			VT_INT		0, 1				0
//	ENR_video_id			VT_INT		0 - 65535			1
//	ENR_audio_id			VT_INT		0 - 65535			2
//  ENR_sdp_profile			VT_INT		0, 1				0
//	ENR_not_control_rate	VT_INT		0, 1				1
//	ENR_user_name			VT_BSTR							
//	ENR_session_name		VT_BSTR							
//	ENR_session_info		VT_BSTR
//	ENR_description			VT_BSTR
//	ENR_email				VT_BSTR
//	ENR_phone				VT_BSTR
//	ENR_sdp_packet			VT_BSTR
//////////////////////////////////////////////////////////////////////////
//	ENR_data_info			VT_BSTR
//  ENR_fec_type            VT_INT      0 - 2               0
//  ENR_fec_rows            VT_INT      2 - 40              7
//  ENR_fec_collumns        VT_INT      1 - 40              5
//  ENR_fec_rows_port       VT_INT		0 - 65535           10501
//  ENR_fec_collumns_port   VT_INT		0 - 65535           10502


#ifndef _NW_RENDERER_GUIDS_
#define _NW_RENDERER_GUIDS_

namespace ENWRender
{
	// paload type
	enum payload_type
	{
		PayloadType_MP1S		= 0,	// MPEG1 System
		PayloadType_MP2P		= 1,	// MPEG2 Program
		PayloadType_MP2T		= 2,	// MPEG2 Transport
		PayloadType_MP4V		= 3,	// MPEG4 Video
		PayloadType_AAC			= 4,	// AAC audio
		PayloadType_H264		= 5,	// H.264/AVC video
		PayloadType_H263		= 6,	// H.263/H263+ video
		PayloadType_AMR			= 7,	// AMR/AMR-WB audio
		PayloadType_MP1A		= 8,	// MPEG1 Audio
		PayloadType_MP2A		= 9,	// MPEG2 Audio
		PayloadType_MP1V		= 10,	// MPEG1 Video
		PayloadType_MP2V		= 11,	// MPEG2 Video
		PayloadType_UNKNOWN		= 999
	};

	// transport type
	enum transport_type
	{ 
		TransType_UDP		= 0,	// Raw UDP
		TransType_RTP		= 1,	// RTP/AVP over UDP
		TransType_TCP_udp	= 2,	// Raw TCP
		TransType_TCP_rtp	= 3		// RTP/AVP over TCP
	};

	// buffer drop mode
	enum drop_mode
	{
		DropMode_NotDrop	= 0,	// Wait for free space
		DropMode_DropFrame	= 1,	// Drop frame
		DropMode_DropGop	= 2		// Drop all gop
	};

	// rtp times source
	enum time_source
	{
		TimeSource_Auto		= 0,	// Auto detection
		TimeSource_Samples	= 1,	// Get time from sample
		TimeSource_Stream	= 2		// Get time from stream
	};

	// broadcasting mode
	enum broadcasting_mode
	{
		BroadCastMode_FromFile		= 0, // broadcasting from file
		BroadCastMode_FromCapture	= 1, // broadcasting from capture source
	};

	// fec type
	enum fec_type
	{
		FecTypeNone            = 0,
		FecType1D              = 1,
		FecType2D              = 2
	};
};


//////////////////////////////////////////////////////////////////////////
// {97A5D863-EC94-4234-8C12-554DE775EAD0}
static const GUID ENR_payload =  
					{ 0x97a5d863, 0xec94, 0x4234, { 0x8c, 0x12, 0x55, 0x4d, 0xe7, 0x75, 0xea, 0xd0 } };

// {C49B0276-2227-4d72-88A2-B5D36969F099}
static const GUID ENR_transport = 
					{ 0xc49b0276, 0x2227, 0x4d72, { 0x88, 0xa2, 0xb5, 0xd3, 0x69, 0x69, 0xf0, 0x99 } };

// {31543CB0-C01C-4b58-B494-E32D0D52CBED}
static const GUID ENR_port = 
					{ 0x31543cb0, 0xc01c, 0x4b58, { 0xb4, 0x94, 0xe3, 0x2d, 0xd, 0x52, 0xcb, 0xed } };

// {C502F4BD-6699-48ff-9086-ADCA4A9700C6}
static const GUID ENR_sapport = 
{ 0xc502f4bd, 0x6699, 0x48ff, { 0x90, 0x86, 0xad, 0xca, 0x4a, 0x97, 0x0, 0xc6 } };


static const GUID ENR_port_video = 
					{ 0x760fcb7a, 0x4f82, 0x4546, { 0x93, 0x5c, 0xd9, 0xeb, 0x73, 0x80, 0x57, 0xcf } };

static const GUID ENR_port_audio = 
					{ 0x89453140, 0xa3c0, 0x47bd, { 0x90, 0x38, 0x48, 0x1e, 0x5, 0xef, 0xfb, 0x39 } };

static const GUID ENR_port_bifs = 
					{ 0x357fa049, 0xaff1, 0x4499, { 0x9c, 0x6b, 0x49, 0x79, 0xf, 0x4d, 0xda, 0x94 } };

// {62E77578-3B29-4702-90AA-E2F6FBF29EDB}
static const GUID ENR_destination = 
					{ 0x62e77578, 0x3b29, 0x4702, { 0x90, 0xaa, 0xe2, 0xf6, 0xfb, 0xf2, 0x9e, 0xdb } };

// {F152AA52-47F6-41af-9296-689C23C01943}
static const GUID ENR_sapdestination = 
{ 0xf152aa52, 0x47f6, 0x41af, { 0x92, 0x96, 0x68, 0x9c, 0x23, 0xc0, 0x19, 0x43 } };


// {5DCF9169-6B9C-40c7-BDA1-F4C9587E9F6F}
static const GUID ENR_interface = 
					{ 0x5dcf9169, 0x6b9c, 0x40c7, { 0xbd, 0xa1, 0xf4, 0xc9, 0x58, 0x7e, 0x9f, 0x6f } };

// {AEB4E28D-D66F-4ec4-9ADD-52F27F44B23F}
static const GUID ENR_connection_speed = 
					{ 0xaeb4e28d, 0xd66f, 0x4ec4, { 0x9a, 0xdd, 0x52, 0xf2, 0x7f, 0x44, 0xb2, 0x3f } };

// {A060FFF0-0FC5-41e7-AE97-21484A91F6A8}
static const GUID ENR_ttl = 
					{ 0xa060fff0, 0xfc5, 0x41e7, { 0xae, 0x97, 0x21, 0x48, 0x4a, 0x91, 0xf6, 0xa8 } };

// {0B67E8A5-6FCF-4f5b-A3FD-9B048361EF98}
static const GUID ENR_av_ssrc = 
					{ 0xb67e8a5, 0x6fcf, 0x4f5b, { 0xa3, 0xfd, 0x9b, 0x4, 0x83, 0x61, 0xef, 0x98 } };

// {29071414-3A9C-4354-94D5-17D14101A84E}
static const GUID ENR_video_ssrc = 
					{ 0x29071414, 0x3a9c, 0x4354, { 0x94, 0xd5, 0x17, 0xd1, 0x41, 0x1, 0xa8, 0x4e } };

// {B7053A10-1249-4047-B7D4-997EE769E8FF}
static const GUID ENR_audio_ssrc = 
					{ 0xb7053a10, 0x1249, 0x4047, { 0xb7, 0xd4, 0x99, 0x7e, 0xe7, 0x69, 0xe8, 0xff } };

// {6F2DD973-E797-4b33-9B81-0D483105F297}
static const GUID ENR_video_id = 
					{ 0x6f2dd973, 0xe797, 0x4b33, { 0x9b, 0x81, 0xd, 0x48, 0x31, 0x5, 0xf2, 0x97 } };

// {CC573BA0-D7BF-4396-95BF-3D68A5BF27B0}
static const GUID ENR_audio_id = 
					{ 0xcc573ba0, 0xd7bf, 0x4396, { 0x95, 0xbf, 0x3d, 0x68, 0xa5, 0xbf, 0x27, 0xb0 } };

// {BB21FBC6-21B9-4b9b-AB5B-2435AE1B8C3B}
static const GUID ENR_max_bit_rate = 
					{ 0xbb21fbc6, 0x21b9, 0x4b9b, { 0xab, 0x5b, 0x24, 0x35, 0xae, 0x1b, 0x8c, 0x3b } };

// {560EB57B-F0CA-4a8e-90B4-FD6AD68B515C}
static const GUID ENR_max_video_bit_rate = 
					{ 0x560eb57b, 0xf0ca, 0x4a8e, { 0x90, 0xb4, 0xfd, 0x6a, 0xd6, 0x8b, 0x51, 0x5c } };

// {AE754EB2-4D02-48dd-BA3B-C0A3EFD2E76B}
static const GUID ENR_max_audio_bit_rate = 
					{ 0xae754eb2, 0x4d02, 0x48dd, { 0xba, 0x3b, 0xc0, 0xa3, 0xef, 0xd2, 0xe7, 0x6b } };

// {B171709F-DA31-4e21-A4DD-EAC16284EBF1}
static const GUID ENR_max_rtcp_bit_rate = 
					{ 0xb171709f, 0xda31, 0x4e21, { 0xa4, 0xdd, 0xea, 0xc1, 0x62, 0x84, 0xeb, 0xf1 } };

// {7696A0BA-C5B6-4786-91F5-8C2699C48EE8}
static const GUID ENR_sync_point = 
					{ 0x7696a0ba, 0xc5b6, 0x4786, { 0x91, 0xf5, 0x8c, 0x26, 0x99, 0xc4, 0x8e, 0xe8 } };

// {CE75DD63-F658-447e-ADC3-FA93D07D5043}
static const GUID ENR_max_upd_size = 
					{ 0xce75dd63, 0xf658, 0x447e, { 0xad, 0xc3, 0xfa, 0x93, 0xd0, 0x7d, 0x50, 0x43 } };

// {3352EE12-6151-415f-A3DD-0472BB694662}
static const GUID ENR_broadcast_mode = 
					{ 0x3352ee12, 0x6151, 0x415f, { 0xa3, 0xdd, 0x4, 0x72, 0xbb, 0x69, 0x46, 0x62 } };


// {805C0EBB-6E16-438a-9BB2-D1565FDE2530}
static const GUID ENR_buffer_size = 
					{ 0x805c0ebb, 0x6e16, 0x438a, { 0x9b, 0xb2, 0xd1, 0x56, 0x5f, 0xde, 0x25, 0x30 } };

// {3CF53E12-2488-4902-AE12-EFF1DCF8DFE7}
static const GUID ENR_buffer_mode = 
					{ 0x3cf53e12, 0x2488, 0x4902, { 0xae, 0x12, 0xef, 0xf1, 0xdc, 0xf8, 0xdf, 0xe7 } };

// {2B2949AC-532B-48cd-982D-767C25465AB7}
static const GUID ENR_time_source = 
					{ 0x2b2949ac, 0x532b, 0x48cd, { 0x98, 0x2d, 0x76, 0x7c, 0x25, 0x46, 0x5a, 0xb7 } };
// {E7B28F76-F4F8-4523-B855-5B12BB58CA39}
static const GUID ENR_synchronization = 
					{ 0xe7b28f76, 0xf4f8, 0x4523, { 0xb8, 0x55, 0x5b, 0x12, 0xbb, 0x58, 0xca, 0x39 } };

// {7BF6F648-6D59-4f9f-94F2-F03CC200E80C}
static const GUID ENR_ts_packets = 
					{ 0x7bf6f648, 0x6d59, 0x4f9f, { 0x94, 0xf2, 0xf0, 0x3c, 0xc2, 0x0, 0xe8, 0xc } };

// {488E8215-8F7E-4530-8007-18FFCA3B25DF}
static const GUID ENR_repeat_mode = 
					{ 0x488e8215, 0x8f7e, 0x4530, { 0x80, 0x7, 0x18, 0xff, 0xca, 0x3b, 0x25, 0xdf } };

// {241A8F9C-278E-4cfc-B5FC-4D105DB0F1F4}
static const GUID ENR_restore_dts = 
					{ 0x241a8f9c, 0x278e, 0x4cfc, { 0xb5, 0xfc, 0x4d, 0x10, 0x5d, 0xb0, 0xf1, 0xf4 } };

// {98E4C026-F110-4c4b-A8C8-DD57AE64E905}
static const GUID ENR_enable_sap = 
					{ 0x98e4c026, 0xf110, 0x4c4b, { 0xa8, 0xc8, 0xdd, 0x57, 0xae, 0x64, 0xe9, 0x5 } };

// {3D7CFA31-466F-4374-BB6B-AADB5408C978}
static const GUID ENR_enable_rtcp = 
					{ 0x3d7cfa31, 0x466f, 0x4374, { 0xbb, 0x6b, 0xaa, 0xdb, 0x54, 0x8, 0xc9, 0x78 } };

// {239EEB26-4D56-4b3f-B892-2288D855A353}
static const GUID ENR_not_control_rate = 
					{ 0x239eeb26, 0x4d56, 0x4b3f, { 0xb8, 0x92, 0x22, 0x88, 0xd8, 0x55, 0xa3, 0x53 } };
// {2709CE7C-1953-43d4-9F7A-586CCBE032DA}
static const GUID ENR_bitrate_smoothing = { 0x2709ce7c, 0x1953, 0x43d4, { 0x9f, 0x7a, 0x58, 0x6c, 0xcb, 0xe0, 0x32, 0xda } };

// {BE6F3622-3E18-4f01-B7E4-0747997B7617}
static const GUID ENR_disable_output = { 0xbe6f3622, 0x3e18, 0x4f01, { 0xb7, 0xe4, 0x7, 0x47, 0x99, 0x7b, 0x76, 0x17 } };

// {F0B10C13-B43C-43e2-846D-E9E823EFE44A}
static const GUID ENR_sdp_profile = 
					{ 0xf0b10c13, 0xb43c, 0x43e2, { 0x84, 0x6d, 0xe9, 0xe8, 0x23, 0xef, 0xe4, 0x4a } };

// {B66E87FA-9A31-4592-8559-DEB0173504A7}
static const GUID ENR_receive_sps_pps = 
{ 0xb66e87fa, 0x9a31, 0x4592, { 0x85, 0x59, 0xde, 0xb0, 0x17, 0x35, 0x4, 0xa7 } };


// {F406F4E5-CE8F-4a20-88B1-B7A9FC2A5FC6}
static const GUID ENR_user_name = 
					{ 0xf406f4e5, 0xce8f, 0x4a20, { 0x88, 0xb1, 0xb7, 0xa9, 0xfc, 0x2a, 0x5f, 0xc6 } };
// {E914C2B7-7A27-4bcd-AB66-1BC7B3D96C47}
static const GUID ENR_session_name = 
					{ 0xe914c2b7, 0x7a27, 0x4bcd, { 0xab, 0x66, 0x1b, 0xc7, 0xb3, 0xd9, 0x6c, 0x47 } };
// {4271B640-E2EC-459e-8474-120AD5A227C6}
static const GUID ENR_session_info = 
					{ 0x4271b640, 0xe2ec, 0x459e, { 0x84, 0x74, 0x12, 0xa, 0xd5, 0xa2, 0x27, 0xc6 } };
// {A1741E5B-FF49-4db4-91B1-2229712D92ED}
static const GUID ENR_description = 
					{ 0xa1741e5b, 0xff49, 0x4db4, { 0x91, 0xb1, 0x22, 0x29, 0x71, 0x2d, 0x92, 0xed } };
// {849F69DD-E669-4c78-80B2-31B66F0EF83D}
static const GUID ENR_email = 
					{ 0x849f69dd, 0xe669, 0x4c78, { 0x80, 0xb2, 0x31, 0xb6, 0x6f, 0xe, 0xf8, 0x3d } };
// {4FEF6DA3-7869-40df-91BB-188438727B30}
static const GUID ENR_phone = 
					{ 0x4fef6da3, 0x7869, 0x40df, { 0x91, 0xbb, 0x18, 0x84, 0x38, 0x72, 0x7b, 0x30 } };

// {1FE0D5D1-E21D-443e-9B9A-BFECEED5B15D}
static const GUID ENR_fixed_ports = 
{ 0x1fe0d5d1, 0xe21d, 0x443e, { 0x9b, 0x9a, 0xbf, 0xec, 0xee, 0xd5, 0xb1, 0x5d } };


// {9C6198D9-E803-426c-99AA-2F68BF52EFFE}
static const GUID ENR_sdp_packet = 
					{ 0x9c6198d9, 0xe803, 0x426c, { 0x99, 0xaa, 0x2f, 0x68, 0xbf, 0x52, 0xef, 0xfe } };

//////////////////////////////////////////////////////////////////////////
// {5345272A-C27F-49a6-93C6-86FEA2AB0845}
static const GUID ENR_data_info = { 0x5345272a, 0xc27f, 0x49a6, { 0x93, 0xc6, 0x86, 0xfe, 0xa2, 0xab, 0x8, 0x45 } };

// {C7EF8756-9D6A-4a91-AC89-14E7738FD52C}
static const GUID ENR_info_bitrate = { 0xc7ef8756, 0x9d6a, 0x4a91, { 0xac, 0x89, 0x14, 0xe7, 0x73, 0x8f, 0xd5, 0x2c } };

// {582E2711-DEF5-44dc-8650-1880E599A65B}
static const GUID ENR_info_buffer_use = { 0x582e2711, 0xdef5, 0x44dc, { 0x86, 0x50, 0x18, 0x80, 0xe5, 0x99, 0xa6, 0x5b } };

// {47CFE6F6-A55F-4A3C-A5A2-8B51B6A7E063}
static const GUID ENR_fec_type = { 0x47CFE6F6, 0xA55F, 0x4A3C, { 0xA5, 0xA2, 0x8B, 0x51, 0xB6, 0xA7, 0xE0, 0x63 } };

// {47FFCD05-58C2-44F3-B509-708F9A81F2C0}
static const GUID ENR_fec_rows = { 0x47FFCD05, 0x58C2, 0x44F3, { 0xB5, 0x09, 0x70, 0x8F, 0x9A, 0x81, 0xF2, 0xC0 } };

// {86A7AD57-C8F1-4F5C-9931-A252E92FB3F3}
static const GUID ENR_fec_collumns = { 0x86A7AD57, 0xC8F1, 0x4F5C, { 0x99, 0x31, 0xA2, 0x52, 0xE9, 0x2F, 0xB3, 0xF3 } };

// {567616D6-2BA0-486F-84A7-6A222B424F07}
static const GUID ENR_fec_rows_port = { 0x567616D6, 0x2BA0, 0x486F, { 0x84, 0xA7, 0x6A, 0x22, 0x2B, 0x42, 0x4F, 0x07 } };

// {30D24FEE-3501-495C-AD89-FF419195FC21}
static const GUID ENR_fec_collumns_port = { 0x30D24FEE, 0x3501, 0x495C, { 0xAD, 0x89, 0xFF, 0x41, 0x91, 0x95, 0xFC, 0x21 } };


#endif //_NW_RENDERER_GUIDS_