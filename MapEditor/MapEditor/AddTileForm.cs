using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace MapEditor
{
    public partial class AddTileForm : Form
    {
        EditForm parent;
        TyleStyle style;
        bool fileLoaded = false;
        bool indexSet = false;
        bool styleSet = false;
        public AddTileForm(EditForm cParent)
        {
            InitializeComponent();
            style = (TyleStyle)this.comboType.SelectedIndex;
            parent = cParent;
            this.numIndex.Value = this.parent.type.MaxTileIndex + 1;
            indexSet = true;
            this.comboType.Items.Add(TyleStyle.SOLID_GROUND); //Maybe do a parse and a loop....
            this.comboType.Items.Add(TyleStyle.WALL);
            this.comboType.Items.Add(TyleStyle.WATER);

        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            string fullPath = this.imageFileOpen.FileName;
            string name = fullPath.Remove(0, fullPath.LastIndexOf("\\") + 1);
            if (this.fileLoaded && this.indexSet && this.styleSet) parent.type.AddTile((FileStream)this.imageFileOpen.OpenFile(), (int)this.numIndex.Value, style, name);
            this.Dispose();
        }

        private void txtPath_TextChanged(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void btnPath_Click(object sender, EventArgs e)
        {
            DialogResult myResult = this.imageFileOpen.ShowDialog();
            
            if (myResult == DialogResult.OK)
            {
                string fullPath = this.imageFileOpen.FileName;
                string name = fullPath.Remove(0, fullPath.LastIndexOf("\\") + 1);
                this.txtPath2.Text = name;
                fileLoaded = true;
            }
        }

        private void numIndex_ValueChanged(object sender, EventArgs e)
        {

        }

        private void comboType_SelectedIndexChanged(object sender, EventArgs e)
        {
            style = (TyleStyle)this.comboType.SelectedIndex;
            this.styleSet = true;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }
    }
}
