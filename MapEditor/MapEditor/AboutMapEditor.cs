using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Windows.Forms;
using System.Threading;

namespace MapEditor
{
    partial class AboutMapEditor : Form
    {
        RectangleF collisionRect;
        Graphics handleGraphics;
        ThreadStart threadJob;
        Thread thread;
        
        public AboutMapEditor()
        {
            InitializeComponent();
            handleGraphics = this.logoPictureBox.CreateGraphics();
            this.Disposed += new EventHandler(AboutMapEditor_Disposed);
            collisionRect = new RectangleF(0,0, this.logoPictureBox.Width, this.logoPictureBox.Height);
            threadJob = new ThreadStart(RunAnimation);
            thread = new Thread(threadJob);
            thread.Start();
            //this.Text = String.Format("About {0} {0}", AssemblyTitle);
            //this.labelProductName.Text = AssemblyProduct;
            this.labelVersion.Text = String.Format("Version {0}", AssemblyVersion);
            //this.labelCopyright.Text = AssemblyCopyright;
            //this.labelCompanyName.Text = AssemblyCompany;
            //this.textBoxDescription.Text = AssemblyDescription;
        }

        private void AboutMapEditor_Disposed(object sender, EventArgs e)
        {
            this.thread.Abort();
        }

        #region Assembly Attribute Accessors

        public string AssemblyTitle
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyTitleAttribute), false);
                if (attributes.Length > 0)
                {
                    AssemblyTitleAttribute titleAttribute = (AssemblyTitleAttribute)attributes[0];
                    if (titleAttribute.Title != "")
                    {
                        return titleAttribute.Title;
                    }
                }
                return System.IO.Path.GetFileNameWithoutExtension(Assembly.GetExecutingAssembly().CodeBase);
            }
        }

        public string AssemblyVersion
        {
            get
            {
                return Assembly.GetExecutingAssembly().GetName().Version.ToString();
            }
        }

        public string AssemblyDescription
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyDescriptionAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyDescriptionAttribute)attributes[0]).Description;
            }
        }

        public string AssemblyProduct
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyProductAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyProductAttribute)attributes[0]).Product;
            }
        }

        public string AssemblyCopyright
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyCopyrightAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyCopyrightAttribute)attributes[0]).Copyright;
            }
        }

        public string AssemblyCompany
        {
            get
            {
                object[] attributes = Assembly.GetExecutingAssembly().GetCustomAttributes(typeof(AssemblyCompanyAttribute), false);
                if (attributes.Length == 0)
                {
                    return "";
                }
                return ((AssemblyCompanyAttribute)attributes[0]).Company;
            }
        }
        #endregion

        private void tableLayoutPanel_Paint(object sender, PaintEventArgs e)
        {

        }

        private void labelCompanyName_Click(object sender, EventArgs e)
        {

        }

        private void okButton_Click(object sender, EventArgs e)
        {
            thread.Abort();
            this.Hide();
        }

        private void RunAnimation()
        {
            double XFactor = 0.5;
            double YFactor = 0.5;
            double speed = 0.2;
            double x = ((int)this.collisionRect.Width) / 2;
            double y = ((int)this.collisionRect.Height) / 2;
            Rectangle rect = new Rectangle((int)x, (int)y, 40, 40);
            Bitmap myBit = new Bitmap(this.logoPictureBox.Width, this.logoPictureBox.Height);
            bool switch1 = true;
            BufferedGraphicsContext context = BufferedGraphicsManager.Current;
            System.Drawing.BufferedGraphics myBuff = context.Allocate(this.handleGraphics, new Rectangle(0, 0, this.logoPictureBox.Width, this.logoPictureBox.Height));
            Random myRand = new Random();
            SolidBrush brush = new SolidBrush(Color.FromArgb(0,0,255));
            while (true)
            {
                if (switch1)
                {
                    rect.X = (int)x;
                    rect.Y = (int)y;
                    myBuff.Graphics.Clear(Color.FromArgb(236, 233, 216));
                    myBuff.Graphics.FillEllipse(brush, rect);
                    myBuff.Graphics.DrawImage(MapEditor.Properties.Resources.logotext, rect.X - 5, rect.Y + 7);
                    if (x + 40 > this.collisionRect.Width - 1 || x < 1)
                    {
                        double randMod = (((double)myRand.Next(-1, 1)) / 100);
                        XFactor *= -1;
                        XFactor += randMod;
                        YFactor -= randMod;
                        int blue = myRand.Next(0, 254);
                        int green = myRand.Next(0, 254);
                        int red = myRand.Next(0, 254);
                        brush.Color = Color.FromArgb(red, green, blue);

                    }

                    if (y + 40 > this.collisionRect.Height - 1 || y < 1)
                    {
                        double randMod = (((double)myRand.Next(-1, 1)) / 100);
                        YFactor *= -1;
                        YFactor += randMod;
                        XFactor -= randMod;
                        int blue = myRand.Next(0, 254);
                        int green = myRand.Next(0, 254);
                        int red = myRand.Next(0, 254);
                        brush.Color = Color.FromArgb(red, green, blue);
                    }

                    x += speed * XFactor;
                    y += speed * YFactor;
                }
                switch1 = !switch1;
                myBuff.Render(this.handleGraphics);
            }
            
        }

        private void textBoxDescription_TextChanged(object sender, EventArgs e)
        {

        }

    }
}
