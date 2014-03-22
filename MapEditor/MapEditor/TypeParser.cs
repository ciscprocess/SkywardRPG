using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
using System.Drawing;
using System.Windows.Forms;

namespace MapEditor
{
    public enum TyleStyle { SOLID_GROUND, WALL, WATER }

    public class TypeParser
    {
        FileStream configStream;
        StreamReader configReader;
        StreamWriter configWriter;
        EditForm parent;
        ArrayList tileTypes;
        string relativeDir = String.Empty;

        public TypeParser(string cFilePath, Form cParent)
        {
            configStream = new FileStream(cFilePath, FileMode.Open);
            configReader = new StreamReader(configStream);
            configWriter = new StreamWriter(configStream);
            tileTypes = new ArrayList();
            parent = (EditForm)cParent;
            Map();
            FlushToConfig();
        }

        private void Map()
        {
            string currentLine = configReader.ReadLine();

            while (!currentLine.Contains("tile_dir_relative"))
            {
                currentLine = configReader.ReadLine();
            }

            relativeDir = ((currentLine.Split(',')[1]).Trim());
            relativeDir = relativeDir.Remove(relativeDir.IndexOf(';'));
            int logicalEnum = 0;
            currentLine = configReader.ReadLine();
            while (currentLine != null)
            {
                int tileIndex;
                try { tileIndex = int.Parse(currentLine.Split(',')[0]); }
                catch (Exception ex) { continue; }
                string fileName = (((currentLine.Split(',')[1]).Trim()).Split(':')[0]).Trim();
                string style = (currentLine.Split(':')[1]).Replace(";", "");
                Tile tTile = new Tile(new Bitmap(relativeDir + fileName), tileIndex, ((TyleStyle)Enum.Parse(typeof(TyleStyle), style)), fileName);
                this.parent.ListTile.Items.Add(tTile);
                tileTypes.Add(tTile);
                currentLine = configReader.ReadLine();
                logicalEnum++;
            }
            
        }

        private void RefreshTileList()
        {
            this.parent.ListTile.Items.Clear();
            foreach (Tile tile in this.tileTypes)
            {
                this.parent.ListTile.Items.Add(tile);
            }
        }

        public void AddTile(FileStream aStream, int aIndex, TyleStyle aStyle, string aFile)
        {
            Bitmap image = new Bitmap(aStream);
            this.tileTypes.Add(new Tile(image, aIndex, aStyle, aFile));
            RefreshTileList();
            this.FlushToConfig();
        }

        public void RemoveTile(int index, bool syncIndices)
        {
            DialogResult toDoOrNotToDo;
            if (syncIndices)
            {
                toDoOrNotToDo = MessageBox.Show("The 'Sync Indices' checkbox is checked. This will shift all of the tile indices, and change the way the map looks dramatically. \nAre you shure this is what you want to do?",
                     "Caution", MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation);
            }
            else
            {
                toDoOrNotToDo = DialogResult.Yes;
            }

            if (toDoOrNotToDo == DialogResult.Yes)
            {
                this.tileTypes.RemoveAt(index);
                if (syncIndices)
                {
                    for (int forIndex = index; forIndex < this.tileTypes.Count; forIndex++)
                    {
                        ((Tile)this.tileTypes[index]).Index--;
                    }
                }
                this.RefreshTileList();
                this.FlushToConfig();
            }
            else if (toDoOrNotToDo == DialogResult.No)
            {
                return;
            }
        }

        public void RemoveTile(Tile objTile, bool syncIndices)
        {
            RemoveTile(objTile.Index, syncIndices);
        }

        public bool HasIndex(int aIndex)
        {
            foreach (Tile tile in this.tileTypes)
            {
                if (tile.Index == aIndex) return true;
            }
            return false;
        }

        private void FlushToConfig()
        {
            ArrayList inFile = new ArrayList();
            configStream.Seek(0, SeekOrigin.Begin); // Just in Case

            string currentLine = String.Empty;
            while (!configReader.EndOfStream) // Could be Redundant
            {
                inFile.Add(configReader.ReadLine());
            }
            configStream.SetLength(0); // GASP! The FILE IS EMPTY!!!

            configWriter.WriteLine(inFile[0]);
            foreach (Tile tle in this.tileTypes)
            {
                string outLine = String.Format("{0}, {1} :{2};", tle.Index, tle.File, (tle.Style.ToString()));
                configWriter.WriteLine(outLine);
            }
            configWriter.Flush();

        }

        public Bitmap GetTileType(int tIndex)
        {
            //return ((Tile)this.tileTypes[tIndex]).Image;
            foreach (Tile tile in this.tileTypes)
            {
                if (tIndex == tile.Index)
                    return tile.Image;
            }
            return null;
        }

        public int MaxTileIndex
        {
            get
            {
                int max = -1;
                for (int forIndex = 0; forIndex < this.tileTypes.Count; forIndex++)
                {
                    if (((Tile)this.tileTypes[forIndex]).Index > max)
                        max = ((Tile)this.tileTypes[forIndex]).Index;
                }
                return max;
            }
        }

        public int TileCount
        {
            get { return this.tileTypes.Count; }
        }

    }
}
