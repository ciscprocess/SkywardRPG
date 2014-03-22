using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class AddMap : Form
    {
        EditForm parent;
        public AddMap(EditForm cParent)
        {
            InitializeComponent();
            this.parent = cParent;
        }

        private void AddMap_Load(object sender, EventArgs e)
        {

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            parent.ShellReader.AddPanel(int.Parse(this.txtX.Text), int.Parse(this.txtY.Text));
            this.Close();
        }
    }
}
