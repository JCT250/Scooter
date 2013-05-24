﻿namespace Scooter_Controller
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btn_speed_1 = new System.Windows.Forms.Button();
            this.btn_speed_2 = new System.Windows.Forms.Button();
            this.btn_speed_3 = new System.Windows.Forms.Button();
            this.btn_speed_4 = new System.Windows.Forms.Button();
            this.btn_indicate_left = new System.Windows.Forms.Button();
            this.btn_indicate_right = new System.Windows.Forms.Button();
            this.btn_headlights = new System.Windows.Forms.Button();
            this.btn_horn = new System.Windows.Forms.Button();
            this.btn_power_on = new System.Windows.Forms.Button();
            this.btn_power_off = new System.Windows.Forms.Button();
            this.btn_remote_lock = new System.Windows.Forms.Button();
            this.btn_remote_unlock = new System.Windows.Forms.Button();
            this.btn_locate = new System.Windows.Forms.Button();
            this.btn_forward = new System.Windows.Forms.Button();
            this.btn_reverse = new System.Windows.Forms.Button();
            this.btn_pan_left = new System.Windows.Forms.Button();
            this.btn_pan_right = new System.Windows.Forms.Button();
            this.btn_pan_up = new System.Windows.Forms.Button();
            this.btn_pan_down = new System.Windows.Forms.Button();
            this.btn_stop = new System.Windows.Forms.Button();
            this.bnt_lighting_mode_1 = new System.Windows.Forms.Button();
            this.btn_lighting_mode_2 = new System.Windows.Forms.Button();
            this.btn_lighting_mode_3 = new System.Windows.Forms.Button();
            this.btn_lighting_mode_4 = new System.Windows.Forms.Button();
            this.btn_lighting_mode_5 = new System.Windows.Forms.Button();
            this.btn_lighting_activate = new System.Windows.Forms.Button();
            this.btn_lighting_deactivate = new System.Windows.Forms.Button();
            this.btn_lighting_mode_6 = new System.Windows.Forms.Button();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btn_camera_raise = new System.Windows.Forms.Button();
            this.btn_camera_lower = new System.Windows.Forms.Button();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.btn_serial_connect = new System.Windows.Forms.Button();
            this.btn_serial_refresh = new System.Windows.Forms.Button();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.btn_serial_disconnect = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.SuspendLayout();
            // 
            // btn_speed_1
            // 
            this.btn_speed_1.Location = new System.Drawing.Point(13, 21);
            this.btn_speed_1.Name = "btn_speed_1";
            this.btn_speed_1.Size = new System.Drawing.Size(100, 30);
            this.btn_speed_1.TabIndex = 0;
            this.btn_speed_1.Text = "Speed 1";
            this.btn_speed_1.UseVisualStyleBackColor = true;
            this.btn_speed_1.Click += new System.EventHandler(this.btn_speed_1_Click);
            // 
            // btn_speed_2
            // 
            this.btn_speed_2.Location = new System.Drawing.Point(127, 21);
            this.btn_speed_2.Name = "btn_speed_2";
            this.btn_speed_2.Size = new System.Drawing.Size(100, 30);
            this.btn_speed_2.TabIndex = 1;
            this.btn_speed_2.Text = "Speed 2";
            this.btn_speed_2.UseVisualStyleBackColor = true;
            this.btn_speed_2.Click += new System.EventHandler(this.btn_speed_2_Click);
            // 
            // btn_speed_3
            // 
            this.btn_speed_3.Location = new System.Drawing.Point(241, 21);
            this.btn_speed_3.Name = "btn_speed_3";
            this.btn_speed_3.Size = new System.Drawing.Size(100, 30);
            this.btn_speed_3.TabIndex = 2;
            this.btn_speed_3.Text = "Speed 3";
            this.btn_speed_3.UseVisualStyleBackColor = true;
            this.btn_speed_3.Click += new System.EventHandler(this.btn_speed_3_Click);
            // 
            // btn_speed_4
            // 
            this.btn_speed_4.Location = new System.Drawing.Point(355, 21);
            this.btn_speed_4.Name = "btn_speed_4";
            this.btn_speed_4.Size = new System.Drawing.Size(100, 30);
            this.btn_speed_4.TabIndex = 3;
            this.btn_speed_4.Text = "Speed 4";
            this.btn_speed_4.UseVisualStyleBackColor = true;
            this.btn_speed_4.Click += new System.EventHandler(this.btn_speed_4_Click);
            // 
            // btn_indicate_left
            // 
            this.btn_indicate_left.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.btn_indicate_left.Location = new System.Drawing.Point(13, 57);
            this.btn_indicate_left.Name = "btn_indicate_left";
            this.btn_indicate_left.Size = new System.Drawing.Size(100, 30);
            this.btn_indicate_left.TabIndex = 4;
            this.btn_indicate_left.Text = "Indicate Left";
            this.btn_indicate_left.UseVisualStyleBackColor = false;
            this.btn_indicate_left.Click += new System.EventHandler(this.btn_indicate_left_Click);
            // 
            // btn_indicate_right
            // 
            this.btn_indicate_right.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.btn_indicate_right.Location = new System.Drawing.Point(127, 57);
            this.btn_indicate_right.Name = "btn_indicate_right";
            this.btn_indicate_right.Size = new System.Drawing.Size(100, 30);
            this.btn_indicate_right.TabIndex = 5;
            this.btn_indicate_right.Text = "Indicate Right";
            this.btn_indicate_right.UseVisualStyleBackColor = false;
            this.btn_indicate_right.Click += new System.EventHandler(this.btn_indicate_right_Click);
            // 
            // btn_headlights
            // 
            this.btn_headlights.Location = new System.Drawing.Point(241, 57);
            this.btn_headlights.Name = "btn_headlights";
            this.btn_headlights.Size = new System.Drawing.Size(100, 30);
            this.btn_headlights.TabIndex = 6;
            this.btn_headlights.Text = "Headlights";
            this.btn_headlights.UseVisualStyleBackColor = true;
            this.btn_headlights.Click += new System.EventHandler(this.btn_headlights_Click);
            // 
            // btn_horn
            // 
            this.btn_horn.Location = new System.Drawing.Point(355, 57);
            this.btn_horn.Name = "btn_horn";
            this.btn_horn.Size = new System.Drawing.Size(100, 30);
            this.btn_horn.TabIndex = 7;
            this.btn_horn.Text = "Horn";
            this.btn_horn.UseVisualStyleBackColor = true;
            this.btn_horn.Click += new System.EventHandler(this.btn_horn_Click);
            // 
            // btn_power_on
            // 
            this.btn_power_on.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.btn_power_on.Location = new System.Drawing.Point(13, 93);
            this.btn_power_on.Name = "btn_power_on";
            this.btn_power_on.Size = new System.Drawing.Size(100, 30);
            this.btn_power_on.TabIndex = 8;
            this.btn_power_on.Text = "On";
            this.btn_power_on.UseVisualStyleBackColor = false;
            this.btn_power_on.Click += new System.EventHandler(this.btn_power_on_Click);
            // 
            // btn_power_off
            // 
            this.btn_power_off.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btn_power_off.Location = new System.Drawing.Point(127, 93);
            this.btn_power_off.Name = "btn_power_off";
            this.btn_power_off.Size = new System.Drawing.Size(100, 30);
            this.btn_power_off.TabIndex = 9;
            this.btn_power_off.Text = "Off";
            this.btn_power_off.UseVisualStyleBackColor = false;
            this.btn_power_off.Click += new System.EventHandler(this.btn_power_off_Click);
            // 
            // btn_remote_lock
            // 
            this.btn_remote_lock.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btn_remote_lock.Location = new System.Drawing.Point(13, 21);
            this.btn_remote_lock.Name = "btn_remote_lock";
            this.btn_remote_lock.Size = new System.Drawing.Size(100, 30);
            this.btn_remote_lock.TabIndex = 10;
            this.btn_remote_lock.Text = "Remote Lock";
            this.btn_remote_lock.UseVisualStyleBackColor = false;
            this.btn_remote_lock.Click += new System.EventHandler(this.btn_remote_lock_Click);
            // 
            // btn_remote_unlock
            // 
            this.btn_remote_unlock.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.btn_remote_unlock.Location = new System.Drawing.Point(119, 21);
            this.btn_remote_unlock.Name = "btn_remote_unlock";
            this.btn_remote_unlock.Size = new System.Drawing.Size(100, 30);
            this.btn_remote_unlock.TabIndex = 11;
            this.btn_remote_unlock.Text = "Remote Unlock";
            this.btn_remote_unlock.UseVisualStyleBackColor = false;
            this.btn_remote_unlock.Click += new System.EventHandler(this.btn_remote_unlock_Click);
            // 
            // btn_locate
            // 
            this.btn_locate.Location = new System.Drawing.Point(13, 57);
            this.btn_locate.Name = "btn_locate";
            this.btn_locate.Size = new System.Drawing.Size(100, 30);
            this.btn_locate.TabIndex = 12;
            this.btn_locate.Text = "Locate";
            this.btn_locate.UseVisualStyleBackColor = true;
            this.btn_locate.Click += new System.EventHandler(this.btn_locate_Click);
            // 
            // btn_forward
            // 
            this.btn_forward.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.btn_forward.Location = new System.Drawing.Point(13, 72);
            this.btn_forward.Name = "btn_forward";
            this.btn_forward.Size = new System.Drawing.Size(100, 30);
            this.btn_forward.TabIndex = 13;
            this.btn_forward.Text = "Forward";
            this.btn_forward.UseVisualStyleBackColor = false;
            this.btn_forward.Click += new System.EventHandler(this.btn_forward_Click);
            // 
            // btn_reverse
            // 
            this.btn_reverse.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btn_reverse.Location = new System.Drawing.Point(119, 72);
            this.btn_reverse.Name = "btn_reverse";
            this.btn_reverse.Size = new System.Drawing.Size(100, 30);
            this.btn_reverse.TabIndex = 14;
            this.btn_reverse.Text = "Reverse";
            this.btn_reverse.UseVisualStyleBackColor = false;
            this.btn_reverse.Click += new System.EventHandler(this.btn_reverse_Click);
            // 
            // btn_pan_left
            // 
            this.btn_pan_left.Location = new System.Drawing.Point(119, 55);
            this.btn_pan_left.Name = "btn_pan_left";
            this.btn_pan_left.Size = new System.Drawing.Size(100, 30);
            this.btn_pan_left.TabIndex = 15;
            this.btn_pan_left.Text = "← Pan Left";
            this.btn_pan_left.UseVisualStyleBackColor = true;
            this.btn_pan_left.Click += new System.EventHandler(this.btn_pan_left_Click);
            // 
            // btn_pan_right
            // 
            this.btn_pan_right.Location = new System.Drawing.Point(331, 55);
            this.btn_pan_right.Name = "btn_pan_right";
            this.btn_pan_right.Size = new System.Drawing.Size(100, 30);
            this.btn_pan_right.TabIndex = 16;
            this.btn_pan_right.Text = "Pan Right →";
            this.btn_pan_right.UseVisualStyleBackColor = true;
            this.btn_pan_right.Click += new System.EventHandler(this.btn_pan_right_Click);
            // 
            // btn_pan_up
            // 
            this.btn_pan_up.Location = new System.Drawing.Point(225, 19);
            this.btn_pan_up.Name = "btn_pan_up";
            this.btn_pan_up.Size = new System.Drawing.Size(100, 30);
            this.btn_pan_up.TabIndex = 17;
            this.btn_pan_up.Text = "Pan Up ↑";
            this.btn_pan_up.UseVisualStyleBackColor = true;
            this.btn_pan_up.Click += new System.EventHandler(this.btn_pan_up_Click);
            // 
            // btn_pan_down
            // 
            this.btn_pan_down.Location = new System.Drawing.Point(225, 91);
            this.btn_pan_down.Name = "btn_pan_down";
            this.btn_pan_down.Size = new System.Drawing.Size(100, 30);
            this.btn_pan_down.TabIndex = 18;
            this.btn_pan_down.Text = "Pan Down ↓";
            this.btn_pan_down.UseVisualStyleBackColor = true;
            this.btn_pan_down.Click += new System.EventHandler(this.btn_pan_down_Click);
            // 
            // btn_stop
            // 
            this.btn_stop.Location = new System.Drawing.Point(13, 108);
            this.btn_stop.Name = "btn_stop";
            this.btn_stop.Size = new System.Drawing.Size(100, 30);
            this.btn_stop.TabIndex = 19;
            this.btn_stop.Text = "Stop";
            this.btn_stop.UseVisualStyleBackColor = true;
            this.btn_stop.Click += new System.EventHandler(this.btn_stop_Click);
            // 
            // bnt_lighting_mode_1
            // 
            this.bnt_lighting_mode_1.Location = new System.Drawing.Point(13, 21);
            this.bnt_lighting_mode_1.Name = "bnt_lighting_mode_1";
            this.bnt_lighting_mode_1.Size = new System.Drawing.Size(100, 30);
            this.bnt_lighting_mode_1.TabIndex = 20;
            this.bnt_lighting_mode_1.Text = "Mode 1";
            this.bnt_lighting_mode_1.UseVisualStyleBackColor = true;
            this.bnt_lighting_mode_1.Click += new System.EventHandler(this.bnt_lighting_mode_1_Click);
            // 
            // btn_lighting_mode_2
            // 
            this.btn_lighting_mode_2.Location = new System.Drawing.Point(119, 21);
            this.btn_lighting_mode_2.Name = "btn_lighting_mode_2";
            this.btn_lighting_mode_2.Size = new System.Drawing.Size(100, 30);
            this.btn_lighting_mode_2.TabIndex = 21;
            this.btn_lighting_mode_2.Text = "Mode 2";
            this.btn_lighting_mode_2.UseVisualStyleBackColor = true;
            this.btn_lighting_mode_2.Click += new System.EventHandler(this.btn_lighting_mode_2_Click);
            // 
            // btn_lighting_mode_3
            // 
            this.btn_lighting_mode_3.Location = new System.Drawing.Point(13, 57);
            this.btn_lighting_mode_3.Name = "btn_lighting_mode_3";
            this.btn_lighting_mode_3.Size = new System.Drawing.Size(100, 30);
            this.btn_lighting_mode_3.TabIndex = 22;
            this.btn_lighting_mode_3.Text = "Mode 3";
            this.btn_lighting_mode_3.UseVisualStyleBackColor = true;
            this.btn_lighting_mode_3.Click += new System.EventHandler(this.btn_lighting_mode_3_Click);
            // 
            // btn_lighting_mode_4
            // 
            this.btn_lighting_mode_4.Location = new System.Drawing.Point(119, 57);
            this.btn_lighting_mode_4.Name = "btn_lighting_mode_4";
            this.btn_lighting_mode_4.Size = new System.Drawing.Size(100, 30);
            this.btn_lighting_mode_4.TabIndex = 23;
            this.btn_lighting_mode_4.Text = "Mode 4";
            this.btn_lighting_mode_4.UseVisualStyleBackColor = true;
            this.btn_lighting_mode_4.Click += new System.EventHandler(this.btn_lighting_mode_4_Click);
            // 
            // btn_lighting_mode_5
            // 
            this.btn_lighting_mode_5.Location = new System.Drawing.Point(13, 93);
            this.btn_lighting_mode_5.Name = "btn_lighting_mode_5";
            this.btn_lighting_mode_5.Size = new System.Drawing.Size(100, 30);
            this.btn_lighting_mode_5.TabIndex = 24;
            this.btn_lighting_mode_5.Text = "Mode 5";
            this.btn_lighting_mode_5.UseVisualStyleBackColor = true;
            this.btn_lighting_mode_5.Click += new System.EventHandler(this.btn_lighting_mode_5_Click);
            // 
            // btn_lighting_activate
            // 
            this.btn_lighting_activate.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.btn_lighting_activate.Location = new System.Drawing.Point(13, 129);
            this.btn_lighting_activate.Name = "btn_lighting_activate";
            this.btn_lighting_activate.Size = new System.Drawing.Size(100, 30);
            this.btn_lighting_activate.TabIndex = 25;
            this.btn_lighting_activate.Text = "Activate";
            this.btn_lighting_activate.UseVisualStyleBackColor = false;
            this.btn_lighting_activate.Click += new System.EventHandler(this.btn_lighting_activate_Click);
            // 
            // btn_lighting_deactivate
            // 
            this.btn_lighting_deactivate.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.btn_lighting_deactivate.Location = new System.Drawing.Point(119, 129);
            this.btn_lighting_deactivate.Name = "btn_lighting_deactivate";
            this.btn_lighting_deactivate.Size = new System.Drawing.Size(100, 30);
            this.btn_lighting_deactivate.TabIndex = 26;
            this.btn_lighting_deactivate.Text = "Deactivate";
            this.btn_lighting_deactivate.UseVisualStyleBackColor = false;
            this.btn_lighting_deactivate.Click += new System.EventHandler(this.btn_lighting_deactivate_Click);
            // 
            // btn_lighting_mode_6
            // 
            this.btn_lighting_mode_6.Location = new System.Drawing.Point(119, 93);
            this.btn_lighting_mode_6.Name = "btn_lighting_mode_6";
            this.btn_lighting_mode_6.Size = new System.Drawing.Size(100, 30);
            this.btn_lighting_mode_6.TabIndex = 27;
            this.btn_lighting_mode_6.Text = "Mode 6";
            this.btn_lighting_mode_6.UseVisualStyleBackColor = true;
            this.btn_lighting_mode_6.Click += new System.EventHandler(this.btn_lighting_mode_6_Click);
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(13, 21);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(206, 45);
            this.trackBar1.TabIndex = 28;
            // 
            // groupBox1
            // 
            this.groupBox1.AutoSize = true;
            this.groupBox1.Controls.Add(this.btn_speed_1);
            this.groupBox1.Controls.Add(this.btn_speed_4);
            this.groupBox1.Controls.Add(this.btn_speed_2);
            this.groupBox1.Controls.Add(this.btn_speed_3);
            this.groupBox1.Controls.Add(this.btn_indicate_left);
            this.groupBox1.Controls.Add(this.btn_indicate_right);
            this.groupBox1.Controls.Add(this.btn_headlights);
            this.groupBox1.Controls.Add(this.btn_horn);
            this.groupBox1.Controls.Add(this.btn_power_on);
            this.groupBox1.Controls.Add(this.btn_power_off);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox1.Size = new System.Drawing.Size(470, 139);
            this.groupBox1.TabIndex = 29;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Main Control";
            // 
            // groupBox2
            // 
            this.groupBox2.AutoSize = true;
            this.groupBox2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox2.Controls.Add(this.btn_remote_lock);
            this.groupBox2.Controls.Add(this.btn_remote_unlock);
            this.groupBox2.Controls.Add(this.btn_locate);
            this.groupBox2.Location = new System.Drawing.Point(12, 157);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox2.Size = new System.Drawing.Size(232, 103);
            this.groupBox2.TabIndex = 30;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "GPS Control";
            // 
            // groupBox3
            // 
            this.groupBox3.AutoSize = true;
            this.groupBox3.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox3.Controls.Add(this.btn_forward);
            this.groupBox3.Controls.Add(this.btn_reverse);
            this.groupBox3.Controls.Add(this.btn_stop);
            this.groupBox3.Controls.Add(this.trackBar1);
            this.groupBox3.Location = new System.Drawing.Point(12, 269);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox3.Size = new System.Drawing.Size(232, 154);
            this.groupBox3.TabIndex = 31;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Throttle Control";
            // 
            // groupBox4
            // 
            this.groupBox4.AutoSize = true;
            this.groupBox4.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox4.Controls.Add(this.bnt_lighting_mode_1);
            this.groupBox4.Controls.Add(this.btn_lighting_mode_2);
            this.groupBox4.Controls.Add(this.btn_lighting_mode_3);
            this.groupBox4.Controls.Add(this.btn_lighting_mode_4);
            this.groupBox4.Controls.Add(this.btn_lighting_deactivate);
            this.groupBox4.Controls.Add(this.btn_lighting_mode_6);
            this.groupBox4.Controls.Add(this.btn_lighting_activate);
            this.groupBox4.Controls.Add(this.btn_lighting_mode_5);
            this.groupBox4.Location = new System.Drawing.Point(250, 157);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox4.Size = new System.Drawing.Size(232, 175);
            this.groupBox4.TabIndex = 32;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Lighting Control";
            // 
            // groupBox5
            // 
            this.groupBox5.AutoSize = true;
            this.groupBox5.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox5.Controls.Add(this.btn_camera_raise);
            this.groupBox5.Controls.Add(this.btn_camera_lower);
            this.groupBox5.Controls.Add(this.groupBox6);
            this.groupBox5.Controls.Add(this.btn_pan_left);
            this.groupBox5.Controls.Add(this.btn_pan_up);
            this.groupBox5.Controls.Add(this.btn_pan_right);
            this.groupBox5.Controls.Add(this.btn_pan_down);
            this.groupBox5.Location = new System.Drawing.Point(12, 429);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox5.Size = new System.Drawing.Size(444, 137);
            this.groupBox5.TabIndex = 33;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Camera Control";
            // 
            // btn_camera_raise
            // 
            this.btn_camera_raise.Location = new System.Drawing.Point(13, 21);
            this.btn_camera_raise.Name = "btn_camera_raise";
            this.btn_camera_raise.Size = new System.Drawing.Size(100, 30);
            this.btn_camera_raise.TabIndex = 35;
            this.btn_camera_raise.Text = "Raise ↑";
            this.btn_camera_raise.UseVisualStyleBackColor = true;
            // 
            // btn_camera_lower
            // 
            this.btn_camera_lower.Location = new System.Drawing.Point(13, 91);
            this.btn_camera_lower.Name = "btn_camera_lower";
            this.btn_camera_lower.Size = new System.Drawing.Size(100, 30);
            this.btn_camera_lower.TabIndex = 34;
            this.btn_camera_lower.Text = "Lower ↓";
            this.btn_camera_lower.UseVisualStyleBackColor = true;
            // 
            // groupBox6
            // 
            this.groupBox6.AutoSize = true;
            this.groupBox6.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox6.Location = new System.Drawing.Point(-9, -25);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox6.Size = new System.Drawing.Size(20, 4);
            this.groupBox6.TabIndex = 32;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Throttle Controller";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(13, 21);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(206, 21);
            this.comboBox1.TabIndex = 34;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // btn_serial_connect
            // 
            this.btn_serial_connect.Location = new System.Drawing.Point(13, 48);
            this.btn_serial_connect.Name = "btn_serial_connect";
            this.btn_serial_connect.Size = new System.Drawing.Size(100, 30);
            this.btn_serial_connect.TabIndex = 33;
            this.btn_serial_connect.Text = "Connect";
            this.btn_serial_connect.UseVisualStyleBackColor = true;
            this.btn_serial_connect.Click += new System.EventHandler(this.btn_serial_connect_Click);
            // 
            // btn_serial_refresh
            // 
            this.btn_serial_refresh.Location = new System.Drawing.Point(13, 84);
            this.btn_serial_refresh.Name = "btn_serial_refresh";
            this.btn_serial_refresh.Size = new System.Drawing.Size(100, 30);
            this.btn_serial_refresh.TabIndex = 35;
            this.btn_serial_refresh.Text = "Refresh";
            this.btn_serial_refresh.UseVisualStyleBackColor = true;
            this.btn_serial_refresh.Click += new System.EventHandler(this.btn_serial_refresh_Click);
            // 
            // groupBox7
            // 
            this.groupBox7.AutoSize = true;
            this.groupBox7.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox7.Controls.Add(this.btn_serial_disconnect);
            this.groupBox7.Controls.Add(this.groupBox8);
            this.groupBox7.Controls.Add(this.btn_serial_refresh);
            this.groupBox7.Controls.Add(this.comboBox1);
            this.groupBox7.Controls.Add(this.btn_serial_connect);
            this.groupBox7.Location = new System.Drawing.Point(488, 12);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox7.Size = new System.Drawing.Size(232, 130);
            this.groupBox7.TabIndex = 36;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "Serial Port Settings";
            // 
            // groupBox8
            // 
            this.groupBox8.AutoSize = true;
            this.groupBox8.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.groupBox8.Location = new System.Drawing.Point(-9, -25);
            this.groupBox8.Name = "groupBox8";
            this.groupBox8.Padding = new System.Windows.Forms.Padding(10, 5, 10, 0);
            this.groupBox8.Size = new System.Drawing.Size(20, 4);
            this.groupBox8.TabIndex = 32;
            this.groupBox8.TabStop = false;
            this.groupBox8.Text = "Throttle Controller";
            // 
            // btn_serial_disconnect
            // 
            this.btn_serial_disconnect.Location = new System.Drawing.Point(119, 48);
            this.btn_serial_disconnect.Name = "btn_serial_disconnect";
            this.btn_serial_disconnect.Size = new System.Drawing.Size(100, 30);
            this.btn_serial_disconnect.TabIndex = 36;
            this.btn_serial_disconnect.Text = "Disconnect";
            this.btn_serial_disconnect.UseVisualStyleBackColor = true;
            this.btn_serial_disconnect.Click += new System.EventHandler(this.btn_serial_disconnect_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.ClientSize = new System.Drawing.Size(787, 603);
            this.Controls.Add(this.groupBox7);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.KeyPreview = true;
            this.Name = "Form1";
            this.Text = "Scooter Controller";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.groupBox7.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_speed_1;
        private System.Windows.Forms.Button btn_speed_2;
        private System.Windows.Forms.Button btn_speed_3;
        private System.Windows.Forms.Button btn_speed_4;
        private System.Windows.Forms.Button btn_indicate_left;
        private System.Windows.Forms.Button btn_indicate_right;
        private System.Windows.Forms.Button btn_headlights;
        private System.Windows.Forms.Button btn_horn;
        private System.Windows.Forms.Button btn_power_on;
        private System.Windows.Forms.Button btn_power_off;
        private System.Windows.Forms.Button btn_remote_lock;
        private System.Windows.Forms.Button btn_remote_unlock;
        private System.Windows.Forms.Button btn_locate;
        private System.Windows.Forms.Button btn_forward;
        private System.Windows.Forms.Button btn_reverse;
        private System.Windows.Forms.Button btn_pan_left;
        private System.Windows.Forms.Button btn_pan_right;
        private System.Windows.Forms.Button btn_pan_up;
        private System.Windows.Forms.Button btn_pan_down;
        private System.Windows.Forms.Button btn_stop;
        private System.Windows.Forms.Button bnt_lighting_mode_1;
        private System.Windows.Forms.Button btn_lighting_mode_2;
        private System.Windows.Forms.Button btn_lighting_mode_3;
        private System.Windows.Forms.Button btn_lighting_mode_4;
        private System.Windows.Forms.Button btn_lighting_mode_5;
        private System.Windows.Forms.Button btn_lighting_activate;
        private System.Windows.Forms.Button btn_lighting_deactivate;
        private System.Windows.Forms.Button btn_lighting_mode_6;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button btn_serial_connect;
        private System.Windows.Forms.Button btn_serial_refresh;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.GroupBox groupBox8;
        private System.Windows.Forms.Button btn_camera_raise;
        private System.Windows.Forms.Button btn_camera_lower;
        private System.Windows.Forms.Button btn_serial_disconnect;
    }
}

