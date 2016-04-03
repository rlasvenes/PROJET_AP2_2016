#include "GraphicElement.h"
#include "View.h"

GraphicElement::GraphicElement()
{

}

GraphicElement::GraphicElement(sf::Texture & image, int x, int y, int w, int h)
{
    this->setPosition((sf::Vector2f(x, y)));
    this->setTexture(image);

    this->setPosition(x, y);

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

