using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using Swifter.Json;
namespace SoftwareProgramming {
    public class TestClass {
        public string t1 { get; set; }
        public string t2 { get; set; }
    }
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
        public static string GetParams(string text) {
            try {
                string[] s0 = text.Split(',');
                switch(s0.Length) {
                    case 1:
                        return JsonFormatter.SerializeObject<TestClass>(new TestClass { t1 = s0[0], t2 = "cbjnb" });
                    //break;
                    case 2:
                        return JsonFormatter.SerializeObject<TestClass>(new TestClass { t1 = s0[0], t2 = s0[1] });
                        //break;
                    default:
                        return JsonFormatter.SerializeObject<TestClass>(new TestClass { t1 = "cbjlaji", t2 = "cbjnb" });
                        //break;
                }
                
                //return null;
            }
            catch(Exception ex) {
                MessageBox.Show(ex.Message, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return null;
            }
        }
        [DllImport("CTestLib.dll", EntryPoint = "test", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public static extern int Test();
    }
}
