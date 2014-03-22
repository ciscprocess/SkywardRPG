#include "ObjectManager.h"
#include <fstream>
#include "ConfigFileReader.h"
#include "ConfigFileException.h"
#include "MapObject.h"
#include <vector>
#include "Globals.h"
#include <sstream>
#include "MapEvent.h"
#include "Word.h"
using namespace std;
using namespace Skyward;
using namespace Exception;

const string ObjectManager::CONFIG_PATH_DEF = "./config/object_definitions.cfg";
const string ObjectManager::CONFIG_PATH_PLAC = "./config/obj_plac/object_placement";

ObjectManager::ObjectManager(World* parent)
{
    //ctor
    //this->m_config_path_def = "./config/object_definitions.cfg";
}

ObjectManager::~ObjectManager()
{
    //dtor
}

void ObjectManager::init_objects()
{
    for (unsigned int for_index = 0; for_index < m_object_instances.size(); for_index++)
    {
        delete m_object_instances[for_index];
    }
    m_object_instances.clear();
    string current_path = ObjectManager::CONFIG_PATH_PLAC;
    current_path+= "(";

    stringstream ss;
    string _new;
    ss << myProg->get_world()->get_world_x();
    ss >> _new;

    current_path+= _new;
    current_path+= "-";

    _new = "";

    stringstream ss1;
    ss1 << myProg->get_world()->get_world_y();
    ss1 >> _new;

    current_path+= _new;
    current_path+= ").cfg";

    ConfigFileReader t_read(current_path);
    //allegro_message("C_path:%s", current_path.c_str());
    t_read.get_next_statement();
    //allegro_message("Param: %s", t_read.get_current_parameter().c_str());
    set_object_position(t_read.get_current_parameter(), t_read.get_current_attribute(0), t_read.get_current_attribute(1));
    t_read.get_next_statement();
    while (t_read.is_reader_good())
    {
        string t_param = t_read.get_current_parameter();
        if (t_param.find_first_of('\n') != -1)
        {
            t_param.erase(0, 1);
        }
        set_object_position(t_param, t_read.get_current_attribute(0), t_read.get_current_attribute(1));

        t_read.get_next_statement();

    }

}

void ObjectManager::set_object_position(string a_name, string a_point, string a_word)
{
    //allegro_message("a_name:%s, a_point:%s, objs: %d, word: %s", a_name.c_str(), a_point.c_str(), m_objects.size(), a_word.c_str());
    for (unsigned int for_index = 0; for_index < m_objects.size(); for_index++)
    {
        string _obj_name = m_objects[for_index]->get_name();
        //allegro_message("a_name:%s, objname:%s", a_name.c_str(), _obj_name.c_str());

        if (_obj_name.compare(a_name) == 0)
        {
            MapObject* _map_object = new MapObject(m_objects[for_index]);

            int _x = 0;
            int _y = 0;
            int _f_pos = a_point.find("p(");
            a_point.erase(a_point.begin(), a_point.begin() + _f_pos + 2);
            string _t_str = a_point;
            string str_x = _t_str.substr(0, _t_str.find('-'));
            _x = atoi(str_x.c_str());
            string str_y = _t_str.substr(_t_str.find('-') + 1, _t_str.find(')') - _t_str.find('-'));
            _y = atoi(str_y.c_str());

            _map_object->set_x(_x);
            _map_object->set_y(_y);
            m_object_instances.push_back(_map_object);
             //allegro_message("Hiz");
            //allegro_message("Aize:%s", _map_object->word_name.c_str());
        }
    }
}

void ObjectManager::draw_objects()
{

    for (unsigned int for_index = 0; for_index < m_object_instances.size(); for_index++)
    {
        m_object_instances[for_index]->draw();
    }

}

int ObjectManager::get_traversability(int a_x, int a_y)
{
    for (unsigned int for_index = 0; for_index < m_object_instances.size(); for_index++)
    {
        MapObject* _in_question = m_object_instances[for_index];
        if (a_x >= _in_question->get_x() && a_x <= _in_question->get_x() + _in_question->get_width() && a_y >= _in_question->get_y() && a_y <= _in_question->get_y() + _in_question->get_height())
        {
            return 0;
        }
    }
    return 1;
}

void ObjectManager::map_words()
{
    ConfigFileReader t_read("./config/word_definitions.cfg");
    t_read.get_next_statement();
    Word* t_word = new Word(t_read.get_current_parameter(), t_read.get_current_attribute(1), t_read.get_current_attribute(0));
    this->m_words.push_back(t_word);
    t_read.get_next_statement();
    while (t_read.is_reader_good())
    {
        string t_param = t_read.get_current_parameter();
        if (t_param.find_first_of('\n') != -1)
        {
            t_param.erase(0, 1);
        }
        Word* t_word2 = new Word(t_param, t_read.get_current_attribute(1), t_read.get_current_attribute(0));
        this->m_words.push_back(t_word2);
        t_read.get_next_statement();
    }
}

/*
    AP Lang Specific Code:
*/

string ObjectManager::get_word_def(string a_word)
{
    //allegro_message("Yay0: %s", a_word.c_str());
    for (unsigned int for_index = 0; for_index < m_words.size(); for_index++)
    {
        //allegro_message("Yay0.5: %s", m_words[for_index]->m_name.c_str());
        if ( a_word.compare(m_words[for_index]->m_name) == 0)
        {
            //allegro_message("Yay.");
            return m_words[for_index]->m_def;
        }
    }
    return "";
}

void ObjectManager::proctor_events()
{
    for (unsigned int for_index = 0; for_index < m_object_instances.size(); for_index++)
    {
        m_events[for_index]->check();
    }
}

void ObjectManager::add_event(MapEvent* a_event)
{
    this->m_events.push_back(a_event);
}

void ObjectManager::add_object(string a_w_type, int a_index)
{
    MapObject* _map_object = new MapObject(m_objects[a_index]);
}
void ObjectManager::load_objects()
{
    ConfigFileReader t_read(ObjectManager::CONFIG_PATH_DEF);
    t_read.get_next_statement();
    string _head = t_read.get_current_parameter();
    string _relative_path = t_read.get_current_attribute(0);
    if (_head.compare("object_dir_relative") != 0)
    {
        throw new ConfigFileException("object_dir_relative not at the head of the object definitions file! Aborting.");
    }

    string _dir = t_read.get_current_attribute(0);
    t_read.get_next_statement();
    while (t_read.is_reader_good())
    {
        string _name = t_read.get_current_parameter();
        string _head2 = _relative_path;
        string _path = _head2.append(t_read.get_current_attribute(0));
//        myProg->s_log->info(_path);
        MOType _pass_state;
        string t_pass_state = t_read.get_current_attribute(1);
        if (t_pass_state.compare("IMPASSE") == 0) _pass_state = IMPASSE;
        else if (t_pass_state.compare("SUBPASSE") == 0) _pass_state = SUBPASSE;
        else if (t_pass_state.compare("SUPERPASSE") == 0) _pass_state = SUPERPASSE;
        else
        {
            myProg->s_log->warning("A pass type is missing from the object definitions file. Using default type of IMPASSE.");
            _pass_state = IMPASSE;
        }
        int _id = m_objects.size();
        //int _obj_type = atoi(t_read.get_current_attribute(2).c_str());
        //allegro_message("Type: %d", _obj_type);
        m_objects.push_back(new MapObject(_name, _id, _pass_state, _path));
        t_read.get_next_statement();
    }
}
