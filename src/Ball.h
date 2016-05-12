#ifndef BALL_H
#define BALL_H

#include "View.h"
#include "MovableElement.h"

class GraphicElement;

class Ball : public MovableElement
{

public:

    Ball();
    Ball(int x, int y, int w, int h, int dx, int dy);

    ~Ball();

    void move();
    void stop();
    void jump();

    void setDeltaX(int deltaX);
    void setDeltaY(int deltaY);

    int getDeltaY() const;

    int getPositionX() const;
    int getPositionY() const;

    void setPositionX(int value);
    void setPositionY(int value);

    float getSizeWidth() const;
    float getSizeHeight() const;

    bool isJumping() const;
    void setJump(bool value);
    int maxJump() const;

    GraphicElement * getShadow() const;

    bool treatColision(const MovableElement * elm) const;

    void setTarget(bool value);
    bool isTargetted() const;

private:

    int _x;
    int _y;

    int _width;
    int _height;

    int _deltaX;
    int _deltaY;

    bool _jump;
    int _maxJump;

    sf::Clock m_clock;
    GraphicElement * _shadow;

    bool _isTargetted;

};

#endif // BALL_H
