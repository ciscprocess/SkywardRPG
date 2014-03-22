using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace MapEditor
{
    public class Tile
    {
        Bitmap image;
        int index;
        Size imageSize;
        TyleStyle tileType;
        string file;

        public Tile(Bitmap cImage, int cIndex, TyleStyle cStyle, string cFile)
        {
            image = cImage;
            index = cIndex;
            tileType = cStyle;
            file = cFile;
            imageSize = new Size(image.Width / int.Parse(MapEditor.Properties.Resources.TILE_WIDTH), image.Height / int.Parse(MapEditor.Properties.Resources.TILE_HEIGHT));
        }

        public Bitmap Image
        {
            get { return this.image; }
        }

        public string File
        {
            get { return this.file;  }
        }

        public TyleStyle Style
        {
            get { return this.tileType; }
        }

        public int Index
        {
            get { return this.index; }
            set { this.index = value; }
        }

        public int Width
        {
            get { return this.imageSize.Width; }
        }

        public int Height
        {
            get { return this.imageSize.Height; }
        }

        public override string ToString()
        {
            return this.Index + " - "  + this.File;
        }

    }
}
