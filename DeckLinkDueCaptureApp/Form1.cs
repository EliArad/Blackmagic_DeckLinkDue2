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


        DeckLinkCSCaptureApi[] m_dl2 = new DeckLinkCSCaptureApi[4];
        FrameCallback pFrameCallback;
         

        public Form1()
        {
            InitializeComponent();

            int id = 0;
            m_dl2[id] = new DeckLinkCSCaptureApi(id);

            AppSettings.Instance.Load("DeckLinkDueCaptureApp.json");

            this.KeyPreview = true;
            Control.CheckForIllegalCrossThreadCalls = false;
            pFrameCallback = new FrameCallback(FrameCallbackData);
            //m_dl2[id].SetFrameCallback(pFrameCallback);
            m_dl2[id].SetVideoHandle(panel1.Handle);
            m_dl2[id].SetWindowSize(0, 0, panel1.Width, panel1.Height);
             
            if (AppSettings.Instance.Config.EnableDownGraph > 0)
            {
                if (AppSettings.Instance.Config.EnableDownGraph == 1)
                {
                    m_dl2[id].Build_H264_TransportMux_Network(AppSettings.Instance.Config.MulticastIpAddress,
                                                          AppSettings.Instance.Config.MulticastPort,
                                                          AppSettings.Instance.Config.NicIpAddress, AppSettings.Instance.Config.bitrate,
                                                          AppSettings.Instance.Config.gopLength);
                }

                if (AppSettings.Instance.Config.EnableDownGraph == 2)
                {

                    m_dl2[id].Build_H264QS_TransportMux_Network(AppSettings.Instance.Config.MulticastIpAddress,
                                                         AppSettings.Instance.Config.MulticastPort,
                                                         AppSettings.Instance.Config.NicIpAddress, AppSettings.Instance.Config.bitrate,
                                                         AppSettings.Instance.Config.gopLength);
                }

            }

            int res;
            if ((res = m_dl2[id].StartCapture(AppSettings.Instance.Config.Device ,SURFACE_ENGINE.DX9)) < 0)
            {
                MessageBox.Show("Failed to start capture: " + res);
            }
        }
 

        [DllImport("kernel32.dll", EntryPoint = "CopyMemory", SetLastError = false)]
        public static extern void CopyMemory(IntPtr dest, IntPtr src, uint count);

        void FrameCallbackData(IntPtr buffer, int width, int height, BMDPixelFormat pf)
        {
             
            Bitmap b = new Bitmap((int)width, (int)height, PixelFormat.Format32bppRgb);
            Rectangle BoundsRect = new Rectangle(0, 0, (int)width, (int)height);
            BitmapData bmpData = b.LockBits(BoundsRect,
                                            ImageLockMode.WriteOnly,
                                            b.PixelFormat);

            IntPtr ptr = bmpData.Scan0;
            // fill in rgbValues
            CopyMemory(ptr, buffer, 1920 * 1080 * 4);

            b.UnlockBits(bmpData);
            /*
            if (m_saveImage == true)
            {
                b.Save(m_imageFileName, ImageFormat.Bmp);
                m_saveImage = false;
            }
            */
            pictureBox1.Image = b;
        }

        bool m_previewVideo = true;
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode ==  Keys.F2)
            {
                m_previewVideo = !m_previewVideo;
                m_dl2[0].SetPreviewVideo(m_previewVideo);
                pictureBox1.Visible = !m_previewVideo;
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_dl2[0].StopCapture();
        }
    }
}
