#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include <vector>
#include "MapObject.h"
#include "World.h"
#include "MapEvent.h"
#include <string>
#include "Word.h"
using namespace std;

namespace Skyward
{
    class ObjectManager //consider adding this as a class of ScreenPanel instead of World
    {
        public:
            ObjectManager(World* parent);
            virtual ~ObjectManager();
            void load_objects();
            void init_objects();
            void draw_objects();
            void proctor_events();
            void add_object(string a_w_type, int a_index);
            string get_word_def(string a_word);
            void map_words();
            int get_traversability(int a_x, int a_y);
            int object_count() { return m_objects.size();}
            void add_event(MapEvent* a_event);
            static const string CONFIG_PATH_DEF;
            static const string CONFIG_PATH_PLAC;
        protected:

        private:
            void set_object_position(string a_name, string a_point, string a_word);
            vector<MapObject*> m_objects;
            vector<MapObject*> m_object_instances;
            vector<MapEvent*> m_events;
            vector<Word*> m_words;

    };
}
#endif // OBJECTMANAGER_H
