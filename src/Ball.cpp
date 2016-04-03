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
{

}

void Ball::setDeltaX(int deltaX) { this->_deltaX = deltaX; }
void Ball::setDeltaY(int deltaY) { this->_deltaY = deltaY; }

int Ball::getPositionX() const { return _x; }
int Ball::getPositionY() const { return _y; }

void Ball::move()
{
    _x += _deltaX;
}

void Ball::jump()
{
    do
    {
        _y -= _deltaY;
    } while ( _y < SOL);
}
