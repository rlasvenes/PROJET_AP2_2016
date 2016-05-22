#include "AnimatedGraphicElement.h"

AnimatedGraphicElement::AnimatedGraphicElement()
{

}

AnimatedGraphicElement::AnimatedGraphicElement(int x, int y, unsigned int w, unsigned int h, const std::string & path, unsigned int lineNumber)
    : _w(w), _h(h), _lineNumber(lineNumber)
{
    if (!_image.loadFromFile(path))
        std::cerr << "ERRRREUR ANIMATED " << std::endl;
    else
    {
        _sprite.setTexture(_image);
        _sprite.setPosition(x, y);

        assert(h * lineNumber < _image.getSize().y);
        _initPos.x = _h * _lineNumber;
    }
}

void AnimatedGraphicElement::draw(sf::RenderWindow * window)
{
    _sourceRect.width = _w;
    _sourceRect.height = _h;

    _sourceRect.top = _initPos.x;

    _sprite.setTextureRect(_sourceRect);

    window->draw(_sprite);
    update();
}

void AnimatedGraphicElement::update()
{
    if (_clock.getElapsedTime().asMilliseconds() > 40.0f)
    {
        if ((unsigned)_sourceRect.left == _image.getSize().x - _sourceRect.width)
        {
            _sourceRect.left = 0;
        }
        else
        {
            _sourceRect.left += _w;
        }
        _clock.restart();
    }
}
