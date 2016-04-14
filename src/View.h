#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <map>

#include "Ball.h"
#include "Model.h"
#include "GraphicElement.h"
#include "TcpClient.h"
#include "Menu.h"
#include "Audio.h"

const std::string BACKGROUND_IMAGE = "../img/city_3.png";
const std::string BALL_IMAGE = "../img/ball3.png";
const std::string SOUND_TEST = "../sounds/rire.wav";

class Model;
class GraphicElement;
class Menu;

class View {

private:

    int _w, _h;

    sf::RenderWindow * _window;

    Model * _model;

    // éléments graphique
    sf::Texture _background;
    sf::Sprite _backgroundSprite;

    sf::Texture _ball;
    sf::Sprite _ballSprite;

    GraphicElement * _ballElm;

    std::map<const MovableElement *, GraphicElement * > _elementToGraphicElement;

    // polices + texte + temps
    sf::Font _font;
    sf::Text _texte;
    sf::Text _getTime;

    // horloge
    sf::Clock _clock;
    sf::Time _time;

    // affichage + audio + couleur
    float _i, _j, _k;

    // menu + interface
    Menu * _menu;

public:

    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    bool treatEvents();

    void treatKeyState();

    void synchronize();

    sf::Sprite * loadSprite(sf::Texture & texture, sf::Sprite &sprite, const std::string & path);
    GraphicElement * loadSprite(sf::Texture & texture, GraphicElement * elem, const std::string & path); // à finir (voir .cpp)

    sf::Font * loadFont(sf::Font font, const std::string & path);
};
#endif
