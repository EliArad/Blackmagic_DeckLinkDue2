﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace DeckLinkCSCaptureLib
{
    public class DeckLinkCSCaptureApi
    {


        public enum BMDPixelFormat
        {
            bmdFormatUnspecified = 0,
            bmdFormat8BitYUV = 0x32767579,
            bmdFormat10BitYUV = 0x76323130,
            bmdFormat8BitARGB = 32,
            bmdFormat8BitBGRA = 0x42475241,
            bmdFormat10BitRGB = 0x72323130,
            bmdFormat12BitRGB = 0x52313242,
            bmdFormat12BitRGBLE = 0x5231324c,
            bmdFormat10BitRGBXLE = 0x5231306c,
            bmdFormat10BitRGBX = 0x52313062,
            bmdFormatH265 = 0x68657631,
            bmdFormatDNxHR = 0x41566468
        }

        public enum DECKLINK2_DEVICES
        {
            DEVICE1,
            DEVICE2,
            DEVICE3,
            DEVICE4,
        }

        public enum SURFACE_ENGINE
        {

            OPENGL,
            DX9
        }


#if DEBUG
        const string path = @"C:\Program Files\Bauotech\Dll\DeckLinkDueApi.dll";
#else
        const string path = @"DeckLinkDueApi.dll";
#endif 


        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern int DL2_StartCapture(DECKLINK2_DEVICES device, SURFACE_ENGINE st);

        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern bool DL2_StopCapture();


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void FrameCallback(IntPtr buffer, int width, int size, BMDPixelFormat pf);


        [DllImport(path, CallingConvention = CallingConvention.Cdecl)]
        public static extern void DL2_SetFrameCallback([MarshalAs(UnmanagedType.FunctionPtr)] FrameCallback callbackPointer);



        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern bool DL2_SetVideoHandle(IntPtr handle);

        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern void DL2_SetWindowSize(int x, int y, int width, int height);
         

        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern void DL2_SetPreviewVideo(bool preview);

        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern void DL2_Build_H264_TransportMux_Network([MarshalAs(UnmanagedType.LPWStr)]String IpAddress, int port, [MarshalAs(UnmanagedType.LPWStr)]String IpInterfaceAddress, uint bitrate, int goplength);


        public void Build_H264_TransportMux_Network(string IpAddress, int port, string IpInterfaceAddress, uint bitrate = 1500000, int goplength = 15)
        {
            DL2_Build_H264_TransportMux_Network(IpAddress, port, IpInterfaceAddress, bitrate, goplength);
        }

        public void SetPreviewVideo(bool preview)
        {
            DL2_SetPreviewVideo(preview);
        }

        public void SetWindowSize(int x, int y, int width, int height)
        {
            DL2_SetWindowSize(x, y, width, height);

        }
        public int StartCapture(DECKLINK2_DEVICES device, SURFACE_ENGINE st)
        {
            return DL2_StartCapture(device, st);
        }

        public bool StopCapture()
        {
            return DL2_StopCapture();
        }
        public void SetVideoHandle(IntPtr handle)
        {
            DL2_SetVideoHandle(handle);
        }
        public void SetFrameCallback([MarshalAs(UnmanagedType.FunctionPtr)] FrameCallback callbackPointer)
        {
            DL2_SetFrameCallback(callbackPointer);
        }
    }
}
