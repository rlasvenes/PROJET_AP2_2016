#ifndef BALL_H
#define BALL_H

#include <View.h>

class Ball
{

public:
    Ball();
    Ball(int x, int y, int w, int h, int dx, int dy);

    void move();
    void jump();

    void setDeltaX(int deltaX);
    void setDeltaY(int deltaY);

    int getPositionX() const;
    int getPositionY() const;

private:
    // Point m_pos;

    int _x;
    int _y;

    int _width;
    int _height;

    int _deltaX;
    int _deltaY;

};

#endif // BALL_H
