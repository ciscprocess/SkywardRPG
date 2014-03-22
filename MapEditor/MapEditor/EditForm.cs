using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace MapEditor
{
    enum DrawingState { NONE, DRAW, CYCLE, SQUARE } 
    public partial class EditForm : Form
    {
        Graphics handleGraphicsRaw;
        BufferedGraphicsContext context = BufferedGraphicsManager.Current;
        System.Drawing.BufferedGraphics handleGraphics;
        Graphics handlePreview;
        AboutMapEditor aboutBox;
        int mode;
        int TILE_W;
        int TILE_H;
        int MAP_W;
        int MAP_H;
        int zoomFactor = 1;
        bool prevDrawn = false;
        Image testBitmap;
        public TypeParser type;
        DrawingState state;
        ShellParser shellReader;
        Rectangle rectTool;
        int adjusX;
        int adjusY;
        bool drawn = false;
        bool clicked = false;
        bool mouseClicked = false;
        int activeMapIndex;
        

        public EditForm()
        {
            InitializeComponent();
            TILE_W = int.Parse(MapEditor.Properties.Resources.TILE_WIDTH);
            TILE_H = int.Parse(MapEditor.Properties.Resources.TILE_HEIGHT);
            MAP_W = int.Parse(MapEditor.Properties.Resources.MAP_WIDTH);
            MAP_H = int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT);
            mode = -1;
            this.graphicsPanel.Width = MAP_W * TILE_W;
            this.graphicsPanel.Height = MAP_H * TILE_H;
            state = DrawingState.NONE;
            handleGraphicsRaw = this.graphicsPanel.CreateGraphics();
            handleGraphics = context.Allocate(this.handleGraphicsRaw, new Rectangle(0, 0, this.graphicsPanel.Width, this.graphicsPanel.Height));
            handlePreview = this.panelPreview.CreateGraphics();
            this.handlePreview.CompositingQuality = System.Drawing.Drawing2D.CompositingQuality.HighSpeed;
            this.graphicsPanel.Paint += new PaintEventHandler(graphicsPanel_Paint);
            testBitmap = new Bitmap("./gfx/tile/FakeFloorTile.bmp");
            this.graphicsPanel.MouseMove += new MouseEventHandler(graphicsPanel_MouseMove);
            this.graphicsPanel.MouseDown += new MouseEventHandler(graphicsPanel_MouseDown);
            this.graphicsPanel.MouseUp +=new MouseEventHandler(graphicsPanel_MouseUp);
            this.MouseDown += new MouseEventHandler(EditForm_MouseDown);
            this.MouseUp += new MouseEventHandler(EditForm_MouseUp);
            this.mapList.SelectedIndexChanged +=new EventHandler(mapList_SelectedIndexChanged);
            this.listTile.SelectedIndexChanged += new EventHandler(listTile_SelectedIndexChanged);
            this.panelPreview.Paint += new PaintEventHandler(panelPreview_Paint);
            type = new TypeParser(MapEditor.Properties.Resources.TileMapPath, this);
            shellReader = new ShellParser(this, MapEditor.Properties.Resources.ShellPath);
            this.mapList.SelectedIndex = 0;
            this.listTile.SelectedIndex = 0;
            activeMapIndex = 0;
            DrawFromMap();
        }

        private void EditForm_MouseDown(object sender, MouseEventArgs e)
        {
            this.mouseClicked = true;
        }

        private void EditForm_MouseUp(object sender, MouseEventArgs e)
        {
            this.mouseClicked = false;
        }
        
        private void panelPreview_Paint(object sender, EventArgs e)
        {
            if (prevDrawn && !mouseClicked)
            {
                mapList_SelectedIndexChanged(new Object(), new EventArgs());
            }
        }
        
        private void graphicsPanel_Paint(object sender, EventArgs e)
        {
            //if (this.mainState != null) this.handleGraphics.Restore(this.mainState);
            switch (mode)
            {
                case -1:
                    break;
                case 0:
                    //DrawFromMap();
                    //if (thread.ThreadState == ThreadState.Unstarted) thread.Start();
                    this.handleGraphics.Render(this.handleGraphicsRaw);
                    break;
                case 1:
                    //DrawSquares();
                    this.handleGraphics.Render(this.handleGraphicsRaw);
                    break;
            }
        }


        private void listTile_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.listTile.SelectedIndex > -1)
            {
                this.imgTilePrev.Image = type.GetTileType(this.CurrentTileIndex);
                this.testBitmap = type.GetTileType(this.CurrentTileIndex);
            }

        }

        private void mapList_SelectedIndexChanged(object sender, EventArgs e)
        {
            for (int forIndex = 0; forIndex < MAP_H; forIndex++)
            {
                for (int forIndex2 = 0; forIndex2 < MAP_W; forIndex2++)
                {
                    //int val = randI.Next(0, 3);
                    Image tImg = ((ScreenPanel)this.shellReader.Panels[this.mapList.SelectedIndex]).Tile[forIndex, forIndex2];
                    if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");
                    this.handlePreview.DrawImage(tImg, new Rectangle(forIndex2 * 8, forIndex * 8, 8, 8));
                }
            }
            prevDrawn = true;
        }

        private void graphicsPanel_MouseMove(object sender, MouseEventArgs e)
        {
            //this.lblCur.Text = "Absolute Mouse coordinates: (" + e.X + ", " + e.Y + "), Adjusted Mouse coordinates: ";
            int adjusX2 = e.X - (e.X % TILE_W);
            int adjusY2 = e.Y - (e.Y % TILE_H);
            int adjusX3 = adjusX / TILE_W;
            int adjusY3 = adjusY / TILE_H;
            this.lblCur.Text = "Absolute Mouse coordinates: (" + e.X + ", " + e.Y + "), Adjusted Mouse coordinates: " + "(" + e.X / TILE_W + ", " + e.Y / TILE_H + ")";
            //this.statusBool.Text = String.Format("(adjusX: {0}, adjusY: {1}, adjusX2: {2}, adjusY2: {3})", adjusX, adjusY, adjusX2, adjusY2);
            try
            {
                if (this.state == DrawingState.DRAW || this.state == DrawingState.CYCLE || this.state == DrawingState.SQUARE)
                {

                    if (!this.drawn) this.handleGraphics.Graphics.DrawRectangle(Pens.Red, new Rectangle(adjusX2, adjusY2, TILE_H - (int)(0.05 * TILE_H), TILE_W - (int)(0.05 * TILE_W)));
                    if (e.Button == MouseButtons.Left && (adjusX2 / TILE_W) < MAP_W+1 && (adjusY / TILE_H) < MAP_H)
                    {
                        if (this.state == DrawingState.DRAW)
                        {
                            int adjustedX = e.X / TILE_W;
                            int adjustedY = e.Y / TILE_H;
                            this.drawn = true;
                            ((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).SetTile(this.CurrentTileIndex, adjustedX, adjustedY);
                            SetSquare(adjustedX, adjustedY);
                        }
                        else if (this.state == DrawingState.SQUARE && this.clicked)
                        {
                            if (e.X < (int.Parse(MapEditor.Properties.Resources.MAP_WIDTH) * int.Parse(MapEditor.Properties.Resources.TILE_HEIGHT)) - 2)
                            {
                                int tWidth = (adjusX3 - this.rectTool.X) + 1;
                                int tHeight = (adjusY3 - this.rectTool.Y) + 1;

                                int dW = this.rectTool.Width - tWidth;
                                int dH = this.rectTool.Height - tHeight;

                                if (dW > 0)
                                    this.RefresheArea((this.rectTool.Width - 1) + this.rectTool.X, this.rectTool.Y, dW + 2, this.rectTool.Height);
                                if (dH > 0)
                                    this.RefresheArea(this.rectTool.X, (this.rectTool.Height - 1) + this.rectTool.Y, this.rectTool.Width, dH + 2);


                                this.rectTool.Width = tWidth;
                                this.rectTool.Height = tHeight;
                                this.DrawToolRect();
                            }

                        }
                    }
                    if ((adjusX2 != adjusX || adjusY2 != adjusY) && adjusX3 < MAP_W+1 && adjusY3 < MAP_H)
                    {
                        if (this.state == DrawingState.SQUARE)
                        {
                            Image tImg = ((ScreenPanel)(this.shellReader.Panels[this.activeMapIndex])).Tile[adjusY3, adjusX3];
                            if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");
                            this.handleGraphics.Graphics.DrawImage(tImg, new Rectangle(adjusX, adjusY, TILE_W, TILE_H));
                            //RefresheArea(this.rectTool.X, this.rectTool.Y, this.rectTool.Width, this.rectTool.Height);
                        }
                        else if (!this.drawn)
                        {
                            Image tImg = ((ScreenPanel)(this.shellReader.Panels[this.activeMapIndex])).Tile[adjusY3, adjusX3];
                            if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");

                            this.handleGraphics.Graphics.DrawImage(tImg, new Rectangle(adjusX, adjusY, TILE_W, TILE_H));

                        }
                        else this.drawn = false;
                    }
                    adjusX = adjusX2;
                    adjusY = adjusY2;
                }
            }
            catch (IndexOutOfRangeException ex)
            {
                 
            }
            this.handleGraphics.Render(this.handleGraphicsRaw);
        }
        
        private void DrawToolRect()
        {
            for (int forIndex = this.rectTool.Y; forIndex < this.rectTool.Height + this.rectTool.Y; forIndex++)
            {

                for (int forIndex2 = this.rectTool.X; forIndex2 < this.rectTool.Width + this.rectTool.X; forIndex2++)
                {
                    Image tImg = this.type.GetTileType(this.CurrentTileIndex);
                    if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");

                    this.handleGraphics.Graphics.DrawImage(tImg, new Rectangle(forIndex2 * TILE_W, forIndex * TILE_H, TILE_W, TILE_H));
                }
            }
            this.handleGraphics.Render(this.handleGraphicsRaw);
        }

        private void RefresheArea(int x, int y, int width, int height)
        {
            for (int forIndex = y; forIndex < height + y; forIndex++)
            {
                for (int forIndex2 = x; forIndex2 < width + x; forIndex2++)
                {
                    Image tImg = ((ScreenPanel)(this.shellReader.Panels[this.activeMapIndex])).Tile[forIndex, forIndex2];
                    if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");

                    this.handleGraphics.Graphics.DrawImage(tImg, new Rectangle(forIndex2 * TILE_W, forIndex * TILE_H, TILE_W, TILE_H));
                }
            }
            this.handleGraphics.Render(this.handleGraphicsRaw);
        }
        
        private void graphicsPanel_MouseDown(object sender, MouseEventArgs e)
        {
            this.mouseClicked = true;
            int adjustedX = e.X / TILE_W;
            int adjustedY = e.Y / TILE_H;
            if (this.state == DrawingState.DRAW)
            {
                this.drawn = true;
                ((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).SetTile(this.CurrentTileIndex, adjustedX, adjustedY);
                SetSquare(adjustedX, adjustedY);
            }
            else if (this.state == DrawingState.CYCLE)
            {
                this.drawn = true;
                int tileNum = -1;
                tileNum = int.Parse(((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).Shell[adjustedY, adjustedX]);
                if (tileNum == this.listTile.Items.Count - 1) tileNum = 0;
                else tileNum += 1;
                ((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).SetTile(tileNum, adjustedX, adjustedY);
                this.testBitmap = ((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).Tile[adjustedY, adjustedX];
                SetSquare(adjustedX, adjustedY);
            }
            else if (this.state == DrawingState.SQUARE)
            {
                this.rectTool = new Rectangle(adjustedX, adjustedY, 1, 1);
                this.clicked = true;
            }
        }
        
        private void graphicsPanel_MouseUp(object sender, MouseEventArgs e)
        {
            this.mouseClicked = false;
            for (int forIndex = 0; forIndex < MAP_H; forIndex++)
            {
                for (int forIndex2 = 0; forIndex2 < MAP_W; forIndex2++)
                {
                    Image tImg = ((ScreenPanel)this.shellReader.Panels[this.mapList.SelectedIndex]).Tile[forIndex, forIndex2];
                    if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");
                    this.handlePreview.DrawImage(tImg, new Rectangle(forIndex2 * 8, forIndex * 8, 8, 8));
                }
            }
            if (this.state == DrawingState.SQUARE)
            {
                for (int forIndex = this.rectTool.Y; forIndex < this.rectTool.Y + this.rectTool.Height; forIndex++)
                {
                    for (int forIndex2 = this.rectTool.X; forIndex2 < this.rectTool.X + this.rectTool.Width; forIndex2++)
                    {
                        this.clicked = false;
                        ((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).SetTile(this.CurrentTileIndex, forIndex2, forIndex);
                    }
                }
                mapList_SelectedIndexChanged(new Object(), new EventArgs());
                this.clicked = false;
            }
        }

        private void DrawSquares()
        {
            Random randI = new Random();
            for (int forIndex = 0; forIndex < MAP_H; forIndex++)
            {
                for (int forIndex2 = 0; forIndex2 < MAP_W; forIndex2++)
                {
                    int val = randI.Next(0, 3);
                    this.handleGraphics.Graphics.DrawImage(this.type.GetTileType(val), new Rectangle(forIndex2 * (TILE_W / zoomFactor), forIndex * (TILE_H / zoomFactor), TILE_W / zoomFactor, TILE_H / zoomFactor));
                }
            }
            mode = 1;
            this.handleGraphics.Render(this.handleGraphicsRaw);
        }

        private void SetSquare(int x, int y)
        {
            //((Bitmap)testBitmap).RotateFlip(RotateFlipType.Rotate90FlipNone);
            this.handleGraphics.Graphics.DrawImage(this.testBitmap, new Rectangle(x * TILE_W, y * TILE_H, TILE_W, TILE_H));
            this.handleGraphics.Render(this.handleGraphicsRaw);
        }

        private void btnDraw_Click(object sender, EventArgs e)
        {
            this.DrawSquares();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            this.handleGraphics.Graphics.Clear(Color.FromArgb(236, 233, 216));
        }

        private void boxEdit_Enter(object sender, EventArgs e)
        {
            
        }
        
        public ComboBox MapList
        {
            get { return this.mapList; }
        }

        public ListBox ListTile
        {
            get { return this.listTile; }
        }

        public ShellParser ShellReader
        {
            get { return this.shellReader; }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.activeMapIndex = this.mapList.SelectedIndex;
            DrawFromMap();
        }

        private void DrawFromMap()
        {
            for (int forIndex = 0; forIndex < MAP_H; forIndex++)
            {
                for (int forIndex2 = 0; forIndex2 < MAP_W; forIndex2++)
                {
                    Image tImg = ((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).Tile[forIndex, forIndex2];
                    if (tImg == null) tImg = new Bitmap(GetType(), "InvalidTile.bmp");
                    this.handleGraphics.Graphics.DrawImage(tImg, new Rectangle(forIndex2 * (TILE_W / zoomFactor), forIndex * (TILE_H / zoomFactor), (TILE_W / zoomFactor), (TILE_H / zoomFactor)));
                }
            }
            mode = 0;
            this.handleGraphics.Render(this.handleGraphicsRaw);
        }

        private void btnPenDraw_Click(object sender, EventArgs e)
        {
            this.SwitchTool(DrawingState.DRAW);
        }

        private void btnSelRotate_Click(object sender, EventArgs e)
        {
            this.SwitchTool(DrawingState.CYCLE);
        }

        private void btnNoTool_Click(object sender, EventArgs e)
        {
            this.SwitchTool(DrawingState.NONE);
        }

        private void SwitchTool(DrawingState state)
        {
            switch (state)
            {
                case DrawingState.CYCLE:
                    this.Cursor = new Cursor(GetType(), "Rotate.cur");
                    this.state = state;
                    break;
                case DrawingState.DRAW:
                    this.Cursor = new Cursor("C:/WINDOWS/Cursors/pen_m.cur");
                    this.state = state;
                    break;
                case DrawingState.NONE:
                    this.Cursor = System.Windows.Forms.Cursors.Default;
                    this.state = state;
                    break;
                case DrawingState.SQUARE:
                    this.Cursor = System.Windows.Forms.Cursors.Cross;
                    this.state = state;
                    break;
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            ((ScreenPanel)this.shellReader.Panels[this.activeMapIndex]).FlushToConfig();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            AddMap ad = new AddMap(this);
            ad.Show();
        }

        private void toolsToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void viewLEWKAStartManualToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string webAdress = "http://www.korzekwa.net/LEWKA/";
            System.Diagnostics.Process.Start(webAdress);
        }

        private void penToolToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.SwitchTool(DrawingState.DRAW);
        }

        private void rotateToolToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.SwitchTool(DrawingState.CYCLE);
        }

        private void noToolToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.SwitchTool(DrawingState.NONE);
        }

        private void addMapToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddMap ad = new AddMap(this);
            ad.Show();
        }

        private void btnSquare_Click(object sender, EventArgs e)
        {
            this.SwitchTool(DrawingState.SQUARE);
        }

        private void testBtn_Click(object sender, EventArgs e)
        {
            this.DrawToolRect();
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            aboutBox = new AboutMapEditor();
            aboutBox.Show();
        }

        private void openNewConfigToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult result =  this.dlgOpenNewShell.ShowDialog();
            if (result == DialogResult.OK)
            {
                Stream thing = this.dlgOpenNewShell.OpenFile();
                MessageBox.Show("This function is not currently implemented, as it does not seem important.",
                    "Information", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void btnAddTile_Click(object sender, EventArgs e)
        {
            (new AddTileForm(this)).Show();
        }

        private void btnRemoveTile_Click(object sender, EventArgs e)
        {
            this.type.RemoveTile(this.CurrentTileIndex, this.checkSyncIndices.Checked);
        }

        public int CurrentTileIndex
        {
            get { return ((Tile)this.listTile.Items[this.listTile.SelectedIndex]).Index; }
        }

        private void dlgOpenNewShell_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void deleteMapToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.shellReader.RemovePanel(((ScreenPanel)this.shellReader.Panels[activeMapIndex]).X, ((ScreenPanel)this.shellReader.Panels[activeMapIndex]).Y);
            this.activeMapIndex = 0;
            this.mapList.SelectedIndex = 0;
        }

        private void btnRemoveMap_Click(object sender, EventArgs e)
        {
            deleteMapToolStripMenuItem_Click(new Object(), new EventArgs());
        }

        private void saveAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.shellReader.SaveAll();
        }

        private void EditForm_Load(object sender, EventArgs e)
        {

        }

        private void btnZoomIn_Click(object sender, EventArgs e)
        {
            if (zoomFactor > 1) zoomFactor--;

            DrawFromMap();
        }

        private void btnZoomOut_Click(object sender, EventArgs e)
        {
            zoomFactor++;
            DrawFromMap();
        }

        private void mapGridWorldToolStripMenuItem_Click(object sender, EventArgs e)
        {
            (new MapGrid(this)).Show();
        }
        
    }
}
