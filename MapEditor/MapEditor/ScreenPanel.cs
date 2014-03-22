using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Drawing;
using System.IO;

namespace MapEditor
{
    public class ScreenPanel
    {
        Bitmap[,] tileImages;
        String[,] shell;
        TypeParser parser;
        string mapNum;
        public ScreenPanel(TypeParser cParser, String[,] cShell, string cMapNum)
        {
            tileImages = new Bitmap[int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT), int.Parse(MapEditor.Properties.Resources.MAP_WIDTH)];
            shell = cShell;
            parser = cParser;
            mapNum = cMapNum;
            MapTiles();
        }

        void MapTiles()
        {
            for (int forIndex = 0; forIndex < int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT); forIndex++)
            {
                for (int forIndex2 = 0; forIndex2 < int.Parse(MapEditor.Properties.Resources.MAP_WIDTH); forIndex2++)
                {
                    tileImages[forIndex, forIndex2] = parser.GetTileType(int.Parse(shell[forIndex, forIndex2])); 
                }
            }
        }

        public void SetTile(int tileType , int x, int y)
        {
            shell[y, x] = tileType.ToString();
            tileImages[y, x] = parser.GetTileType(tileType);
        }

        public void FlushToConfig()
        {
            string currentDir = Directory.GetCurrentDirectory();
            if (currentDir.Contains("\\gfx\\tile"))
            {
                Directory.SetCurrentDirectory("../../");
            }
            currentDir = Directory.GetCurrentDirectory();
            FileStream stream = new FileStream(MapEditor.Properties.Resources.ShellPath, FileMode.Open);
            StreamReader read = new StreamReader(stream);
            StreamWriter write = new StreamWriter(stream);
            ArrayList inData = new ArrayList();
            stream.Seek(0, SeekOrigin.Begin);
            
            // We Read the File
            while (!read.EndOfStream)
            {
                inData.Add(read.ReadLine());
            }

            int startIndex = 0;
            int tLength = shell.GetLength(0);
            ArrayList outData = new ArrayList();
            for (int forIndex = 0; forIndex < tLength; forIndex++)
            {
                string row = String.Empty;
                row += "[";
                for (int forIndex2 = 0; forIndex2 < shell.GetLength(1); forIndex2++)
                {
                    row += shell[forIndex, forIndex2];
                    if (forIndex2 < shell.GetLength(1) - 1)
                        row += ",";
                }
                row += "]";
                outData.Add(row);
            }
            bool addNew = false;
            startIndex = inData.IndexOf(mapNum) + 1;
            if (startIndex < 1)
            {
                addNew = true;
            }

            if (!addNew)
            {
                int neutralIter = 0;
                for (int forIndex = startIndex; forIndex < startIndex + int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT); forIndex++)
                {
                    inData[forIndex] = outData[neutralIter];
                    neutralIter++;
                }
            }
            else if (addNew)
            {
                int neutralIter = 0;
                inData.Add(this.mapNum);
                for (int forIndex = 0; forIndex < int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT); forIndex++)
                {
                    inData.Add(outData[neutralIter]);
                    neutralIter++;
                }
                
            }

            stream.Close();
            stream = new FileStream(MapEditor.Properties.Resources.ShellPath, FileMode.Truncate);
            write = new StreamWriter(stream);
            foreach (string str in inData)
            {
                write.WriteLine(str);
            }
            write.Flush();
            stream.Flush();
            stream.Close();
        }

        public Bitmap[,] Tile
        {
            get { return this.tileImages; }
        }

        public String[,] Shell
        {
            get { return this.shell; }
        }

        public int X
        {
            get { return int.Parse(this.mapNum.Replace("m(", "").Replace("):", "").Split(',')[0]); }
        }

        public int Y
        {
            get { return int.Parse(this.mapNum.Replace("m(", "").Replace("):", "").Split(',')[1]); }
        }
    }
}
