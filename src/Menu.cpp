#include "Menu.h"

Menu::Menu()
    : Menu(200, 200, 200, 200)
{
    // par défaut, on récupère l
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
    // remarque : si menu contient autre objet => parcourir avec itérateur puis appel destructeur objet
}
