#include "MovableElement.h"
#include "View.h"

#include <iostream>

MovableElement::MovableElement()
    : _slidingSpeed(5)
    , _x(0)
    , _y(0)

{

}

MovableElement::MovableElement(int x, int y, int w, int h)
    : _x(x)
    , _y(y)
    , _width(w)
    , _height(h)
    , _slidingSpeed(-2)
{
    this->move();
}

void MovableElement::setDeltaX(int deltaX)
{
    _deltaX = deltaX;
}

void MovableElement::setDeltaY(int deltaY)
{
    _deltaY = deltaY;
}

int MovableElement::getPositionX() const { return _x; }
int MovableElement::getPositionY() const { return _y; }

int MovableElement::getDeltaX() const { return _deltaX; }
int MovableElement::getDeltaY() const { return _deltaY; }

float MovableElement::getSizeWidth() const { return _width; }
float MovableElement::getSizeHeight() const { return _height; }

void MovableElement::move()
{
    _x += _slidingSpeed;
}

void MovableElement::setSlidingSpeed(unsigned int value)
{
    _slidingSpeed = value;
}

unsigned int MovableElement::getSlidingSpeed() const
{
    return _slidingSpeed;
}
