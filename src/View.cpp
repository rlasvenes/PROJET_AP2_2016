#include "View.h"
#include "Model.h"
#include "Ball.h"
#include "GraphicElement.h"
#include "Menu.h"

#include <fstream>

#include <sstream>
#include <iostream>

using namespace std;

//=======================================
// Constructeur
//=======================================
View::View(int w, int h)
    : _w(w),_h(h)
{
    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner", sf::Style::Close);
    _window->setFramerateLimit(60);

    // DÉBUT centrer écran
    int screen_width = (sf::VideoMode::getDesktopMode().width - w)/2;
    int screen_height = (sf::VideoMode::getDesktopMode().height - h)/2;

    _window->setPosition(sf::Vector2i(screen_width, screen_height));
    //FIN centrer écran

    if (!_background.loadFromFile(BACKGROUND_IMAGE)) {
        std::cerr << "ERROR when loading image file: "
                  << BACKGROUND_IMAGE << std::endl;
        exit(EXIT_FAILURE);

    } else {
        _backgroundSprite.setTexture(_background);
        _backgroundSprite.setPosition(sf::Vector2f(0.f,0.f));
    }

    // ------------ Faire méthode load_sprite() -----------------------------------------------

    if (!_ball.loadFromFile(BALL_IMAGE)) {
        std::cerr << "ERROR when loading image file: "
                  << BALL_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    } else {

        _ballElm = new GraphicElement(_ball, 50, 450, 50 ,50);

        _ballElm->resize(50, 50);

        _ball.setSmooth(true);
    }

// ================================ DÉBUT TESTS ================================
    if (!_font.loadFromFile("../fonts/8_bit_font2.ttf"))
        std::cout << "ERREUR LORS DU CHARGEMENT DE 8_bit_font !" << std::endl;

    _texte.setFont(_font);
    _getTime.setFont(_font);

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

        // test class TcpClient


// ================================= FIN TESTS ==================================

    _menu = new Menu(600, 500, (_window->getSize().x) / 2, (_window->getSize().y) / 2);

}

//=======================================
// Destructeur
//=======================================
View::~View(){
    if(_window != NULL) // si la fenetre est ouverte
        delete _window; // alors on la "détruit"
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

    _window->clear();

    _window->draw(_backgroundSprite);
    _ballElm->draw(_window);

    _window->draw(_texte);
    _window->draw(_getTime);
    //_menu->draw(_window);


    _window->display();
}

//=======================================
// Traitement des evenements
//=======================================
bool View::treatEvents(){

    bool result = false;
    if(_window->isOpen()){
        result = true;

        sf::Event event;
        while (_window->pollEvent(event)) {

            _time = _clock.getElapsedTime();
            _getTime.setString("[ " + std::to_string((int) _time.asSeconds()) + " ]");

            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();

                result = false;
            }


            if (sf::Event::KeyPressed && !(sf::Event::KeyReleased))
            {
                int x , y;
                switch (event.key.code) {

                case sf::Keyboard::Left :
                    _model->moveBall(false);
                    break;

                case sf::Keyboard::Right:
                    _model->moveBall(true);
                    break;

                case sf::Keyboard::Space :
                    _model->jumpBall();
                    break;

                default:
                    break;
                }

//                if (sf::Event::KeyReleased)
//                {
//                    switch (event.key.code) {

//                    case sf::Keyboard::Left :
//                        _model->stopBall();
//                        break;

//                    case sf::Keyboard::Right:
//                        _model->stopBall();
//                        break;

//                    case sf::Keyboard::Space :
//                        //
//                        break;

//                    default:
//                        break;
//                    }
//                }

                _model->getBallPosition(x, y);
                _ballElm->setPosition(x, y);
            }

        }
    }
    return result;
}

