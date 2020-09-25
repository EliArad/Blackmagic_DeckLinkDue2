using DeckLinkCSCaptureLib;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static DeckLinkCSCaptureLib.DeckLinkCSCaptureApi;

namespace DeckLinkDueCaptureApp
{
    public partial class Form1 : Form
    {


        DeckLinkCSCaptureApi m_dl2 = new DeckLinkCSCaptureApi();
        FrameCallback pFrameCallback;

        
        byte [] pitcureByteArray = new byte[1920 * 1080 * 4];
    

        public Form1()
        {
            InitializeComponent();
            Control.CheckForIllegalCrossThreadCalls = false;
            pFrameCallback = new FrameCallback(FrameCallbackData);
            //m_dl2.SetFrameCallback(pFrameCallback);
            m_dl2.SetVideoHandle(panel1.Handle);
            this.Resize += Form1_Resize;
            m_dl2.SetWindowSize(0, 0, panel1.Width, panel1.Height);
            m_dl2.StartCapture();
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            panel1.Width = this.Width;
            panel1.Height = this.Height;
            panel1.Left = this.Left;
            panel1.Top = this.Top;
            m_dl2.SetVideoHandle(panel1.Handle);
            m_dl2.SetWindowSize(0, 0, panel1.Width, panel1.Height);

        }

        [DllImport("kernel32.dll", EntryPoint = "CopyMemory", SetLastError = false)]
        public static extern void CopyMemory(IntPtr dest, IntPtr src, uint count);

        void FrameCallbackData(IntPtr buffer, int width, int height)
        {
           

            Bitmap b = new Bitmap((int)width, (int)height, PixelFormat.Format16bppRgb565);
            Rectangle BoundsRect = new Rectangle(0, 0, (int)width, (int)height);
            BitmapData bmpData = b.LockBits(BoundsRect,
                                            ImageLockMode.WriteOnly,
                                            b.PixelFormat);

            IntPtr ptr = bmpData.Scan0;

            // fill in rgbValues
            CopyMemory(ptr, buffer, (uint)(width * height * 2));
            b.UnlockBits(bmpData);
            //pictureBox1.Image = b;
        }        
    }
}
