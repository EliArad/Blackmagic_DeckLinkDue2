//////////////////////////////////////////////////////////////////////////
//
//	created:	2009/01/09
//	file name:	empegmux.h
//	author:		Alexander Ustinov
//
//////////////////////////////////////////////////////////////////////////
//
//	Copyright (c) 2009 Elecard.
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
//	purpose: The definition of the Elecard MPEG multiplexer filter's parameters CLSIDs and type definitions
//
//////////////////////////////////////////////////////////////////////////

//Elementary stream properties(Accessible via Input Pin's IModuleConfig)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    GUID							   Type			 Available range             Default Value           Note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EMUX_StreamType						VT_I4		ELEMENTARY_STREAM_TYPE		ES_UNKNOWN				Shows current connection ES Type. ES_UNKNOWN if pin is not connected
//EMUX_InputBufSize						VT_I4		[1MB-45MB]					2000000					Parser buffer size
//EMUX_StreamPID						VT_I4		[0-8191]					0						ES PID. MUST be set in non zero value. 
//EMUX_StreamPESID						VT_I4		[0-255]						224(video), 192(audio)	PES ID for the stream (Table 2-18 in ISO/IES 13818-1) 
//EMUX_StreamBitrate					VT_I4		Unbounded					0						If 0 muxer get bitrate from AM_MEDIA_TYPE of the connection
//EMUX_UpdateBitrateStatTimeout			VT_I4		Unbounded					300						Update bitrate statistic timeout (msec)
//EMUX_SizeofBitrateStatMA				VT_I4		[100-60000]					2000					Size of bitrate statistic moving average (msec)
//EMUX_InitialShift						VT_I4		[0-20000]					0						In milliseconds
//EMUX_StreamOwnerPID					VT_I4		0,List						0						Allow to set PMT PID of existing programs
//EMUX_DescriptorLength					VT_I4		[0-2048]					0						
//EMUX_DescriptorData					VT_PTR			-						-						Rewrites data from input values to internal buffer and from internal buffer to input array
//EMUX_ChangeLanguage					VT_PTR		3 characters array of new language working only if language descriptor exists


//Output stream properties(Accessible via Output Pin's IModuleConfig)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    GUID					             Type        Available range             Default Value           Note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EMUX_OutputStreamType					VT_I4		STREAM_TYPE					TRANSPORT_STREAM		
//EMUX_Initial_Delay					VT_I4		[-1000-+1000]				0						In milliseconds. Delay for filling of the STD buffers.
//EMUX_VideoBufferingDelay				VT_I4		[-1000-20000]				0						In milliseconds. Delay for video decoding.
//EMUX_LiveMode							VT_I4		[0-off;1-yes]				0						Allows muxer do not stuck in realtime transcoding.
//EMUX_TS_Required_Bitrate				VT_I4		[0-1000M]					0						In bit/s. 0 means automatically bitrate calculation(output bitrate = (sum of ES bitrates)*1.1) (Transport stream only)
//EMUX_TS_PCR_Interval					VT_I4		[10-500]					25						In milliseconds. PCR timestamping interval for every ES. (Transport stream only)
//EMUX_TS_ID							VT_I4		[0-0xFFFF]					0						(Transport stream only)
//EMUX_TS_Padding						VT_I4		[0 - no;1 - yes]			Yes						Use padding in transport stream. If it set to No PCR calculates as if padding exists.(Transport stream only)
//EMUX_TS_Number_Of_Packets_To_Deliver	VT_I4		[1-100]						1						Outbut buffer size (in transport packets units)(Transport stream only)
//EMUX_TS_LowDelay						VT_I4		[0;1]						0						Use low delay muxing mode. 0 - false; 1 - true;
//EMUX_TS_DVB_Style						VT_I4		[0;1]						0						0 - ATSC style, 1 - DVB style
//EMUX_AdjustSysClockByStreamTime		VT_I4		[0;1]						0						Adjust System Clock by stream time (0 - Off, 1 - On)
//EMUX_DvdCompatible					VT_I4		[0;1]						0						Generate DVD compatible Program Stream (0 - Off, 1 - On)
//EMUX_WriteCrashDumpFiles				VT_I4		[0;1]						1						Write Crash-dump files (.dmp)


//Programs management options(Accessible via Filter's IModuleConfig)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    GUID					             Type        Available range             Default Value           Note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EMUX_GetNextProgram					VT_UNKNOWN	0,IUnknown											Get next program from the programs list. (Next means after program pointer to which pointer was set before caling this method). If input parameter equal NULL this method returns the first program in the list. If end of the list achieved method return NULL. User have to release returned pointer.
//EMUX_CreateProgram					VT_UNKNOWN	IUnknown											Creates the program, insert it after the current program and returns pointer to the program. User have to release the returned pointer.
//EMUX_DestroyProgram					VT_UNKNOWN	IUnknown											Deletes the current program from the list and set current program to the next program after removed. If this is the last program in list current program sets to the previous program. Can not delete the last program.
//EMUX_Program							VT_UNKNOWN	IUnknown											Returns pointer to the current program in list. Returned pointer have to be released.

//Programs options (Accessible via IModuleConfig of programs you can get with Programs managment methods)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    GUID					             Type        Available range             Default Value           Note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EMUX_ProgramID						VT_I4		[0-0x1FFF]					0				PMT PID of the program. 
//EMUX_ProgramNumber					VT_I4		[1-0x1000]					1				Program Number. 
//EMUX_PCR_PID							VT_I4		0,List						0				PID of ES carries PCR the program.

//Streams management options(accessible via Program's IModuleConfig)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    GUID					             Type        Available range             Default Value           Note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EMUX_GetNextStream					VT_UNKNOWN	0, IUnknown									    Get next stream in the program. (Next means after stream pointer to which pointer was set before caling this method). If input parameter equal NULL this method returns the first stream in the program. If end of the list achieved method return NULL. User have to release returned pointer.
//EMUX_DescriptorLength					VT_I4		[0-2048]					0						
//EMUX_DescriptorData					VT_PTR		-							-					Rewrites data from input values to internal buffer and from internal buffer to input array


#ifndef __EMPEGMUX_H__
#define __EMPEGMUX_H__

// {5DF046B3-0089-4646-8002-8E2A96D95207}
static const GUID EMUX_Program = {
	0x5df046b3, 0x0089, 0x4646,{ 0x80, 0x2, 0x8e, 0x2a, 0x96, 0xd9, 0x52, 0x7}};

// {D73893EE-5FB8-49bf-A08A-E16AC25A9DE2}
static const GUID EMUX_GetNextProgram = {
	0xd73893ee, 0x5fb8, 0x49bf,{ 0xa0, 0x8a, 0xe1, 0x6a, 0xc2, 0x5a, 0x9d, 0xe2}};

// {A2FFF856-3C45-4b0b-AD5D-9C77937CEFE4}
static const GUID EMUX_CreateProgram = {
	0xa2fff856, 0x3c45, 0x4b0b,{ 0xad, 0x5d, 0x9c, 0x77, 0x93, 0x7c, 0xef, 0xe4}};

// {479C74F9-809F-41d7-81A7-CBE810EEB4F2}
static const GUID EMUX_DestroyProgram = {
	0x479c74f9, 0x809f, 0x41d7,{ 0x81, 0xa7, 0xcb, 0xe8, 0x10, 0xee, 0xb4, 0xf2}};

// {A06123DE-2234-41f1-A961-716163488A9B}
static const GUID EMUX_OutputStreamType = {
	0xa06123de, 0x2234, 0x41f1,{ 0xa9, 0x61, 0x71, 0x61, 0x63, 0x48, 0x8a, 0x9b}};

// {61A1D036-FCB0-40b5-B649-5B32BEB76D00}
static const GUID EMUX_TS_Required_Bitrate = {
	0x61a1d036, 0xfcb0, 0x40b5,{ 0xb6, 0x49, 0x5b, 0x32, 0xbe, 0xb7, 0x6d, 0x0}};

// {7D1C6AB8-FE1C-4440-8A2C-39D4E2B533A3}
static const GUID EMUX_TS_PCR_Interval = {
	0x7d1c6ab8, 0xfe1c, 0x4440,{ 0x8a, 0x2c, 0x39, 0xd4, 0xe2, 0xb5, 0x33, 0xa3}};

// {34381DB1-3CD6-4ba9-A7C0-6693C5C904BA}
static const GUID EMUX_TS_ID = {
	0x34381db1, 0x3cd6, 0x4ba9,{ 0xa7, 0xc0, 0x66, 0x93, 0xc5, 0xc9, 0x4, 0xba}};

// {CA39159F-C9D9-42d5-88DB-317B2668ED51}
static const GUID EMUX_TS_Padding = {
	0xca39159f, 0xc9d9, 0x42d5,{ 0x88, 0xdb, 0x31, 0x7b, 0x26, 0x68, 0xed, 0x51}};

// {381B03F4-899E-46f3-880F-39C487048444}
static const GUID EMUX_TS_Number_Of_Packets_To_Deliver = {
	0x381b03f4, 0x899e, 0x46f3,{ 0x88, 0xf, 0x39, 0xc4, 0x87, 0x4, 0x84, 0x44}};

// {316EBBEA-002E-498e-B45F-CEF6B94CDAC9}
static const GUID EMUX_Initial_Delay = {
	0x316ebbea, 0x002e, 0x498e,{ 0xb4, 0x5f, 0xce, 0xf6, 0xb9, 0x4c, 0xda, 0xc9}};

// {D4804B3D-1F83-4182-9B24-C8494AB7391F}
static const GUID EMUX_VideoBufferingDelay = 
{ 0xd4804b3d, 0x1f83, 0x4182, { 0x9b, 0x24, 0xc8, 0x49, 0x4a, 0xb7, 0x39, 0x1f } };

// {2079DB46-6D4B-4630-9B91-C593E8C6F65E}
static const GUID EMUX_ProgramNumber = {
	0x2079db46, 0x6d4b, 0x4630,{ 0x9b, 0x91, 0xc5, 0x93, 0xe8, 0xc6, 0xf6, 0x5e}};

// {531E2E4C-D7DD-40a6-8772-F6A4FC4AC643}
static const GUID EMUX_ProgramID = {
	0x531e2e4c, 0xd7dd, 0x40a6,{ 0x87, 0x72, 0xf6, 0xa4, 0xfc, 0x4a, 0xc6, 0x43}};

// {9D77D0FB-448F-4de4-9642-1B4E9E12EFE6}
static const GUID EMUX_PCR_PID = {
	0x9d77d0fb, 0x448f, 0x4de4,{ 0x96, 0x42, 0x1b, 0x4e, 0x9e, 0x12, 0xef, 0xe6}};

// {8EB43758-EAC1-4b66-8AC7-9955BD4752E1}
static const GUID EMUX_StreamType = { 
	0x8eb43758, 0xeac1, 0x4b66,{ 0x8a, 0xc7, 0x99, 0x55, 0xbd, 0x47, 0x52, 0xe1}};

// {83CB7DC0-B1FA-4c47-88C1-CF2DA869A6F0}
static const GUID EMUX_InputBufSize = {
	0x83cb7dc0, 0xb1fa, 0x4c47,{ 0x88, 0xc1, 0xcf, 0x2d, 0xa8, 0x69, 0xa6, 0xf0}};

// {14641AEE-6404-4e26-95D8-61855B6D8B1B}
static const GUID EMUX_InitialShift = {
	0x14641aee, 0x6404, 0x4e26,{ 0x95, 0xd8, 0x61, 0x85, 0x5b, 0x6d, 0x8b, 0x1b}};

// {1A0394D6-EAF7-4043-BC3E-0432D18EF7BF}
static const GUID EMUX_StreamPID = {
	0x1a0394d6, 0xeaf7, 0x4043,{ 0xbc, 0x3e, 0x4, 0x32, 0xd1, 0x8e, 0xf7, 0xbf}};

// {756F8041-6B17-4a5d-8BF5-DCBB92CDCA30}
static const GUID EMUX_StreamPESID = {
	0x756f8041, 0x6b17, 0x4a5d,{ 0x8b, 0xf5, 0xdc, 0xbb, 0x92, 0xcd, 0xca, 0x30}};

// {4A5DB920-D142-4902-A319-7F484BE955B0}
static const GUID EMUX_StreamBitrate = {
	0x4a5db920, 0xd142, 0x4902,{ 0xa3, 0x19, 0x7f, 0x48, 0x4b, 0xe9, 0x55, 0xb0}};

// {72CD0C8F-18C3-4567-B568-F4EF488C9FFA}
static const GUID EMUX_StreamOwnerPID = {
	0x72cd0c8f, 0x18c3, 0x4567,{ 0xb5, 0x68, 0xf4, 0xef, 0x48, 0x8c, 0x9f, 0xfa}};

// {1736955D-05C3-4054-8223-ACDE0C28C5FE}
static const GUID EMUX_DescriptorLength = {
	0x1736955d, 0x05c3, 0x4054,{ 0x82, 0x23, 0xac, 0xde, 0xc, 0x28, 0xc5, 0xfe}};

// {A867BCF5-91DF-4329-91C1-707EA60F383A}
static const GUID EMUX_DescriptorData = {
	0xa867bcf5, 0x91df, 0x4329,{ 0x91, 0xc1, 0x70, 0x7e, 0xa6, 0xf, 0x38, 0x3a}};

// {6B8A4CDE-3537-48f2-A9BC-C78240FC1614}
static const GUID EMUX_ChangeLanguage = {
	0x6b8a4cde, 0x3537, 0x48f2,{ 0xa9, 0xbc, 0xc7, 0x82, 0x40, 0xfc, 0x16, 0x14}};

// {2AE31144-9B73-4b78-B827-D8484FAC31BE}
static const GUID EMUX_GetNextStream = {
	0x2ae31144, 0x9b73, 0x4b78,{ 0xb8, 0x27, 0xd8, 0x48, 0x4f, 0xac, 0x31, 0xbe}};

// {C1827FB2-AA5C-40c9-8326-0DA6A6AF36C8}
static const GUID EMUX_MoveStreamTo = {
	0xc1827fb2, 0xaa5c, 0x40c9,{ 0x83, 0x26, 0xd, 0xa6, 0xa6, 0xaf, 0x36, 0xc8}};

// {227D014D-964C-4ab5-BC43-94199A1AEEA6}
static const GUID EMUX_Stream = {
	0x227d014d, 0x964c, 0x4ab5,{ 0xbc, 0x43, 0x94, 0x19, 0x9a, 0x1a, 0xee, 0xa6}};

// {F7264585-4C3B-48f4-81FF-3DC00ACBE88A}
static const GUID EMUX_Overhead = {
	0xf7264585, 0x4c3b, 0x48f4,{ 0x81, 0xff, 0x3d, 0xc0, 0xa, 0xcb, 0xe8, 0x8a}};

// {396F1A79-6777-4b0a-883D-BF7B7EFE629A}
static const GUID EMUX_Mux_Time = {
	0x396f1a79, 0x6777, 0x4b0a,{ 0x88, 0x3d, 0xbf, 0x7b, 0x7e, 0xfe, 0x62, 0x9a}};

// {59A0406C-B3E8-48b8-BF75-B9C49EC6970E}
static const GUID EMUX_Output_Bitrate = {
	0x59a0406c, 0xb3e8, 0x48b8,{ 0xbf, 0x75, 0xb9, 0xc4, 0x9e, 0xc6, 0x97, 0xe}};

// {30CE7853-9698-4940-95C6-11AEFDE07844}
static const GUID EMUX_Number_Of_Padding_Packets = {
	0x30ce7853, 0x9698, 0x4940,{ 0x95, 0xc6, 0x11, 0xae, 0xfd, 0xe0, 0x78, 0x44}};

// {6B1DF39E-087A-4735-90DA-1D0BC939772D}
static const GUID EMUX_StreamBitrateAnnounced = {
	0x6b1df39e, 0x087a, 0x4735,{ 0x90, 0xda, 0x1d, 0xb, 0xc9, 0x39, 0x77, 0x2d}};

// {7DA3A717-DFB2-4818-8A21-F4669150F83E}
static const GUID EMUX_StreamBitrateReal = {
	0x7da3a717, 0xdfb2, 0x4818,{ 0x8a, 0x21, 0xf4, 0x66, 0x91, 0x50, 0xf8, 0x3e}};

// {117E8920-4B6D-4bf9-851D-BF415987F46E}
static const GUID EMUX_StreamTime = {
	0x117e8920, 0x4b6d, 0x4bf9,{ 0x85, 0x1d, 0xbf, 0x41, 0x59, 0x87, 0xf4, 0x6e}};

// {66BDC41D-2FC7-4002-97E4-6317043BD825}
static const GUID EMUX_TS_LowDelay = 
{ 0x66bdc41d, 0x2fc7, 0x4002, { 0x97, 0xe4, 0x63, 0x17, 0x4, 0x3b, 0xd8, 0x25 } };

// {3BAF78C1-8A06-422b-B25A-2992E967E211}
static const GUID EMUX_LiveMode = 
{ 0x3baf78c1, 0x8a06, 0x422b, { 0xb2, 0x5a, 0x29, 0x92, 0xe9, 0x67, 0xe2, 0x11 } };

// {C053E894-1F3C-4540-976A-47068F85D012}
static const GUID EMUX_NIT_Table_Data = 
{ 0xc053e894, 0x1f3c, 0x4540, { 0x97, 0x6a, 0x47, 0x6, 0x8f, 0x85, 0xd0, 0x12 } };

// {D2B72160-0338-4c62-94B8-0F1119B35336}
static const GUID EMUX_BAT_SDT_Table_Data = 
{ 0xd2b72160, 0x338, 0x4c62, { 0x94, 0xb8, 0xf, 0x11, 0x19, 0xb3, 0x53, 0x36 } };

// {BD41CC55-4ED0-457c-BCA2-864DE8DA8982}
static const GUID EMUX_EIT_Table_Data = 
{ 0xbd41cc55, 0x4ed0, 0x457c, { 0xbc, 0xa2, 0x86, 0x4d, 0xe8, 0xda, 0x89, 0x82 } };

// {4B2BA8B7-19E3-4a14-8F5C-EA7E159D450A}
static const GUID EMUX_TDT_TOT_Table_Data = 
{ 0x4b2ba8b7, 0x19e3, 0x4a14, { 0x8f, 0x5c, 0xea, 0x7e, 0x15, 0x9d, 0x45, 0xa } };

// {1077E849-0C5A-4e35-A772-2633A0627079}
static const GUID EMUX_RST_Table_Data = 
{ 0x1077e849, 0xc5a, 0x4e35, { 0xa7, 0x72, 0x26, 0x33, 0xa0, 0x62, 0x70, 0x79 } };

// {028A5614-9E02-4a87-BFBF-F19F40D3F9F6}
static const GUID EMUX_NIT_Table_Size = 
{ 0x28a5614, 0x9e02, 0x4a87, { 0xbf, 0xbf, 0xf1, 0x9f, 0x40, 0xd3, 0xf9, 0xf6 } };

// {F3DE72A9-35B0-4bf9-B192-3E94AC5783F0}
static const GUID EMUX_BAT_SDT_Table_Size = 
{ 0xf3de72a9, 0x35b0, 0x4bf9, { 0xb1, 0x92, 0x3e, 0x94, 0xac, 0x57, 0x83, 0xf0 } };

// {0784EFEA-B954-4b67-B949-150EB3C1918C}
static const GUID EMUX_EIT_Table_Size = 
{ 0x784efea, 0xb954, 0x4b67, { 0xb9, 0x49, 0x15, 0xe, 0xb3, 0xc1, 0x91, 0x8c } };

// {A2C42BE4-07C4-412f-9721-4B1C38B94929}
static const GUID EMUX_TDT_TOT_Table_Size = 
{ 0xa2c42be4, 0x7c4, 0x412f, { 0x97, 0x21, 0x4b, 0x1c, 0x38, 0xb9, 0x49, 0x29 } };

// {BB423127-138B-42d9-97B4-37DB3C583EE4}
static const GUID EMUX_RST_Table_Size = 
{ 0xbb423127, 0x138b, 0x42d9, { 0x97, 0xb4, 0x37, 0xdb, 0x3c, 0x58, 0x3e, 0xe4 } };

// {FD39C3C7-D4BB-4a6a-9323-2904D0CF6FB3}
static const GUID EMUX_TS_DVB_Style = 
{ 0xfd39c3c7, 0xd4bb, 0x4a6a, { 0x93, 0x23, 0x29, 0x4, 0xd0, 0xcf, 0x6f, 0xb3 } };

// {BDF70F2B-6509-4d2b-A628-EFFC5E38D830}
static const GUID EMUX_AdjustSysClockByStreamTime = 
{ 0xbdf70f2b, 0x6509, 0x4d2b, { 0xa6, 0x28, 0xef, 0xfc, 0x5e, 0x38, 0xd8, 0x30 } };

// {65AD4B82-FAF5-48ca-A6AD-DD96A90BEA2D}
static const GUID EMUX_DvdCompatible = 
{ 0x65ad4b82, 0xfaf5, 0x48ca, { 0xa6, 0xad, 0xdd, 0x96, 0xa9, 0xb, 0xea, 0x2d } };

// {E4B60957-6BCC-4fab-B9CE-1CF795E36407}
static const GUID EMUX_TS_PSI_Interval = 
{ 0xe4b60957, 0x6bcc, 0x4fab, { 0xb9, 0xce, 0x1c, 0xf7, 0x95, 0xe3, 0x64, 0x7 } };

// {856B3514-F948-4c0f-A824-33DFB80C3BDF}
static const GUID EMUX_Padding_Level = 
{ 0x856b3514, 0xf948, 0x4c0f, { 0xa8, 0x24, 0x33, 0xdf, 0xb8, 0xc, 0x3b, 0xdf } };

// {0C05EA52-50CE-467a-B9BB-6DE3C44E837E}
static const GUID EMUX_UseInputOverrunProtection = 
{ 0xc05ea52, 0x50ce, 0x467a, { 0xb9, 0xbb, 0x6d, 0xe3, 0xc4, 0x4e, 0x83, 0x7e } };

// {F8924013-D116-489e-9C07-10374F4F6410}
static const GUID EMUX_LiveModeDataMonitoringTimeout = 
{ 0xf8924013, 0xd116, 0x489e, { 0x9c, 0x7, 0x10, 0x37, 0x4f, 0x4f, 0x64, 0x10 } };

// {07BAA071-9122-4723-B6BF-FD7418511C32}
static const GUID EMUX_WriteCrashDumpFiles = 
{ 0x7baa071, 0x9122, 0x4723, { 0xb6, 0xbf, 0xfd, 0x74, 0x18, 0x51, 0x1c, 0x32 } };

// {AEA89C38-BCCF-48f4-A86F-74554BB4C606}
static const GUID EMUX_HEVCOverrideFrameRate =
{ 0xaea89c38, 0xbccf, 0x48f4, { 0xa8, 0x6f, 0x74, 0x55, 0x4b, 0xb4, 0xc6, 0x6 } };

// {16952F5C-F4E5-4421-B7DD-E20449070DBD}
static const GUID EMUX_OverrideStreamType = 
{ 0x16952f5c, 0xf4e5, 0x4421, { 0xb7, 0xdd, 0xe2, 0x4, 0x49, 0x7, 0xd, 0xbd } };

// {4A2B85A3-8270-42c9-A3B8-F62A671440EF}
static const GUID EMUX_InverseByteOrder = {
	0x4a2b85a3, 0x8270, 0x42c9, { 0xa3, 0xb8, 0xf6, 0x2a, 0x67, 0x14, 0x40, 0xef } };

// {22FB97CB-1D59-47CB-9361-574ABC8E148F}
static const GUID EMUX_SmartVbrMultiplexing =
{ 0x22fb97cb, 0x1d59, 0x47cb, { 0x93, 0x61, 0x57, 0x4a, 0xbc, 0x8e, 0x14, 0x8f } };


namespace EMPEGMUX {

enum ELEMENTARY_STREAM_TYPE {	
	STREAM_PRIVATE1 = 0,
	STREAM_PRIVATE2,
	STREAM_DVB_SUBTITLE,
	STREAM_DVD_SUBTITLE,
	STREAM_TELETEXT,

	STREAM_MPEG2_VIDEO,
	STREAM_MPEG1_VIDEO,
	STREAM_AVC_VIDEO,
	STREAM_MPEG4_VIDEO,
	STREAM_VC1_VIDEO,
	STREAM_HEVC_VIDEO,

	STREAM_MPEG1_AUDIO,
	STREAM_MPEG2_AUDIO,
	STREAM_AC3_AUDIO,
	STREAM_LPCM_AUDIO,
	STREAM_AAC_AUDIO,
	STREAM_EAC3_AUDIO,
	STREAM_DTS_AUDIO,
	STREAM_DTSHD_AUDIO,
	STREAM_LATM_AUDIO
};

enum ELEMENTARY_STREAM_TYPE2 {
	STREAM_UNDEF = STREAM_PRIVATE1 - 1,
};

enum STREAM_TYPE {
	PROGRAM_STREAM = 1, TRANSPORT_STREAM = 2, DVD_PROGRAM_STREAM, SVCD_PROGRAM_STREAM, VCD_PROGRAM_STREAM, MPEG1_SYSTEM_STREAM, AVCHD_TRANSPORT_STREAM
};


}	// namespace EMPEGMUX

#endif	// __EMPEGMUX_H__
