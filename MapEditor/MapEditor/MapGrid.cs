using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class MapGrid : Form
    {
        private System.Windows.Forms.TableLayoutPanel testTable;
        private ArrayList viewPanels;
        private ArrayList gfxHandles;
        private ArrayList bufferedGfxHandles;
        private ArrayList screenPanels;
        bool tableCreated = false;
        BufferedGraphicsContext context = BufferedGraphicsManager.Current;
        EditForm parent;
        public MapGrid(EditForm machoist)
        {
            InitializeComponent();
            parent = machoist;
            viewPanels = new ArrayList();
            gfxHandles = new ArrayList();
            bufferedGfxHandles = new ArrayList();
            screenPanels = this.parent.ShellReader.Panels;
            CreateTable(null, null);
            DrawMaps();
            panel1.Paint += new PaintEventHandler(RedrawMaps);

        }

        public void RedrawMaps(Object aParent, EventArgs e)
        {
            if (!tableCreated) return;
            for (int forIndex = 0; forIndex < viewPanels.Count; forIndex++)
            {
                Graphics tGfx = (Graphics)gfxHandles[forIndex];
                BufferedGraphics tbuff = (BufferedGraphics)bufferedGfxHandles[forIndex];
                tbuff.Render(tGfx);
            }
        }

        public void DrawMaps()
        {
            for (int forIndex = 0; forIndex < viewPanels.Count; forIndex++)
            {
                ScreenPanel tScr = (ScreenPanel)screenPanels[forIndex];
                Panel tPnl = (Panel)viewPanels[forIndex];
                Graphics tGfx = tPnl.CreateGraphics();
                gfxHandles.Add(tGfx);
                BufferedGraphics tBuff = context.Allocate(tGfx, new Rectangle(0, 0, tPnl.Width, tPnl.Height));
                bufferedGfxHandles.Add(tBuff);
                for (int forIndex11 = 0; forIndex11 < 24; forIndex11++)
                {
                    for (int forIndex2 = 0; forIndex2 < 32; forIndex2++)
                    {
                        //int val = randI.Next(0, 3);
                        Image tImg = ((ScreenPanel)tScr).Tile[forIndex11, forIndex2];

                        if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");
                        tBuff.Graphics.DrawImage(tImg, new Rectangle(forIndex2 * 8, forIndex11 * 8, 8, 8));
                    }
                }

            }
            tableCreated = true;
        }

        public void CreateTable(Object aParent, EventArgs e)
        {
            BufferedGraphics handleGraphics;
            foreach (ScreenPanel scrPnl in screenPanels)
            {
                TableLayoutPanel ttPanel = new TableLayoutPanel();
                Panel viewPanel = new Panel();
                viewPanel.Width = 8 * 32;
                viewPanel.Height = 8 * 24;
                viewPanel.Top = 0;
                viewPanel.Left = 0;
                Label ttBox = (new Label());
                ttBox.Text = "m(" + scrPnl.X + "," + scrPnl.Y + "):";
                ttPanel.Controls.Add(ttBox, 0, 0);
                ttPanel.Controls.Add(viewPanel, 0, 1);
                ttPanel.Width = 8 * 32;
                ttPanel.Height = (8 * 24) + 32;
                this.gridView.Width = ((ttPanel.Width) * this.parent.ShellReader.Width);
                this.gridView.Height = ((ttPanel.Height) * this.parent.ShellReader.Height); 
                this.gridView.Controls.Add(ttPanel, scrPnl.X, scrPnl.Y);
                viewPanels.Add(viewPanel);

            }

        }


    }
}
