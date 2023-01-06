using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using static WinFormFramework1.Program;
namespace WinFormFramework1 {

    public partial class Form1 : Form {
        Bitmap bmp = new Bitmap(256, 128);
        public Form1() {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e) {
            if(!File.Exists("cbj1.dll")) {
                MessageBox.Show("library not ready", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                this.Close();
            }

        }

        private void btnexec_Click(object sender, EventArgs e) {
            byte result = Execute(tbinput.Text);
            tbcmd.AppendText(tbinput.Text);
            tbcmd.AppendText("\r\n");
            switch(result) {
            case 1:
                tbcmd.AppendText("invalid command\r\n");
                break;
            case 2:
                tbcmd.AppendText("invalid parameter\r\n");
                break;
            case 3:
                tbcmd.AppendText("file system error\r\n");
                break;
            default:
                tbcmd.AppendText("success\r\n");
                break;
            }
        }

        private void btnclear_Click(object sender, EventArgs e) {
            tbcmd.Clear();
        }

        private void btnpreview_Click(object sender, EventArgs e) {
            try {
                byte[] data = new byte[1024];
                using(FileStream fs = File.Open("oled_tmp.bin", FileMode.Open, FileAccess.Read, FileShare.ReadWrite)) {
                    fs.Read(data, 0, 1024);
                }
                for(int i = 0; i < 8; i++) {
                    for(int j = 0; j < 128; j++) {
                        for(int k = 0; k < 8; k++) {
                            if((data[i * 128 + j] & (1 << k)) != 0) {
                                bmp.SetPixel(j, i * 8 + k, Color.White);
                            }
                            else {
                                bmp.SetPixel(j, i * 8 + k, Color.Black);
                            }
                        }
                    }
                }
                picresult.Image = bmp;
            }
            catch(Exception ex) {
                MessageBox.Show("input file not ready", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
