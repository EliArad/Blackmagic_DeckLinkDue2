using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using static DeckLinkCSCaptureLib.DeckLinkCSCaptureApi;

namespace DeckLinkDueCaptureApp
{
    
    public class AppConfig
    {
        public DECKLINK2_DEVICES Device;
        public int EnableDownGraph;
        public string MulticastIpAddress;
        public int MulticastPort;
        public string NicIpAddress;
        public uint bitrate;
        public int gopLength;
    }
     

    public sealed class AppSettings
    {
        private static AppSettings instance = null;
        private static readonly object padlock = new object();
        AppConfig m_config;
        string m_fileName;

        AppSettings()
        {
        }
        public AppConfig Config
        {
            get
            {
                return m_config;
            }
        }


 
        public void Default()
        {
            m_config.EnableDownGraph = 0;
            m_config.MulticastIpAddress = "234.5.5.5";
            m_config.MulticastPort = 6000;
            m_config.NicIpAddress = "10.0.0.10";
            m_config.bitrate = 3000000;
            m_config.gopLength = 15;
            m_config.Device = DECKLINK2_DEVICES.DEVICE2;
        }

        public string Save()
        {
            try
            {


                string json = JsonConvert.SerializeObject(m_config);
                string jsonFormatted = JValue.Parse(json).ToString(Formatting.Indented);
                File.WriteAllText(m_fileName, jsonFormatted);

                return "ok";
            }
            catch (Exception err)
            {
                return err.Message;
            }
        }


        public string Load(string fileName, bool defaultIfNeed = true)
        {
            try
            {
                m_fileName = fileName;
                if (File.Exists(fileName) == false)
                {
                    m_config = new AppConfig();
                    Default();
                    Save();
                    return "file not found";
                }
                string text = File.ReadAllText(m_fileName);
                m_config = JsonConvert.DeserializeObject<AppConfig>(text);
                if (m_config == null)
                {
                    m_config = new AppConfig();
                    Default();
                    Save();
                }


                return "ok";
            }
            catch (Exception err)
            {
                m_config = new AppConfig();
                Default();
                Save();
                return err.Message;
            }
        }

        public static AppSettings Instance
        {
            get
            {
                if (instance == null)
                {
                    lock (padlock)
                    {
                        if (instance == null)
                        {
                            instance = new AppSettings();
                        }
                    }
                }
                return instance;
            }
        }
    }

}
