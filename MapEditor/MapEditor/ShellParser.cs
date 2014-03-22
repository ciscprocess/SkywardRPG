using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using System.IO; 

namespace MapEditor
{
    public class ShellParser
    {
        ArrayList headerStrings;
        Form parent;
        FileStream shellStream;
        StreamReader shellReader;
        ArrayList panels;
        ArrayList headerPoints;
        bool init = false;

        string shellPath;

        public ShellParser(Form cParent, string cShellFile)
        {
            headerStrings = new ArrayList();
            parent = cParent;
            shellPath = cShellFile;
            shellStream = new FileStream(shellPath, FileMode.Open);
            shellReader = new StreamReader(shellStream);
            panels = new ArrayList();
            headerPoints = new ArrayList();
            GetMapHeaders();
            GetHeaderPoints();
            CreateScreenPanels();
            shellStream.Close();
            init = true;
        }
        
        private void Refresh()
        {
            headerStrings.Clear();
            panels.Clear();
            headerPoints.Clear();
            ((EditForm)this.parent).MapList.Items.Clear();
            if (!shellStream.CanSeek)
            {
                shellStream = new FileStream(shellPath, FileMode.Open);
                shellReader = new StreamReader(shellStream);
            }
            GetMapHeaders();
            GetHeaderPoints();
            CreateScreenPanels();
            shellStream.Close();
        }
        
        private void GetMapHeaders()
        {
            //string header = String.Empty;
            ((EditForm)this.parent).MapList.Items.Clear();
            if (!shellStream.CanRead)
            {
                shellStream = new FileStream(shellPath, FileMode.Open);
                shellReader = new StreamReader(shellStream);
            }
            string currentLine = shellReader.ReadLine();
            while (currentLine != null)
            {
                if (currentLine.Contains("m("))
                {
                    headerStrings.Add(currentLine);
                    ((EditForm)this.parent).MapList.Items.Add(currentLine);
                }
                currentLine = shellReader.ReadLine();
            }
        }

        private void GetHeaderPoints()
        {
            foreach (string str in this.headerStrings)
            {
                string nums = str.Replace("m(", "");
                nums = nums.Replace("):", "");
                string[] split = nums.Split(',');
                this.headerPoints.Add(new Point(int.Parse(split[0]), int.Parse(split[1])));

            }
        }

        private void CreateScreenPanels()
        {
            shellStream.Seek(0, SeekOrigin.Begin);
            string currentLine = shellReader.ReadLine();
            int iterator = 0;
            foreach (string str in headerStrings)
            {
                while (!currentLine.Contains(str))
                {
                    currentLine = shellReader.ReadLine();
                }

                currentLine = shellReader.ReadLine();
                string[,] tShell = new String[int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT), int.Parse(MapEditor.Properties.Resources.MAP_WIDTH)];
                int iter = 0;
                int iter2 = 0;
                int lastFound = 0;
                
                while (currentLine != null && !currentLine.Contains("m("))
                {
                    /*for (int forIndex = 0; forIndex < currentLine.Length; forIndex++)
                    {
                        tShell[iter, forIndex] = currentLine[forIndex].ToString();
                    }*/
                    if (currentLine.CompareTo("") == 0)
                    {
                        currentLine = shellReader.ReadLine();
                        continue;
                    }
                    iter2 = 0;
                    do
                    {
                        int tLength = currentLine.IndexOf(',', lastFound + 1) - lastFound - 1;
                        string numString;

                        if (tLength > 0) numString = currentLine.Substring(lastFound + 1, tLength);
                        else numString = currentLine.Substring(lastFound + 1);

                        int brackPos = numString.IndexOf(']');
                        int opnBrackPos = numString.IndexOf('[');

                        if (opnBrackPos != -1) numString = numString.Remove(opnBrackPos, 1);
                        if (brackPos != -1) numString = numString.Remove(brackPos);
                        tShell[iter, iter2] = numString;
                        lastFound = currentLine.IndexOf(',', lastFound + 1);
                        iter2++;
                    } while (lastFound != -1);
                    iter++;
                    currentLine = shellReader.ReadLine();
                }
                panels.Add(new ScreenPanel(((EditForm)parent).type, tShell, (string)headerStrings[iterator]));
                iterator++;
                
            }
        }

        public void AddPanel(int x, int y)
        {
            string tHeader = "m(" + x + "," + y + "):";
            if (headerStrings.IndexOf(tHeader) != -1)
            {
                DialogResult result = MessageBox.Show("There is already a map at the location you specified, do you really want to replace it with a new one?", "Warning", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                if (result == DialogResult.No) return;
                int index = this.headerStrings.IndexOf(tHeader);
                this.panels[index] = null;
                string[,] tShell = new String[int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT), int.Parse(MapEditor.Properties.Resources.MAP_WIDTH)];

                for (int forIndex = 0; forIndex < tShell.GetLength(0); forIndex++)
                {
                    for (int forIndex2 = 0; forIndex2 < tShell.GetLength(1); forIndex2++)
                    {
                        tShell[forIndex, forIndex2] = "0";
                    }
                }
                this.panels[index] = new ScreenPanel(((EditForm)parent).type, tShell, tHeader);
                ((ScreenPanel)this.panels[index]).FlushToConfig();
            }
            else if (headerStrings.IndexOf(tHeader) == -1)
            {
                string[,] tShell = new String[int.Parse(MapEditor.Properties.Resources.MAP_HEIGHT), int.Parse(MapEditor.Properties.Resources.MAP_WIDTH)];

                for (int forIndex = 0; forIndex < tShell.GetLength(0); forIndex++)
                {
                    for (int forIndex2 = 0; forIndex2 < tShell.GetLength(1); forIndex2++)
                    {
                        tShell[forIndex, forIndex2] = "0";
                    }
                }
                this.panels.Add(new ScreenPanel(((EditForm)parent).type, tShell, tHeader));
                ((ScreenPanel)this.panels[this.panels.Count - 1]).FlushToConfig();
            }
            this.Refresh();
        }

        public void RemovePanel(int x, int y)
        {
            string tHeader = "m(" + x + "," + y + "):";
            DialogResult continueB = MessageBox.Show("This will delete the currently opened map on the left side of the screen. This cannot be undone.\nAre you sure this is what you want to do?", "Whoa!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (continueB == DialogResult.No) return;
            if (headerStrings.IndexOf(tHeader) == -1)
            {
                MessageBox.Show("There is no ScreenPanel at the location specified for deletion.", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            else if (headerStrings.IndexOf(tHeader) != -1)
            {
                int index = this.headerStrings.IndexOf(tHeader);
                this.panels.RemoveAt(index);
                shellStream = new FileStream(shellPath, FileMode.Open);
                shellStream.SetLength(0);
                shellStream.Close();
                foreach (ScreenPanel panelI in this.panels)
                {
                    panelI.FlushToConfig();
                }
            }
            this.Refresh();
        }

        public void SaveAll()
        {
            shellStream = new FileStream(shellPath, FileMode.Open);
            shellStream.SetLength(0);
            shellStream.Close();
            foreach (ScreenPanel panelI in this.panels)
            {
                panelI.FlushToConfig();
            }
        }

        public ArrayList Panels
        {
            get { return this.panels; }
        }

        public int Width
        {
            get
            {
                int[] thing = new int[headerPoints.Count];
                int iter = 0;
                foreach (Point pnt in headerPoints)
                {
                    thing[iter] = ((Point)this.headerPoints[iter]).X;
                    iter++;
                }
                Array.Sort(thing);
                return (thing[thing.Length - 1] + 1);
            }
            
        }

        public int Height
        {
            get
            {
                int[] thing = new int[headerPoints.Count];
                int iter = 0;
                foreach (Point pnt in headerPoints)
                {
                    thing[iter] = ((Point)this.headerPoints[iter]).Y;
                    iter++;
                }
                Array.Sort(thing);
                return (thing[thing.Length - 1] + 1);
            }

        }
    }
}
