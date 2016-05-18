#ifndef MENU_H
#define MENU_H

 #include "View.h"

class Menu
{
private:

    sf::RectangleShape _rect;

    float _posX;
    float _posY;

    float _width;
    float _height;

    sf::Color _couleur;
    sf::Text _textHeader;
    sf::Font _font;

    std::vector<std::string> _buttons;

public:

    Menu();
    Menu(float width, float height, float x, float y);
    Menu(float width, float height, float x, float y, sf::Color couleur);
    Menu(float width, float height, float x, float y, sf::Color couleur, std::string text);
    Menu(float width, float height, float x, float y, sf::Color couleur, std::vector<std::string> buttons);

    ~Menu();

    void draw(sf::RenderWindow * window);
    void close();

    // get + set
    void setPositionX(float value);
    void setPositionY(float value);

    void setWidth(float value);
    void setHeight(float value);
};

#endif // MENU_H
