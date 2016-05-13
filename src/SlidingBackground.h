#ifndef SLIDINGBACKGROUND_H
#define SLIDINGBACKGROUND_H

#include "View.h"

class GraphicElement;

class SlidingBackground
{
private:

    GraphicElement * _left;
    GraphicElement * _right;

    float _width;
    float _height;

    unsigned int _speed;

    unsigned int _distanceTraveled;


public:

    SlidingBackground();
    SlidingBackground(sf::Texture & image, float w, float h, unsigned int speed);

    ~SlidingBackground();

    void draw(sf::RenderWindow * window);
    void setSpeed(unsigned int value);

    unsigned int getDistanceTraveled() const;
    void setDistanceTraveled(unsigned int value);
};

#endif // SLIDINGBACKGROUND_H
