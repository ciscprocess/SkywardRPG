/*
  Name:
  Copyright:
  Author:
  Date: 04/02/10 18:48
  Description:
*/

#include "Globals.h"
using namespace std;
using namespace Skyward;
BITMAP* buffer;
BITMAP* gui_buffer;
BITMAP* guage_buffer;
BITMAP* hw_buffer;
BITMAP* layer_buffer;

/*
  Allegro timer routines
*/
volatile int speed_counter = 0;

void increment_speed_counter()
{
    speed_counter++;
}

END_OF_FUNCTION(increment_speed_counter)

int main()
{
    /*
      Let's initialize the program
    */
    myProg = new Program();
	myProg->initialize();

    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(increment_speed_counter);
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(120));

    /*
	  Creates a new world with a ScreenPanel viewport at (0,0).
    */
    myProg->add_world(0,0);

    World* testWorld = myProg->get_world();

    /*
	  Creates a handle for World's currently active ScreenPanel.
    */

	ScreenPanel* drawPanel = testWorld->get_screen();
	drawPanel->draw_to_screen();

    /*
        Creates character with random bitmap that serves no purpose (I was too lazy to delete it)
        and a spritesheet.
    */
	testWorld->create_character("./gfx/character/sprite.bmp", "./gfx/character/sheet.bmp", 80, 80);

	bool quitting = false;
	while (true)
    {
		myProg->update(); // Run unbridled routines
        while (speed_counter > 0)
        {
            if (myProg->run() != 1) quitting = true; // Run time restricted routines

    		draw_sprite(buffer, guage_buffer, 0,0);

            speed_counter--;
        }

        draw_sprite(hw_buffer, buffer, 0, 0);
        draw_sprite(hw_buffer, layer_buffer, 0, 0);
        draw_sprite(hw_buffer, gui_buffer, 0, 0);
        draw_sprite(screen, hw_buffer, 0, 0);

	    if (quitting) break;
    }
	myProg->s_log->info("Program exited normally.");
	return 0;
}

END_OF_MAIN()


