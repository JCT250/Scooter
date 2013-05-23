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

namespace Scooter_Controller
{
    public partial class Form1 : Form
    {
      
        public Form1()
        {
            InitializeComponent();
        
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            var ports = SerialPort.GetPortNames();
            comboBox1.DataSource = ports;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
      
        }

        private void btn_serial_connect_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex > -1)
            {
                MessageBox.Show(String.Format("Attempting to connect to '{0}'", comboBox1.SelectedItem));
                Connect(comboBox1.SelectedItem.ToString());
            }
            else
            {
                MessageBox.Show("Please select a port first");
            }
        }

        private void Connect(string portName)
        {
            var port = new SerialPort(portName);
            if (!port.IsOpen)
            {
                port.BaudRate = 19200;
                port.Open();
            }
        }

        private void btn_serial_refresh_Click(object sender, EventArgs e)
        {
            var ports = SerialPort.GetPortNames();
            comboBox1.DataSource = ports;
        }
    }
}
