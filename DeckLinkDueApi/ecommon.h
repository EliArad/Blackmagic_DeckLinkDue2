///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2014 Elecard.
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

#ifndef _ECOMMON_
#define _ECOMMON_

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  GUID                        Value Type      Available range    Default Value   Note
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Unified for all components
//
// EMC_NAME                     VT_BSTR         type limits         undefined       Full component name (read-only)
// EMC_OPERATION_MODE           VT_INT          [OperationMode]     undefined       "License state" on property page) Operation mode (read-only)
// EMC_OEM_NAME                 VT_BSTR         type limits         undefined       OEM customer Name (read-only)
// EMC_OUT_SAMPLE_SIZE          VT_INT          type limits         [0]             Output sample size: 0 - size should be calculated automatically
// EMC_PRESET                   VT_INT          type limits         undefined       A number of grouped settings
// EMC_AFFINITY_MASK            VT_UI4          type limits         undefined       A bit vector, its every bit represents the processors that are allowed to run a process or thread (depending on the component implementation) 
// EMC_AUTOPERSIST              VT_UI4          [0, 1]              [1]             Enables/disables automatic updating of registry settings
// EMC_NUM_THREADS              VT_UI4          [0, 16]             [0]             Number of used threads, 0 - Auto.
//
// Encoder parameters  (video, audio)
//
// EMC_BITRATE_AVG              VT_INT          type limits         undefined       Average Bit rate 
// EMC_BITRATE_INSTANT          VT_INT          type limits         undefined       Instant bitrate for delivered data
// EMC_BITRATE_MAX              VT_INT          type limits         undefined       Maximal Bit rate 
// EMC_BITRATE_MIN              VT_INT          type limits         undefined       Minimal Bit rate 
// EMC_BITRATE_MODE             VT_INT          type limits         undefined       Bit Rate Control Mode
// EMC_BITRATE_PASS             VT_INT          type limits         undefined       Multipass encoding mode
// EMC_BITRATE_STAT             VT_BSTR         type limits         undefined       Path of file for storage rate control statistics
// EMC_BITRATE_WINDOW_MODE      VT_UI4          type limits         undefined       Enables/disables usage of fixed-size window for bitrate smoothing
// EMC_BITRATE_WINDOW_SIZE      VT_R8           type limits         undefined       Defines window size used for bitrate smoothing
// EMC_LOOKAHEAD                VT_UI4          type limits         [0]             Defines lookahead buffer size (in frames)
// EMC_PROFILE                  VT_INT          type limits         undefined       Profile
// EMC_LEVEL                    VT_INT          type limits         undefined       Level
// EMC_CHROMA_FORMAT            VT_INT          [ChromaFormat]      undefined       Specifies colour format.
//
// Audio Encoder parameters 
//
// EMC_STEREO_MODE              VT_INT          type limits         undefined       Stereo coding mode (mono, independent channels, stereo, joint stereo)
// EMC_LPF_CUTOFF               VT_INT          type limits         [0]             Cut-off frequency for low-pass filter that is applied before encoding, 0 - do not use filter
// EMC_CRC_PROTECTION           VT_INT          [0, 1]              [0]             Enable CRC protection or not
//
//  Video Encoder specific parameters
//
// EMC_PICTURE_MODE             VT_INT          [PictureMode]       encoder dependent   Picture coding mode
// EMC_FIELD_ORDER              VT_INT          [FieldOrder]        encoder dependent   Field order
// EMC_PULLDOWN_MODE            VT_INT          [PulldownMode]      encoder dependent   Pull-down mode
// EMC_USE_SCD                  VT_INT          [0, 1]              encoder dependent   Enables/disables scene change detection
// EMC_GOP_MIN_LENGTH           VT_INT          type limits         encoder dependent   Minimum GOP length
// EMC_GOP_ADAPTIVE             VT_INT          [0, 1]              encoder dependent   Enables/disables adaptive B-frames placement
// EMC_GOP_TIME_LENGTH          VT_INT          type limits         [-1]                GOP time length (in milliseconds)
// EMC_VBV_SIZE                 VT_INT          type limits         encoder dependent   Rate control buffer size
// EMC_QUANT_MIN                VT_INT          type limits         encoder dependent   Minimum quantizer
// EMC_QUANT_MAX                VT_INT          type limits         encoder dependent   Maximum quantizer
// EMC_QUANT_I                  VT_INT          type limits         encoder dependent   Quantizer for I-pictures (ConstQ mode)
// EMC_QUANT_P                  VT_INT          type limits         encoder dependent   Quantizer for P-pictures (ConstQ mode)
// EMC_QUANT_B                  VT_INT          type limits         encoder dependent   Quantizer for B-pictures (ConstQ mode)
// EMC_ADAPTIVE_QUANT_MODE      VT_INT          [AdaptiveQuantMode] encoder dependent   Enables/disables adaptive quantization mode
// EMC_ADAPTIVE_QUANT_STRENGTH  VT_INT          [1, 10]             encoder dependent   Adaptive quantization variability
// EMC_ROI_X                    VT_INT          type limits         encoder dependent   X coordinate of top left ROI corner
// EMC_ROI_Y                    VT_INT          type limits         encoder dependent   Y coordinate of top left ROI corner
// EMC_ROI_WIDTH                VT_INT          type limits         encoder dependent   ROI window width in pixels
// EMC_ROI_HEIGHT               VT_INT          type limits         encoder dependent   ROI window height in pixels
// EMC_ROI_QP_OFFSET            VT_INT          type limits         encoder dependent   ROI quantization offset
// EMC_ASPECT_RATIO_MODE        VT_INT          [AspectRatioMode]   encoder dependent   Picture or sample aspect ratio
// EMC_ASPECT_RATIO_AUTO        VT_INT          [0, 1]              encoder dependent   Auto aspect ratio mode
// EMC_PAR_WIDTH                VT_INT          type limits         encoder dependent   Picture aspect ratio width
// EMC_PAR_HEIGHT               VT_INT          type limits         encoder dependent   Picture aspect ratio height
// EMC_SAR_WIDTH                VT_INT          type limits         encoder dependent   Sample aspect ratio width
// EMC_SAR_HEIGHT               VT_INT          type limits         encoder dependent   Sample aspect ratio height
// EMC_FIX_SOURCE_FRAME_RATE    VT_INT          [0, 1]              [0]                 Enables/disables the fixed source frame rate
// EMC_SOURCE_FRAME_RATE        VT_R8           [1, 100]            original frame rate Specifies the source frame rate if it is set to fixed
// EMC_FIX_OUTPUT_FRAME_RATE    VT_INT          [0, 1]              [0]                 Enables/disables the fixed output frame rate
// EMC_OUTPUT_FRAME_RATE        VT_R8           [1, 100]            source frame rate   Specifies the output frame rate if it is set to fixed
// EMC_GOP_MAX_LENGTH           VT_INT          type limits         undefined           Maximum GOP length
// EMC_GOP_MAX_BCOUNT           VT_INT          type limits         undefined           Maximum number of B-frames
// EMC_ASPECT_RATIO_CODE        VT_INT          type limits         undefined           Picture aspect ratio code
// EMC_QS_PERFORMANCE           VT_INT          [Performance]       [0]                 Switching between performance modes
// EMC_QS_SLICE_COUNT           VT_INT          [1, 99]             [1]                 Number of slices in video frame
// EMC_QS_INITIAL_DELAY         VT_INT          [1024, 288000000]   [67500]             The decoder starts decoding after the buffer reaches the initial size
// EMC_QS_NUM_REFERENCE_FRAMES  VT_INT          [0, 16]             [0]                 Number of reference frames
// EMC_QS_IDR_FREQUENCY         VT_INT          [1, 1000]           [1]                 IDR-frame interval (1 - every I-frame is an IDR-frame, 2 - every second I-frame is an IDR-frame)
// EMC_QS_CLOSEDGOP             VT_INT          [0, 1]              [1]                 Specifies closed or open GOP
// EMC_QS_WRITE_CC              VT_INT          [CCFormat]          [0]                 Specifies the format of closed captions
//
// Audio Decoder parameters 
//
//EMC_STREAM_TYPE               VT_INT          type limits         undefined       Input stream type
//EMC_SAMPLE_RATE               VT_INT          type limits         undefined       Input stream sample rate
//EMC_CHANNELS_CONFIG           VT_INT          [bit mask]          [-1]            Input channels configuration (L,R, LS, RS etc.)
//EMC_CHANNELS_CHOICE           VT_INT          [bit mask]          [0]             Select channels for output (L,R, LS, RS etc.)
//EMC_CHANNELS_MAP              VT_INT          [bit mask]          [0]             Assignment of channels of output stream to speaker positions (L,R, LS, RS etc.)
//EMC_MUTE                      VT_INT          [0,1]               [0]             Mute output or not
//
// Video Decoder parameters
//
// EMC_HardwareAcceleration     VT_UI4          [0, 1]              [0]             Switches between the software and hardware decoding modes
// EMC_HardwareAccelerationState VT_UI4         [0, 1]              undefined       Current mode of the component: using or not using hardware acceleration
// EMC_CCPassthrough            VT_UI4          [0, 1]              [0]             Switches Closed Captioning Passthrough mode off/on
// EMC_CCChannel                VT_INT          [0, 1, 2]		    [0]             Selects CC type to delivery for ~CC output pin. 0 - first field (EIA-608), 1 - second field (EIA-608), 2 - CEA-708
//																					top field first (ttf) or bottom field first (btf)
// EMC_CCInverseField           VT_INT          [0, 1]			    [0]             Inverting of EMC_CCChannel params for incorrect streams
// EMC_PostProcess              VT_UI4          [0, 1]              [0]             Enables/disables the deblocking and deringing filtering (only for software mode)
// EMC_Brightness               VT_UI4          [0, 255]            [128]           Brightness level
// EMC_Contrast                 VT_UI4          [0, 255]            [128]           Contrast level
// EMC_DeinterlaceMode          VT_UI4          [DeinterlaceMode2]  [0]             Selects the output deinterlacing mode
// EMC_Deinterlace              VT_UI4          [DeinterlaceMode]   [0]             Selects the output deinterlacing mode(Obsolete for AVC and MPEG2 decoders, use "EMC_DeinterlaceMode" for these components)
// EMC_Quality                  VT_UI4          [0, 4]              [0]             Selects the skip mode(I,IP,IBP) or 'obey quality messages' mode
// EMC_OSD                      VT_UI4          [0, 1]              [0]             Enables/disables on screen info displaying (only for software mode)
// EMC_CapturePicture           VT_BYREF        []                  [0]             Gets the last decoded picture. Call GetValue(...) and send the empty VARIANT argument. Reinterpreted pbVal to EM2VD_CapturePictureInfo
//                                                                                  struct pointer. Free allocated memory using CoTaskMemFree
// EMC_FramesDecoded            VT_UI4          []                  [0]             Number of decoded frames (read only)
// EMC_FramesSkipped            VT_UI4          []                  [0]             Number of skipped frames (read only)
// (use EMC_NUM_THREADS instead of EMC_MultiThread)
// EMC_MultiThread              VT_UI4          [0, 1]              [1]             ("SMP" On Property Page)    Use multi-thread if it is available (is available for MPEG-2 software decoding on multi-processors systems)
// EMC_MediaTimeStart           VT_I8           []                  [0]             Media start time of the current frame (it may be a byte offset of the current frame)
// EMC_MediaTimeStop            VT_I8           []                  [0]             Media stop time of the current frame (it may be a byte offset of the current frame)
// EMC_ResetStatistics          VT_UI4          [0, 1]              [0]             Resets decoder statistics (decoded and skipped frames counter).
// EMC_ErrorConcealment         VT_UI4          [0, 1]              [1]             Do not show frames with errors
// EMC_VMRMaintainAspectRatio   VT_UI4          [0, 1]              [1]             Enables 'maintain aspect ratio' for VMR-7,9 when the connection is completed
// EMC_Reordering               VT_UI4		    [0, 1]              [1]	            Enables/disables delivering frames with reordering (in display or in stream order).
// EMC_FormatVideoInfo			VT_UI4			[0, 2]				[2]				Sets VIDEOINFOHEADER format
//
// Information and Statistics 
//
// EMC_ENCODED_FRAMES           VT_INT          type limits         undefined       Encoded and delivered frames (read-only)
// EMC_SKIPPED_FRAMES           VT_INT          type limits         undefined       Skipped frames (read-only)
// EMC_FPS                      VT_R8           type limits         undefined       Retrieves actual frame rate (frames per second) (read-only)
// EMC_REAL_FPS                 VT_R8           type limits         undefined       Retrieves current (real) frame rate (frames per second) (read-only)
// EMC_METRIC                   VT_INT          [0, 1]              [0]             Enables/disables metric calculationhe overall PSNR calculation
// EMC_METRIC_CUR_VAL           VT_R8       [0, limit of DOUBLE]    undefined       Metric value for current frame
// EMC_METRIC_AVG_VAL           VT_R8       [0, limit of DOUBLE]    undefined       Average metric value
// EMC_IMPL                     VT_INT          [Impl]              undefined       Implementation mode (read-only)
// EMC_BITRATE_REAL             VT_R8       [0, limit of DOUBLE]    undefined       Real average bitrate (read-only)
// EMC_BITRATE_DECLARED         VT_I8       	type limits         undefined       Declared bitrate in headers (read-only)
// EMC_ERROR_MSG                VT_BSTR         type limits         undefined       Retrieves the last error description (read-only)
//
// EMC_ORIGINAL_WIDTH           VT_INT          type limits         undefined       Original width (read-only)
// EMC_ORIGINAL_HEIGHT          VT_INT          type limits         undefined       Original height (read-only)
// EMC_ORIGINAL_PAR_WIDTH       VT_INT          type limits         undefined       Width component of original picture aspect ratio  (read-only)
// EMC_ORIGINAL_PAR_HEIGHT      VT_INT          type limits         undefined       Height component of original picture aspect ratio (read-only)
// EMC_ORIGINAL_FRAME_RATE      VT_R8           type limits         undefined       Original stream declared frame rate (read-only)
// EMC_ORIGINAL_PICTURE_MODE    VT_INT          [OrgPictureMode]    undefined       Original picture mode (read-only)
// EMC_ORIGINAL_FOURCC          VT_INT          FOURCC code         undefined       Original FOURCC code (read-only)
// EMC_FILTER_STATE             VT_INT          [FilterState]       undefined       Filter state (read-only)
// EMC_HeapUsage	            VT_UI4          []                  [0]             Size of heap usage [bits] (read-only)
//
// Additional Mediatypes
//
// MEDIATYPE_ClosedCaptions															Closed Captions Interchange mediatype
// MEDIASUBTYPE_Passthrough															CC Passthrough mode
//
//
// EMC_SET_DEF_VALUES           VT_INT          [0, 1]              [0]             Sets default values

namespace EMC_COMMON
{
    enum OperationMode
    {
        NOTACTIVE_MODE = 0,
        DEMO_MODE = 1, 
        EVALUATION_MODE = 2,
        EVALUATION_EXPIRED_MODE = 3,
        FULL_MODE = 4
    };

    enum FilterState
    {
        EMC_Filter_Stopped = 0,
        EMC_Filter_Running
    };

    enum ChromaFormat
    {
        EMC_Chroma400 = 0,
        EMC_Chroma420,
        EMC_Chroma422,
        EMC_Chroma444
    };

    enum PictureMode
    {
        EMC_PictureFrame = 0,
        EMC_PictureField,
        EMC_PictureAdaptive
    };

    enum FieldOrder
    {
        EMC_FieldOrderTFF = 0,
        EMC_FieldOrderBFF,
        EMC_FieldOrderAuto
    };

    enum PulldownMode
    {
        EMC_Pulldown_None = 0,
        EMC_Pulldown_23_i,
        EMC_Pulldown_32_i,
        EMC_Pulldown_23_p,
        EMC_Pulldown_32_p,
        EMC_Pulldown_Auto
    };

    enum AspectRatioMode
    {
        EMC_AspectRatio_PAR = 0,
        EMC_AspectRatio_SAR
    };

    enum RateControlMode
    {
        EMC_RCMode_ConstQ = 0,
        EMC_RCMode_VBR,
        EMC_RCMode_CBR,
        EMC_RCMode_ABR,
        EMC_RCMode_QVBR,
        EMC_RCMode_LA_HRD,
    };

    enum OrgPictureMode
    {
        EMC_OrgPictureNA = -1,
        EMC_OrgPictureFrame,
        EMC_OrgPictureField
    };

    enum AdaptiveQuantMode
    {
        EMC_AdaptiveQuantNone = 0,
        EMC_AdaptiveQuantMode1,
        EMC_AdaptiveQuantMode2,
        EMC_AdaptiveQuantROI,
        EMC_AdaptiveQuantMode4
    };

    enum TrellisMode
    {
      EMC_TrellisOff = 0,
      EMC_TrellisPSNR,
      EMC_TrellisHVS
    };

    enum RCPass
    {
        EMC_Pass_Single = 0,
        EMC_Pass_Multi_Analyze,
        EMC_Pass_Multi_Encode,
        EMC_Pass_Multi_Analyze_Fast,
    };

    enum Metric
    {
        EMC_MetricNone = 0,
        EMC_MetricPSNR,
        EMC_MetricSSIM
    };

    enum Impl
    {
      EMC_ImplAuto = 0,
      EMC_ImplHardware = 1,
      EMC_ImplSoftware = 2,
      EMC_ImplNotAvailable = 3
    };


	enum FormatVideoInfo
	{
		EMC_FormatVideoInfo_1 = 0,
		EMC_FormatVideoInfo_2 = 1,
		EMC_FormatVideoInfo_Both = 2
	};

    enum Performance
    {
        EMC_QS_Perf_Auto = 0,
        EMC_QS_Perf_HighestQuality = 1,
        EMC_QS_Perf_HigherQuality = 2,
        EMC_QS_Perf_HighQuality = 3,
        EMC_QS_Perf_Optimal = 4,
        EMC_QS_Perf_FastSpeed = 5,
        EMC_QS_Perf_FasterSpeed = 6,
        EMC_QS_Perf_FastestSpeed = 7
    };

	
	typedef enum _eStreamType  
	{
		E_STREAM_TYPE_UNKNOWN   = 0,
		E_STREAM_TYPE_SYSTEM    = 1,
		E_STREAM_TYPE_PROGRAM   = 2,
		E_STREAM_TYPE_TRANSPORT = 3,
		E_STREAM_TYPE_MPEG2V    = 4,
		E_STREAM_TYPE_PVA       = 5,
		E_STREAM_TYPE_MPEG2A    = 6,
		E_STREAM_TYPE_AC3       = 7,
		E_STREAM_TYPE_H264      = 8,
		E_STREAM_TYPE_MPEG4V    = 9,
		E_STREAM_TYPE_VC1       = 10,
		E_STREAM_TYPE_H263      = 11,    
		E_STREAM_TYPE_MP4       = 12,    
		E_STREAM_TYPE_AAC       = 13,
		E_STREAM_TYPE_MPEG1V    = 14,
		E_STREAM_TYPE_MPEG1A    = 15,
		E_STREAM_TYPE_DIV3      = 16,
		E_STREAM_TYPE_DIV4      = 17,
		E_STREAM_TYPE_DIV5      = 18,
		E_STREAM_TYPE_VSSH      = 19,    
		E_STREAM_TYPE_PCM       = 20,    
		E_STREAM_TYPE_DVDSUB    = 21,
		E_STREAM_TYPE_HDMV      = 22,
		E_STREAM_TYPE_HEVC		= 23,
		E_STREAM_TYPE_AES3		= 24,
		E_STREAM_TYPE_SCTE35	= 25
	} E_STREAM_TYPE;
}

//
//  Unified for all components

// Full component name (read-only).
// {AE016B1D-47AC-4cc3-9A48-4EB73D2BCDD7}
static const GUID EMC_NAME = 
{ 0xae016b1d, 0x47ac, 0x4cc3, { 0x9a, 0x48, 0x4e, 0xb7, 0x3d, 0x2b, 0xcd, 0xd7 } };


//  Operation mode (read-only).
//  Retrieves the component operation mode (returned by License Control or tuned by the application).
// {AFE11383-84D7-4f83-B114-ADC382F97D71}
static const GUID EMC_OPERATION_MODE =
{ 0xafe11383, 0x84d7, 0x4f83, { 0xb1, 0x14, 0xad, 0xc3, 0x82, 0xf9, 0x7d, 0x71 } };


//  OEM Name (read-only).
// {F9041053-1903-4497-82C4-519F0DA71196}
static const GUID EMC_OEM_NAME =
{ 0xf9041053, 0x1903, 0x4497, { 0x82, 0xc4, 0x51, 0x9f, 0xd, 0xa7, 0x11, 0x96 } };


//  Preset. A number of grouped settings. 
// {0D6239BD-E7DC-4ddb-AB8D-C21E8AFDA71C}
static const GUID EMC_PRESET =
{ 0xd6239bd, 0xe7dc, 0x4ddb, { 0xab, 0x8d, 0xc2, 0x1e, 0x8a, 0xfd, 0xa7, 0x1c } };


//  Output sample size.
// {32DAF502-17D2-4cfd-ABD9-CF5C0F447D0B}
static const GUID EMC_OUT_SAMPLE_SIZE =
{ 0x32daf502, 0x17d2, 0x4cfd, { 0xab, 0xd9, 0xcf, 0x5c, 0xf, 0x44, 0x7d, 0xb } };


// Affinity mask. A bit vector, its every bit represents the processors that are allowed to run a process or thread (depending on component implementation) 
// {D030CB55-C27C-4eaa-93CC-1DD13FE2A515}
static const GUID EMC_AFFINITY_MASK = 
{0xd030cb55, 0xc27c, 0x4eaa, { 0x93, 0xcc, 0x1d, 0xd1, 0x3f, 0xe2, 0xa5, 0x15} };

// Number of used threads
//{73cc554f-acff-4b07-ade8-65b23d8263ee}
static const GUID EMC_NUM_THREADS = 
{ 0x73cc554f, 0xacff, 0x4b07, { 0xad, 0xe8, 0x65, 0xb2, 0x3d, 0x82, 0x63, 0xee } };

// Auto persist management. Enables/disables automatic updating of registry settings
// {5B6B1EA9-7867-4f67-AD77-46F51C214E1D}
static const GUID EMC_AUTOPERSIST = 
{ 0x5b6b1ea9, 0x7867, 0x4f67, { 0xad, 0x77, 0x46, 0xf5, 0x1c, 0x21, 0x4e, 0x1d } };

// Implementation mode (read-only)
// {C37B3590-9EF4-49d9-96CC-B825EDC02EEA}
static const GUID EMC_IMPL = 
{ 0xc37b3590, 0x9ef4, 0x49d9, { 0x96, 0xcc, 0xb8, 0x25, 0xed, 0xc0, 0x2e, 0xea } };

//
//  Uniform Encoder parameters 

// Average bit rate
// {6764BCBD-E971-480e-A40D-DABD92A03302}
static const GUID EMC_BITRATE_AVG =
{ 0x6764bcbd, 0xe971, 0x480e, { 0xa4, 0xd, 0xda, 0xbd, 0x92, 0xa0, 0x33, 0x2 } };

// Maximum bit rate
// {94F0A9FB-A29B-453d-851D-9618465A5768}
static const GUID EMC_BITRATE_MAX =
{ 0x94f0a9fb, 0xa29b, 0x453d, { 0x85, 0x1d, 0x96, 0x18, 0x46, 0x5a, 0x57, 0x68 } };

// Minimum bit rate
// {1E3574B1-F91C-453f-9652-8C25160AA225}
static const GUID EMC_BITRATE_MIN =
{ 0x1e3574b1, 0xf91c, 0x453f, { 0x96, 0x52, 0x8c, 0x25, 0x16, 0xa, 0xa2, 0x25 } };

// Bit Rate Control Mode
// {81FB253D-D9E6-4490-AF9D-A463EF00A278}
static const GUID EMC_BITRATE_MODE =
{ 0x81fb253d, 0xd9e6, 0x4490, { 0xaf, 0x9d, 0xa4, 0x63, 0xef, 0x0, 0xa2, 0x78 } };

// Multipass encoding mode
// {9B4C1FB0-F6B1-432a-AB84-269F3973A533}
static const GUID EMC_BITRATE_PASS = 
{ 0x9b4c1fb0, 0xf6b1, 0x432a, { 0xab, 0x84, 0x26, 0x9f, 0x39, 0x73, 0xa5, 0x33 } };

// File name of multipass statistics 
// {D8D6699D-A3FE-47c1-896D-54406C6CBF54}
static const GUID EMC_BITRATE_STAT =
{ 0xd8d6699d, 0xa3fe, 0x47c1, { 0x89, 0x6d, 0x54, 0x40, 0x6c, 0x6c, 0xbf, 0x54 } };

// Enables/disables usage of fixed-size window for bitrate smoothing
// {E3107E39-546A-4c7d-8DD4-21CA5BB26D4F}
static const GUID EMC_BITRATE_WINDOW_MODE = 
{ 0xe3107e39, 0x546a, 0x4c7d, { 0x8d, 0xd4, 0x21, 0xca, 0x5b, 0xb2, 0x6d, 0x4f } };

// Defines window size used for bitrate smoothing
// {199CCFEB-4691-4907-8025-673E22E22AAC}
static const GUID EMC_BITRATE_WINDOW_SIZE = 
{ 0x199ccfeb, 0x4691, 0x4907, { 0x80, 0x25, 0x67, 0x3e, 0x22, 0xe2, 0x2a, 0xac } };

// Defines lookahead buffer size (in seconds)
// {ECACC952-5D32-493f-9680-A7A5BD9AA4E0}
static const GUID EMC_LOOKAHEAD = 
{ 0xecacc952, 0x5d32, 0x493f, { 0x96, 0x80, 0xa7, 0xa5, 0xbd, 0x9a, 0xa4, 0xe0 } };

// Profile
// {0AD3108D-C747-4504-86D7-0A2235F4BE74}
static const GUID EMC_PROFILE =
{ 0xad3108d, 0xc747, 0x4504, { 0x86, 0xd7, 0xa, 0x22, 0x35, 0xf4, 0xbe, 0x74 } };

// Level
// {CAEAA6A6-DDB5-4aff-88D2-E55AE5C37EBE}
static const GUID EMC_LEVEL =
{ 0xcaeaa6a6, 0xddb5, 0x4aff, { 0x88, 0xd2, 0xe5, 0x5a, 0xe5, 0xc3, 0x7e, 0xbe } };

// Chroma format
// {7B89BA80-5F0C-49f8-87AE-E3698C6E3F34}
static const GUID EMC_CHROMA_FORMAT = 
{ 0x7b89ba80, 0x5f0c, 0x49f8, { 0x87, 0xae, 0xe3, 0x69, 0x8c, 0x6e, 0x3f, 0x34 } };


//
//  Audio Encoder parameters

// Stereo coding mode
// {29CF6A68-CFB7-4f0a-B35D-99155DAD2969}
static const GUID EMC_STEREO_MODE = 
{ 0x29cf6a68, 0xcfb7, 0x4f0a, { 0xb3, 0x5d, 0x99, 0x15, 0x5d, 0xad, 0x29, 0x69 } };

// Cut-off frequency for low-pass filter that is applied before encoding
// {862EB500-5A74-4e14-ABCE-528D684C15FB}
static const GUID EMC_LPF_CUTOFF = 
{ 0x862eb500, 0x5a74, 0x4e14, { 0xab, 0xce, 0x52, 0x8d, 0x68, 0x4c, 0x15, 0xfb } };

// Enables/disables CRC
// {91A2B5A9-930C-4f6e-93E9-6A80C5DBF646}
static const GUID EMC_CRC_PROTECTION = 
{ 0x91a2b5a9, 0x930c, 0x4f6e, { 0x93, 0xe9, 0x6a, 0x80, 0xc5, 0xdb, 0xf6, 0x46 } };


//
//  Video Encoder parameters

// Picture coding mode
// {75D6CDA0-32EA-4bbc-A7CD-26FF36801BE1}
static const GUID EMC_PICTURE_MODE =
{ 0x75d6cda0, 0x32ea, 0x4bbc, { 0xa7, 0xcd, 0x26, 0xff, 0x36, 0x80, 0x1b, 0xe1 } };

// Field order
// {088CACD9-BC8B-4d7d-B125-ED3659E6847D}
static const GUID EMC_FIELD_ORDER =
{ 0x88cacd9, 0xbc8b, 0x4d7d, { 0xb1, 0x25, 0xed, 0x36, 0x59, 0xe6, 0x84, 0x7d } };

// Pull-down mode
// {1DC5ABB7-E065-4161-8B55-920E48B2FA87}
static const GUID EMC_PULLDOWN_MODE =
{ 0x1dc5abb7, 0xe065, 0x4161, { 0x8b, 0x55, 0x92, 0xe, 0x48, 0xb2, 0xfa, 0x87 } };

// Enables/disables scene change detection
// {B186705E-61CD-4066-B84D-7A8B8D25EF4F}
static const GUID EMC_USE_SCD =
{ 0xb186705e, 0x61cd, 0x4066, { 0xb8, 0x4d, 0x7a, 0x8b, 0x8d, 0x25, 0xef, 0x4f } };

// Minimum GOP length
// {3BF71658-5ED5-4bbc-99F8-DF051A66D04B}
static const GUID EMC_GOP_MIN_LENGTH =
{ 0x3bf71658, 0x5ed5, 0x4bbc, { 0x99, 0xf8, 0xdf, 0x5, 0x1a, 0x66, 0xd0, 0x4b } };

// Enables/disables adaptive B-frames placement
// {92C266D0-0A45-4827-BC02-579534F95E6E}
static const GUID EMC_GOP_ADAPTIVE =
{ 0x92c266d0, 0xa45, 0x4827, { 0xbc, 0x2, 0x57, 0x95, 0x34, 0xf9, 0x5e, 0x6e } };

// GOP time length (in milliseconds)
// {6E24D354-202F-4063-80FF-C6E6E511A84E}
static const GUID EMC_GOP_TIME_LENGTH =
{ 0x6e24d354, 0x202f, 0x4063, { 0x80, 0xff, 0xc6, 0xe6, 0xe5, 0x11, 0xa8, 0x4e } };

// Rate control buffer size
// {1A8FA378-BE28-4350-A128-E094D0435CA2}
static const GUID EMC_VBV_SIZE =
{ 0x1a8fa378, 0xbe28, 0x4350, { 0xa1, 0x28, 0xe0, 0x94, 0xd0, 0x43, 0x5c, 0xa2 } };

// Minimum quantizer
// {443B9A89-5155-45bd-88E2-578AF90CB839}
static const GUID EMC_QUANT_MIN =
{ 0x443b9a89, 0x5155, 0x45bd, { 0x88, 0xe2, 0x57, 0x8a, 0xf9, 0xc, 0xb8, 0x39 } };

// Trellis quantization
// {9955185B-5226-4f12-AF03-57D65D798B2B}
static const GUID EMC_QUANT_TRELLIS = 
{ 0x9955185b, 0x5226, 0x4f12, { 0xaf, 0x3, 0x57, 0xd6, 0x5d, 0x79, 0x8b, 0x2b } };

// Maximum quantizer
// {FC7043A0-C70D-42e2-A335-2919CB410FAE}
static const GUID EMC_QUANT_MAX =
{ 0xfc7043a0, 0xc70d, 0x42e2, { 0xa3, 0x35, 0x29, 0x19, 0xcb, 0x41, 0xf, 0xae } };

// Quantizer for I-pictures (ConstQ mode)
// {4CBA7208-D548-4126-BE14-CFB32ED9C8D6}
static const GUID EMC_QUANT_I =
{ 0x4cba7208, 0xd548, 0x4126, { 0xbe, 0x14, 0xcf, 0xb3, 0x2e, 0xd9, 0xc8, 0xd6 } };

// Quantizer for P-pictures (ConstQ mode)
// {F9B8CAA0-1746-433d-AF98-0F5F89F8ADE5}
static const GUID EMC_QUANT_P =
{ 0xf9b8caa0, 0x1746, 0x433d, { 0xaf, 0x98, 0xf, 0x5f, 0x89, 0xf8, 0xad, 0xe5 } };

// Quantizer for B-pictures (ConstQ mode)
// {F7E05479-7D3F-43b3-8417-34E3DE3A5C49}
static const GUID EMC_QUANT_B =
{ 0xf7e05479, 0x7d3f, 0x43b3, { 0x84, 0x17, 0x34, 0xe3, 0xde, 0x3a, 0x5c, 0x49 } };

// Enables/disable adaptive quantization mode
// {EBC45857-0A65-44d1-9585-E3EFBBE3575C}
static const GUID EMC_ADAPTIVE_QUANT_MODE =
{ 0xebc45857, 0xa65, 0x44d1, { 0x95, 0x85, 0xe3, 0xef, 0xbb, 0xe3, 0x57, 0x5c } };

// Adaptive quantization qp variability [-strength; +strength]
// {C116835E-6F05-4c15-84DD-7A6285B7D151}
static const GUID EMC_ADAPTIVE_QUANT_STRENGTH =
{ 0xc116835e, 0x6f05, 0x4c15, { 0x84, 0xdd, 0x7a, 0x62, 0x85, 0xb7, 0xd1, 0x51 } };

// x coordinate of top left ROI corner
// {DC26E16C-4BA8-46b4-8C69-4CF9EC68F277}
static const GUID EMC_ROI_X= 
{ 0xdc26e16c, 0x4ba8, 0x46b4, { 0x8c, 0x69, 0x4c, 0xf9, 0xec, 0x68, 0xf2, 0x77 } };

// y coordinate of top left ROI corner
// {B346E251-027D-4124-A49E-D607CE987D29}
static const GUID EMC_ROI_Y = 
{ 0xb346e251, 0x27d, 0x4124, { 0xa4, 0x9e, 0xd6, 0x7, 0xce, 0x98, 0x7d, 0x29 } };

// ROI window width in pixels
// {753E94E7-5E55-4ba6-8B3F-5045AFBFCA8A}
static const GUID EMC_ROI_WIDTH = 
{ 0x753e94e7, 0x5e55, 0x4ba6, { 0x8b, 0x3f, 0x50, 0x45, 0xaf, 0xbf, 0xca, 0x8a } };

// ROI window height in pixels
// {FF1C4B30-D23A-4cec-A03D-639C33BD0A81}
static const GUID EMC_ROI_HEIGHT = 
{ 0xff1c4b30, 0xd23a, 0x4cec, { 0xa0, 0x3d, 0x63, 0x9c, 0x33, 0xbd, 0xa, 0x81 } };

// ROI quantization offset
// {8D0AB276-77E8-4057-9A71-BDCAD7ACA500}
static const GUID EMC_ROI_QP_OFFSET = 
{ 0x8d0ab276, 0x77e8, 0x4057, { 0x9a, 0x71, 0xbd, 0xca, 0xd7, 0xac, 0xa5, 0x0 } };

// Picture or sample aspect ratio
// {D0A6450B-BE88-414a-ACA0-28C843589334}
static const GUID EMC_ASPECT_RATIO_MODE =
{ 0xd0a6450b, 0xbe88, 0x414a, { 0xac, 0xa0, 0x28, 0xc8, 0x43, 0x58, 0x93, 0x34 } };

// Auto aspect ratio mode
// {537D1A22-84F8-4687-83B7-C34227A69771}
static const GUID EMC_ASPECT_RATIO_AUTO =
{ 0x537d1a22, 0x84f8, 0x4687, { 0x83, 0xb7, 0xc3, 0x42, 0x27, 0xa6, 0x97, 0x71 } };

// Width component of picture aspect ratio 
// {ED88E800-1062-4632-8487-6D0E412801AB}
static const GUID EMC_PAR_WIDTH =
{ 0xed88e800, 0x1062, 0x4632, { 0x84, 0x87, 0x6d, 0xe, 0x41, 0x28, 0x1, 0xab } };

// Height component of picture aspect ratio
// {900426AB-B427-47bf-A023-FC676FCC329F}
static const GUID EMC_PAR_HEIGHT =
{ 0x900426ab, 0xb427, 0x47bf, { 0xa0, 0x23, 0xfc, 0x67, 0x6f, 0xcc, 0x32, 0x9f } };

// Width component of sample aspect ratio
// {A5764BB0-5ED7-40d9-AD7C-70166B21CF1F}
static const GUID EMC_SAR_WIDTH =
{ 0xa5764bb0, 0x5ed7, 0x40d9, { 0xad, 0x7c, 0x70, 0x16, 0x6b, 0x21, 0xcf, 0x1f } };

// Height component of sample aspect ratio
// {1F1124D0-1516-474c-9C87-3B0FC954A6FA}
static const GUID EMC_SAR_HEIGHT =
{ 0x1f1124d0, 0x1516, 0x474c, { 0x9c, 0x87, 0x3b, 0xf, 0xc9, 0x54, 0xa6, 0xfa } };

// Enables/disables the fixed source frame rate
// {1071DCA3-F32A-4633-8A94-1F731083CFBD}
static const GUID EMC_FIX_SOURCE_FRAME_RATE =
{ 0x1071dca3, 0xf32a, 0x4633, { 0x8a, 0x94, 0x1f, 0x73, 0x10, 0x83, 0xcf, 0xbd } };

// Specifies the source frame rate if it is set to fixed
// {3AF09663-0BD2-4103-90F1-191808B1BF1B}
static const GUID EMC_SOURCE_FRAME_RATE = 
{ 0x3af09663, 0xbd2, 0x4103, { 0x90, 0xf1, 0x19, 0x18, 0x8, 0xb1, 0xbf, 0x1b } };

// Enables/disables the fixed output frame rate
// {E9883735-8439-425c-B953-D7493791687D}
static const GUID EMC_FIX_OUTPUT_FRAME_RATE =
{ 0xe9883735, 0x8439, 0x425c, { 0xb9, 0x53, 0xd7, 0x49, 0x37, 0x91, 0x68, 0x7d } };

// Specifies the output frame rate if it is set to fixed
// {A9EF6357-2CE6-40c7-BCD7-109879F41B2A}
static const GUID EMC_OUTPUT_FRAME_RATE =
{ 0xa9ef6357, 0x2ce6, 0x40c7, { 0xbc, 0xd7, 0x10, 0x98, 0x79, 0xf4, 0x1b, 0x2a } };

// Maximum GOP length
// {F254808C-7182-464d-BEC7-59907E71D6FE}
static const GUID EMC_GOP_MAX_LENGTH =
{ 0xf254808c, 0x7182, 0x464d, { 0xbe, 0xc7, 0x59, 0x90, 0x7e, 0x71, 0xd6, 0xfe } };

// Maximum number of B-frames
// {27FF14E8-3016-447b-8228-14C76CC5F849}
static const GUID EMC_GOP_MAX_BCOUNT =
{ 0x27ff14e8, 0x3016, 0x447b, { 0x82, 0x28, 0x14, 0xc7, 0x6c, 0xc5, 0xf8, 0x49 } };

// Picture aspect ratio code
// {8D831F7E-F23B-4f07-A887-52D5035E5362}
static const GUID EMC_ASPECT_RATIO_CODE = 
{ 0x8d831f7e, 0xf23b, 0x4f07, { 0xa8, 0x87, 0x52, 0xd5, 0x3, 0x5e, 0x53, 0x62 } };

// {D222EDE3-0903-4924-84C4-CD62F3EF3650}
static const GUID EMC_QS_PERFORMANCE =
{ 0xd222ede3, 0x903, 0x4924, { 0x84, 0xc4, 0xcd, 0x62, 0xf3, 0xef, 0x36, 0x50 } };

// {F18A170F-1745-4A1F-9D86-83C173401900}
static const GUID EMC_QS_SLICE_COUNT =
{ 0xf18a170f, 0x1745, 0x4a1f, { 0x9d, 0x86, 0x83, 0xc1, 0x73, 0x40, 0x19, 0x0 } };

// {98A6AF2E-EE90-4919-801F-6E69E555E956}
static const GUID EMC_QS_INITIAL_DELAY =
{ 0x98a6af2e, 0xee90, 0x4919, { 0x80, 0x1f, 0x6e, 0x69, 0xe5, 0x55, 0xe9, 0x56 } };

// {284C611A-33FD-4939-B8DE-B78CCAAD5AFF}
static const GUID EMC_QS_NUM_REFERENCE_FRAMES =
{ 0x284c611a, 0x33fd, 0x4939, { 0xb8, 0xde, 0xb7, 0x8c, 0xca, 0xad, 0x5a, 0xff } };

// {E065999B-53F1-45AB-A8E5-ACECDA5BECE9}
static const GUID EMC_QS_IDR_FREQUENCY =
{ 0xe065999b, 0x53f1, 0x45ab, { 0xa8, 0xe5, 0xac, 0xec, 0xda, 0x5b, 0xec, 0xe9 } };

// {2f8f759a-f4ed-4bf8-8762-9a493fa62f83}
static const GUID EMC_QS_CLOSEDGOP =
{ 0x2f8f759a, 0xf4ed, 0x4bf8, { 0x87, 0x62, 0x9a, 0x49, 0x3f, 0xa6, 0x2f, 0x83 } };

// {4eba45b3-1af6-41b3-9ea1-1bcc6b405f0b}
static const GUID EMC_QS_WRITE_CC =
{ 0x4eba45b3, 0x1af6, 0x41b3, { 0x9e, 0xa1, 0x1b, 0xcc, 0x6b, 0x40, 0x5f, 0xb } };

//
// Audio Decoder parameters 

// Input stream type
// {E970A9A5-48C9-40db-A2BB-0F42B5F40D8C}
static const GUID EMC_STREAM_TYPE = 
{ 0xe970a9a5, 0x48c9, 0x40db, { 0xa2, 0xbb, 0xf, 0x42, 0xb5, 0xf4, 0xd, 0x8c } };

// Input stream sample rate
// {E8FB4E4F-9B77-4831-B198-CC53D109C3B3}
static const GUID EMC_SAMPLE_RATE = 
{ 0xe8fb4e4f, 0x9b77, 0x4831, { 0xb1, 0x98, 0xcc, 0x53, 0xd1, 0x9, 0xc3, 0xb3 } };
                        
// Input channels configuration 
// {C095B27F-4609-435d-983E-93FEFF84BA45}
static const GUID EMC_CHANNELS_CONFIG = 
{ 0xc095b27f, 0x4609, 0x435d, { 0x98, 0x3e, 0x93, 0xfe, 0xff, 0x84, 0xba, 0x45 } };

// Output channels configuration
// {A0128CCE-9FD8-48a7-A96F-910719D39DF7}
static const GUID EMC_CHANNELS_CHOICE = 
{ 0xa0128cce, 0x9fd8, 0x48a7, { 0xa9, 0x6f, 0x91, 0x7, 0x19, 0xd3, 0x9d, 0xf7 } };

// {C1E1A09A-70E7-4fb7-A6D3-F4F964BE8565}
static const GUID EMC_CHANNELS_MIX = 
{ 0xc1e1a09a, 0x70e7, 0x4fb7, { 0xa6, 0xd3, 0xf4, 0xf9, 0x64, 0xbe, 0x85, 0x65 } };

// Output channels configuration mask 
// {378A5284-C8B6-4231-B30D-E9371B840DDA}
static const GUID EMC_CHANNELS_MAP = 
{ 0x378a5284, 0xc8b6, 0x4231, { 0xb3, 0xd, 0xe9, 0x37, 0x1b, 0x84, 0xd, 0xda } };

// Mutes output
// {60309A0A-30F4-4654-90ED-7C2298E3C87A}
static const GUID EMC_MUTE = 
{ 0x60309a0a, 0x30f4, 0x4654, { 0x90, 0xed, 0x7c, 0x22, 0x98, 0xe3, 0xc8, 0x7a } };

//
// Audio Decoder parameters
namespace EMC_COMMON
{
    enum ChannelsMask
    {
        Channels_Unknown            = -1,           //EMC_CHANNELS_CONFIG - unknown input configuration
                                                    //EMC_CHANNELS_CHOICE - in output stream presents only channels defined in input MediaType
                                                    //EMC_CHANNELS_MAP - do not use channel mapping
        Channels_Auto               = 0,            //EMC_CHANNELS_CHOICE, EMC_CHANNELS_MAP - same as input ("AS-IS")

        Channel_L                   = 0x001,        //Left
        Channel_R                   = 0x002,        //Right
        Channel_C                   = 0x004,        //Center
        Channel_LFE                 = 0x008,        //Low frequency
        Channel_LB                  = 0x010,        //Back Left
        Channel_RB                  = 0x020,        //Back Right
		Channel_LC					= 0x040,        //Back Left of Center
		Channel_RC					= 0x080,        //Back Right of Center
        Channel_CB                  = 0x100,        //Back Center
        Channel_LS                  = 0x200,        //Side Left
        Channel_RS                  = 0x400,        //Side right
        Channel_CT                  = 0x800,        //Top center
        Channel_LTF                 = 0x1000,       //Left top front
        Channel_CTF                 = 0x2000,       //Center top front
        Channel_RTF                 = 0x4000,       //Right top front
        Channel_LTB                 = 0x8000,       //Left top back
        Channel_CTB                 = 0x10000,      //Center top back
        Channel_RTB                 = 0x20000,      //Right top back

        Channels_All                = Channel_L | Channel_R | Channel_C | Channel_LFE |
                                    Channel_LB | Channel_RB | Channel_CB |
                                    Channel_LS | Channel_RS |
                                    Channel_CT |
                                    Channel_LTF | Channel_CTF | Channel_RTF |
                                    Channel_LTB | Channel_CTB | Channel_RTB
    };

    enum MixPreset
    {
        PRESET_mono             =   Channel_C,
        PRESET_stereo           =   Channel_L | Channel_R,
        PRESET_3_0              =   Channel_L | Channel_R | Channel_C,
        PRESET_2_1              =   Channel_L | Channel_R | Channel_LB,
        PRESET_3_1              =   Channel_L | Channel_R | Channel_C | Channel_LB,
        PRESET_quadro           =   Channel_L | Channel_R | Channel_LB | Channel_RB,
        PRESET_3_2              =   Channel_L | Channel_R | Channel_C | Channel_LB | Channel_RB,
        PRESET_4_2              =   Channel_L | Channel_R | Channel_LTF | Channel_RTF | Channel_LB | Channel_RB,
        PRESET_5_2              =   Channel_L | Channel_R | Channel_C | Channel_LTF | Channel_RTF | Channel_LB | Channel_RB,
        PRESET_5_3              =   Channel_L | Channel_R | Channel_C | Channel_LTF | Channel_RTF | Channel_LB | Channel_RB | Channel_CB,
        
        PRESET_mono_lfe         =   PRESET_mono | Channel_LFE,
        PRESET_stereo_lfe       =   PRESET_stereo | Channel_LFE,
        PRESET_3_0_lfe          =   PRESET_3_0 | Channel_LFE,
        PRESET_2_1_lfe          =   PRESET_2_1 | Channel_LFE,
        PRESET_3_1_lfe          =   PRESET_3_1 | Channel_LFE,
        PRESET_quadro_lfe       =   PRESET_quadro | Channel_LFE,
		PRESET_3_2_lfe			= PRESET_3_2 | Channel_LFE,
		PRESET_7_1_front		= PRESET_3_2 | Channel_LC | Channel_RC | Channel_LFE,
		PRESET_7_1_surround		= PRESET_3_2 | Channel_LS | Channel_RS | Channel_LFE,
    };
}

//
// Video Decoder parameters

namespace EMC_COMMON
{

    enum State
    {
        State_Off = 0,
        State_On = 1
    };

    enum HWAcceleration
    {
        HWAcceleration_Off = 0,
        HWAcceleration_Native = 1,
        HWAcceleration_Copyback = 2
    };

    enum DeinterlaceMode
    {
        Deinterlace_Weave = 0,                   // Do not deinterlace
        Deinterlace_VerticalFilter = 1,         // Interpolation by using info from the both fields
        Deinterlace_FieldInterpolation = 2,     // Stretch one of fields
        Deinterlace_VMR = 3,                    // Do not deinterlace, just set deinterlace flags for VMR
        Deinterlace_Auto = 4                    // == now the Vertical Filter interpolation is performed

    };

    enum DeinterlaceMode2 
    {
        DeinterlaceMode_Auto = 0,
        DeinterlaceMode_On = 1,
        DeinterlaceMode_Off = 2,
        DeinterlaceMode_DoubleRate = 3,
        DeinterlaceMode_DoubleWeave = 4
    };

    enum Quality{
        Quality_ObeyQualityMessages = 0,
        Quality_I  = 1,
        Quality_IP = 2,
        Quality_IPB = 3,
        Quality_Ref = 4,
		Quality_DisableDbf = 5
    };

    enum ErrorConcealmentMode{
        ErrorConcealment_Off = 0,
        ErrorConcealment_NotShowFramesWithErrors = 1,
        ErrorConcealment_Temporal  = 2,
        ErrorConcealment_Spatial  = 3,
        ErrorConcealment_Smart  = 4
    };

    enum MaxResolution
    {
        MaxResolution_Unrestricted = 0,
        MaxResolution_4096x4096 = 1,
        MaxResolution_8192x8192 = 2,
        MaxResolution_16384x16384 = 3
    };


    typedef struct _CapturePictureInfo{
        VOID * pBuffer;
        SIZE_T szBuffer;
    }CapturePictureInfo;
}

// Switches between the software and hardware decoding modes
// {BA6DDF74-5F8A-4bdc-88BB-A2563314BC3E}
static const GUID EMC_HardwareAcceleration = 
{0xba6ddf74, 0x5f8a, 0x4bdc, {0x88, 0xbb, 0xa2, 0x56, 0x33, 0x14, 0xbc, 0x3e }};

// Current mode of the component: using or not using hardware acceleration
// {059C8584-3282-4EF9-90DD-DD61D98252D7}
static const GUID EMC_HardwareAccelerationState = 
{ 0x59c8584, 0x3282, 0x4ef9, { 0x90, 0xdd, 0xdd, 0x61, 0xd9, 0x82, 0x52, 0xd7 } };

// {E1D0920F-4552-43d0-A3E1-01D5927EE818}
static const GUID EMC_CCPassthrough = 
{ 0xe1d0920f, 0x4552, 0x43d0, { 0xa3, 0xe1, 0x1, 0xd5, 0x92, 0x7e, 0xe8, 0x18 } };

// {614823A8-7C83-4794-B9EE-0358356552ED}
static const GUID EMC_CCChannel =
{ 0x614823a8, 0x7c83, 0x4794, { 0xb9, 0xee, 0x3, 0x58, 0x35, 0x65, 0x52, 0xed } };

// {498B06FF-B1DF-4843-AA8F-F2B220ABA713}
static const GUID EMC_CCInverseField =
{ 0x498b06ff, 0xb1df, 0x4843, { 0xaa, 0x8f, 0xf2, 0xb2, 0x20, 0xab, 0xa7, 0x13 } };

// Enables/disables the deblocking and deringing filtering (only for software mode)
// {9CF1A334-E72B-4a6d-BBE8-199595944546}
static const GUID EMC_PostProcess = 
{0x9cf1a334, 0xe72b, 0x4a6d, {0xbb, 0xe8, 0x19, 0x95, 0x95, 0x94, 0x45, 0x46 }};

// Brightness level
// {9CF1A336-E72B-4a6d-BBE8-199595944546}
static const GUID EMC_Brightness = 
{0x9cf1a336, 0xe72b, 0x4a6d, {0xbb, 0xe8, 0x19, 0x95, 0x95, 0x94, 0x45, 0x46 }};

// Contrast level
// {23E2776D-3BB5-4aa5-9563-4DBE5AF9539E}
static const GUID EMC_Contrast =
{ 0x23e2776d, 0x3bb5, 0x4aa5, { 0x95, 0x63, 0x4d, 0xbe, 0x5a, 0xf9, 0x53, 0x9e } };

// Selects the output deinterlacing mode
// {D4A86DC5-DB02-4319-A434-430F0A3ABB50}
static const GUID EMC_DeinterlaceMode = 
{ 0xd4a86dc5, 0xdb02, 0x4319, { 0xa4, 0x34, 0x43, 0xf, 0xa, 0x3a, 0xbb, 0x50 } };

// Selects the output deinterlacing mode(Obsolete for AVC and MPEG2 decoders, use "EMC_DeinterlaceMode" for these components)
// {9CF1A332-E72B-4a6d-BBE8-199595944546}
static const GUID EMC_Deinterlace = 
{0x9cf1a332, 0xe72b, 0x4a6d, {0xbb, 0xe8, 0x19, 0x95, 0x95, 0x94, 0x45, 0x46 }};

// Selects the skip mode(I,IP,IBP) or 'obey quality messages' mode
// {9CF1A330-E72B-4a6d-BBE8-199595944546}
static const GUID EMC_Quality = 
{0x9cf1a330, 0xe72b, 0x4a6d, {0xbb, 0xe8, 0x19, 0x95, 0x95, 0x94, 0x45, 0x46 }};

// Enables/disables on screen info displaying (only for software mode)
// {F5C51906-ED89-4c6e-9C37-A5CCB34F5389}
static const GUID EMC_OSD = 
{0xf5c51906, 0xed89, 0x4c6e, {0x9c, 0x37, 0xa5, 0xcc, 0xb3, 0x4f, 0x53, 0x89 }};

// Gets the last decoded picture. Calls GetValue(...) and sends empty VARIANT argument. Reinterpreted pbVal to EM2VD_CapturePictureInfo
// struct pointer. Free allocated memory using CoTaskMemFree.
// {6118A160-0FF0-43c8-94E4-345AC9E9F362}
static const GUID EMC_CapturePicture = 
{0x6118a160, 0xff0, 0x43c8, {0x94, 0xe4, 0x34, 0x5a, 0xc9, 0xe9, 0xf3, 0x62 }};

// Number of decoded frames (read only)
// {575BA759-6F13-4a84-A126-005A5523D203}
static const GUID EMC_FramesDecoded = 
{0x575ba759, 0x6f13, 0x4a84, {0xa1, 0x26, 0x0, 0x5a, 0x55, 0x23, 0xd2, 0x3 }};

// Number of skipped frames (read only)
// {592A9FAB-CBF8-4592-A0B2-21D0C79DACE4}
static const GUID EMC_FramesSkipped = 
{0x592a9fab, 0xcbf8, 0x4592, {0xa0, 0xb2, 0x21, 0xd0, 0xc7, 0x9d, 0xac, 0xe4 }};

// Use multi-thread if it is available (is available for MPEG-2 software decoding on multi-processors systems)
// OBSOLETE. Use EMC_NUM_THREADS instead of EMC_MultiThread
// {0612C1C6-DEF7-4d01-A0DA-90F426F9B312}
static const GUID EMC_MultiThread = 
{0x612c1c6, 0xdef7, 0x4d01, {0xa0, 0xda, 0x90, 0xf4, 0x26, 0xf9, 0xb3, 0x12 }};

// Media time of the current frame (it may be a byte offset of the current frame)
// {3903A73E-6A89-4e09-8E9F-95E8A56F614D}
static const GUID EMC_MediaTimeStart = 
{ 0x3903a73e, 0x6a89, 0x4e09, { 0x8e, 0x9f, 0x95, 0xe8, 0xa5, 0x6f, 0x61, 0x4d } };

// Media time of the current frame (it may be a byte offset of the current frame)
// {BCF5D243-B80E-400a-9B60-035A1D3E5C38}
static const GUID EMC_MediaTimeStop = 
{ 0xbcf5d243, 0xb80e, 0x400a, { 0x9b, 0x60, 0x3, 0x5a, 0x1d, 0x3e, 0x5c, 0x38 } };

// Resets decoder statistics (decoded and skipped frames counter).
// {164966A1-2BFD-4c74-A80E-E5769A219B9F}
static const GUID EMC_ResetStatistics = 
{ 0x164966a1, 0x2bfd, 0x4c74, { 0xa8, 0xe, 0xe5, 0x76, 0x9a, 0x21, 0x9b, 0x9f } };

// Do not show frames with errors
// {BB8F00E9-655B-47c4-966A-A4B4BBF8D2D2}
static const GUID EMC_ErrorConcealment = 
{ 0xbb8f00e9, 0x655b, 0x47c4, { 0x96, 0x6a, 0xa4, 0xb4, 0xbb, 0xf8, 0xd2, 0xd2 } };

// Enable 'maintain aspect ratio' for VMR-7,9 when the connection is completed
// {7F261D15-62E2-46e5-86EB-3537DD72DD56}
static const GUID EMC_VMRMaintainAspectRatio = 
{ 0x7f261d15, 0x62e2, 0x46e5, { 0x86, 0xeb, 0x35, 0x37, 0xdd, 0x72, 0xdd, 0x56 } };

// Sets maximum decodeable resolution limit
// {799147A9-778D-4b16-8DF8-09B009C57705}
static const GUID EMC_MaxResolution = 
{ 0x799147a9, 0x778d, 0x4b16, { 0x8d, 0xf8, 0x9, 0xb0, 0x9, 0xc5, 0x77, 0x5 } };


// {40D2105D-0277-41a5-A424-C009D2B5BE16}
static const GUID EMC_LowDelay = 
{ 0x40d2105d, 0x277, 0x41a5, { 0xa4, 0x24, 0xc0, 0x9, 0xd2, 0xb5, 0xbe, 0x16 } };

// {0066D9CC-884C-4dfc-A0A6-65B62C3A58E7}
static const GUID EMC_Reordering = 
{ 0x66d9cc, 0x884c, 0x4dfc, { 0xa0, 0xa6, 0x65, 0xb6, 0x2c, 0x3a, 0x58, 0xe7 } };

// {110272F6-DA17-4162-B6BA-866CC5CB6889} equal EM2VD_FormatVideoInfo
static const GUID EMC_FormatVideoInfo = { 0x110272f6, 0xda17, 0x4162, { 0xb6, 0xba, 0x86, 0x6c, 0xc5, 0xcb, 0x68, 0x89 } };

//
// Information and Statistics

// Encoded and delivered frames (read-only)
// {0647EE53-0D21-4aae-9AA7-CEFC2C200BF4}
static const GUID EMC_ENCODED_FRAMES =
{ 0x647ee53, 0xd21, 0x4aae, { 0x9a, 0xa7, 0xce, 0xfc, 0x2c, 0x20, 0xb, 0xf4 } };

// Skipped frames (read-only)
// {41BA2006-B132-432b-B54E-A143E1803E8D}
static const GUID EMC_SKIPPED_FRAMES =
{ 0x41ba2006, 0xb132, 0x432b, { 0xb5, 0x4e, 0xa1, 0x43, 0xe1, 0x80, 0x3e, 0x8d } };

// Frames per second (read-only)
// {09008DA7-4D14-4cf7-B2B3-102F26F185DA}
static const GUID EMC_FPS =
{ 0x9008da7, 0x4d14, 0x4cf7, { 0xb2, 0xb3, 0x10, 0x2f, 0x26, 0xf1, 0x85, 0xda } };

// {B4E4399F-5516-4b55-9F42-EB99C3E9BFC5}
static const GUID EMC_REAL_FPS = 
{ 0xb4e4399f, 0x5516, 0x4b55, { 0x9f, 0x42, 0xeb, 0x99, 0xc3, 0xe9, 0xbf, 0xc5 } };

// Enables/disables metric calculation
// {8D9F9D23-C283-469e-B2CE-A12B00E4BE6C}
static const GUID EMC_METRIC = 
{0x8d9f9d23, 0xc283, 0x469e, { 0xb2, 0xce, 0xa1, 0x2b, 0x0, 0xe4, 0xbe, 0x6c } };

// Metric value for current frame
// {14ADD9AC-9329-4515-A368-5F460F6DB951}
static const GUID EMC_METRIC_CUR_VAL = 
{0x14add9ac, 0x9329, 0x4515, { 0xa3, 0x68, 0x5f, 0x46, 0xf, 0x6d, 0xb9, 0x51 } };

// Average metric value
// {B835FB8C-10B6-4995-ADB2-664C3FA65822}
static const GUID EMC_METRIC_AVG_VAL = 
{0xb835fb8c, 0x10b6, 0x4995, { 0xad, 0xb2, 0x66, 0x4c, 0x3f, 0xa6, 0x58, 0x22 } };

// Average metric value on luma component
// {43575BB9-8CBC-4389-A561-9ACA701160AB}
static const GUID EMC_METRIC_AVG_LUMA_VAL = 
{ 0x43575bb9, 0x8cbc, 0x4389, { 0xa5, 0x61, 0x9a, 0xca, 0x70, 0x11, 0x60, 0xab } };

// Real average bitrate
// {5474A680-0448-4f27-9D07-529393F7A69B}
static const GUID EMC_BITRATE_REAL = 
{ 0x5474a680, 0x448, 0x4f27, { 0x9d, 0x7, 0x52, 0x93, 0x93, 0xf7, 0xa6, 0x9b } };

// Instant bitrate
// {1EBDE816-13B6-400b-8B6F-40D5A0B1DECE}
static const GUID EMC_BITRATE_INSTANT = 
{ 0x1ebde816, 0x13b6, 0x400b, { 0x8b, 0x6f, 0x40, 0xd5, 0xa0, 0xb1, 0xde, 0xce } };

// Declared bitrate in headers (read-only)
// {6C393B72-68AD-4769-8D45-5DA308219569}
static const GUID EMC_BITRATE_DECLARED = 
{ 0x6c393b72, 0x68ad, 0x4769, { 0x8d, 0x45, 0x5d, 0xa3, 0x8, 0x21, 0x95, 0x69 } };


// Last error description
// {9A0036F5-5CAA-4da8-AA0E-FB1A29134BFF}
static const GUID EMC_ERROR_MSG = 
{ 0x9a0036f5, 0x5caa, 0x4da8, { 0xaa, 0xe, 0xfb, 0x1a, 0x29, 0x13, 0x4b, 0xff } };

// Original width
// {8B7A4368-3701-447f-9F49-4D6EC91734AB}
static const GUID EMC_ORIGINAL_WIDTH =
{ 0x8b7a4368, 0x3701, 0x447f, { 0x9f, 0x49, 0x4d, 0x6e, 0xc9, 0x17, 0x34, 0xab } };

// Original height
// {AD2669B9-96B1-411a-B01A-81C044F0388F}
static const GUID EMC_ORIGINAL_HEIGHT =
{ 0xad2669b9, 0x96b1, 0x411a, { 0xb0, 0x1a, 0x81, 0xc0, 0x44, 0xf0, 0x38, 0x8f } };

// With component of original picture aspect ratio
// {1F3EB61F-0BA5-4fb7-A41B-424B7814C607}
static const GUID EMC_ORIGINAL_PAR_WIDTH =
{ 0x1f3eb61f, 0xba5, 0x4fb7, { 0xa4, 0x1b, 0x42, 0x4b, 0x78, 0x14, 0xc6, 0x7 } };

// Height component of original picture aspect ratio
// {CD3EAA8A-5D4C-4239-8C5B-A088791C78E0}
static const GUID EMC_ORIGINAL_PAR_HEIGHT =
{ 0xcd3eaa8a, 0x5d4c, 0x4239, { 0x8c, 0x5b, 0xa0, 0x88, 0x79, 0x1c, 0x78, 0xe0 } };

// Original stream declared frame rate
// {D1B08B55-E9FF-416c-AE84-7D297935B338}
static const GUID EMC_ORIGINAL_FRAME_RATE =
{ 0xd1b08b55, 0xe9ff, 0x416c, { 0xae, 0x84, 0x7d, 0x29, 0x79, 0x35, 0xb3, 0x38 } };

// Original picture mode
// {C96F3CE2-DF13-4bcd-8BDD-06F4B135941C}
static const GUID EMC_ORIGINAL_PICTURE_MODE =
{ 0xc96f3ce2, 0xdf13, 0x4bcd, { 0x8b, 0xdd, 0x6, 0xf4, 0xb1, 0x35, 0x94, 0x1c } };

// Original FOURCC code
// {97604510-07B9-44fb-A13A-4EC9F99F6606}
static const GUID EMC_ORIGINAL_FOURCC =
{ 0x97604510, 0x7b9, 0x44fb, { 0xa1, 0x3a, 0x4e, 0xc9, 0xf9, 0x9f, 0x66, 0x6 } };

// Filter state
// {CE089243-28C5-46da-96C5-3A16A5AE84D2}
static const GUID EMC_FILTER_STATE =
{ 0xce089243, 0x28c5, 0x46da, { 0x96, 0xc5, 0x3a, 0x16, 0xa5, 0xae, 0x84, 0xd2 } };

// {5690DAEF-65DE-40f9-ADB6-F9A702770DC5}
static const GUID MEDIATYPE_ClosedCaptions = 
{ 0x5690daef, 0x65de, 0x40f9, { 0xad, 0xb6, 0xf9, 0xa7, 0x2, 0x77, 0xd, 0xc5 } };

// {E7877D69-ECE0-48ea-B3A3-B70ED933F288}	Closed captions passthrough transcoding
static const GUID MEDIASUBTYPE_Passthrough = 
{ 0xe7877d69, 0xece0, 0x48ea, { 0xb3, 0xa3, 0xb7, 0xe, 0xd9, 0x33, 0xf2, 0x88 } };

// Heap Usage
// {5C95CC7E-0291-4557-95B5-449419F21411}
static const GUID EMC_HeapUsage =
{ 0x5c95cc7e, 0x291, 0x4557, { 0x95, 0xb5, 0x44, 0x94, 0x19, 0xf2, 0x14, 0x11 } };

//
// Close Caption

// {6B380E38-A5E6-4B64-B891-AC2B73769969}
static const GUID MEDIATYPE_AUX_708_608_E =
{ 0x6b380e38, 0xa5e6, 0x4b64, { 0xb8, 0x91, 0xac, 0x2b, 0x73, 0x76, 0x99, 0x69 } };

// {B5D7BF00-9BE9-426C-AD1A-F52314CF1B28}
static const GUID MEDIASUBTYPE_708_608_E =
{ 0xb5d7bf00, 0x9be9, 0x426c, { 0xad, 0x1a, 0xf5, 0x23, 0x14, 0xcf, 0x1b, 0x28 } };


// Sets default values
// {E68BB2EE-16EF-4e5f-93A1-D631C6D60AA5}
static const GUID EMC_SET_DEF_VALUES = 
{ 0xe68bb2ee, 0x16ef, 0x4e5f, { 0x93, 0xa1, 0xd6, 0x31, 0xc6, 0xd6, 0xa, 0xa5 } };

#endif

