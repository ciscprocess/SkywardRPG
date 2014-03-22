#ifndef MAPOBJECT_H
#define MAPOBJECT_H
#include <allegro.h>
#include <string>
#include "EventCapable.h"

using namespace std;

namespace Skyward
{
    enum MOType {IMPASSE, SUPERPASSE, SUBPASSE};
    class FaceKeyEvent ;
    class MapObject : EventCapable
    {
        public:
            MapObject(int c_x, int c_y, string c_name, int c_id, MOType c_pass_state);
            MapObject(string c_name, int c_id, MOType c_pass_state, string c_path);
            MapObject(MapObject* c_object);
            virtual ~MapObject();
            int get_x() { return m_x; }
            int get_y() { return m_y; }
            string get_name() { return m_name; }
            int get_id() { return m_id; }
            string get_path() { return m_image_path; }
            void set_x(int a_x) { m_x = a_x; }
            void set_y(int a_y) { m_y = a_y; }
            int get_width() { return m_width; }
            int get_height() { return m_height; }
            MOType get_pass_state() { return m_pass_state; }
            void draw();

        protected:
            int m_x;
            int m_y;
            int m_width;
            int m_height;
            string m_name;
            string m_image_path;
            int m_id;

            BITMAP *m_image;
            MOType m_pass_state;
            FaceKeyEvent* m_on_face_key;

    };

}
#endif // MAPOBJECT_H
