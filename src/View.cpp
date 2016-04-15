#include "View.h"
#include "Model.h"
#include "Ball.h"
#include "GraphicElement.h"
#include "Menu.h"
#include "Audio.h"

#include <fstream>
#include <sstream>
#include <iostream>

#define PI 3.14159265359

using namespace std;

//=======================================
// Constructeur
//=======================================
View::View(int w, int h)
    : _w(w)
    , _h(h)
    , _slidingSpeed(5)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner - Projet POO 2015/2016", sf::Style::Close, settings);
    _window->setFramerateLimit(60);

    _i = _j = _k = 0;

    loadSprite(_background, _backgroundSprite, PATH_BACKGROUND_IMAGE);
    _slideBackground = new SlidingBackground(_background, _w, _h, _slidingSpeed/2);

    loadSprite(_foreground, _foregroundSprite, PATH_FOREGROUND_IMAGE);
    _slideForeground = new SlidingBackground(_foreground, _w, _h, _slidingSpeed*2);

    loadSprite(_ball, _ballElm, PATH_BALL_IMAGE);
    _ballElm = new GraphicElement(_ball, 100, 450, 70 ,70);
    _ballElm->setOrigin(_ballElm->getTexture()->getSize().x/2, _ballElm->getTexture()->getSize().y/2);
    _ballElm->resize(70, 70);

    _shadow = new GraphicElement(_ball, 50, 525, 70, 70);
    _shadow->setOrigin(_shadow->getTexture()->getSize().x/2, _shadow->getTexture()->getSize().y/2);
    _shadow->resize(70, 45);
    _shadow->setOpacity(50);
    _shadow->setColor(sf::Color(128, 128, 128, _shadow->getOpacity()));

    // ================================ DÉBUT TESTS ================================

    if (!_font.loadFromFile(PATH_FONT))
        std::cout << "ERREUR LORS DU CHARGEMENT DE " << PATH_FONT << std::endl;

    _texte.setFont(_font);
    _getTime.setFont(_font);

    _getTime.setPosition(40, 25);

    std::string m_IP = "IP = " + sf::IpAddress::getLocalAddress().toString();
    std::string IP = sf::IpAddress::getPublicAddress().toString();

    _texte.setString(m_IP);

    _texte.setCharacterSize(26);
    _getTime.setCharacterSize(22);

    _texte.setColor(sf::Color::Black);
    _getTime.setColor(sf::Color::White);

    TcpClient clientTest;
    std::string _it = std::to_string(clientTest.getPortNumber());
    _texte.setString(_texte.getString() + " ; Port = " + _it);
    _texte.setPosition((w/2) - ((_texte.getString().getSize())/2)*(_texte.getCharacterSize() + 9.5)/2, (h/2) + _texte.getCharacterSize() + 210);

    // ================================= FIN TESTS ==================================

}

//=======================================
// Chargement des sprites
//=======================================
sf::Sprite * View::loadSprite(sf::Texture & texture, sf::Sprite & sprite, const std::string & path)
{
    if (! texture.loadFromFile(path))
    {
        std::cerr << "ERREUR LORS DU CHARGEMENT DU SPRITE : " << path << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        sprite.setTexture(texture);
        return & sprite;
    }
}

GraphicElement & View::loadSprite(sf::Texture &texture, GraphicElement * elem, const string &path) // à finir
{
    if (! texture.loadFromFile(path))
    {
        std::cerr << "ERREUR LORS DU CHARGEMENT DU SPRITE : " << path << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        elem = new GraphicElement(texture, 50, 450, 50 ,50);
        return * elem;
    }
}

//=======================================
// Destructeur
//=======================================
View::~View(){
    if(_window != NULL)
        delete _window;
}

//=======================================
// Accesseurs en écriture
//=======================================
void View::setModel(Model * model){
    _model = model;
}

//=======================================
// Fonction de dessin
//=======================================
void View::draw(){

    _window->clear(sf::Color(abs(255*sin(_i)), abs(255*sin(_j)), abs(255*sin(_k)), 0)); // affichage fond ecran dynamique

    _slideBackground->draw(_window);
    _slideForeground->draw(_window);

    _shadow->draw(_window);
    _ballElm->draw(_window);

    _window->draw(_texte);
    _window->draw(_getTime);

    for (auto it : _elementToGraphicElement)
    {
        _window->draw(*it.second);
    }

    _model->drawGraphicPositionBall(350, 10, _font, _window);

    _window->display();
}

//=======================================
// Traitement des evenements
//=======================================
bool View::treatEvents(){

    bool result = false;
    if(_window->isOpen()){
        {
            _time = _clock.getElapsedTime();
            _getTime.setString("[ TIME : " + std::to_string((int) _time.asSeconds()) + " ]");

            _i += (2 * PI) / 500 ;      _j += (2 * PI) / 660;    _k += (2 * PI) / 770;

            _ballElm->rotate(3);

            if (_model->getBall()->isJumping())
            {
                if (_model->getBall()->getDeltaY() > 0)
                {
                    _shadow->resize(_shadow->getSizeWidth() + 3,
                                    _shadow->getSizeHeight() + 3);
                    _shadow->setOpacity(_shadow->getOpacity() - 1);
                    _shadow->setColor(sf::Color(128, 128, 128, _shadow->getOpacity()));
                }
                else if (_model->getBall()->getDeltaY() < 0)
                {
                    _shadow->resize(_shadow->getSizeWidth() - 3,
                                    _shadow->getSizeHeight() - 3);
                    _shadow->setOpacity(_shadow->getOpacity() + 2);
                    _shadow->setColor(sf::Color(128, 128, 128, _shadow->getOpacity() ));
                }
            }
            else
            {
               _shadow->setOpacity(50);
               _shadow->resize(70, 45);
            }

            result = true;
        }

        sf::Event event;
        while (_window->pollEvent(event)) {

            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();

                result = false;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up) && _model->getBall()->getPositionY() == 500)
            {
                _model->getBall()->setJump(true); // _jump = true;
                _model->getBall()->setDeltaY(_model->getBall()->maxJump());
            }

        } // pollevent
    } // isOpen

    return result;
}

void View::treatKeyState()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _model->moveBall(false);
        _ballElm->rotate(1);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _model->moveBall(true);
        _ballElm->rotate(6);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
    {
        _model->addElement();
        std::cout << "taille : " << _model->getSize() << std::endl;
    }

    _shadow->setPosition(_ballElm->getPosition().x, _shadow->getPosition().y);

}    

void View::synchronize()
{
    int x, y;

    _model->getBallPosition(x, y);
    _ballElm->setPosition(x, y);

    for (auto it : _elementToGraphicElement)
    {
        GraphicElement * elm = new GraphicElement(_ball, rand()%250 + 100, rand()%250 + 100, 50, 50);
        _elementToGraphicElement; // faut insérer une pair (std::pair) ?
    }


}

void View::setPositionCenter() const
{
    int screen_width = (sf::VideoMode::getDesktopMode().width - _w)/2;
    int screen_height = (sf::VideoMode::getDesktopMode().height - _h)/2;

    _window->setPosition(sf::Vector2i(screen_width, screen_height));
}
