#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include "View.h"
#include <SFML/Graphics.hpp>

class Model;
class View;

class GraphicElement : public sf::Sprite
{

private:

    int _w;
    int _h;

    unsigned int _opacity;

public:

    GraphicElement();
    GraphicElement(sf::Texture & image, int x, int y, int w, int h);

    void draw(sf::RenderWindow * window);
    void resize(int w, int h);

    float getSizeWidth() const;
    float getSizeHeight() const;

    void setOpacity(unsigned int value);
    unsigned int getOpacity() const;
};

#endif // GRAPHICELEMENT_H
