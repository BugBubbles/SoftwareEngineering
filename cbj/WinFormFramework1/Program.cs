using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace WinFormFramework1 {
    public static class Program {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        public static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
        [DllImport("cbj1.dll",CallingConvention=CallingConvention.Cdecl,CharSet =CharSet.Ansi,EntryPoint ="cli_handler")]
        public static extern byte Execute(string cmdline); 

    }
}
