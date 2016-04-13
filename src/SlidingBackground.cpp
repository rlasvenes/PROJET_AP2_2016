#include "SlidingBackground.h"

SlidingBackground::SlidingBackground()
{

}

SlidingBackground::SlidingBackground(sf::Texture & image, float w, float h, unsigned int speed)
    : _width(w)
    , _height(h)
    , _speed(speed)
{
    _left.setTexture(image);
    _right.setTexture(image);
}
