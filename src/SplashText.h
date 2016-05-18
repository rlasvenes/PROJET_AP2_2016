#ifndef SPLASHTEXT_H
#define SPLASHTEXT_H

#include "View.h"

class SplashText : public sf::Text
{
private:

    sf::Font _font;
    sf::Text _text;

    std::string _string;
    unsigned int _size;

    int _w, _h;
    int _incrementValue;

public:

    SplashText();
    SplashText(std::string chaine, const std::string & font_path, int w, int h);

    void draw(sf::RenderWindow * window);

    void update();
};

#endif // SPLASHTEXT_H
