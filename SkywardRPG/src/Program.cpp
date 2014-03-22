/*
	Program.cpp - this file contains the implementation of Program.h.
*/

#ifndef PROGRAM_H
	#include "Globals.h"
#endif
#include "LogEventWriter.h"

extern BITMAP* buffer;
extern BITMAP* guage_buffer;
extern BITMAP* gui_buffer;
extern BITMAP* hw_buffer;
extern BITMAP* layer_buffer;

using namespace Gui;
using namespace Exception;
namespace Skyward
{
	Program::Program()
	{
         this->menu_active = false;
         this->battle_active = false;
         this->world_active = false;
         this->title_active = true;
         s_log = new Logger();
         m_input = new InputManager();
         m_gui = new GuiManager();
	}

	Program::~Program()
	{
		clear_keybuf();
	}

	void Program::initialize()
	{
    	int depth, res;
    	allegro_init();
    	depth = 32;//desktop_color_depth();
    	if (depth == 0)
    	{
            depth = 32;
            this->s_log->warning("Could not retrieve desktop color depth, using default depth of 32-bit!");
        }
    	set_color_depth(depth);
    	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);


    	if (res != 0) {
            string err = ": An Allegro error has occured, probably could not set app resolution.";
            err.insert(0, allegro_error);
    		this->s_log->fatal(err);
    	}
    	hw_buffer = create_bitmap(640,480);
        buffer = create_bitmap(640,480);
        gui_buffer = create_bitmap(640,480);
        layer_buffer = create_bitmap(640,480);
        guage_buffer = create_bitmap(100,10);
        clear_to_color(guage_buffer, makecol(255, 0, 255));
        clear_to_color(layer_buffer, makecol(255, 0, 255));
    	//install_timer();
    	install_keyboard();
    	install_mouse();
       /* install a MIDI sound driver */
       //if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "") != 0) {
         // this->s_log->fatal("Failed to initialize sound. Aborting.");
          //}

          m_music = new MusicPlayer("./audio/MorningTime.ogg", OGG_SONG);
          m_music->play_oggfile();
          m_music->pause();
          /*
            AP Lang Specific Code:
          */

          GenericMemPTR _temp = reinterpret_cast<GenericMemPTR>(&GuiElement::destroy);
          //GenericMemPTR _temp2 = reinterpret_cast<GenericMemPTR>(&MusicPlayer::pause);
          string str01 = "Welcome to LANG (Linguistic Accumen Necessary Growth); I know the acronym's horrible, but don't worry: The game is too. ";
          string str02 = "The objective of this game is to simply browse around LANGWorld. Hit the SPACEBAR to interact with the 'W' words. ";
          string str03 = "";
          string str04 = "";
          string str05 = "";
          string str06 = "As a note, this game was *VERY* hard to make. I programmed it from SCRATCH in C++, and all *3,500* lines of source code have been included with the game, if you're curious. ";
          string str07 = "As another note, included is a basemap editor (for the lower tiles only) if for some god-forsaken reason you want to edit the maps, and the word definition and object ";
          string str08 = "placement files are in the config directory for you to look at or edit if you are completely bored and/or insane. ";
          string str09 = "Every single thing in this game (the code, the graphics, the music, etc) was made by me (I used a tool for the character), which is why I was sent well into Sunday night working on this. ";
          string str_final;
            str_final+=str01;str_final+=str02;str_final+=str03;str_final+=str04;str_final+=str05;str_final+=str06;str_final+=str07;str_final+=str08;str_final+=str09;
          MessageBox *t_msg1 = new MessageBox(NULL, 40, 40, 400, 310, str_final);

          //t_msg1->add_child(new Button(NULL, 20, 290, "I'd guess it's time to play....", _temp, t_msg1));

          //t_msg1->add_child(new Button(NULL, 70, 380, "Stop", _temp2, myProg->get_music_player()));
          //GuiElement *_t_elem = new MessageBox(NULL, 150, 350, 200, 100, "Disguisable weapons.");
          //m_gui->add_element(_t_elem);
          //m_gui->add_element(t_msg1);

	}

	void Program::add_world(int x, int y)
	{
	    try
	    {
            this->m_world = new World(x, y);
            m_world->m_objects->load_objects();
            m_world->m_objects->map_words();
            this->m_world->create_screen();
            this->get_world()->get_object_manager()->init_objects();
	    }
	    catch (ConfigFileException* ex)
	    {
            this->s_log->fatal(ex->what());
	    }
    }

   	void Program::add_world(World* a_world)
	{
         if (!a_world) this->s_log->fatal("NULL pointer passed into add_world, cannot continue.");
         this->m_world = a_world;
        m_world->m_objects->load_objects();
        m_world->m_objects->map_words();
         this->m_world->create_screen();

         this->get_world()->get_object_manager()->init_objects();
    }

    World* Program::get_world()
    {
        return this->m_world;
    }

    int Program::run()
    {
        clear_to_color(guage_buffer, makecol(0, 0, 0));
        int _ret_value = 1;
        m_input->poll_game_keys();

        this->get_world()->draw_chars();
        this->get_world()->get_object_manager()->draw_objects();

        textprintf_ex(guage_buffer, font, 0, 1, makecol(0, 100, 243), -1, "(%d,%d)", this->m_world->get_character(0)->get_x(), this->m_world->get_character(0)->get_y());

        if (key[KEY_ESC]) _ret_value = -1;
        return _ret_value;
    }

    void Program::update()
    {
        clear_to_color(gui_buffer, makecol(255,0,255)); //This could be bad.
        m_input->poll_mouse();
        m_gui->draw_elements();
        m_gui->proctor_events();
        m_world->get_object_manager()->proctor_events();
        m_input->draw_cursor();
    }
}
