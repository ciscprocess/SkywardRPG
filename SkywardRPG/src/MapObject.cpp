#include <allegro.h>
#include "MapObject.h"
#include "Globals.h"
#include "FaceKeyEvent.h"
extern BITMAP* buffer;
using namespace Skyward;
using namespace Gui;

MapObject::MapObject(int c_x, int c_y, string c_name, int c_id, MOType c_pass_state)
{
    //ctor
}

/*
    TODO (nkorzekwa): Make this into a real copy ctor, ASAP.
*/

MapObject::MapObject(MapObject* c_object)
{
    m_name = c_object->get_name();
    m_id = c_object->get_id();
    m_pass_state = c_object->get_pass_state();
    m_image_path = c_object->get_path();
    m_image = load_bitmap(c_object->get_path().c_str(), NULL);
    m_width = m_image->w;
    m_height = m_image->h;
    m_x = c_object->get_x();
    m_y = c_object->get_y();

    m_on_face_key = new FaceKeyEvent(this);
    GenericMemPTR _temp2 = reinterpret_cast<GenericMemPTR>(&MusicPlayer::play);
    Delegate *t_deleg = new Delegate(_temp2, myProg->get_music_player());
    m_on_face_key->set_trigger(t_deleg);
    //show_definition();
}

MapObject::MapObject(string c_name, int c_id, MOType c_pass_state, string c_path)
{
    //allegro_message("search res:%d", c_name.find_first_of('\n'));
    if (c_name.find_first_of('\n') != -1)
    {
        c_name.erase(0, 1);
    }
    m_name = c_name;
    m_id = c_id;
    m_pass_state = c_pass_state;
    m_image_path = c_path;
    m_image = load_bitmap(c_path.c_str(), NULL);
    if (m_image)
    {
        if (is_memory_bitmap(m_image) == TRUE)
        {
            m_width = m_image->w;
            m_height = m_image->h;
        }
        else
        {
           m_width = 0;
           m_height = 0;
        }
    }
    else
    {
       m_width = 0;
       m_height = 0;
    }

    m_x = -1;
    m_y = -1;
    m_on_face_key = new FaceKeyEvent(this);
    GenericMemPTR _temp2 = reinterpret_cast<GenericMemPTR>(&MusicPlayer::play);
    Delegate *t_deleg = new Delegate(_temp2, myProg->get_music_player());
    m_on_face_key->set_trigger(t_deleg);
}

void MapObject::draw()
{
    if (m_x >= 0 && m_y >= 0)
    {
        draw_sprite(buffer, m_image, m_x, m_y);
    }
}

MapObject::~MapObject()
{
    //dtor
}
