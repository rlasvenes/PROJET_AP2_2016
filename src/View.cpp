#include "View.h"
#include "Model.h"
#include "Ball.h"
#include "GraphicElement.h"
#include "Menu.h"
#include "Audio.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//=======================================
// Constructeur
//=======================================
View::View(int w, int h)
    : _w(w)
    , _h(h)
{
    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner - Projet POO 2015/2016", sf::Style::Close);
    _window->setFramerateLimit(30);

    // _audio->loadSound(SOUND_TEST); // à corriger, fait planter le programme

    _i = _j = _k = 0;

    int screen_width = (sf::VideoMode::getDesktopMode().width - w)/2;
    int screen_height = (sf::VideoMode::getDesktopMode().height - h)/2;

    _window->setPosition(sf::Vector2i(screen_width, screen_height));

    loadSprite(_background, _backgroundSprite, BACKGROUND_IMAGE);

    if (!_ball.loadFromFile(BALL_IMAGE)) {
        std::cerr << "ERROR when loading image file: "
                  << BALL_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    } else {
        _ballElm = new GraphicElement(_ball, 50, 450, 50 ,50);
    }

    // ================================ DÉBUT TESTS ================================

    if (!_font.loadFromFile("../fonts/8_bit_font2.ttf"))
        std::cout << "ERREUR LORS DU CHARGEMENT DE 8_bit_font !" << std::endl;

    _texte.setFont(_font);
    _getTime.setFont(_font);

    _getTime.setPosition(40, 25);

    std::string m_IP = "IP = " + sf::IpAddress::getLocalAddress().toString();
    std::string IP = sf::IpAddress::getPublicAddress().toString();

    _texte.setString(m_IP);

    _texte.setCharacterSize(36);
    _getTime.setCharacterSize(22);

    _texte.setColor(sf::Color::Black);
    _getTime.setColor(sf::Color::Red);

    TcpClient clientTest;
    std::string _it = std::to_string(clientTest.getPortNumber());
    _texte.setString(_texte.getString() + " ; Port = " + _it);
    _texte.setPosition((w/2) - ((_texte.getString().getSize())/2)*(_texte.getCharacterSize() + 9.5)/2, (h/2) + _texte.getCharacterSize());

    // ================================= FIN TESTS ==================================

}

//=======================================
// Chargement des sprites
//=======================================
sf::Sprite *View::loadSprite(sf::Texture & texture, sf::Sprite & sprite, const std::string & path)
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

/*GraphicElement * View::loadSprite(sf::Texture &texture, GraphicElement * elem, const string &path) // à finir
{
    if (! texture.loadFromFile(path))
    {
        std::cerr << "ERREUR LORS DU CHARGEMENT DU SPRITE : " << path << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        elem = new GraphicElement(texture, 50, 450, 50 ,50);
    }
}*/

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

    _window->clear(sf::Color(_i%255, _j%255, _k%255, 0)); // affichage fond ecran dynamique

    _window->draw(_backgroundSprite);
    _ballElm->draw(_window);

    _window->draw(_texte);
    _window->draw(_getTime);

    _model->drawGraphicPositionBall(400, 10, _font, _window);

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

            _i += 1;    _j += 2;    _k += 3;

            result = true;
        }

        sf::Event event;
        while (_window->pollEvent(event)) {

            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();

                result = false;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space) && _model->getBall()->getPositionY() == 500)
            {
                _model->getBall()->setDeltaY(20);
                _model->jumpBall();
            }

        } // pollevent
    } // isOpen
    return result;
}

void View::treatKeyState()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _model->moveBall(false);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _model->moveBall(true);
}

void View::synchronize()
{
    int x, y;

    _model->getBallPosition(x, y);
    _ballElm->setPosition(x, y);
}
