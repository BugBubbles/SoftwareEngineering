namespace SoftwareProgramming {
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.btnexec = new System.Windows.Forms.Button();
            this.tbresult = new System.Windows.Forms.TextBox();
            this.tbinput = new System.Windows.Forms.TextBox();
            this.picresult = new System.Windows.Forms.PictureBox();
            this.btnclearcli = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picresult)).BeginInit();
            this.SuspendLayout();
            // 
            // btnexec
            // 
            this.btnexec.Location = new System.Drawing.Point(751, 368);
            this.btnexec.Name = "btnexec";
            this.btnexec.Size = new System.Drawing.Size(75, 23);
            this.btnexec.TabIndex = 0;
            this.btnexec.Text = "执行";
            this.btnexec.UseVisualStyleBackColor = true;
            this.btnexec.Click += new System.EventHandler(this.btnexec_Click);
            // 
            // tbresult
            // 
            this.tbresult.Location = new System.Drawing.Point(12, 12);
            this.tbresult.Multiline = true;
            this.tbresult.Name = "tbresult";
            this.tbresult.ReadOnly = true;
            this.tbresult.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbresult.Size = new System.Drawing.Size(652, 341);
            this.tbresult.TabIndex = 1;
            // 
            // tbinput
            // 
            this.tbinput.Location = new System.Drawing.Point(12, 368);
            this.tbinput.Name = "tbinput";
            this.tbinput.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbinput.Size = new System.Drawing.Size(652, 20);
            this.tbinput.TabIndex = 2;
            // 
            // picresult
            // 
            this.picresult.Location = new System.Drawing.Point(670, 12);
            this.picresult.Name = "picresult";
            this.picresult.Size = new System.Drawing.Size(253, 341);
            this.picresult.TabIndex = 3;
            this.picresult.TabStop = false;
            // 
            // btnclearcli
            // 
            this.btnclearcli.Location = new System.Drawing.Point(670, 368);
            this.btnclearcli.Name = "btnclearcli";
            this.btnclearcli.Size = new System.Drawing.Size(75, 23);
            this.btnclearcli.TabIndex = 4;
            this.btnclearcli.Text = "清空命令行";
            this.btnclearcli.UseVisualStyleBackColor = true;
            this.btnclearcli.Click += new System.EventHandler(this.btnclearcli_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(935, 410);
            this.Controls.Add(this.btnclearcli);
            this.Controls.Add(this.picresult);
            this.Controls.Add(this.tbinput);
            this.Controls.Add(this.tbresult);
            this.Controls.Add(this.btnexec);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Test";
            ((System.ComponentModel.ISupportInitialize)(this.picresult)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnexec;
        private System.Windows.Forms.TextBox tbresult;
        private System.Windows.Forms.TextBox tbinput;
        private System.Windows.Forms.PictureBox picresult;
        private System.Windows.Forms.Button btnclearcli;
    }
}

