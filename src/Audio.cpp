#include "Audio.h"
#include <iostream>

Audio::Audio(const std::string &name)
{
    loadSound(name);
    _sound.setBuffer(_buffer);
}

void Audio::loadSound(const std::string & name)
{
    if (!_buffer.loadFromFile(name))
    {
        std::cerr << "ERREUR CHARGEMENT SON : " << name << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        _sound.setBuffer(_buffer);
    }
}

Audio::~Audio()
{
    delete & _sound;
    delete & _buffer;
}

void Audio::play()
{
    _sound.play();
}

void Audio::pause()
{
    _sound.pause();
}

void Audio::stop()
{
    _sound.stop();
}

void Audio::setLoop(bool value)
{
    _sound.setLoop(value);
}

void Audio::setPitch(float value)
{
    _sound.setPitch(value);
}

void Audio::resetBuffer()
{
    _sound.resetBuffer();
}
