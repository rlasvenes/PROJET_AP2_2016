#include "Menu.h"

Menu::Menu()
    : Menu(200, 200, 200, 200)
{

}

Menu::~Menu()
{
    delete & _rect;
}

Menu::Menu(float width, float height, float x, float y)
    : _posX(x)
    , _posY(y)
    , _width(width)
    , _height(height)
{
    _rect.setOrigin(width/2, height/2);
    _rect.setPosition(x, y);
    _rect.setSize(sf::Vector2f(width, height));
}

Menu::Menu(float width, float height, float x, float y, sf::Color couleur)
    : _posX(x)
    , _posY(y)
    , _width(width)
    , _height(height)
    , _couleur(couleur)

{
    _rect.setOrigin(width/2, height/2);
    _rect.setPosition(x, y);
    _rect.setSize(sf::Vector2f(width, height));

    _rect.setFillColor(couleur);
}

Menu::Menu(float width, float height, float x, float y, sf::Color couleur, sf::Text textHeader)
    : _posX(x)
    , _posY(y)
    , _width(width)
    , _height(height)
    , _couleur(couleur)
    , _textHeader(textHeader)
{
    _rect.setOrigin(width/2, height/2);
    _rect.setPosition(x, y);
    _rect.setSize(sf::Vector2f(width, height));

    _rect.setFillColor(couleur);
}

void Menu::setPositionX(float value) { _posX = value; }
void Menu::setPositionY(float value) { _posY = value; }

void Menu::setWidth(float value) { _width = value; }
void Menu::setHeight(float value) { _height = value; }

void Menu::draw(sf::RenderWindow * window)
{
    window->draw(_rect);
}

void Menu::close()
{
    // appeller le destructeur
}
