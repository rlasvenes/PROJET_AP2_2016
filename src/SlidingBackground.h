#ifndef SLIDINGBACKGROUND_H
#define SLIDINGBACKGROUND_H

#include "View.h"

class GraphicElement;

class SlidingBackground
{
private:

    GraphicElement _left;
    GraphicElement _right;

    float _width;
    float _height;

    unsigned int _speed;


public:

    SlidingBackground();
    SlidingBackground(sf::Texture & image, float w, float h, unsigned int speed);
};

#endif // SLIDINGBACKGROUND_H
