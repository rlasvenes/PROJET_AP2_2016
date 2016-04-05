#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Ball.h"
#include "Model.h"
#include "GraphicElement.h"
#include "TcpClient.h"
#include "Menu.h"

const std::string BACKGROUND_IMAGE = "../img/city.png";
const std::string BALL_IMAGE = "../img/ball.png";

class Model;
class GraphicElement;
class Menu;

class View {

private:

    int _w, _h;

    sf::RenderWindow * _window;

    Model * _model;

    sf::Texture _background;
    sf::Sprite _backgroundSprite;

    sf::Texture _ball;
    sf::Sprite _ballSprite;

    GraphicElement * _ballElm;

    //===========================
    //
    //       TEST POLICES
    //
    //===========================

    sf::Font _font;
    sf::Text _texte;
    sf::Text _getTime;

    sf::Clock _clock;
    sf::Time _time;

    Menu * _menu;

public:

    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    bool treatEvents();

    // TESTS

};
#endif
