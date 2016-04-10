#include "MovableElement.h"

MovableElement::MovableElement()
{

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
