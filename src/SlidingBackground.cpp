#include "SlidingBackground.h"

SlidingBackground::SlidingBackground()
{

}

SlidingBackground::SlidingBackground(sf::Texture & image, float w, float h, unsigned int speed)
    : _width(w)
    , _height(h)
    , _speed(speed)
    , _distanceTraveled(0)
{
    _left = new GraphicElement(image, 0, 0, image.getSize().x, image.getSize().y);
    _right = new GraphicElement(image, _left->getTexture()->getSize().x, 0, w, h);
}

void SlidingBackground::draw(sf::RenderWindow * window)
{
    _left->setPosition(_left->getPosition().x - _speed, _left->getPosition().y);
    _right->setPosition(_right->getPosition().x - _speed, _right->getPosition().y);

    _distanceTraveled += _speed * 2;

    if (_left->getPosition().x + _left->getTexture()->getSize().x < 0)
        _left->setPosition(_right->getPosition().x + _right->getTexture()->getSize().x, _left->getPosition().y);

    if (_right->getPosition().x + _right->getTexture()->getSize().x < 0)
        _right->setPosition(_left->getPosition().x + _left->getTexture()->getSize().x, _right->getPosition().y);

    window->draw(*_left);
    window->draw(*_right);
}

void SlidingBackground::setSpeed(unsigned int value)
{
    _speed = value;
}

unsigned int SlidingBackground::getDistanceTraveled() const
{
    return _distanceTraveled;
}

void SlidingBackground::setDistanceTraveled(unsigned int value)
{
    _distanceTraveled = value;
}
