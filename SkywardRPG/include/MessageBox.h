/*
  Name: MessageBox.h
  Copyright: none
  Author: Nathan Korzekwa
  Date: 12/08/10 20:15
  Description: Simple alert box with a message.
*/
#include "GuiElement.h"

using namespace std;
namespace Skyward
{
    namespace Gui
    {
        class MessageBox : public GuiElement
        {
            public:
                   MessageBox(Skyward::Gui::GuiElement* c_parent, int c_x, int c_y, int c_width, int c_height, string c_message);

                   virtual void deutsche();

                   void Llog(); // This and the following function are purely for event testing.
                   void Llog2();
            private:
                   string m_message;
                   int m_lines;
                   int m_letts;
                   virtual void draw_internal();
        };
    }
}
