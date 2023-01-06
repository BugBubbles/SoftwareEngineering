namespace WinFormFramework1 {
    partial class Form1 {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if(disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.btnpreview = new System.Windows.Forms.Button();
            this.tbcmd = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.tbinput = new System.Windows.Forms.TextBox();
            this.btnexec = new System.Windows.Forms.Button();
            this.picresult = new System.Windows.Forms.PictureBox();
            this.btnclear = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picresult)).BeginInit();
            this.SuspendLayout();
            // 
            // btnpreview
            // 
            this.btnpreview.Location = new System.Drawing.Point(417, 213);
            this.btnpreview.Name = "btnpreview";
            this.btnpreview.Size = new System.Drawing.Size(75, 23);
            this.btnpreview.TabIndex = 5;
            this.btnpreview.Text = "预览oled图";
            this.btnpreview.UseVisualStyleBackColor = true;
            this.btnpreview.Click += new System.EventHandler(this.btnpreview_Click);
            // 
            // tbcmd
            // 
            this.tbcmd.Location = new System.Drawing.Point(12, 29);
            this.tbcmd.Multiline = true;
            this.tbcmd.Name = "tbcmd";
            this.tbcmd.ReadOnly = true;
            this.tbcmd.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbcmd.Size = new System.Drawing.Size(480, 149);
            this.tbcmd.TabIndex = 6;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(16, 13);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(67, 13);
            this.label8.TabIndex = 7;
            this.label8.Text = "绘图命令行";
            // 
            // tbinput
            // 
            this.tbinput.Location = new System.Drawing.Point(12, 184);
            this.tbinput.Name = "tbinput";
            this.tbinput.Size = new System.Drawing.Size(399, 20);
            this.tbinput.TabIndex = 8;
            // 
            // btnexec
            // 
            this.btnexec.Location = new System.Drawing.Point(417, 184);
            this.btnexec.Name = "btnexec";
            this.btnexec.Size = new System.Drawing.Size(75, 23);
            this.btnexec.TabIndex = 9;
            this.btnexec.Text = "执行命令";
            this.btnexec.UseVisualStyleBackColor = true;
            this.btnexec.Click += new System.EventHandler(this.btnexec_Click);
            // 
            // picresult
            // 
            this.picresult.Location = new System.Drawing.Point(283, 210);
            this.picresult.Name = "picresult";
            this.picresult.Size = new System.Drawing.Size(128, 64);
            this.picresult.TabIndex = 10;
            this.picresult.TabStop = false;
            // 
            // btnclear
            // 
            this.btnclear.Location = new System.Drawing.Point(417, 242);
            this.btnclear.Name = "btnclear";
            this.btnclear.Size = new System.Drawing.Size(75, 23);
            this.btnclear.TabIndex = 11;
            this.btnclear.Text = "清空命令";
            this.btnclear.UseVisualStyleBackColor = true;
            this.btnclear.Click += new System.EventHandler(this.btnclear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(499, 294);
            this.Controls.Add(this.btnclear);
            this.Controls.Add(this.picresult);
            this.Controls.Add(this.btnexec);
            this.Controls.Add(this.tbinput);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.tbcmd);
            this.Controls.Add(this.btnpreview);
            this.Name = "Form1";
            this.Text = "OLED图形界面辅助工具";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picresult)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnpreview;
        private System.Windows.Forms.TextBox tbcmd;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button btnexec;
        private System.Windows.Forms.PictureBox picresult;
        private System.Windows.Forms.Button btnclear;
        private System.Windows.Forms.TextBox tbinput;
    }
}

