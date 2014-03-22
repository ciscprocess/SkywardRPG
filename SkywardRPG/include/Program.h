/*
	Program.h - this file contains the headers for the Program class.
	The program class represents one instance of the application, and it contains
	all global resources and global initialization routines.
*/

#ifndef PROGRAM_H
	#define PROGRAM_H

#include <stdlib.h>
#include <iostream>
#include <allegro.h>
#include "World.h"
#include "Logger.h"
#include "Input.h"
#include "GuiManager.h"
#include "LogEventWriter.h"
#include "MusicPlayer.h"
#include "ObjectManager.h"

namespace Skyward
{
	namespace Utils
	{

    };

    class Program
	{
	public:
		Program();
		~Program();
		void initialize();
		int run(); // Runs time-restricted game routines, e.g. character animation
		void update(); // Runs unrestricted game routines, e.g. GUI
		void add_world(int x, int y);
		void add_world(World* a_world);
		World* get_world();
		Logger* s_log;
		InputManager* get_input_manager() { return this->m_input; }
		Gui::GuiManager* get_gui_manager() { return this->m_gui; }
        void set_t_writ(LogEventWriter* a_t) { t_writ = a_t; }
        LogEventWriter* get_t_writ() { return t_writ; }
        void set_tt_writ(LogEventWriter* a_tt) { t_writ = a_tt; }
        LogEventWriter* get_tt_writ() { return tt_writ; }
        MusicPlayer* get_music_player() { return m_music; }

    private:
        bool menu_active;
        bool battle_active;
        bool world_active;
        bool title_active;
        int m_current_world;
        World* m_world;
        Gui::GuiManager* m_gui;
        InputManager* m_input;
        MusicPlayer* m_music;
        LogEventWriter *t_writ; // These are used only for event-testing
        LogEventWriter *tt_writ; // --

	};
};
#endif
