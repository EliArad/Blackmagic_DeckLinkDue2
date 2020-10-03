/*/////////////////////////////////////////////////////////////////////////////
//
//    Elecard MPEG-4 part 10 (AVC/H.264) encoder. (ISO/IEC 14496-10:2005)
//
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2009 Elecard Ltd.
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

#ifndef AVCENC_AVCENC_GUIDS_H
#define AVCENC_AVCENC_GUIDS_H

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    GUID                          Type        Available range             Default Value           Note
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// EMC_PRESET                       VT_INT      [EAVCENC_Preset]            Preset_Baseline         Switching between Presets
// EMC_PROFILE                      VT_INT      [EAVCENC_Profile]           Profile_Baseline        Switching between Profiles
// EMC_LEVEL                        VT_INT      [EAVCENC_Level]             Level_Auto              Switching between Levels
// EAVCENC_VIDEO_FORMAT             VT_INT      [EAVCENC_VideoFormat]       VideoFormat_Unspecified Switching between video formats
// EAVCENC_FULL_RANGE_COLORS        VT_INT      [0, 1]                      0                       Value for video_full_range_flag
// EAVCENC_COLOUR_DESCRIPTION       VT_INT      [0, 1]                      1                       Ebable/disable writing colout description
// EAVCENC_COLOUR_DESCRIPTION_VALUE VT_INT      0-255                       2                       Value for vui.colour_primaries, vui.transfer_characteristics and vui.matrix_coefficients
// EAVCENC_ENTROPY_MODE             VT_INT      [EAVCENC_EntropyMode]       Entropy_CAVLC           Switching between Entropy coding mode
// EAVCENC_TRANSFORM_MODE           VT_INT      [EAVCENC_TransformMode]     Transform_Adaptive      Block transform size
// EAVCENC_SLICE_COUNT              VT_INT      [1, number of MB rows]      1                       Slice count
// EMC_NUM_THREADS                  VT_UI4      [0, 16]                     0                       Number of used threads, 0 - Auto.

// EMC_PICTURE_MODE                 VT_INT      [PictureMode]               EMC_PictureFrame        Picture coding mode
// EMC_FIELD_ORDER                  VT_INT      [FieldOrder]                EMC_FieldOrderAuto      Field order
// EMC_PULLDOWN_MODE                VT_INT      [PulldownMode]              EMC_Pulldown_Auto       Pull-down mode

// EAVCENC_USE_INTRA_REFRESH       VT_INT      [0, 1]                      0                       Enable/disable running intra slice mode

// EMC_ASPECT_RATIO_MODE            VT_INT      [AspectRatioMode]           EMC_AspectRatio_PAR     Picture or sample aspect ratio
// EMC_ASPECT_RATIO_AUTO            VT_INT      [0, 1]                      1                       Auto aspect ratio mode
// EMC_PAR_WIDTH                    VT_INT      type limits                 4                       Picture aspect ratio width
// EMC_PAR_HEIGHT                   VT_INT      type limits                 3                       Picture aspect ratio height
// EMC_SAR_WIDTH                    VT_INT      type limits                 1                       Sample aspect ratio width
// EMC_SAR_HEIGHT                   VT_INT      type limits                 1                       Sample aspect ratio height
// EMC_USE_SCD                      VT_INT      [0, 1]                      1                       Enables/disables scene change detection
// EMC_GOP_MAX_LENGTH               VT_INT      type limits                 250                     Maximum GOP length
// EMC_GOP_MIN_LENGTH               VT_INT      type limits                 1                       Minimum GOP length
// EMC_GOP_MAX_BCOUNT               VT_INT      type limits                 0                       Maximum number of B-frames
// EAVCENC_IDR_FREQUENCY            VT_INT      [1, 1000]                   1                       Frequency of IDR-pictures
// EMC_GOP_ADAPTIVE                 VT_INT      [0, 1]                      1                       Enables/disables adaptive B-frames placement
// EAVCENC_B_FRAMES_MODE            VT_INT      [EAVCENC_BMode]             BMode_Plain             B-frames mode
// EAVCENC_GOP_INFINITE             VT_INT      [0, 1]                      0                       Enable/disable GOP with infinite length
// EAVCENC_CROP_RECT_X              VT_INT      picture height limits       encoder dependent       X coordinate of top left crop rect corner
// EAVCENC_CROP_RECT_Y              VT_INT      picture height limits       encoder dependent       Y coordinate of top left crop rect corner
// EAVCENC_CROP_RECT_WIDTH          VT_INT      picture width limits        encoder dependent       crop rect width in pixels
// EAVCENC_CROP_RECT_HEIGHT         VT_INT      picture width limits        encoder dependent       crop rect height in pixels

// EAVCENC_DEBLOCK_MODE             VT_INT      [EAVCENC_DeblockMode]       Deblock_Picture         Deblocking filter mode
// EAVCENC_DEBLOCK_ALPHA            VT_INT      [-6, 6]                     0                       Deblocking alpha offset
// EAVCENC_DEBLOCK_BETA             VT_INT      [-6, 6]                     0                       Deblocking beta offset
// EAVCENC_DEBLOCK_CONTROL_PRESENT  VT_INT      [0, 1]                      1                       Enable/disable per-slice deblock control parameters.
//                                                                                                  If parameter's set to 0, deblock filter is enabled and
//                                                                                                  alpha/beta offsets set to 0.

// EAVCENC_PERFORMANCE              VT_INT      [EAVCENC_Performance]       Perf_Custom             Speed/Quality trade-off
// EAVCENC_SPEED_MODE               VT_INT      [EAVCENC_SpeedMode]         Speed_Default           Encoding speed mode
// EAVCENC_SPEED_VALUE              VT_INT      [0, 999]                    25                      Encoding speed
// EAVCENC_RD_METRIC                VT_INT      [EAVCENC_RD_Metric]         RD_SAD                  RD metric
// EAVCENC_USE_INEW_IN_ISLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 16x16 mode in I-slices
// EAVCENC_USE_I8x8_IN_ISLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 8x8 mode in I-slices
// EAVCENC_USE_I4x4_IN_ISLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 4x4 mode in I-slices
// EAVCENC_USE_INEW_DC_ONLY_IN_ISLICE  VT_INT   [0, 1]                      0                       Enable/disable restriction of  intra prediction modes
//                                                                                                  to DC only (both luma & chroma) in I-slices
// EAVCENC_USE_INEW_IN_PSLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 16x16 mode in P-slices
// EAVCENC_USE_I8x8_IN_PSLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 8x8 mode in P-slices
// EAVCENC_USE_I4x4_IN_PSLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 4x4 mode in P-slices
// EAVCENC_USE_INEW_DC_ONLY_IN_PSLICE  VT_INT   [0, 1]                      0                       Enable/disable restriction of  intra prediction modes
//                                                                                                  to DC only (both luma & chroma) in P-slices
// EAVCENC_USE_INEW_IN_BSLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 16x16 mode in B-slices
// EAVCENC_USE_I8x8_IN_BSLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 8x8 mode in B-slices
// EAVCENC_USE_I4x4_IN_BSLICE       VT_INT      [0, 1]                      1                       Enable/disable Intra 4x4 mode in B-slices
// EAVCENC_USE_INEW_DC_ONLY_IN_BSLICE  VT_INT   [0, 1]                      0                       Enable/disable restriction of  intra prediction modes
//                                                                                                  to DC only (both luma & chroma) in B-slices
// EAVCENC_WPRED_IN_PSLICE          VT_INT      [WPred_Off, WPred_Explicit] WPred_Off               Weighted prediction mode in P-slices
// EAVCENC_WPRED_IN_BSLICE          VT_INT      [WPred_Off, WPred_Implicit] WPred_Off               Weighted prediction mode in B-slices
// EAVCENC_MC_MIN_BLOCK_SIZE        VT_INT      [EAVCENC_MC_MinBlockSize]   MC_8x8                  Minimum block size for motion compensation
// EAVCENC_MC_MIN_SUBPEL_SIZE       VT_INT      [EAVCENC_MC_SubPelSize]     SUB_QPEL                Minimum sub-pixel refinement size
// EAVCENC_NUM_REFERENCE_FRAMES     VT_INT      [0, 16]                     1                       Number of reference frames
// EAVCENC_ME_SEARCH_RANGE          VT_INT      [0, 511]                    255                     Motion estimation search range
// EAVCENC_USE_OUT_OF_PICTURE_MV    VT_INT      [0, 1]                      1                       Enable/disable motion vectors out of picture boundaries
// EAVCENC_ME_SEARCH_RANGE_EXPLICIT_IN_SLICES  VT_INT      [0, 1]           0                       Enable/disable usage of explicit ME search ranges in P 
//                                                                                                  and B-slices (see params below)
// EAVCENC_ME_SEARCH_RANGE_X_IN_PSLICE  VT_INT  [0, 511]                    0                       Horizontal motion estimation search range in P-slices
// EAVCENC_ME_SEARCH_RANGE_Y_IN_PSLICE  VT_INT  [0, 511]                    0                       Vertical motion estimation search range in P-slices
// EAVCENC_ME_SEARCH_RANGE_X_IN_BSLICE  VT_INT  [0, 511]                    0                       Horizontal motion estimation search range in B-slices
// EAVCENC_ME_SEARCH_RANGE_Y_IN_BSLICE  VT_INT  [0, 511]                    0                       Vertical motion estimation search range in B-slices

// EMC_BITRATE_MODE                 VT_INT      [RateControlMode]           EMC_RCMode_VBR          Bit Rate Control Mode
// EMC_BITRATE_AVG                  VT_INT      type limits                 1500000                 Average Bit rate 
// EMC_BITRATE_MAX                  VT_INT      type limits                 3000000                 Maximal Bit rate 
// EMC_VBV_SIZE                     VT_INT      type limits                 1200000                 Rate control buffer size
// EAVCENC_INITIAL_DELAY            VT_INT      [1024, 288000000]           36000                   Initial HRD delay (90 kHz)
// EAVCENC_CB_QP_OFFSET             VT_INT      [-10, 10]                   1                       Cb chroma qp offset
// EAVCENC_CR_QP_OFFSET             VT_INT      [-10, 10]                   1                       Cr chroma qp offset
// EMC_QUANT_MIN                    VT_INT      type limits                 0                       Minimum quantizer
// EMC_QUANT_MAX                    VT_INT      type limits                 51                      Maximum quantizer
// EMC_QUANT_I                      VT_INT      type limits                 23                      Quantizer for I-pictures (ConstQ mode)
// EMC_QUANT_P                      VT_INT      type limits                 25                      Quantizer for P-pictures (ConstQ mode)
// EMC_QUANT_B                      VT_INT      type limits                 28                      Quantizer for B-pictures (ConstQ mode)
// EMC_QUANT_TRELLIS                VT_INT      [0, 1]                      0                       Enable/disable trellis optimized quantization mode.
// EAVCENC_PIC_INIT_QP              VT_INT      [0, 51]                     26                      Picture init qp (Picture Parameter Set value)
// EMC_ADAPTIVE_QUANT_MODE          VT_INT      [AdaptiveQuantMode]         EMC_AdaptiveQuantNone   Enable/disable adaptive quantization mode
// EMC_ADAPTIVE_QUANT_STRENGTH      VT_INT      [1, 10]                     4                       Adaptive quantization variability
// EMC_BITRATE_PASS                 VT_INT      [RCPass]                    EMC_Pass_Single         Multipass encoding mode
// EMC_BITRATE_STAT                 VT_BSTR     type limits                 undefined               Path of file for storage rate control statistics
// EMC_BITRATE_WINDOW_MODE          VT_UI4      type limits                 0                       Enables/disables usage of fixed-size window for bitrate smoothing
// EMC_BITRATE_WINDOW_SIZE          VT_R8       type limits                 current gop size        Defines window size used for bitrate smoothing
// EMC_GOP_TIME_LENGTH              VT_INT      type limits                 [-1]                    GOP time length (in milliseconds)

// EAVCENC_WRITE_HRD_PARAMS         VT_INT      [0, 1]                      1                       Enable/disable writing of HRD parameters
// EAVCENC_WRITE_AU_DELIMITERS      VT_INT      [0, 1]                      1                       Enable/disable writing access unit delimiters
// EAVCENC_WRITE_SEQ_END_CODE       VT_INT      [0, 1]                      1                       Enable/disable writing end of sequence code
// EAVCENC_WRITE_CC                 VT_INT      [0, 1]                      0                       Enable/disable writing closed captions
// EAVCENC_WRITE_AFD                VT_INT      [0, 1]                      0                       Enable/disable writing of Active Format Descriptor (AFD)
// EAVCENC_SPS_MODE                 VT_INT      [0, 1]                      1                       Sequence Parameter Set (SPS) write mode
// EAVCENC_PPS_MODE                 VT_INT      [0, 1]                      1                       Picture Parameter Set (PPS) write mode
// EAVCENC_LOG2_MAX_FRAME_NUM       VT_INT      [0, 12]                     8                       Specifies log2_max_frame_num syntax element value written to bitstream.
// EAVCENC_LOG2_MAX_PIC_ORDER_CNT_LSB VT_INT    [0, 12]                     8                       Specifies log2_max_pic_order_cnt_lsb syntax element value written to bitstream.
// EAVCENC_PIC_ORDER_CNT_TYPE       VT_INT      [0, 2]                      0                       Specifies pic_order_cnt_type syntax element value written to bitstream.
// EAVCENC_MEDIASDK_ASYNC_DEPTH     VT_INT      [1, 16]                     4                       Specifies how many asynchronous operations performs before synchronization 
// EAVCENC_FORCE_PIC_STRUCT_PRESENT_FLAG VT_INT [0, 1]                      0                       Force writing pic_struct to picture timing SEI messages
//                                                                                                  (MediaSDK encoder only)

// EMC_FIX_SOURCE_FRAME_RATE        VT_INT      [0, 1]                      0                       Enables/disables the fixed source frame rate
// EMC_SOURCE_FRAME_RATE            VT_R8       [1, 100]                    original frame rate     Specifies the source frame rate if it is set to fixed
// EMC_FIX_OUTPUT_FRAME_RATE        VT_INT      [0, 1]                      0                       Enables/disables the fixed output frame rate
// EMC_OUTPUT_FRAME_RATE            VT_R8       [1, 100]                    source frame rate       Specifies the output frame rate if it is set to fixed

// EMC_METRIC                       VT_INT      [0, 1]                      0                       Enables/disables metric calculationhe overall PSNR calculation
// EMC_METRIC_CUR_VAL               VT_R8       [0, limit of DOUBLE]        0                       Metric value for current frame
// EMC_METRIC_AVG_VAL               VT_R8       [0, limit of DOUBLE]        0                       Average metric value
// EMC_IMPL                         VT_INT      [Impl]                      undefined               Implementation mode (read-only)
// EMC_ENCODED_FRAMES               VT_INT      type limits                 0                       Encoded and delivered frames (read-only)
// EMC_FPS                          VT_R8       type limits                 0                       Retrieves actual frame rate (frames per second) (read-only)
// EMC_BITRATE_REAL                 VT_R8       [0, limit of DOUBLE]        0                       Real average bitrate (read-only)

// EMC_ORIGINAL_WIDTH               VT_INT      type limits                 352                     Original width (read-only)
// EMC_ORIGINAL_HEIGHT              VT_INT      type limits                 288                     Original height (read-only)
// EMC_ORIGINAL_PAR_WIDTH           VT_INT      type limits                 4                       Width component of original picture aspect ratio  (read-only)
// EMC_ORIGINAL_PAR_HEIGHT          VT_INT      type limits                 3                       Height component of original picture aspect ratio (read-only)
// EMC_ORIGINAL_FRAME_RATE          VT_R8       type limits                 0                       Original stream declared frame rate (read-only)
// EMC_ORIGINAL_PICTURE_MODE        VT_INT      [OrgPictureMode]            EMC_OrgPictureNA        Original picture mode (read-only)
// EMC_ORIGINAL_FOURCC              VT_INT      FOURCC code                 0                       Original FOURCC code (read-only)
// EMC_FILTER_STATE                 VT_INT      [FilterState]               EMC_Filter_Stopped      Filter state (read-only)

// EAVCENC_USE_UTC_TIME             VT_INT      [0, 1]                      0                       Enables/disables write sei picture timing for UTC time

namespace EAVCENC_PARAMS
{
    typedef enum {
        Preset_Custom				= 0,
        Preset_Baseline				= 1,
        Preset_Main					= 2,
        Preset_High					= 3,
        Preset_iPod					= 4,
        Preset_PSP					= 5,
        Preset_DVD					= 6,
        Preset_HD_DVD				= 7,
        Preset_BD					= 8,
        Preset_BD_HDMV				= 9,
        Preset_HDV_HD1				= 10,
        Preset_HDV_HD2				= 11,
        Preset_AVCHD				= 12,
        Preset_Offline				= 13,
		Preset_AvcIntraClass50		= 14,
		Preset_AvcIntraClass100		= 15
    } EAVCENC_Preset;

    typedef enum {
        Profile_Baseline= 0,
        Profile_Main    = 1,
        Profile_High    = 3,
        Profile_High10  = 4,
        Profile_High422 = 5,
        Profile_High444 = 6,
        Profile_CnstrBaseline = 7
    } EAVCENC_Profile;

    typedef enum {
        Level_1     = 10,
        Level_11    = 11,
        Level_12    = 12,
        Level_13    = 13,
        Level_1b    = 14,
        Level_2     = 20,
        Level_21    = 21,
        Level_22    = 22,
        Level_3     = 30,
        Level_31    = 31,
        Level_32    = 32,
        Level_4     = 40,
        Level_41    = 41,
        Level_42    = 42,
        Level_5     = 50,
        Level_51    = 51,
        Level_Auto  = 100
    } EAVCENC_Level;

    typedef enum {
        VideoFormat_Component = 0,
        VideoFormat_PAL = 1,
        VideoFormat_NTSC = 2,
        VideoFormat_SECAM = 3,
        VideoFormat_MAC = 4,
        VideoFormat_Unspecified = 5
    } EAVCENC_VideoFormat;

    typedef enum {
        Entropy_CAVLC = 0,
        Entropy_CABAC = 1
    } EAVCENC_EntropyMode;

    typedef enum {
        Transform_4x4_only = 0,
        Transform_Adaptive = 1,
        Transform_8x8_only = 2
    } EAVCENC_TransformMode;

    typedef enum {
        Perf_Custom = 0,
        Perf_Highest_Quality = 1,
        Perf_High_Quality = 2,
        Perf_Optimal = 3,
        Perf_Fast_Speed = 4,
        Perf_Fastest_Speed = 5
    } EAVCENC_Performance;

    typedef enum {
        HdrMode_EachIDR = 0,
        HdrMode_EachI = 1,
        HdrMode_EachPicture = 2,
        HdrMode_Once = 3,
        HdrMode_EverySecond = 4
    } EAVCENC_HdrMode;

    typedef enum {
        Speed_Default = 0,
        Speed_qxRealTime = 1,
        Speed_hxRealTime = 2,
        Speed_1xRealTime = 3,
        Speed_2xRealTime = 4,
        Speed_4xRealTime = 5,
        Speed_Specified = 6
    } EAVCENC_SpeedMode;

    typedef enum {
        RD_SAD = 0,
        RD_SATD = 1,
        RD_RDO = 2
    } EAVCENC_RD_Metric;

    typedef enum {
        BMode_Plain = 0,
        BMode_Reference = 1,
        BMode_Hierarchical = 2
    } EAVCENC_BMode;

    typedef enum {
        Deblock_Picture = 0,
        Deblock_Disable = 1,
        Deblock_Slices = 2
    } EAVCENC_DeblockMode;

    typedef enum {
      WPred_Off = 0,
      WPred_Explicit = 1,
      WPred_Implicit = 2
    } EAVCENC_WPredMode;

    typedef enum {
        MC_16x16 = 0,
        MC_8x8 = 1
    } EAVCENC_MC_MinBlockSize;

    typedef enum {
        SUB_QPEL = 0,
        SUB_HPEL = 1
    } EAVCENC_MC_SubPelSize;

    typedef enum {
        CCFormat_None = 0,
        CCFormat_ATSC = 1,
        CCFormat_SCTE = 2,
        CCFormat_CCube = 3,
        CCFormat_Passthrough = 4
    } EAVCENC_CCFormat;

};

//////////////////////////////////////////////////////////////////////////
//    Parameters GUIDs
//////////////////////////////////////////////////////////////////////////

DEFINE_GUID(EAVCENC_VIDEO_FORMAT, 0xabca3dd2, 0x1f6a, 0x45bb, 0x93, 0x6b, 0x79, 0xe3, 0xa7, 0x91, 0x26, 0x63);
DEFINE_GUID(EAVCENC_ENTROPY_MODE, 0xdcc1a5d2, 0xe985, 0x4e41, 0x9d, 0xdd, 0xb9, 0x56, 0x2e, 0x1e, 0xa1, 0xe7);
DEFINE_GUID(EAVCENC_TRANSFORM_MODE, 0xe330bf14, 0xb943, 0x42d7, 0x94, 0x22, 0x1f, 0x0, 0x31, 0xb7, 0x1d, 0xb3);
DEFINE_GUID(EAVCENC_SLICE_COUNT, 0x8c50ac28, 0x942c, 0x4454, 0xa7, 0x46, 0x83, 0xdb, 0xe7, 0xa9, 0x39, 0x5c);

DEFINE_GUID(EAVCENC_IDR_FREQUENCY, 0x7fd8a79, 0xde8c, 0x45ec, 0xb9, 0x7a, 0x5e, 0x8d, 0x31, 0x31, 0x8c, 0x84);
DEFINE_GUID(EAVCENC_B_FRAMES_MODE, 0xd26c8646, 0x2283, 0x4e54, 0xb2, 0xfe, 0x8c, 0x46, 0x97, 0x88, 0x1e, 0xa4);
DEFINE_GUID(EAVCENC_GOP_INFINITE, 0x917ba28, 0x116e, 0x40da, 0x93, 0x5f, 0x8a, 0x5c, 0xd8, 0x71, 0xd2, 0x81);
DEFINE_GUID(EAVCENC_GOP_USE_REORDERING, 0x63032a2, 0xb7c5, 0x41f1, 0x8f, 0x76, 0x30, 0x6c, 0xc6, 0x86, 0x65, 0xa7);

// {23018DD5-2913-4E35-A841-99BF005B4D8A}
DEFINE_GUID(EAVCENC_CROP_LEFT, 0x23018dd5, 0x2913, 0x4e35, 0xa8, 0x41, 0x99, 0xbf, 0x0, 0x5b, 0x4d, 0x8a);
// {82CA15BF-CFDB-4811-9B2B-1B49FA95C932}
DEFINE_GUID(EAVCENC_CROP_TOP, 0x82ca15bf, 0xcfdb, 0x4811, 0x9b, 0x2b, 0x1b, 0x49, 0xfa, 0x95, 0xc9, 0x32);
// {E68B5EF0-868E-43D5-A588-904DBB8B98A2}
DEFINE_GUID(EAVCENC_CROP_RIGHT, 0xe68b5ef0, 0x868e, 0x43d5, 0xa5, 0x88, 0x90, 0x4d, 0xbb, 0x8b, 0x98, 0xa2);
// {3C2B5657-3339-4394-B540-2D538F1357AD}
DEFINE_GUID(EAVCENC_CROP_BOT, 0x3c2b5657, 0x3339, 0x4394, 0xb5, 0x40, 0x2d, 0x53, 0x8f, 0x13, 0x57, 0xad);

DEFINE_GUID(EAVCENC_INITIAL_DELAY, 0x4839d249, 0x2b74, 0x40e8, 0xab, 0x8e, 0xc9, 0x7f, 0xf0, 0xca, 0xbc, 0x47);
DEFINE_GUID(EAVCENC_CB_QP_OFFSET, 0xcb61f635, 0x5122, 0x4a73, 0xa4, 0x34, 0x1c, 0xdc, 0x7e, 0x6d, 0xcd, 0x58);
DEFINE_GUID(EAVCENC_CR_QP_OFFSET, 0x6807a6d7, 0xdf25, 0x44ab, 0xaa, 0x7a, 0x40, 0xd6, 0xbd, 0x50, 0x7f, 0xfd);
DEFINE_GUID(EAVCENC_PIC_INIT_QP, 0x80fddfe8, 0x14dc, 0x4bd5, 0xa0, 0x2b, 0xfa, 0x24, 0x26, 0x76, 0x8c, 0xd4);

DEFINE_GUID(EAVCENC_DEBLOCK_MODE, 0xd85dfb8e, 0x6fcb, 0x42f6, 0x88, 0xf3, 0x61, 0x35, 0x18, 0xe6, 0xae, 0x54);
DEFINE_GUID(EAVCENC_DEBLOCK_ALPHA, 0x7820edce, 0xbd4, 0x40cb, 0xa1, 0x59, 0x4b, 0x9c, 0xad, 0xf6, 0x4e, 0x93);
DEFINE_GUID(EAVCENC_DEBLOCK_BETA, 0xebca1945, 0x1570, 0x4a54, 0xa0, 0xd3, 0xaf, 0x77, 0x8f, 0x66, 0xea, 0x49);
DEFINE_GUID(EAVCENC_DEBLOCK_CONTROL_PRESENT, 0xdba5298b, 0xb583, 0x4cd3, 0xbc, 0x86, 0xa7, 0x3d, 0x11, 0x42, 0x6e, 0x79);

DEFINE_GUID(EAVCENC_PERFORMANCE, 0xc297a30d, 0x2f7e, 0x4080, 0xb9, 0x4c, 0x80, 0x9, 0xd4, 0x57, 0x9b, 0xba);
DEFINE_GUID(EAVCENC_SPEED_MODE, 0x8b6b783d, 0xe328, 0x4b72, 0xb0, 0x6a, 0xe1, 0x46, 0x36, 0xf0, 0x96, 0x63);
DEFINE_GUID(EAVCENC_SPEED_VALUE, 0x72533f44, 0xc7e, 0x441e, 0x9d, 0x69, 0x20, 0xcd, 0xd6, 0xdf, 0xc5, 0xee);
DEFINE_GUID(EAVCENC_RD_METRIC, 0x97e47e0f, 0x19d4, 0x44b6, 0x9d, 0x6, 0xe4, 0xc0, 0xf3, 0xf7, 0x7b, 0x49);
DEFINE_GUID(EAVCENC_USE_INEW_IN_ISLICE, 0x92c136ca, 0x4277, 0x46a6, 0x89, 0xd7, 0xc, 0xff, 0x2e, 0x6, 0xe6, 0x17);
DEFINE_GUID(EAVCENC_USE_I8x8_IN_ISLICE, 0x77edb55, 0x7678, 0x4129, 0x93, 0x47, 0x1f, 0xc2, 0x4f, 0x55, 0xa9, 0x67);
DEFINE_GUID(EAVCENC_USE_I4x4_IN_ISLICE, 0x5b9aafe2, 0x2ba1, 0x484d, 0xa9, 0xc1, 0x44, 0xec, 0xc7, 0x7b, 0x50, 0xbc);
DEFINE_GUID(EAVCENC_USE_INEW_DC_ONLY_IN_ISLICE, 0x3d22df24, 0x877, 0x46bd, 0xb7, 0xaf, 0xc3, 0x3e, 0xc4, 0x5a, 0x86, 0x16);
DEFINE_GUID(EAVCENC_USE_INEW_IN_PSLICE, 0x16024c6b, 0x450c, 0x449b, 0x92, 0xe9, 0x27, 0xe8, 0x2f, 0x9c, 0xaf, 0x82);
DEFINE_GUID(EAVCENC_USE_I8x8_IN_PSLICE, 0x9fc595c9, 0x506, 0x4edf, 0xbf, 0x4, 0x96, 0x68, 0x6, 0x5e, 0xa7, 0xce);
DEFINE_GUID(EAVCENC_USE_I4x4_IN_PSLICE, 0xbd581582, 0xd7f4, 0x4bd5, 0x89, 0xab, 0x17, 0x98, 0xee, 0xfc, 0x7c, 0x94);
DEFINE_GUID(EAVCENC_USE_INEW_DC_ONLY_IN_PSLICE, 0xb294a8a0, 0xdcb6, 0x4d3f, 0x8c, 0x39, 0xd7, 0x82, 0xb8, 0x6c, 0x2c, 0x46);
DEFINE_GUID(EAVCENC_USE_INEW_IN_BSLICE, 0x9bf7cd52, 0xda7c, 0x40b0, 0xa0, 0x80, 0xf4, 0x89, 0xea, 0x35, 0x7d, 0x1a);
DEFINE_GUID(EAVCENC_USE_I8x8_IN_BSLICE, 0xabfc2152, 0xf11b, 0x48ff, 0x8f, 0x1d, 0x87, 0x8c, 0x12, 0x66, 0x8b, 0xd9);
DEFINE_GUID(EAVCENC_USE_I4x4_IN_BSLICE, 0x810c1530, 0x759f, 0x49fe, 0x8a, 0x93, 0xef, 0xac, 0xc2, 0xfc, 0xf3, 0xec);
DEFINE_GUID(EAVCENC_USE_INEW_DC_ONLY_IN_BSLICE, 0x7bc4ab4e, 0x8b19, 0x45b8, 0x8d, 0xf9, 0x22, 0x24, 0xdf, 0x93, 0x8a, 0x4d);
DEFINE_GUID(EAVCENC_WPRED_IN_PSLICE, 0x3eb61b98, 0x2ee9, 0x47e4, 0x8a, 0xda, 0x20, 0x7c, 0xc, 0x47, 0x54, 0x5d);
DEFINE_GUID(EAVCENC_WPRED_IN_BSLICE, 0x5b2a906d, 0x77b2, 0x4946, 0xae, 0x63, 0xff, 0x3f, 0xd7, 0xc8, 0xe8, 0x18);
DEFINE_GUID(EAVCENC_MC_MIN_BLOCK_SIZE, 0xc6d8546d, 0xd858, 0x4104, 0xb9, 0x33, 0x7b, 0x42, 0x84, 0x9f, 0x6c, 0x62);
DEFINE_GUID(EAVCENC_MC_MIN_SUBPEL_SIZE, 0x9e0b42c6, 0x7dfa, 0x4f88, 0x82, 0x31, 0xed, 0xa5, 0x87, 0x6b, 0x20, 0x59);
DEFINE_GUID(EAVCENC_NUM_REFERENCE_FRAMES, 0x1f6d5e98, 0xbdda, 0x4a99, 0x80, 0x61, 0x5d, 0x9e, 0xe0, 0xf6, 0x79, 0x9);
DEFINE_GUID(EAVCENC_NUM_REF_IDX_L0_ACTIVE, 0x699b6f52, 0xded2, 0x44ce, 0x85, 0xa8, 0x61, 0x1a, 0x99, 0xe1, 0xeb, 0xd8);
DEFINE_GUID(EAVCENC_NUM_REF_IDX_L1_ACTIVE, 0xbe7c97a, 0x4a79, 0x43d5, 0x90, 0x1c, 0x94, 0xef, 0x18, 0xdc, 0x27, 0x38);

DEFINE_GUID(EAVCENC_ME_SEARCH_RANGE, 0xc261fb19, 0xefab, 0x4a0a, 0x8d, 0xf0, 0x8e, 0x6c, 0x33, 0x99, 0x50, 0x4b);
DEFINE_GUID(EAVCENC_USE_OUT_OF_PICTURE_MV, 0xb2905faf, 0x18bc, 0x4e64, 0x85, 0xff, 0x94, 0x1e, 0x6f, 0x11, 0xb1, 0xb);
DEFINE_GUID(EAVCENC_ME_SEARCH_RANGE_EXPLICIT_IN_SLICES, 0x1804c8da, 0x9dc7, 0x43e0, 0x92, 0xbe, 0xb9, 0x33, 0x9d, 0xa3, 0x9c, 0x17);
DEFINE_GUID(EAVCENC_ME_SEARCH_RANGE_X_IN_PSLICE, 0x65ef1a76, 0xa247, 0x42cc, 0xbe, 0x80, 0x76, 0x97, 0x42, 0x1a, 0xc2, 0xa0);
DEFINE_GUID(EAVCENC_ME_SEARCH_RANGE_Y_IN_PSLICE, 0xb1d85895, 0xab1, 0x4aa1, 0x98, 0x12, 0x66, 0x8a, 0x6f, 0x40, 0xed, 0xe7);
DEFINE_GUID(EAVCENC_ME_SEARCH_RANGE_X_IN_BSLICE, 0xc2b3d2f7, 0xcef2, 0x487b, 0x86, 0xa1, 0xd4, 0xfb, 0x79, 0x50, 0x33, 0x1a);
DEFINE_GUID(EAVCENC_ME_SEARCH_RANGE_Y_IN_BSLICE, 0x77eb8048, 0x6f2d, 0x4195, 0xa2, 0x86, 0x89, 0x66, 0x7, 0x6f, 0x72, 0xb2);

DEFINE_GUID(EAVCENC_WRITE_AU_DELIMITERS, 0x235cd12c, 0xc1e4, 0x46ac, 0xa2, 0xf3, 0xe9, 0xa5, 0xa5, 0xf3, 0xf2, 0xb0);
DEFINE_GUID(EAVCENC_WRITE_SEQ_END_CODE, 0xa945b5fe, 0x5b21, 0x4957, 0x81, 0xee, 0x68, 0x13, 0xf2, 0x61, 0x9d, 0xef);
DEFINE_GUID(EAVCENC_WRITE_TIME_STAMPS, 0x93e7ca5b, 0x9415, 0x470e, 0x84, 0x59, 0xc0, 0xd8, 0x1b, 0x2c, 0xf3, 0x3);
DEFINE_GUID(EAVCENC_WRITE_CC, 0x4eba45b3, 0x1af6, 0x41b3, 0x9e, 0xa1, 0x1b, 0xcc, 0x6b, 0x40, 0x5f, 0xb);
DEFINE_GUID(EAVCENC_WRITE_AFD, 0x91bf6093, 0x7365, 0x42b2, 0xa7, 0x75, 0x6a, 0xb0, 0x1a, 0x6e, 0xcd, 0xaf);
DEFINE_GUID(EAVCENC_WRITE_ASPECT_INFO, 0xec7972f0, 0x391b, 0x4aaf, 0xa3, 0xfe, 0xc4, 0xe1, 0x39, 0x0, 0xb5, 0xb6);
DEFINE_GUID(EAVCENC_FULL_RANGE_COLORS, 0x20109c1e, 0x72e5, 0x48bf, 0x83, 0x30, 0xd0, 0x3f, 0x3b, 0x27, 0x8, 0xe3);
DEFINE_GUID(EAVCENC_WRITE_HRD_PARAMS, 0x2f3d7938, 0xd30e, 0x477a, 0xba, 0x51, 0x9a, 0x7b, 0x53, 0x3b, 0x65, 0xf0);
DEFINE_GUID(EAVCENC_SPS_MODE, 0x3a37a0b1, 0x41b, 0x41d8, 0x8a, 0xff, 0xde, 0xd1, 0xb, 0xd6, 0x1a, 0xcb);
DEFINE_GUID(EAVCENC_PPS_MODE, 0x6ab17b06, 0x7356, 0x4b96, 0x93, 0x86, 0xf2, 0x88, 0x9e, 0xda, 0xfb, 0x80);
DEFINE_GUID(EAVCENC_USE_INTRA_REFRESH, 0xada46268, 0x545c, 0x44fd, 0xbd, 0xf4, 0x74, 0xd2, 0xee, 0x5f, 0x8d, 0x22);
DEFINE_GUID(EAVCENC_LOG2_MAX_FRAME_NUM, 0x8b13bb, 0x66a0, 0x410e, 0xb7, 0x2f, 0xac, 0x44, 0x1c, 0x39, 0x7f, 0x64);
DEFINE_GUID(EAVCENC_LOG2_MAX_PIC_ORDER_CNT_LSB, 0xb2c0719b, 0xce82, 0x456e, 0x94, 0xe2, 0x9c, 0xa2, 0xe2, 0xb9, 0x50, 0xf1);
DEFINE_GUID(EAVCENC_PIC_ORDER_CNT_TYPE, 0x108ab2f4, 0x6671, 0x480d, 0xa8, 0xb1, 0x50, 0x79, 0x1e, 0xe, 0x76, 0x53);
DEFINE_GUID(EAVCENC_MEDIASDK_ASYNC_DEPTH, 0x23cac9e, 0xc0b0, 0x4981, 0xaa, 0x4d, 0x3f, 0x99, 0xf8, 0xd2, 0xf1, 0x89);
DEFINE_GUID(EAVCENC_USE_UTC_TIME, 0xa12af436, 0xd9b1, 0x361a, 0xcc, 0x5b, 0x9c, 0x43, 0xa5, 0x10, 0x21, 0x32);
DEFINE_GUID(EAVCENC_COLOUR_DESCRIPTION, 0xdbf3e690, 0x3f00, 0x4952, 0x8d, 0x92, 0xbb, 0x21, 0xa7, 0xf3, 0x90, 0x55);
DEFINE_GUID(EAVCENC_COLOUR_DESCRIPTION_VALUE, 0x1957fa71, 0x1146, 0xaf62, 0x8a, 0x32, 0xa1, 0x17, 0x7a, 0x19, 0x83, 0x46);
DEFINE_GUID(EAVCENC_FORCE_PIC_STRUCT_PRESENT_FLAG, 0x1905af87, 0x961b, 0x61c0, 0x15, 0x64, 0x32, 0x18, 0x81, 0x75, 0x69, 0xa0);


#endif
