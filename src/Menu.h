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

public:

    Menu();
    Menu(float width, float height, float x, float y);

    void draw(sf::RenderWindow * window);
    void close();

    // get + set
    void setPositionX(float value);
    void setPositionY(float value);

    void setWidth(float value);
    void setHeight(float value);
};

#endif // MENU_H
