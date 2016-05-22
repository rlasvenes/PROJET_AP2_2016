#include "Ball.h"
#include <iostream>

Ball::Ball()
    : _x(0)
    , _y(0)
{

}

Ball::Ball(int x, int y, int w, int h, int dx, int dy)
    : _x(x)
    , _y(y)
    , _width(w)
    , _height(h)
    , _deltaX(dx)
    , _deltaY(dy)
    , _maxJump(25)
    , _isTargetted(false)
{

}

Ball::~Ball()
{

}

void Ball::setDeltaX(int deltaX) { this->_deltaX = deltaX; }
void Ball::setDeltaY(int deltaY) { this->_deltaY = deltaY; }

int Ball::getDeltaY() const { return _deltaY; }

int Ball::getPositionX() const { return _x; }
int Ball::getPositionY() const { return _y; }

void Ball::setPositionX(int value) { _x = value; }
void Ball::setPositionY(int value) { _y = value; }

float Ball::getSizeWidth() const { return _width; }
float Ball::getSizeHeight() const { return _height; }

void Ball::move()
{
    _x += _deltaX;
}

void Ball::jump()
{
    _y -= _deltaY;
}

bool Ball::isJumping() const
{
    return _jump;
}

void Ball::setJump(bool value)
{
    _jump = value;
}

int Ball::maxJump() const
{
    return _maxJump;
}

bool Ball::treatColision(const MovableElement *elm) const
{
    if (this->getPositionX() - this->getSizeWidth()/2 <= elm->getPositionX() + elm->getSizeWidth()
     && this->getPositionX() + this->getSizeWidth() - this->getSizeWidth() >= elm->getPositionX() - this->getSizeWidth()/2
     && this->getPositionY() + this->getSizeHeight()/2 <= elm->getPositionY() + elm->getSizeHeight()
     && this->getPositionY() + this->getSizeHeight()/2 >= elm->getPositionY() )
    {
        return true;
    }

    return false;
}

void Ball::setTarget(bool value)
{
    _isTargetted = value;
}

bool Ball::isTargetted() const
{
    return _isTargetted;
}
