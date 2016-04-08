#ifndef AUDIO_H
#define AUDIO_H

#include "View.h"

class Audio : public sf::Sound
{
private:

    sf::SoundBuffer _buffer;
    sf::Sound _sound;

public:

    Audio();

    Sound * loadSound(const std::string & name);
};

#endif // AUDIO_H
