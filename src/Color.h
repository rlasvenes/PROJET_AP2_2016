#ifndef COLOR_H
#define COLOR_H

#include "View.h"

class Color
{
private:

    float _r; // red
    float _g; // green
    float _b; // blue

    // sf::Color _color;

public:

    Color();

    sf::Color getCurrentColor();

    // getters + setters
    float getRedValue() const;
    float getGreenValue() const;
    float getBlueValue() const;

    void setRedValue(float value);
    void setGreenValue(float value);
    void setBlueValue(float value);

    int getState() const;
};

#endif // COLOR_H
