//////////////////////////////////////////////////////////////////////////
//
//	created:	2006/03/10
//	file name:	enwsplus.h
//
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2005-2009 Elecard Ltd.
//  All rights are reserved.  Reproduction  in whole or  in part is  prohibited
//  without the written consent of the copyright owner.
//
//  Elecard Ltd reserves the right  to make changes to this software program
//  without notice  at any time.  Elecard Ltd makes no warranty,  expressed,
//  implied or statutory, including but not limited to  any implied warranty of
//  merchantability of fitness for any particular purpose.
//  Elecard Ltd  does not represent  or warrant that  the programs furnished
//  hereunder are free of infringement of any third-party patents, copyright or
//  trademark.
//  In no event shall Elecard Ltd be liable for any incidental, punitive, or
//  consequential damages of any kind  whatsoever arising from the use of these
//  programs.
//
///////////////////////////////////////////////////////////////////////////////
//
//	author:  Melnikov Grigoriy <Grigory.Melnikov@elecard.ru>
//	
//	purpose: Elecard NWSource-Plus parameters GUIDs 
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//	GUID					Value Type	Available range		Default Value	Note
//////////////////////////////////////////////////////////////////////////
//	ENS_announces_bstr		VT_UI8		announces_descr_ext struct			Announces descriptions.
//	ENS_port				VT_INT		DWORD values						Server port nubber
//	ENS_payload_emc			VT_INT		EMC_COMMON::STREAM_TYPE				Payload type - MP2T, MP2P, MP1S. This is old interface, please use ENS_payload_emc.
//	ENS_transport			VT_INT		transport_type						Transport type - UPD, RTP, APP
//	ENS_timeout				VT_INT		1..max_int			10				Timeout value in seconds
//	ENS_dmux_timeout		VT_INT		1..3600				30				PushDemuxer initialize timeout value in seconds
//	ENS_mcast_address		VT_BSTR											Multicast IP
//	ENS_interface			VT_BSTR											Network interfcae IP
//	ENS_server				VT_BSTR											Server IP
//	ENS_fixed_mediatype		VT_INT		0-Off/1-On			0				Fixed output mediatype for dynamic change: ports, server IP
//	ENS_disable_serv_sign	VT_INT		0-Off/1-On			0				Disable server signature validation
//	ENS_announce_sdp_data	VT_BSTR											SDP data for specific announce
//	ENS_dynamic_change_interf VT_INT	0-Off/1-On			1				Disable/Enable dynamic change network interface
//	ENS_cache_buffer_fullness VT_INT	0..max_int							Current receive from network buffer fullness in percents
//	ENS_latency				VT_I8		0..max_longlong		1500			Latency before playing
//	ENS_always_receive_sdp	VT_INT		0-Off/1-On			0				Enable/Disable always receive SDP data (usually receive begin after RegisterForNotify and finish after UnRegisterFromNotify)
//	ENS_current_sdp			VT_BSTR											SAP/SDP description
//	ENS_payload				VT_INT		ENWSource_Plus::payload_type		Payload type. This is old interface, please use ENS_payload_emc.
//      ENS_sapdestination      VT_INT
//      ENS_sapport             VT_INT
//      ENS_rtp_cache_size      VT_INT
//      ENS_buffer_size         VT_INT             0-max_int 4194304	Size of internal buffer to temporary store data after getting from network and before deliver to output
//////////////////////////////////////////////////////////////////////////
// NOTIFYCATIONS
//////////////////////////////////////////////////////////////////////////
//	ENS_announces			VT_UI8		announces_descr structure			Announces descriptions.
//  ENS_data_enable															Notify on data enabled
//	ENS_data_null															Notify on data not enabled
//	ENS_drop				VT_INT											Count drop packets

#ifndef _NW_SOURCE_PLUS_GUIDS_
#define _NW_SOURCE_PLUS_GUIDS_

//////////////////////////////////////////////////////////////////////////
// {7B3E0B86-8AA0-416d-8C2E-6ACDBFD61646}
static const GUID ENS_announces_bstr =  { 0x7b3e0b86, 0x8aa0, 0x416d, { 0x8c, 0x2e, 0x6a, 0xcd, 0xbf, 0xd6, 0x16, 0x46 } };

// {F152AA52-47F6-41af-9296-689C23C01943}
static const GUID ENS_sapdestination = { 0xf152aa52, 0x47f6, 0x41af, { 0x92, 0x96, 0x68, 0x9c, 0x23, 0xc0, 0x19, 0x43 } };

// {C502F4BD-6699-48ff-9086-ADCA4A9700C6}
static const GUID ENS_sapport = { 0xc502f4bd, 0x6699, 0x48ff, { 0x90, 0x86, 0xad, 0xca, 0x4a, 0x97, 0x0, 0xc6 } };

// {2977F94A-029A-4daf-B7D0-AA69B52E6147}
static const GUID ENS_port = { 0x2977f94a, 0x29a, 0x4daf, { 0xb7, 0xd0, 0xaa, 0x69, 0xb5, 0x2e, 0x61, 0x47 } };

// {C97BA6DF-C5EF-4d84-86D7-D49199FB7DA1}
static const GUID ENS_payload_emc = { 0xc97ba6df, 0xc5ef, 0x4d84, { 0x86, 0xd7, 0xd4, 0x91, 0x99, 0xfb, 0x7d, 0xa1 } };

// {01B51BBC-CA5B-4a54-A948-5DF641DBD98B}
static const GUID ENS_transport = { 0x1b51bbc, 0xca5b, 0x4a54, { 0xa9, 0x48, 0x5d, 0xf6, 0x41, 0xdb, 0xd9, 0x8b } };

// {8FA9585B-ACEA-4776-85FA-29F7ABCFFFF2}
static const GUID ENS_timeout = { 0x8fa9585b, 0xacea, 0x4776, { 0x85, 0xfa, 0x29, 0xf7, 0xab, 0xcf, 0xff, 0xf2 } };

// {36255965-9A9B-4e06-94F7-02AA7A8F1C8C}
static const GUID ENS_dmux_timeout = { 0x36255965, 0x9a9b, 0x4e06, { 0x94, 0xf7, 0x2, 0xaa, 0x7a, 0x8f, 0x1c, 0x8c } };

// {756E26AC-4E3F-4580-8503-2AFBB4FB33FB}
static const GUID ENS_mcast_address = { 0x756e26ac, 0x4e3f, 0x4580, { 0x85, 0x3, 0x2a, 0xfb, 0xb4, 0xfb, 0x33, 0xfb } };

// {3A7BF1FB-7627-4acf-9A20-31932E9930F6}
static const GUID ENS_interface =  { 0x3a7bf1fb, 0x7627, 0x4acf, { 0x9a, 0x20, 0x31, 0x93, 0x2e, 0x99, 0x30, 0xf6 } };

// {82BB61FC-E058-438e-A5DB-119A664459EB}
static const GUID ENS_server = { 0x82bb61fc, 0xe058, 0x438e, { 0xa5, 0xdb, 0x11, 0x9a, 0x66, 0x44, 0x59, 0xeb } };

// {FBA210A0-BA53-4c9c-A381-DDDB0A59E1E9}
static const GUID ENS_data_enable = { 0xfba210a0, 0xba53, 0x4c9c, { 0xa3, 0x81, 0xdd, 0xdb, 0xa, 0x59, 0xe1, 0xe9 } };

// {629E6687-E505-478b-9FF0-7007BD586046}
static const GUID ENS_data_null = { 0x629e6687, 0xe505, 0x478b, { 0x9f, 0xf0, 0x70, 0x7, 0xbd, 0x58, 0x60, 0x46 } };

// {4D5A4D51-B073-489c-82EB-70E16228C754}
static const GUID ENS_drop = { 0x4d5a4d51, 0xb073, 0x489c, { 0x82, 0xeb, 0x70, 0xe1, 0x62, 0x28, 0xc7, 0x54 } };

// {F7007218-0F14-4283-89C6-CDEBFF33A89E}
static const GUID ENS_fixed_mediatype = { 0xf7007218, 0xf14, 0x4283, { 0x89, 0xc6, 0xcd, 0xeb, 0xff, 0x33, 0xa8, 0x9e } };

// {DE15F3D6-F715-4656-A16F-825F6A610AA7}
static const GUID ENS_disable_serv_sign = { 0xde15f3d6, 0xf715, 0x4656, { 0xa1, 0x6f, 0x82, 0x5f, 0x6a, 0x61, 0xa, 0xa7 } };

// {EB240A31-B27A-461b-8203-C5717DD5A159}
static const GUID ENS_announce_sdp_data = { 0xeb240a31, 0xb27a, 0x461b, { 0x82, 0x3, 0xc5, 0x71, 0x7d, 0xd5, 0xa1, 0x59 } };

// {AE1A43AA-7139-4c2d-990C-9E5EF4DF1238}
static const GUID ENS_dynamic_change_interf = { 0xae1a43aa, 0x7139, 0x4c2d, { 0x99, 0xc, 0x9e, 0x5e, 0xf4, 0xdf, 0x12, 0x38 } };

// {0AB41357-8058-4a27-B42B-8049BCAC0773}
static const GUID ENS_cache_buffer_fullness = { 0xab41357, 0x8058, 0x4a27, { 0xb4, 0x2b, 0x80, 0x49, 0xbc, 0xac, 0x7, 0x73 } };

// {882658FB-434D-4920-B1E2-C2DD128B8B44}
static const GUID ENS_latency = { 0x882658fb, 0x434d, 0x4920, { 0xb1, 0xe2, 0xc2, 0xdd, 0x12, 0x8b, 0x8b, 0x44 } };

// {807CF24E-A113-4cbb-A57E-6A67B7E82193}
static const GUID ENS_always_receive_sdp = { 0x807cf24e, 0xa113, 0x4cbb, { 0xa5, 0x7e, 0x6a, 0x67, 0xb7, 0xe8, 0x21, 0x93 } };

// {D54E2D4C-0BE9-461c-8DA2-6930365C1B75}
static const GUID ENS_current_sdp = { 0xd54e2d4c, 0xbe9, 0x461c, { 0x8d, 0xa2, 0x69, 0x30, 0x36, 0x5c, 0x1b, 0x75 } };

// {8FEC54A5-DAA6-47a7-B111-1536D0748626}
static const GUID ENS_rtp_cache_size = { 0x8fec54a5, 0xdaa6, 0x47a7, { 0xb1, 0x11, 0x15, 0x36, 0xd0, 0x74, 0x86, 0x26 } };

// {3CAD425C-4131-4bb3-83D7-248F9F8C9637}
static const GUID ENS_free_mem_on_overflow = { 0x3cad425c, 0x4131, 0x4bb3, { 0x83, 0xd7, 0x24, 0x8f, 0x9f, 0x8c, 0x96, 0x37 } };

// {EA14C343-AF2E-4e4c-9765-8D68E6AF4F22}
static const GUID ENS_socket_buff_size = { 0xea14c343, 0xaf2e, 0x4e4c, { 0x97, 0x65, 0x8d, 0x68, 0xe6, 0xaf, 0x4f, 0x22 } };


// {2E81B2C8-390F-4fbb-8934-27EFF836C9A6}
static const GUID ENS_saptimeout = { 0x2e81b2c8, 0x390f, 0x4fbb, { 0x89, 0x34, 0x27, 0xef, 0xf8, 0x36, 0xc9, 0xa6 } };

// {EC38446F-340E-402d-9CEB-7D4BEA1BA5B1}
static const GUID EMC_crashdump = { 0xec38446f, 0x340e, 0x402d, { 0x9c, 0xeb, 0x7d, 0x4b, 0xea, 0x1b, 0xa5, 0xb1 } };

// {6E3B295E-4BB8-46b2-A726-9B6CA519866F}
static const GUID ENS_buffer_size = { 0x6e3b295e, 0x4bb8, 0x46b2, { 0xa7, 0x26, 0x9b, 0x6c, 0xa5, 0x19, 0x86, 0x6f } };

// {cfeb46ef-8df9-45ad-a340-c048095ecc41}
static const GUID ENS_fec_type = { 0xcfeb46ef, 0x8df9, 0x45ad, { 0xa3, 0x40, 0xc0, 0x48, 0x09, 0x5e, 0xcc, 0x41 } };

// {c46817d8-fb81-4430-a6ae-cc92b6d94302}
static const GUID ENS_fec_rows_port = { 0xc46817d8, 0xfb81, 0x4430, { 0xa6, 0xae, 0xcc, 0x92, 0xb6, 0xd9, 0x43, 0x02 } };

// {c3c2e0f5-65c5-4c15-9146-2af1109db73c}
static const GUID ENS_fec_collumns_port = {0xc3c2e0f5, 0x65c5, 0x4c15, { 0x91, 0x46, 0x2a, 0xf1, 0x10, 0x9d, 0xb7, 0x3c } };

// {f0a7732d-740e-46c4-88bd-8ffb8a693642}
static const GUID ENS_fec_restored_packets = {0xf0a7732d, 0x740e, 0x46c4, { 0x88, 0xbd, 0x8f, 0xfb, 0x8a, 0x69, 0x36, 0x42 } };




//////////////////////////////////////////////////////////////////////////
// OLD INTERFACES
// {0F058D32-7808-49cd-AA1F-EA20E4E4CF2F}
static const GUID ENS_announces = { 0xf058d32, 0x7808, 0x49cd, { 0xaa, 0x1f, 0xea, 0x20, 0xe4, 0xe4, 0xcf, 0x2f } };

// {D9AA8694-43E3-4dd8-A440-A076796B4D23}
static const GUID ENS_payload = { 0xd9aa8694, 0x43e3, 0x4dd8, { 0xa4, 0x40, 0xa0, 0x76, 0x79, 0x6b, 0x4d, 0x23 } };




//////////////////////////////////////////////////////////////////////////
//	Elecard NWSource-Plus namespace
//////////////////////////////////////////////////////////////////////////
namespace ENWSource_Plus
{
	typedef enum _eStreamType 
	{
		E_STREAM_TYPE_UNKNOWN	= 0,
		E_STREAM_TYPE_SYSTEM	= 1,	// MPEG1 System 
		E_STREAM_TYPE_PROGRAM	= 2,	// MPEG2 Programm
		E_STREAM_TYPE_TRANSPORT	= 3,	// MPEG2 Transport
		E_STREAM_TYPE_MPEG2V	= 4,	// MPEG2 Video
		E_STREAM_TYPE_PVA		= 5,	// 
		E_STREAM_TYPE_MPEG2A	= 6,	// MPEG2 Audio
		E_STREAM_TYPE_AC3		= 7,	// AC3 Audio
		E_STREAM_TYPE_H264		= 8,	// H264/AVC Video
		E_STREAM_TYPE_MPEG4		= 9,	// MPEG4
		E_STREAM_TYPE_VC1		= 10,	// 
		E_STREAM_TYPE_H263		= 11,	// H263
		E_STREAM_TYPE_MPEG4V	= 12,	// MPEG4 Video
		E_STREAM_TYPE_AAC		= 13,	// AAC Audio
		E_STREAM_TYPE_MPEG1V	= 14,	// MPEG1 Video
		E_STREAM_TYPE_MPEG1A	= 15,	// MPEG1 Audio
		E_STREAM_TYPE_DIV3		= 16,	// 
		E_STREAM_TYPE_DIV4		= 17,	// 
		E_STREAM_TYPE_DIV5		= 18,	// 
		E_STREAM_TYPE_VSSH		= 19,	// VideoSoft H264 (under development - no parcer)
		E_STREAM_TYPE_PCM		= 20,	// LPCM (under development)
		E_STREAM_TYPE_DVDSUB	= 21,	// 
		E_STREAM_TYPE_LATM		= 22
	} STREAM_TYPE;

	// payload type
	enum payload_type{	PayloadType_MP1S = 0,
						PayloadType_MP2P = 1,
						PayloadType_MP2T = 2,
						PayloadType_MP4v = 3,
						PayloadType_MP4a = 4,
						PayloadType_H264 = 5,
						PayloadType_latm = 6,
						PayloadType_UNKNOWN = 999
					};

	//transport type
	enum transport_type{TransType_UDP = 0,
						TransType_RTP = 1,
						TransType_TCP = 2,
						TransType_TCP_rtp = 3,
						TransType_UNKNOWN = 999
						};

	//////////////////////////////////////////////////////////////////////////
	// Announces description structure
	//////////////////////////////////////////////////////////////////////////
	typedef struct _announces_descr_ext
	{
		// count announces
		unsigned long cnt_announces;

		//////////////////////////////////////////////////////////////////////////
		//	Extended announce description structure
		//////////////////////////////////////////////////////////////////////////
		struct announce_struct_ext
		{
			// count sources streams
			WORD	m_cnt_sources;

			// payload type
			STREAM_TYPE *m_payload;

			// host port
			unsigned int *m_Mcast_port;

			// transport type
			transport_type m_transport;

			// session name
			BSTR	m_session_name;
			// session information
			BSTR	m_session_information;
			// session description
			BSTR	m_description;
			// email
			BSTR	m_email;
			// phone
			BSTR	m_phone;
			// bandwidth
			BSTR	m_bandwidth_information;

			// mcast adress
			BSTR	m_Mcast_address;
			// interface IP
			BSTR	m_interface;
			// host IP
			BSTR	m_server_address;

			// time-to-live (TTL)
			short	m_TTL;

			// session ID
			BSTR	m_sessionID;

			// SDP description
			BSTR	m_SDPdata;
		} *announces_description;

	} announces_descr_ext;

	//////////////////////////////////////////////////////////////////////////
	//	Base structure for announce description
	//////////////////////////////////////////////////////////////////////////
	struct announce_struct_base
	{
	public:
		// transport type
		transport_type m_transport;

		// session name
		char	m_session_name[MAX_PATH];
		// session information
		char	m_session_information[MAX_PATH];
		// session description
		char	m_description[MAX_PATH];
		// email
		char	m_email[MAX_PATH];
		// phone
		char	m_phone[MAX_PATH];
		// bandwidth
		char	m_bandwidth_information[MAX_PATH];

		// mcast adress
		char	m_Mcast_address[MAX_PATH];
		// interface IP
		char	m_interface[MAX_PATH];
		// host IP
		char	m_server_address[MAX_PATH];

		// time-to-live (TTL)
		short	m_TTL;

		// session ID
		char	m_sessionID[MAX_PATH];
	};

	//////////////////////////////////////////////////////////////////////////
	// Announces description structure
	//////////////////////////////////////////////////////////////////////////
	typedef struct _announces_descr
	{
		// count announces
		unsigned long cnt_announces;

		//////////////////////////////////////////////////////////////////////////
		//	Extended announce description structure
		//////////////////////////////////////////////////////////////////////////
		struct announce_struct:	public announce_struct_base
		{
			announce_struct()
				: m_payload(NULL)
				, m_Mcast_port(NULL)
				, m_cnt_sources(0)
			{
			}

			// count sources streams
			WORD	m_cnt_sources;

			// payload type
			payload_type *m_payload;

			// host port
			unsigned int *m_Mcast_port;
		} *announces_description;
	} announces_descr;

	enum fec_type
	{
		FecTypeNone = 0,
		FecType1D = 1,
		FecType2D = 2
	};
};

#endif 
