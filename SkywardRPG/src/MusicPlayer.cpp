#include "MusicPlayer.h"

using namespace Skyward;
using namespace std;

MusicPlayer::MusicPlayer()
{

}

MusicPlayer::MusicPlayer(string path, MUSIC_TYPE type)
{
    this->index = 0;

    device = new AudioDevicePtr(OpenDevice());
    if (!(*device))
    {
        allegro_message("Failed on Device.");
    }

    this->add_song(path, type);

}

MusicPlayer::~MusicPlayer()
{
    destroy_midi(this->active_music);
}

void MusicPlayer::add_song(string path, MUSIC_TYPE type)
{
    if (type == MIDI_SONG) this->active_music = load_midi(path.c_str());
    else if (type == OGG_SONG)
    {
            stream = new OutputStreamPtr(OpenSound((*device), path.c_str(), true));

            if (!(*stream))
            {
                allegro_message("Failed on Stream.");
            }
    }

    this->music_paths[index] = path.c_str();
    this->index++;

}

void MusicPlayer::next_song()
{

}

void MusicPlayer::pause()
{
    //midi_pause();
    (*stream)->stop();
}

void MusicPlayer::play()
{
     //play_midi(this->active_music, 1);
     (*stream)->play();
}

void MusicPlayer::play_oggfile()
{
    (*stream)->setRepeat(true);
    (*stream)->setVolume(0.5f); // 50% volume
    (*stream)->play();
}

void MusicPlayer::resume()
{
    (*stream)->play();
}
