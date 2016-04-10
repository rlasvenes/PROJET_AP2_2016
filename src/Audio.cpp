#include "Audio.h"
#include <iostream>

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
