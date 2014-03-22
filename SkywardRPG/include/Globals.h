/*
  Globals.h - this file contains all global instances necessary for the program.
*/
#ifndef GLOBALS_H
    #include <allegro.h>
    #include "Program.h"
    #include "ScreenPanel.h"
    #include "World.h"
    #include "Tile.h"
    #include "CharPC.h"
    #include "Logger.h"
    #include "Input.h"
    #include "MusicPlayer.h"
    #include "GetTileException.h"
    #include "ConfigFileException.h"
    #include "Event.h"
    #include "MouseOverEvent.h"
    #include "GuiElement.h"
    #include "MessageBox.h"
    #include "UniversalTypes.h"
    #include "MouseDownEvent.h"
    #include "MouseOutEvent.h"
    #include "Settings.h"
    #include "EventCapable.h"
    #include "Button.h"
    #include <vector>
    #include <time.h>
    #include <math.h>
    using namespace Skyward;
    extern Program* myProg;
    extern BITMAP* gui_buffer;
#endif
