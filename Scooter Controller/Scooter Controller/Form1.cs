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

        private void btn_speed_1_Click(object sender, EventArgs e)
        {

        }

        private void btn_speed_2_Click(object sender, EventArgs e)
        {

        }

        private void btn_speed_3_Click(object sender, EventArgs e)
        {

        }

        private void btn_speed_4_Click(object sender, EventArgs e)
        {

        }

        private void btn_indicate_left_Click(object sender, EventArgs e)
        {

        }

        private void btn_indicate_right_Click(object sender, EventArgs e)
        {

        }

        private void btn_headlights_Click(object sender, EventArgs e)
        {

        }

        private void btn_horn_Click(object sender, EventArgs e)
        {

        }

        private void btn_power_on_Click(object sender, EventArgs e)
        {

        }

        private void btn_power_off_Click(object sender, EventArgs e)
        {

        }

        private void btn_remote_lock_Click(object sender, EventArgs e)
        {

        }

        private void btn_remote_unlock_Click(object sender, EventArgs e)
        {

        }

        private void btn_locate_Click(object sender, EventArgs e)
        {

        }

        private void btn_forward_Click(object sender, EventArgs e)
        {

        }

        private void btn_reverse_Click(object sender, EventArgs e)
        {

        }

        private void btn_stop_Click(object sender, EventArgs e)
        {

        }

        private void btn_pan_up_Click(object sender, EventArgs e)
        {

        }

        private void btn_pan_down_Click(object sender, EventArgs e)
        {

        }

        private void btn_pan_left_Click(object sender, EventArgs e)
        {

        }

        private void btn_pan_right_Click(object sender, EventArgs e)
        {

        }

        private void bnt_lighting_mode_1_Click(object sender, EventArgs e)
        {

        }

        private void btn_lighting_mode_2_Click(object sender, EventArgs e)
        {

        }

        private void btn_lighting_mode_3_Click(object sender, EventArgs e)
        {

        }

        private void btn_lighting_mode_4_Click(object sender, EventArgs e)
        {

        }

        private void btn_lighting_mode_5_Click(object sender, EventArgs e)
        {

        }

        private void btn_lighting_mode_6_Click(object sender, EventArgs e)
        {

        }

        private void btn_lighting_activate_Click(object sender, EventArgs e)
        {

        }

        private void btn_lighting_deactivate_Click(object sender, EventArgs e)
        {

        }




    }
}
