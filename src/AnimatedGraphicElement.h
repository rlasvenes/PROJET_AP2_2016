#ifndef ANIMATEDGRAPHICELEMENT_H
#define ANIMATEDGRAPHICELEMENT_H

#include "View.h"
#include "MovableElement.h"

class AnimatedGraphicElement
{
private:

    sf::Sprite _sprite;
    sf::IntRect _sourceRect;
    unsigned int _w, _h, _lineNumber;

    sf::Vector2i _initPos;

    sf::Clock _clock;

    sf::Texture _image;

public:

    AnimatedGraphicElement();
    AnimatedGraphicElement(int x, int y, unsigned int w, unsigned int h, const std::string & path, unsigned int lineNumber);

    void draw(sf::RenderWindow * window);
    void update();

};

#endif // ANIMATEDGRAPHICELEMENT_H
