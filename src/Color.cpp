#include "Color.h"

Color::Color()
    : _r(0)
    , _g(0)
    , _b(0)
{

}

float Color::getRedValue() const { return _r; }
float Color::getGreenValue() const { return _g; }
float Color::getBlueValue() const { return _b; }

void Color::setRedValue(float value)
{
    _r = value;
}

void Color::setGreenValue(float value)
{
    _g = value;
}

void Color::setBlueValue(float value)
{
    _b = value;
}
