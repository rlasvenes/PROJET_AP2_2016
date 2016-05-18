#include "SplashText.h"

SplashText::SplashText()
{

}

SplashText::SplashText(std::string chaine, const std::string & font_path, int w, int h)
    : _string(chaine), _size(35)
    , _w(w), _h(h), _incrementValue(1)
{
    if (!_font.loadFromFile(font_path))
    {
        std::cerr << "ERREUR LORS DU CHARGEMENT DE LA FONT : " << font_path << std::endl;
        throw  "LoadingFontFailExecption";
        exit(EXIT_FAILURE);
    }
    else
    {
        _text.setFont(_font);
        _text.setString(_string);
        sf::FloatRect tRect = _text.getLocalBounds();
        _text.setOrigin(tRect.width/2, tRect.height/2);

        _text.setCharacterSize(_size);

        _text.setPosition(_w, _h);
        _text.setColor(sf::Color::Red);
    }


}

void SplashText::draw(sf::RenderWindow * window)
{
    _size += _incrementValue;
    update();

    if (_size < 35 || _size > 50) // 20 est la borne inférieur
    {
        _incrementValue *= (-1);
    }

    update();

    window->draw(_text);
}

void SplashText::update()
{
    sf::FloatRect tRect = _text.getLocalBounds();
    _text.setOrigin(tRect.width/2, tRect.height/2);

    _text.setCharacterSize(_size);
}


