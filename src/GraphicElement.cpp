#include "GraphicElement.h"
#include "View.h"

GraphicElement::GraphicElement()
{

}

GraphicElement::GraphicElement(sf::Texture & image, int x, int y, int w, int h) // hérite de sf::Sprite, donc x et y = coord du sprite
{
    this->setTexture(image);
    this->setPosition(x, y);

    this->resize(70, 70);
    this->setOrigin((image.getSize().x)/2, (image.getSize().y)/2);

    _w = w;
    _h = h;
}

void GraphicElement::draw(sf::RenderWindow * window)
{
    window->draw(*this);
}

void GraphicElement::resize(int w, int h)
{
    float new_value_w = (this->getTexture()->getSize().x) / w;
    float new_value_h = (this->getTexture()->getSize().y) / h;

    this->setScale(1/new_value_w, 1/new_value_h);
}

