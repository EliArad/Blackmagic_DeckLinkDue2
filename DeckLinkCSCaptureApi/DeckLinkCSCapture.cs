using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace DeckLinkCSCaptureLib
{
    public class DeckLinkCSCaptureApi
    {

        const string path = @"C:\Program Files\Bauotech\Dll\DeckLinkDueApi.dll";

        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern bool DL2_StartCapture();

        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern bool DL2_StopCapture();


        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void FrameCallback(IntPtr buffer, int width, int size);


        [DllImport(path, CallingConvention = CallingConvention.Cdecl)]
        public static extern void DL2_SetFrameCallback([MarshalAs(UnmanagedType.FunctionPtr)] FrameCallback callbackPointer);



        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern bool DL2_SetVideoHandle(IntPtr handle);

        [DllImport(path, CallingConvention = CallingConvention.StdCall)]
        public static extern void DL2_SetWindowSize(int x, int y, int width, int height);

        public void SetWindowSize(int x, int y, int width, int height)
        {
            DL2_SetWindowSize(x, y, width, height);

        }
        public bool StartCapture()
        {
            return DL2_StartCapture();
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
