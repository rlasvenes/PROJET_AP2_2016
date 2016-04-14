#include "Ball.h"
#define SOL 500

Ball::Ball()
    : _x(0)
    , _y(0)
{

}

Ball::Ball(int x, int y, int w, int h, int dx, int dy)
    : _x(x)
    , _y(y)
    , _height(h)
    , _width(w)
    , _deltaX(dx)
    , _deltaY(dy)
    , _maxJump(30)
{

}

void Ball::setDeltaX(int deltaX) { this->_deltaX = deltaX; }
void Ball::setDeltaY(int deltaY) { this->_deltaY = deltaY; }

int Ball::getDeltaY() const { return _deltaY; }

int Ball::getPositionX() const { return _x; }
int Ball::getPositionY() const { return _y; }

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
