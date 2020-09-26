//////////////////////////////////////////////////////////////////////////
//
//	created:	2006/02/01
//	file name:	ertspnws.h
//
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2006-2009 Elecard.
//  All rights reserved. Whole or part reproduction is prohibited
//  without the written consent of the copyright owner.
//
//  Elecard reserves the right to make changes at any time without the notice.
//  Elecard does not provide expressed, implied or statutory warranty,
//  including it but is not limited by other warranty of merchantability of
//  fitness for any particular purpose. The use will be not infringe any
//  third party patent, copyright or trademark.
//
//  Elecard must not be liable for any loss or damage resulting from the use.
//
///////////////////////////////////////////////////////////////////////////////
//
//	author:  Melnikov Grigoriy <Grigory.Melnikov@elecard.ru>
//
//	purpose: Elecard RTSP NetSource filter parameters' GUIDs
//
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//	GUID					Value Type	Available range		Default Value	Note
////////////////////////////////////////////////////////////////////////////////////
// ERTSP_compatible			VT_INT			0..6			0				ERTSPSource::compatibles_enum
// ERTSP_server_url			VT_BSTR							rtsp://localhost:554
// ERTSP_input_interf		VT_BSTR											Input interface for receive data
// ERTSP_transport			VT_INT			0..2			0				ERTSPSource::transport_enum
// ERTSP_profile			VT_INT			0..2			0				ERTSPSource::profile_enum
// ERTSP_lower_transport	VT_INT			0..1			0				0-UDP / 1-TCP
// ERTSP_destination		VT_BSTR							234.5.5.5
// ERTSP_ttl				VT_INT			0..65535		10
// ERTSP_layers				VT_INT			0..65535		0
// ERTSP_unicast			VT_INT			0..1			0				0-Multicast / 1-Unicast
// ERTSP_append				VT_INT			0..1			0				0-Off / 1-On
// ERTSP_ssrc				VT_BSTR
// ERTSP_mode				VT_BSTR
// ERTSP_interleaved_start	VT_INT			-1...65535		-1				-1 - Parameter is not used
// ERTSP_interleaved_stop	VT_INT			-1...65535		-1				-1 - Parameter is not used
// ERTSP_port_start			VT_INT			-1...65535		-1				-1 - Parameter is not used
// ERTSP_port_stop			VT_INT			-1...65535		-1				-1 - Parameter is not used
// ERTSP_client_port_start	VT_INT			-1...65535		10202			-1 - Parameter is not used
// ERTSP_client_port_stop	VT_INT			-1...65535		10203			-1 - Parameter is not used
// ERTSP_use_sdp_config		VT_INT			0..1			0				0-Off / 1-On
// ERTSP_commands_dump		VT_BSTR											Specify file name and path if you want to save commands exchange
// ERTSP_play_rate		VT_R8							1.0				Specify playing rate
// ERTSP_any_source		 VT_INT			0..1			0				check or not network source for incoming packets
// ERTSP_latency		 VT_INT			0..65535		500				time delay between processing and playing samples
// ERTSP_keepalive_use_parameter VT_INT		0,1				0				use GET/SET PARAMETER as keep alive instead of OPTIONS
// ERTSP_last_ntp		VT_I8
// ERTSP_last_rtp		VT_I4
// ERTSP_reconnect			VT_INT			0..1			0				Reconnect on data timeout

#ifndef _RTSP_SOURCE_GUIDS_
#define _RTSP_SOURCE_GUIDS_

//////////////////////////////////////////////////////////////////////////
// {0C330612-DD94-4a26-87AC-ACE00680DA8A}
static const GUID ERTSP_compatible = { 0xc330612, 0xdd94, 0x4a26, { 0x87, 0xac, 0xac, 0xe0, 0x6, 0x80, 0xda, 0x8a } };

// {535AFA5A-9358-4ced-9004-89E5B9DA2B0A}
static const GUID ERTSP_server_url = { 0x535afa5a, 0x9358, 0x4ced, { 0x90, 0x4, 0x89, 0xe5, 0xb9, 0xda, 0x2b, 0xa } };

// {8B18C975-8CBC-45ae-B54E-8990CD5850E5}
static const GUID ERTSP_input_interf = { 0x8b18c975, 0x8cbc, 0x45ae, { 0xb5, 0x4e, 0x89, 0x90, 0xcd, 0x58, 0x50, 0xe5 } };

// {F6547545-0FCC-453e-9D36-0A70B4A797BD}
static const GUID ERTSP_transport = { 0xf6547545, 0xfcc, 0x453e, { 0x9d, 0x36, 0xa, 0x70, 0xb4, 0xa7, 0x97, 0xbd } };

// {BFAF1340-00A8-4f1c-BD38-D90ABC61EB24}
static const GUID ERTSP_profile = { 0xbfaf1340, 0xa8, 0x4f1c, { 0xbd, 0x38, 0xd9, 0xa, 0xbc, 0x61, 0xeb, 0x24 } };

// {B5876E14-818D-4719-9E55-198417011482}
static const GUID ERTSP_lower_transport = { 0xb5876e14, 0x818d, 0x4719, { 0x9e, 0x55, 0x19, 0x84, 0x17, 0x1, 0x14, 0x82 } };

// {98AD1272-DD16-4307-AAEB-680BBBB8906A}
static const GUID ERTSP_destination = { 0x98ad1272, 0xdd16, 0x4307, { 0xaa, 0xeb, 0x68, 0xb, 0xbb, 0xb8, 0x90, 0x6a } };

// {929EA087-F1C6-44e0-87B6-5E57FFDCBA3D}
static const GUID ERTSP_ttl = { 0x929ea087, 0xf1c6, 0x44e0, { 0x87, 0xb6, 0x5e, 0x57, 0xff, 0xdc, 0xba, 0x3d } };

// {E8D480AB-5EF6-4c59-B154-3B357DBC11EC}
static const GUID ERTSP_layers = { 0xe8d480ab, 0x5ef6, 0x4c59, { 0xb1, 0x54, 0x3b, 0x35, 0x7d, 0xbc, 0x11, 0xec } };

// {F1E61901-84E3-47ab-971F-0F61613FE157}
static const GUID ERTSP_unicast = { 0xf1e61901, 0x84e3, 0x47ab, { 0x97, 0x1f, 0xf, 0x61, 0x61, 0x3f, 0xe1, 0x57 } };

// {683002E7-DA9D-4580-B174-2FD2D617B676}
static const GUID ERTSP_append = { 0x683002e7, 0xda9d, 0x4580, { 0xb1, 0x74, 0x2f, 0xd2, 0xd6, 0x17, 0xb6, 0x76 } };

// {8C53FE6D-7209-4b0d-ABBB-8DD05942F48F}
static const GUID ERTSP_ssrc = { 0x8c53fe6d, 0x7209, 0x4b0d, { 0xab, 0xbb, 0x8d, 0xd0, 0x59, 0x42, 0xf4, 0x8f } };

// {794D41EC-79B8-4bb6-BF19-59723B21E161}
static const GUID ERTSP_mode = { 0x794d41ec, 0x79b8, 0x4bb6, { 0xbf, 0x19, 0x59, 0x72, 0x3b, 0x21, 0xe1, 0x61 } };

// {22E927A9-9679-4fe5-880C-3E2BC0545F7E}
static const GUID ERTSP_interleaved_start = { 0x22e927a9, 0x9679, 0x4fe5, { 0x88, 0xc, 0x3e, 0x2b, 0xc0, 0x54, 0x5f, 0x7e } };

// {2BD2A622-F105-4ab9-8AF3-C9A9B2976966}
static const GUID ERTSP_interleaved_stop = { 0x2bd2a622, 0xf105, 0x4ab9, { 0x8a, 0xf3, 0xc9, 0xa9, 0xb2, 0x97, 0x69, 0x66 } };

// {71694BB4-B99E-4a93-954C-8BA4107F5ECE}
static const GUID ERTSP_port_start = { 0x71694bb4, 0xb99e, 0x4a93, { 0x95, 0x4c, 0x8b, 0xa4, 0x10, 0x7f, 0x5e, 0xce } };

// {358132E2-8360-49b7-A902-B4F8CD77A181}
static const GUID ERTSP_port_stop = { 0x358132e2, 0x8360, 0x49b7, { 0xa9, 0x2, 0xb4, 0xf8, 0xcd, 0x77, 0xa1, 0x81 } };

// {50F7676C-7C8B-4c7e-B571-451807FF5CE4}
static const GUID ERTSP_client_port_start = { 0x50f7676c, 0x7c8b, 0x4c7e, { 0xb5, 0x71, 0x45, 0x18, 0x7, 0xff, 0x5c, 0xe4 } };

// {01360E30-95B2-4a2a-AFC0-D4D556501FD4}
static const GUID ERTSP_client_port_stop = { 0x1360e30, 0x95b2, 0x4a2a, { 0xaf, 0xc0, 0xd4, 0xd5, 0x56, 0x50, 0x1f, 0xd4 } };

// {3732C198-BB0C-4651-94AF-19593827D031}
static const GUID ERTSP_server_timeout = 
{ 0x3732c198, 0xbb0c, 0x4651, { 0x94, 0xaf, 0x19, 0x59, 0x38, 0x27, 0xd0, 0x31 } };

// {EA9A2214-61BE-4c4d-A2EB-772F904F6D90}
static const GUID ERTSP_use_sdp_config = { 0xea9a2214, 0x61be, 0x4c4d, { 0xa2, 0xeb, 0x77, 0x2f, 0x90, 0x4f, 0x6d, 0x90 } };

// {B21A77B0-150C-4d1d-9BA8-F8A601A24AB9}
static const GUID ERTSP_commands_dump = { 0xb21a77b0, 0x150c, 0x4d1d, { 0x9b, 0xa8, 0xf8, 0xa6, 0x1, 0xa2, 0x4a, 0xb9 } };

// {5A02B789-BA97-4ed5-A347-F89CBDA17DA9}
static const GUID ERTSP_play_rate = { 0x5a02b789, 0xba97, 0x4ed5, { 0xa3, 0x47, 0xf8, 0x9c, 0xbd, 0xa1, 0x7d, 0xa9 } };

// {e4176010-5b9a-4808-b745-9f6c46de57ea}
static const GUID ERTSP_any_source = { 0xe4176010, 0x5b9a, 0x4808, {0xb7, 0x45, 0x9f, 0x6c, 0x46, 0xde, 0x57, 0xea } };

// {9a5ea69c-868d-4420-8590-2738e1693246}
static const GUID ERTSP_latency = { 0x9a5ea69c, 0x868d, 0x4420, {0x85, 0x90, 0x27, 0x38, 0xe1, 0x69, 0x32, 0x46} };

// {8FEC54A5-DAA6-47a7-B111-1536D0748626}
static const GUID ERTSP_rtp_cache_size = { 0x8fec54a5, 0xdaa6, 0x47a7, { 0xb1, 0x11, 0x15, 0x36, 0xd0, 0x74, 0x86, 0x26 } };

// {8FA9585B-ACEA-4776-85FA-29F7ABCFFFF2}
static const GUID ERTSP_timeout_data = { 0x8fa9585b, 0xacea, 0x4776, { 0x85, 0xfa, 0x29, 0xf7, 0xab, 0xcf, 0xff, 0xf2 } };

// {382E7710-6DA6-40f6-8670-85F61E0A5C80}
static const GUID ERTSP_timeout_connect = { 0x382e7710, 0x6da6, 0x40f6, { 0x86, 0x70, 0x85, 0xf6, 0x1e, 0xa, 0x5c, 0x80 } };

// {8D4E2FDC-7E41-424e-AEC0-3354554EC070}
static const GUID ERTSP_keepalive_use_parameter = { 0x8d4e2fdc, 0x7e41, 0x424e, { 0xae, 0xc0, 0x33, 0x54, 0x55, 0x4e, 0xc0, 0x70 } };

// {61E4E0E1-52B0-430f-BF23-FBA7469F7587}
static const GUID ERTSP_last_ntp = { 0x61e4e0e1, 0x52b0, 0x430f, { 0xbf, 0x23, 0xfb, 0xa7, 0x46, 0x9f, 0x75, 0x87 } };

// {47994229-16E5-45c4-98B3-6D76CED26AC1}
static const GUID ERTSP_last_rtp = { 0x47994229, 0x16e5, 0x45c4, { 0x98, 0xb3, 0x6d, 0x76, 0xce, 0xd2, 0x6a, 0xc1 } };

// {4E9E24B2-9C9B-4F8F-92B7-DBFE5CC5D316}
static const GUID ERTSP_reconnect = 
{ 0x4e9e24b2, 0x9c9b, 0x4f8f, { 0x92, 0xb7, 0xdb, 0xfe, 0x5c, 0xc5, 0xd3, 0x16 } };

//////////////////////////////////////////////////////////////////////////
namespace ERTSPSource
{
	// RTSP commands compliance
	typedef enum _compatibles_enum
	{
		RFC_base_RTSP			= 0,
		Kasenna_RTSP			= 1,
		SeaChange_RTSP			= 2,
		SeaChange_RTSP_range	= 3,
		Darwin_RTSP				= 4,
		SeaChange_RTSP_208		= 5,
		compatible_auto			= 6
	} compatibles_enum;

	// RTSP transport
	typedef enum _transport_enum
	{
		transport_RTP	= 0
		,transport_MP2T	= 1
		,transport_RAW	= 2
	} transport_enum;

	// RTSP profile
	typedef enum _profile_enum
	{
		profile_AVP		= 0
		,profile_H2221	= 1
		,profile_RAW	= 2
	} profile_enum;

	// RTSP lower transport
	typedef enum _lower_transport_enum
	{
		lower_transp_UDP	= 0
		,lower_transp_TCP	= 1
	} lower_transport_enum;

};

#endif 
