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
            this.KeyPreview = true;
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
        }

        private void Form1_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
        {
         //   MessageBox.Show("key pressed = " + e.KeyCode);
            if (e.KeyCode == (Keys.D1))
            {
                btn_speed_1.PerformClick();
            }
            if (e.KeyCode == (Keys.D2))
            {
                btn_speed_2.PerformClick();
            }
            if (e.KeyCode == (Keys.D3))
            {
                btn_speed_3.PerformClick();
            }
            if (e.KeyCode == (Keys.D4))
            {
                btn_speed_4.PerformClick();
            }
            if (e.KeyCode == (Keys.Q))
            {
                btn_indicate_left.PerformClick();
            }
            if (e.KeyCode == (Keys.E))
            {
                btn_indicate_right.PerformClick();
            }
            if (e.KeyCode == (Keys.O))
            {
                btn_power_off.PerformClick();
            }
            if (e.KeyCode == (Keys.I))
            {
                btn_power_on.PerformClick();
            }
            if (e.KeyCode == (Keys.C))
            {
                btn_horn.PerformClick();
            }
            if (e.KeyCode == (Keys.Z))
            {
                btn_headlights.PerformClick();
            }
            if (e.KeyCode == (Keys.F))
            {
                btn_forward.PerformClick();
            }
            if (e.KeyCode == (Keys.R))
            {
                btn_reverse.PerformClick();
            }
            if (e.KeyCode == (Keys.W))
            {
                if (trackBar1.Value <= 125)
                {
                    trackBar1.Value = trackBar1.Value + 2;
                    textBox1.AppendText("Throttle Position = " + trackBar1.Value + Environment.NewLine);

                }
            }
            if (e.KeyCode == (Keys.S))
            {
                if (trackBar1.Value > 1)
                {
                    trackBar1.Value = trackBar1.Value - 2;
                    textBox1.AppendText("Throttle Position = " + trackBar1.Value + Environment.NewLine);
                }
            }
            if (e.KeyCode == (Keys.X))
            {
                trackBar1.Value = 0;
                btn_stop.PerformClick();
            }
            if (e.KeyCode == (Keys.NumPad8 ))
            {
                btn_pan_up.PerformClick();
            }
            if (e.KeyCode == (Keys.NumPad2))
            {
                btn_pan_down.PerformClick();
            }
            if (e.KeyCode == (Keys.NumPad4))
            {
                btn_pan_left.PerformClick();
            }
            if (e.KeyCode == (Keys.NumPad6))
            {
                btn_pan_right.PerformClick();
            }
            if (e.KeyCode == (Keys.NumPad7))
            {
                btn_camera_raise.PerformClick();
            }
            if (e.KeyCode == (Keys.NumPad1))
            {
                btn_camera_lower.PerformClick();
            }
            

        }

        private void serial_check()
        {
            MessageBox.Show("Please open Serial Connection");
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Connect(string portName)
        {
            serialPort1 = new SerialPort(portName);
            if (!serialPort1.IsOpen)
            {
                serialPort1.BaudRate = 19200;
                serialPort1.Open();
                btn_serial_connect.Enabled = false;
                lbl_serial.Text = (String.Format("Connected to '{0}'", comboBox1.SelectedItem));

            }
        }

        private void btn_serial_connect_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex > -1)
            {
               // MessageBox.Show(String.Format("Connecting to '{0}'", comboBox1.SelectedItem));
                Connect(comboBox1.SelectedItem.ToString());
            }
            else
            {
                MessageBox.Show("Please select a port first");
            }
        }

        private void btn_serial_disconnect_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
                lbl_serial.Text = ("Serial Connection Closed");
               // MessageBox.Show("Serial connection closed");
                btn_serial_connect.Enabled = true;
            }
            else if (!serialPort1.IsOpen)
            {
                MessageBox.Show("No connection currently open", "Alert");
            }

        }

        private void btn_serial_refresh_Click(object sender, EventArgs e)
        {
            var ports = SerialPort.GetPortNames();
            comboBox1.DataSource = ports;
        }

        private void btn_speed_1_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] speed_1 = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x31, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x0A };
                serialPort1.Write(speed_1, 0, 18);
                textBox1.AppendText("Speed set to 1" + Environment.NewLine);
            }
        } //done

        private void btn_speed_2_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] speed_2 = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x30, 0x31, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x0A };
                serialPort1.Write(speed_2, 0, 18);
                textBox1.AppendText("Speed set to 2" + Environment.NewLine);
            }
        } //done

        private void btn_speed_3_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] speed_3 = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x30, 0x30, 0x31, 0x30, 0x30, 0x30, 0x30, 0x30, 0x0A };
                serialPort1.Write(speed_3, 0, 18);
                textBox1.AppendText("Speed set to 3" + Environment.NewLine);
            }
        } //done

        private void btn_speed_4_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] speed_4 = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x30, 0x30, 0x30, 0x31, 0x30, 0x30, 0x30, 0x30, 0x0A };
                serialPort1.Write(speed_4, 0, 18);
                textBox1.AppendText("Speed set to 4" + Environment.NewLine);
            }
        } //done

        private void btn_indicate_left_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] indicate_left = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x30, 0x30, 0x30, 0x30, 0x31, 0x30, 0x30, 0x30, 0x0A };
                serialPort1.Write(indicate_left, 0, 18);
                textBox1.AppendText("Indicating Left" + Environment.NewLine);
            }
        } //done

        private void btn_indicate_right_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] indicate_right = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x30, 0x30, 0x0A };
                serialPort1.Write(indicate_right, 0, 18);
                textBox1.AppendText("Indicating Right" + Environment.NewLine);
            }
        } //done

        private void btn_headlights_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] headlights = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x0A };
                serialPort1.Write(headlights, 0, 18);
                textBox1.AppendText("Headlights Toggled" + Environment.NewLine);
            }
        } //done

        private void btn_horn_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] horn = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x41, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x31, 0x30, 0x0A };
                serialPort1.Write(horn, 0, 18);
                textBox1.AppendText("Horn Triggered" + Environment.NewLine);
            }
        } //done

        private void btn_power_on_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] power_on = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x42, 0x31, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
                serialPort1.Write(power_on, 0, 18);
                textBox1.AppendText("Powering On" + Environment.NewLine);
            }
        } //done

        private void btn_power_off_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] power_off = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x32, 0x57, 0x42, 0x30, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
                serialPort1.Write(power_off, 0, 18);
                textBox1.AppendText("Powering Off" + Environment.NewLine);
            }
        } //done

        private void btn_remote_lock_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] remote_lock = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x57, 0x41, 0x31, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
                serialPort1.Write(remote_lock, 0, 18);
                textBox1.AppendText("Remote Lock Set" + Environment.NewLine);
            }
        } //done

        private void btn_remote_unlock_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] remote_unlock = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x57, 0x41, 0x30, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
                serialPort1.Write(remote_unlock, 0, 18);
                textBox1.AppendText("Remote Lock Unset" + Environment.NewLine);
            }
        } //done

        private void btn_locate_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
                Byte[] locate = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x52, 0x41, 0x43, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
                serialPort1.Write(locate, 0, 18);
                textBox1.AppendText("Gps Location Requested" + Environment.NewLine);
            }
        } //done

        private void btn_forward_Click(object sender, EventArgs e)
        {
            btn_forward.BackColor = System.Drawing.Color.FromArgb(128, 255, 128);
            btn_reverse.BackColor = System.Drawing.Color.FromArgb(255, 128, 128);
            textBox1.AppendText("Setting Direction to Forward" + Environment.NewLine);
        }

        private void btn_reverse_Click(object sender, EventArgs e)
        {
            btn_forward.BackColor = System.Drawing.Color.FromArgb(255, 128, 128);
            btn_reverse.BackColor = System.Drawing.Color.FromArgb(128, 255, 128);
            textBox1.AppendText("Setting Direction to Reverse" + Environment.NewLine);
        }

        private void btn_stop_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("All Stop Selected" + Environment.NewLine);
        }

        private void btn_pan_up_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
               //Byte[] locate = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x52, 0x41, 0x43, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
               // serialPort1.Write(locate, 0, 18);
                textBox1.AppendText("Camera Panning Up" + Environment.NewLine);
            }
        }

        private void btn_pan_down_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
               //Byte[] locate = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x52, 0x41, 0x43, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
               // serialPort1.Write(locate, 0, 18);
                textBox1.AppendText("Camera Panning Down" + Environment.NewLine);
            }
         }

        private void btn_pan_left_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
               //Byte[] locate = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x52, 0x41, 0x43, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
               // serialPort1.Write(locate, 0, 18);
                textBox1.AppendText("Camera Panning Left" + Environment.NewLine);
            }
        }

        private void btn_pan_right_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
               //Byte[] locate = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x52, 0x41, 0x43, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
               // serialPort1.Write(locate, 0, 18);
                textBox1.AppendText("Camera Panning Right" + Environment.NewLine);
            }
        }

        private void btn_camera_raise_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
               Byte[] camera_raise = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x57, 0x43, 0x52, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
               serialPort1.Write(camera_raise, 0, 18);
               textBox1.AppendText("Raising Camera" + Environment.NewLine);
            }
        } //done

        private void btn_camera_lower_Click(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
            {
                serial_check();
            }
            else
            {
               Byte[] camera_lower = { 0x1B, Convert.ToByte(code_1.Value), Convert.ToByte(code_2.Value), Convert.ToByte(code_3.Value), Convert.ToByte(code_4.Value), Convert.ToByte(code_5.Value), 0x30, 0x57, 0x43, 0x4C, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x0A };
               serialPort1.Write(camera_lower, 0, 18);
               textBox1.AppendText("Lowering Camera" + Environment.NewLine);
            }
        } //done

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

        public void code_1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void code_2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void code_3_ValueChanged(object sender, EventArgs e)
        {

        }

        private void code_4_ValueChanged(object sender, EventArgs e)
        {

        }

        private void code_5_ValueChanged(object sender, EventArgs e)
        {

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            textBox1.AppendText("Throttle Position = " + trackBar1.Value + Environment.NewLine);
        }
        
    }
}
