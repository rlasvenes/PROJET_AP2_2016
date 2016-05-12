#include "Menu.h"

Menu::Menu()
    : Menu(200, 200, 200, 200)
{

}

Menu::~Menu()
{
    delete & _rect;
}

// les implémentations des différents constructeurs ci-dessous ne sont pas optimales; j'ai eu des erreurs avec la délégation de constructeur

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

Menu::Menu(float width, float height, float x, float y, sf::Color couleur, std::string text)
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

    if (!_font.loadFromFile(PATH_FONT))
    {
        std::cerr << "ERREUR LORS DE L'INITIALISATION DE LA FONT : " << PATH_FONT << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        _textHeader.setString(text);
        _textHeader.setFont(_font);
        _textHeader.setCharacterSize(64);
        _textHeader.setOrigin(_textHeader.getLocalBounds().left + _textHeader.getLocalBounds().width/2,
                              _textHeader.getLocalBounds().top + _textHeader.getLocalBounds().height/2);
        _textHeader.setPosition(_rect.getPosition().x , _rect.getPosition().y);
    }
}

void Menu::setPositionX(float value) { _posX = value; }
void Menu::setPositionY(float value) { _posY = value; }

void Menu::setWidth(float value) { _width = value; }
void Menu::setHeight(float value) { _height = value; }

void Menu::draw(sf::RenderWindow * window)
{
    window->draw(_rect);
    window->draw(_textHeader);
}

void Menu::close()
{
    // appeller le destructeur
}
