#ifndef BALL_H
#define BALL_H

#include "View.h"
#include "MovableElement.h"

class Ball : public MovableElement
{

public:

    Ball();
    Ball(int x, int y, int w, int h, int dx, int dy);

    void move();
    void stop();
    void jump();

    void setDeltaX(int deltaX);
    void setDeltaY(int deltaY);

    int getDeltaY() const;

    int getPositionX() const;
    int getPositionY() const;

private:

    int _x;
    int _y;

    int _width;
    int _height;

    int _deltaX;
    int _deltaY;

    sf::Clock m_clock;

};

#endif // BALL_H
