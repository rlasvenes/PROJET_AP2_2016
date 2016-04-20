#ifndef AUDIO_H
#define AUDIO_H

#include "View.h"

class Audio : public sf::Sound
{
private:

    // attributs + buffer, etc...
    sf::SoundBuffer _buffer;
    sf::Sound _sound;

public:

    Audio();
    Audio(const std::string & name); // name = path en l'occurence

    void loadSound(const std::string & name);
    void play();
    void pause();
    void stop();
};

#endif // AUDIO_H
