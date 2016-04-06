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
    void jump(int value);

    void setDeltaX(int deltaX);
    void setDeltaY(int deltaY);

    int getDeltaY();

    int getPositionX() const;
    int getPositionY() const;

    // TEST CLOCK

    sf::Clock m_clock;
    float _value;

    //===============

private:

    int _x; // changer par un vector2f
    int _y;

    int _width;
    int _height;

    int _deltaX;
    int _deltaY;

};

#endif // BALL_H
