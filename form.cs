using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Windows.Forms;

namespace hyper
{
    public partial class Form1 : Form
    {
       
        public Form1()
        {
            InitializeComponent();
        }
        public void Connect() { 
        try { 
            if (!oSerialPort.IsOpen) { 
                oSerialPort.Open(); 
               textBox1.Text="Connected"; 
            } // else already open 
        } catch (Exception e1) {  
              MessageBox.Show("Error: Connection is in use or is not available: \n\n" + e1);  
         } 
	    }
   
	    public string Handshake = ""; 
	 
	    public string DataReceived = ""; 

        SerialPort oSerialPort = new SerialPort("COM6", 9600, Parity.None, 8, StopBits.One);

 
        public void Write(string sData) { 
	     
            if (oSerialPort.IsOpen) { 
	            try { 
	                oSerialPort.Write(sData);
                    //oSerialPort.Write(new char[] { '1', '2', '3' }, Convert.ToInt32(textBox1.Text) - 1, 1);
	                
	            } catch { } 
	        } 
	    } 
         public string Read() { 
	        try { 
	            this.DataReceived = oSerialPort.ReadLine().ToString(); 
	            MessageBox.Show(this.DataReceived); 
	            return (this.DataReceived); 
        } catch { 
	            return ""; 
	        } 
	    } 
        public void Disconnect() { 
	        try{ 
	            if (oSerialPort.IsOpen) { 
	                oSerialPort.Close();
                    textBox1.Text = "Disconnected"; 
	            } //else not open 
	        } catch { } 
	    } 

        private void button1_Click(object sender, EventArgs e)
        {
            if (!oSerialPort.IsOpen)
            {
                MessageBox.Show("Lütfen bağlantıyı yapınız"); 
            }
            else
            {
                oSerialPort.DiscardOutBuffer();
                Write("1");
                textBox1.Text = "1.led için veri gönderildi";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {if (!oSerialPort.IsOpen)
	        {
                MessageBox.Show("Lütfen bağlantıyı yapınız"); 
        	}
            else { 
            oSerialPort.DiscardOutBuffer();
            Write("2");
            textBox1.Text = "2.led için veri gönderildi";
        }
        }

        private void button3_Click(object sender, EventArgs e)
        {if (!oSerialPort.IsOpen)
	        {
                MessageBox.Show("Lütfen bağlantıyı yapınız"); 
        	}
            else { 
            oSerialPort.DiscardOutBuffer();
            Write("3");
            textBox1.Text = "3.led için veri gönderildi";
        }
        }

        private void button4_Click(object sender, EventArgs e)
        {if (!oSerialPort.IsOpen)
	        {
                MessageBox.Show("Lütfen bağlantıyı yapınız"); 
        	}
            else { 
            oSerialPort.DiscardOutBuffer();
            Write("4");
            textBox1.Text = "4.led için veri gönderildi";
        }
        }

        private void button5_Click(object sender, EventArgs e)
        {if (!oSerialPort.IsOpen)
	        {
                MessageBox.Show("Lütfen bağlantıyı yapınız"); 
        	}
            else { 
            oSerialPort.DiscardOutBuffer();
            Write("5");
            textBox1.Text = "5.led için veri gönderildi";
        }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Connect();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Disconnect();
        }

        private void Key_Presss(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == 'a' || e.KeyChar == 's' || e.KeyChar == 'd' || e.KeyChar == 'w')
            {
                oSerialPort.DiscardOutBuffer();
                Write(e.KeyChar.ToString());
                textBox1.Text = e.KeyChar.ToString() + " gönderildi";
            }
            
        }

        private void Key_Press_Up(object sender, KeyEventArgs e)
        {
             wif (e.KeyCode == Keys.Space)
            {
                oSerialPort.DiscardOutBuffer();
                Write("6");
                textBox1.Text = "Motorlar durduruldu";
            }
        }

       

       

    }
}
