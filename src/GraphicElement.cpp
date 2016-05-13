#include "GraphicElement.h"
#include "View.h"

GraphicElement::GraphicElement()
{

}

GraphicElement::GraphicElement(sf::Texture & image, int x, int y, int w, int h) // hérite de sf::Sprite, donc x et y = coord du sprite
    : _opacity(0)
{
    this->setTexture(image);
    this->setPosition(x, y);

    _w = w;
    _h = h;
}

GraphicElement::~GraphicElement()
{
    delete this;
}

void GraphicElement::draw(sf::RenderWindow * window)
{
    window->draw(*this);
}

void GraphicElement::resize(int w, int h)
{
    float new_value_w = (this->getTexture()->getSize().x)*1.00f / w;
    float new_value_h = (this->getTexture()->getSize().y)*1.00f / h;

    this->setScale(1/new_value_w, 1/new_value_h);
}

float GraphicElement::getSizeWidth() const
{
    return this->getTexture()->getSize().x * this->getScale().x;
}

float GraphicElement::getSizeHeight() const
{
    return this->getTexture()->getSize().y * this->getScale().y;
}

void GraphicElement::setOpacity(unsigned int value)
{
    _opacity = value;
}

unsigned int GraphicElement::getOpacity() const
{
    return _opacity;
}
