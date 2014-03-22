namespace MapEditor
{
    partial class AddTileForm
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
            this.lblInstructions = new System.Windows.Forms.Label();
            this.numIndex = new System.Windows.Forms.NumericUpDown();
            this.comboType = new System.Windows.Forms.ComboBox();
            this.lblPath = new System.Windows.Forms.Label();
            this.lblIndex = new System.Windows.Forms.Label();
            this.lblType = new System.Windows.Forms.Label();
            this.btnPath = new System.Windows.Forms.Button();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.imageFileOpen = new System.Windows.Forms.OpenFileDialog();
            this.txtPath2 = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.numIndex)).BeginInit();
            this.SuspendLayout();
            // 
            // lblInstructions
            // 
            this.lblInstructions.AutoSize = true;
            this.lblInstructions.Location = new System.Drawing.Point(13, 13);
            this.lblInstructions.Name = "lblInstructions";
            this.lblInstructions.Size = new System.Drawing.Size(238, 13);
            this.lblInstructions.TabIndex = 0;
            this.lblInstructions.Text = "To add a tile to the definitions file, please specify:";
            // 
            // numIndex
            // 
            this.numIndex.Location = new System.Drawing.Point(77, 61);
            this.numIndex.Name = "numIndex";
            this.numIndex.Size = new System.Drawing.Size(138, 20);
            this.numIndex.TabIndex = 1;
            this.numIndex.ValueChanged += new System.EventHandler(this.numIndex_ValueChanged);
            // 
            // comboType
            // 
            this.comboType.FormattingEnabled = true;
            this.comboType.Location = new System.Drawing.Point(77, 88);
            this.comboType.Name = "comboType";
            this.comboType.Size = new System.Drawing.Size(138, 21);
            this.comboType.TabIndex = 2;
            this.comboType.SelectedIndexChanged += new System.EventHandler(this.comboType_SelectedIndexChanged);
            // 
            // lblPath
            // 
            this.lblPath.AutoSize = true;
            this.lblPath.Location = new System.Drawing.Point(13, 38);
            this.lblPath.Name = "lblPath";
            this.lblPath.Size = new System.Drawing.Size(64, 13);
            this.lblPath.TabIndex = 4;
            this.lblPath.Text = "Image Path:";
            // 
            // lblIndex
            // 
            this.lblIndex.AutoSize = true;
            this.lblIndex.Location = new System.Drawing.Point(13, 63);
            this.lblIndex.Name = "lblIndex";
            this.lblIndex.Size = new System.Drawing.Size(56, 13);
            this.lblIndex.TabIndex = 5;
            this.lblIndex.Text = "Tile Index:";
            // 
            // lblType
            // 
            this.lblType.AutoSize = true;
            this.lblType.Location = new System.Drawing.Point(15, 91);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(54, 13);
            this.lblType.TabIndex = 6;
            this.lblType.Text = "Tile Type:";
            // 
            // btnPath
            // 
            this.btnPath.Location = new System.Drawing.Point(221, 33);
            this.btnPath.Name = "btnPath";
            this.btnPath.Size = new System.Drawing.Size(24, 23);
            this.btnPath.TabIndex = 7;
            this.btnPath.Text = "...";
            this.btnPath.UseVisualStyleBackColor = true;
            this.btnPath.Click += new System.EventHandler(this.btnPath_Click);
            // 
            // btnOK
            // 
            this.btnOK.Location = new System.Drawing.Point(59, 115);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 8;
            this.btnOK.Text = "OK";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(140, 115);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 9;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // imageFileOpen
            // 
            this.imageFileOpen.Filter = "BMP Files|*.bmp";
            // 
            // txtPath2
            // 
            this.txtPath2.Location = new System.Drawing.Point(77, 35);
            this.txtPath2.Name = "txtPath2";
            this.txtPath2.Size = new System.Drawing.Size(138, 20);
            this.txtPath2.TabIndex = 10;
            // 
            // AddTileForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(265, 150);
            this.Controls.Add(this.txtPath2);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.btnPath);
            this.Controls.Add(this.lblType);
            this.Controls.Add(this.lblIndex);
            this.Controls.Add(this.lblPath);
            this.Controls.Add(this.comboType);
            this.Controls.Add(this.numIndex);
            this.Controls.Add(this.lblInstructions);
            this.Name = "AddTileForm";
            this.Text = "Add Tile";
            ((System.ComponentModel.ISupportInitialize)(this.numIndex)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblInstructions;
        private System.Windows.Forms.NumericUpDown numIndex;
        private System.Windows.Forms.ComboBox comboType;
        private System.Windows.Forms.Label lblPath;
        private System.Windows.Forms.Label lblIndex;
        private System.Windows.Forms.Label lblType;
        private System.Windows.Forms.Button btnPath;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.OpenFileDialog imageFileOpen;
        private System.Windows.Forms.TextBox txtPath2;
    }
}