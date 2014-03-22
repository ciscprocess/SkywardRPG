/*
  MusicPlayer.h - this file contains the Class MusicPlayer, which, *GASP* plays music.
*/

#ifndef MUSICPLAYER_H

#define MUSICPLAYER_H

#include <string>
#include <allegro.h>
#include <audiere.h>
#include "EventCapable.h"
using namespace std;
using namespace audiere;

namespace Skyward
{
    enum MUSIC_TYPE { MIDI_SONG, OGG_SONG };

    class MusicPlayer : public EventCapable
    {
    public:
          MusicPlayer();
          MusicPlayer(string path, MUSIC_TYPE type);
          ~MusicPlayer();
          void add_song(string path, MUSIC_TYPE type);
          void next_song();
          void pause();
          void play();
          void resume();
          void play_oggfile();
    private:
          MIDI *active_music;
          string music_paths[64];
          AudioDevicePtr *device;
          OutputStreamPtr *stream;
          int index;
    };
}
#endif
