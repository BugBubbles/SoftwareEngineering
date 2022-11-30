using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static SoftwareProgramming.Program;
namespace SoftwareProgramming {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        private void btnexec_Click(object sender, EventArgs e) {
            tbresult.AppendText(tbinput.Text);
            tbresult.AppendText("\r\n");
            //Test();
            tbresult.AppendText(GetParams(tbinput.Text));
            tbresult.AppendText("\r\n");
        }

        private void btnclearcli_Click(object sender, EventArgs e) {
            tbresult.Clear();
        }
    }
}
