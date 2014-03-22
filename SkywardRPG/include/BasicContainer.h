/*
  Name: BasicContainer.h
  Copyright: none
  Author: Nathan Korzekwa
  Date: 13/08/10 20:51
  Description: This GuiElement only serves to hold other GuiElements
*/

#include "GuiElement.h"

namespace Skyward
{
    namespace Gui
    {
        class BasicContainer : public GuiElement
        {
            BasicContainer(GuiElement* c_parent, int c_x, int c_y, int c_width, int c_height);
            
        }
    }
}
