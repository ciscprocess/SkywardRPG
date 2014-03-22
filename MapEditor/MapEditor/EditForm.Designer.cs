namespace MapEditor
{
    partial class EditForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(EditForm));
            this.graphicsPanel = new System.Windows.Forms.Panel();
            this.lblCur = new System.Windows.Forms.Label();
            this.mapList = new System.Windows.Forms.ComboBox();
            this.boxEdit = new System.Windows.Forms.GroupBox();
            this.btnRemoveMap = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.checkSyncIndices = new System.Windows.Forms.CheckBox();
            this.btnRemoveTile = new System.Windows.Forms.Button();
            this.btnAddTile = new System.Windows.Forms.Button();
            this.btnSquare = new System.Windows.Forms.Button();
            this.btnNoTool = new System.Windows.Forms.Button();
            this.btnSelRotate = new System.Windows.Forms.Button();
            this.boxTilePreview = new System.Windows.Forms.GroupBox();
            this.imgTilePrev = new System.Windows.Forms.PictureBox();
            this.lblListTile = new System.Windows.Forms.Label();
            this.listTile = new System.Windows.Forms.ListBox();
            this.btnPenDraw = new System.Windows.Forms.Button();
            this.lblPreview = new System.Windows.Forms.Label();
            this.panelPreview = new System.Windows.Forms.Panel();
            this.lblMapSelect = new System.Windows.Forms.Label();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAllToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mapGridWorldToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteMapToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addMapToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dlgOpenNewShell = new System.Windows.Forms.OpenFileDialog();
            this.grpEdit = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btnZoomOut = new System.Windows.Forms.Button();
            this.btnZoomIn = new System.Windows.Forms.Button();
            this.boxEdit.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.boxTilePreview.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.imgTilePrev)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.grpEdit.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // graphicsPanel
            // 
            this.graphicsPanel.AutoScroll = true;
            this.graphicsPanel.Location = new System.Drawing.Point(3, 3);
            this.graphicsPanel.Name = "graphicsPanel";
            this.graphicsPanel.Size = new System.Drawing.Size(638, 480);
            this.graphicsPanel.TabIndex = 0;
            // 
            // lblCur
            // 
            this.lblCur.AutoSize = true;
            this.lblCur.Location = new System.Drawing.Point(9, 535);
            this.lblCur.Name = "lblCur";
            this.lblCur.Size = new System.Drawing.Size(0, 13);
            this.lblCur.TabIndex = 3;
            // 
            // mapList
            // 
            this.mapList.FormattingEnabled = true;
            this.mapList.Location = new System.Drawing.Point(77, 19);
            this.mapList.Name = "mapList";
            this.mapList.Size = new System.Drawing.Size(229, 21);
            this.mapList.TabIndex = 4;
            // 
            // boxEdit
            // 
            this.boxEdit.Controls.Add(this.btnRemoveMap);
            this.boxEdit.Controls.Add(this.btnAdd);
            this.boxEdit.Controls.Add(this.btnSave);
            this.boxEdit.Controls.Add(this.button2);
            this.boxEdit.Controls.Add(this.groupBox1);
            this.boxEdit.Controls.Add(this.lblPreview);
            this.boxEdit.Controls.Add(this.panelPreview);
            this.boxEdit.Controls.Add(this.lblMapSelect);
            this.boxEdit.Controls.Add(this.mapList);
            this.boxEdit.Location = new System.Drawing.Point(679, 39);
            this.boxEdit.Name = "boxEdit";
            this.boxEdit.Size = new System.Drawing.Size(317, 516);
            this.boxEdit.TabIndex = 5;
            this.boxEdit.TabStop = false;
            this.boxEdit.Text = "Map";
            this.boxEdit.Enter += new System.EventHandler(this.boxEdit_Enter);
            // 
            // btnRemoveMap
            // 
            this.btnRemoveMap.Location = new System.Drawing.Point(90, 487);
            this.btnRemoveMap.Name = "btnRemoveMap";
            this.btnRemoveMap.Size = new System.Drawing.Size(124, 23);
            this.btnRemoveMap.TabIndex = 12;
            this.btnRemoveMap.Text = "Remove Map";
            this.btnRemoveMap.UseVisualStyleBackColor = true;
            this.btnRemoveMap.Click += new System.EventHandler(this.btnRemoveMap_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(153, 461);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(105, 23);
            this.btnAdd.TabIndex = 11;
            this.btnAdd.Text = "Add Map";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(42, 461);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(105, 23);
            this.btnSave.TabIndex = 10;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(126, 270);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 9;
            this.button2.Text = "Open Map";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.checkSyncIndices);
            this.groupBox1.Controls.Add(this.btnRemoveTile);
            this.groupBox1.Controls.Add(this.btnAddTile);
            this.groupBox1.Controls.Add(this.btnSquare);
            this.groupBox1.Controls.Add(this.btnNoTool);
            this.groupBox1.Controls.Add(this.btnSelRotate);
            this.groupBox1.Controls.Add(this.boxTilePreview);
            this.groupBox1.Controls.Add(this.lblListTile);
            this.groupBox1.Controls.Add(this.listTile);
            this.groupBox1.Controls.Add(this.btnPenDraw);
            this.groupBox1.Location = new System.Drawing.Point(6, 299);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(296, 156);
            this.groupBox1.TabIndex = 8;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Tools";
            // 
            // checkSyncIndices
            // 
            this.checkSyncIndices.AutoSize = true;
            this.checkSyncIndices.Location = new System.Drawing.Point(203, 23);
            this.checkSyncIndices.Name = "checkSyncIndices";
            this.checkSyncIndices.Size = new System.Drawing.Size(87, 17);
            this.checkSyncIndices.TabIndex = 10;
            this.checkSyncIndices.Text = "Sync Indices";
            this.checkSyncIndices.UseVisualStyleBackColor = true;
            // 
            // btnRemoveTile
            // 
            this.btnRemoveTile.Location = new System.Drawing.Point(251, 100);
            this.btnRemoveTile.Name = "btnRemoveTile";
            this.btnRemoveTile.Size = new System.Drawing.Size(20, 20);
            this.btnRemoveTile.TabIndex = 9;
            this.btnRemoveTile.Text = "-";
            this.btnRemoveTile.UseVisualStyleBackColor = true;
            this.btnRemoveTile.Click += new System.EventHandler(this.btnRemoveTile_Click);
            // 
            // btnAddTile
            // 
            this.btnAddTile.Location = new System.Drawing.Point(251, 48);
            this.btnAddTile.Name = "btnAddTile";
            this.btnAddTile.Size = new System.Drawing.Size(20, 20);
            this.btnAddTile.TabIndex = 8;
            this.btnAddTile.Text = "+";
            this.btnAddTile.UseVisualStyleBackColor = true;
            this.btnAddTile.Click += new System.EventHandler(this.btnAddTile_Click);
            // 
            // btnSquare
            // 
            this.btnSquare.Image = ((System.Drawing.Image)(resources.GetObject("btnSquare.Image")));
            this.btnSquare.Location = new System.Drawing.Point(6, 74);
            this.btnSquare.Name = "btnSquare";
            this.btnSquare.Size = new System.Drawing.Size(24, 22);
            this.btnSquare.TabIndex = 7;
            this.btnSquare.UseVisualStyleBackColor = true;
            this.btnSquare.Click += new System.EventHandler(this.btnSquare_Click);
            // 
            // btnNoTool
            // 
            this.btnNoTool.Image = ((System.Drawing.Image)(resources.GetObject("btnNoTool.Image")));
            this.btnNoTool.Location = new System.Drawing.Point(6, 100);
            this.btnNoTool.Name = "btnNoTool";
            this.btnNoTool.Size = new System.Drawing.Size(24, 23);
            this.btnNoTool.TabIndex = 6;
            this.btnNoTool.UseVisualStyleBackColor = true;
            this.btnNoTool.Click += new System.EventHandler(this.btnNoTool_Click);
            // 
            // btnSelRotate
            // 
            this.btnSelRotate.Image = ((System.Drawing.Image)(resources.GetObject("btnSelRotate.Image")));
            this.btnSelRotate.Location = new System.Drawing.Point(6, 48);
            this.btnSelRotate.Name = "btnSelRotate";
            this.btnSelRotate.Size = new System.Drawing.Size(24, 23);
            this.btnSelRotate.TabIndex = 5;
            this.btnSelRotate.UseVisualStyleBackColor = true;
            this.btnSelRotate.Click += new System.EventHandler(this.btnSelRotate_Click);
            // 
            // boxTilePreview
            // 
            this.boxTilePreview.Controls.Add(this.imgTilePrev);
            this.boxTilePreview.Location = new System.Drawing.Point(247, 65);
            this.boxTilePreview.Name = "boxTilePreview";
            this.boxTilePreview.Size = new System.Drawing.Size(28, 31);
            this.boxTilePreview.TabIndex = 4;
            this.boxTilePreview.TabStop = false;
            // 
            // imgTilePrev
            // 
            this.imgTilePrev.Location = new System.Drawing.Point(4, 9);
            this.imgTilePrev.Name = "imgTilePrev";
            this.imgTilePrev.Size = new System.Drawing.Size(20, 20);
            this.imgTilePrev.TabIndex = 3;
            this.imgTilePrev.TabStop = false;
            // 
            // lblListTile
            // 
            this.lblListTile.AutoSize = true;
            this.lblListTile.Location = new System.Drawing.Point(131, 24);
            this.lblListTile.Name = "lblListTile";
            this.lblListTile.Size = new System.Drawing.Size(32, 13);
            this.lblListTile.TabIndex = 2;
            this.lblListTile.Text = "Tiles:";
            // 
            // listTile
            // 
            this.listTile.FormattingEnabled = true;
            this.listTile.Location = new System.Drawing.Point(36, 40);
            this.listTile.Name = "listTile";
            this.listTile.Size = new System.Drawing.Size(205, 95);
            this.listTile.TabIndex = 1;
            // 
            // btnPenDraw
            // 
            this.btnPenDraw.Image = ((System.Drawing.Image)(resources.GetObject("btnPenDraw.Image")));
            this.btnPenDraw.Location = new System.Drawing.Point(6, 19);
            this.btnPenDraw.Name = "btnPenDraw";
            this.btnPenDraw.Size = new System.Drawing.Size(24, 23);
            this.btnPenDraw.TabIndex = 0;
            this.btnPenDraw.UseVisualStyleBackColor = true;
            this.btnPenDraw.Click += new System.EventHandler(this.btnPenDraw_Click);
            // 
            // lblPreview
            // 
            this.lblPreview.AutoSize = true;
            this.lblPreview.Location = new System.Drawing.Point(137, 53);
            this.lblPreview.Name = "lblPreview";
            this.lblPreview.Size = new System.Drawing.Size(48, 13);
            this.lblPreview.TabIndex = 7;
            this.lblPreview.Text = "Preview:";
            // 
            // panelPreview
            // 
            this.panelPreview.Location = new System.Drawing.Point(37, 69);
            this.panelPreview.Name = "panelPreview";
            this.panelPreview.Size = new System.Drawing.Size(256, 192);
            this.panelPreview.TabIndex = 6;
            // 
            // lblMapSelect
            // 
            this.lblMapSelect.AutoSize = true;
            this.lblMapSelect.Location = new System.Drawing.Point(7, 26);
            this.lblMapSelect.Name = "lblMapSelect";
            this.lblMapSelect.Size = new System.Drawing.Size(64, 13);
            this.lblMapSelect.TabIndex = 5;
            this.lblMapSelect.Text = "Select Map:";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1008, 24);
            this.menuStrip1.TabIndex = 6;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveAllToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // saveAllToolStripMenuItem
            // 
            this.saveAllToolStripMenuItem.Name = "saveAllToolStripMenuItem";
            this.saveAllToolStripMenuItem.Size = new System.Drawing.Size(115, 22);
            this.saveAllToolStripMenuItem.Text = "Save All";
            this.saveAllToolStripMenuItem.Click += new System.EventHandler(this.saveAllToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mapGridWorldToolStripMenuItem,
            this.deleteMapToolStripMenuItem,
            this.addMapToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(48, 20);
            this.toolsToolStripMenuItem.Text = "Tools";
            this.toolsToolStripMenuItem.Click += new System.EventHandler(this.toolsToolStripMenuItem_Click);
            // 
            // mapGridWorldToolStripMenuItem
            // 
            this.mapGridWorldToolStripMenuItem.Name = "mapGridWorldToolStripMenuItem";
            this.mapGridWorldToolStripMenuItem.Size = new System.Drawing.Size(166, 22);
            this.mapGridWorldToolStripMenuItem.Text = "Map Grid (World)";
            this.mapGridWorldToolStripMenuItem.Click += new System.EventHandler(this.mapGridWorldToolStripMenuItem_Click);
            // 
            // deleteMapToolStripMenuItem
            // 
            this.deleteMapToolStripMenuItem.Name = "deleteMapToolStripMenuItem";
            this.deleteMapToolStripMenuItem.Size = new System.Drawing.Size(166, 22);
            this.deleteMapToolStripMenuItem.Text = "Delete Map";
            this.deleteMapToolStripMenuItem.Click += new System.EventHandler(this.deleteMapToolStripMenuItem_Click);
            // 
            // addMapToolStripMenuItem
            // 
            this.addMapToolStripMenuItem.Name = "addMapToolStripMenuItem";
            this.addMapToolStripMenuItem.Size = new System.Drawing.Size(166, 22);
            this.addMapToolStripMenuItem.Text = "Add Map";
            this.addMapToolStripMenuItem.Click += new System.EventHandler(this.addMapToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // dlgOpenNewShell
            // 
            this.dlgOpenNewShell.FileOk += new System.ComponentModel.CancelEventHandler(this.dlgOpenNewShell_FileOk);
            // 
            // grpEdit
            // 
            this.grpEdit.Controls.Add(this.panel1);
            this.grpEdit.Location = new System.Drawing.Point(12, 42);
            this.grpEdit.Name = "grpEdit";
            this.grpEdit.Size = new System.Drawing.Size(661, 513);
            this.grpEdit.TabIndex = 7;
            this.grpEdit.TabStop = false;
            this.grpEdit.Text = "Edit";
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.Controls.Add(this.graphicsPanel);
            this.panel1.Location = new System.Drawing.Point(3, 16);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(646, 487);
            this.panel1.TabIndex = 0;
            // 
            // btnZoomOut
            // 
            this.btnZoomOut.Location = new System.Drawing.Point(18, 552);
            this.btnZoomOut.Name = "btnZoomOut";
            this.btnZoomOut.Size = new System.Drawing.Size(19, 20);
            this.btnZoomOut.TabIndex = 9;
            this.btnZoomOut.Text = "-";
            this.btnZoomOut.UseVisualStyleBackColor = true;
            this.btnZoomOut.Click += new System.EventHandler(this.btnZoomOut_Click);
            // 
            // btnZoomIn
            // 
            this.btnZoomIn.Location = new System.Drawing.Point(654, 552);
            this.btnZoomIn.Name = "btnZoomIn";
            this.btnZoomIn.Size = new System.Drawing.Size(19, 20);
            this.btnZoomIn.TabIndex = 10;
            this.btnZoomIn.Text = "+";
            this.btnZoomIn.UseVisualStyleBackColor = true;
            this.btnZoomIn.Click += new System.EventHandler(this.btnZoomIn_Click);
            // 
            // EditForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.ClientSize = new System.Drawing.Size(1008, 573);
            this.Controls.Add(this.btnZoomIn);
            this.Controls.Add(this.btnZoomOut);
            this.Controls.Add(this.grpEdit);
            this.Controls.Add(this.boxEdit);
            this.Controls.Add(this.lblCur);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "EditForm";
            this.Text = "LANGEdit";
            this.Load += new System.EventHandler(this.EditForm_Load);
            this.boxEdit.ResumeLayout(false);
            this.boxEdit.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.boxTilePreview.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.imgTilePrev)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.grpEdit.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel graphicsPanel;
        private System.Windows.Forms.Label lblCur;
        private System.Windows.Forms.ComboBox mapList;
        private System.Windows.Forms.GroupBox boxEdit;
        private System.Windows.Forms.Label lblMapSelect;
        private System.Windows.Forms.Label lblPreview;
        private System.Windows.Forms.Panel panelPreview;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnPenDraw;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.ListBox listTile;
        private System.Windows.Forms.Label lblListTile;
        private System.Windows.Forms.PictureBox imgTilePrev;
        private System.Windows.Forms.GroupBox boxTilePreview;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnSelRotate;
        private System.Windows.Forms.Button btnNoTool;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAllToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mapGridWorldToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteMapToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addMapToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.Button btnSquare;
        private System.Windows.Forms.Button btnRemoveTile;
        private System.Windows.Forms.Button btnAddTile;
        private System.Windows.Forms.OpenFileDialog dlgOpenNewShell;
        private System.Windows.Forms.CheckBox checkSyncIndices;
        private System.Windows.Forms.Button btnRemoveMap;
        private System.Windows.Forms.GroupBox grpEdit;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btnZoomOut;
        private System.Windows.Forms.Button btnZoomIn;
    }
}

