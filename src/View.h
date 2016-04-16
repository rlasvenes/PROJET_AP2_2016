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
#include "SlidingBackground.h"
#include "TcpClient.h"
#include "Menu.h"
#include "Audio.h"

const std::string PATH_BACKGROUND_IMAGE = "../img/city_3.png";
const std::string PATH_FOREGROUND_IMAGE = "../img/city_1.png";
const std::string PATH_BALL_IMAGE = "../img/ball3.png";
const std::string PATH_SOUND_TEST = "../sounds/rire.wav";
const std::string PATH_FONT = "../fonts/courier_prime.ttf";

const int FRAME_LIMIT = 60;

class Model;
class GraphicElement;
class SlidingBackground;
class Menu;

class View {

private:

    int _w, _h;

    sf::RenderWindow * _window;

    Model * _model;

    // éléments graphique

        // arrière-plan
    SlidingBackground * _slideBackground;

    sf::Texture _background;
    sf::Sprite _backgroundSprite;

        // premier plan
    SlidingBackground * _slideForeground;

    sf::Texture _foreground;
    sf::Sprite _foregroundSprite;

        // vitesse de défilement
    unsigned int _slidingSpeed;

    sf::Texture _ball;

    GraphicElement * _ballElm; // sprite de la balle avec sa texture
    GraphicElement * _shadow; // ombre de la balle

    std::map<const MovableElement *, GraphicElement * > _elementToGraphicElement;

    // polices + texte + temps
    sf::Font _font;
    sf::Text _texte;
    sf::Text _getTime;

    // horloge temps (chronomètre)
    sf::Clock _clock;
    sf::Time _time;

    // affichage + audio + couleur
    float _i, _j, _k;

    // menu + interface + pause
    Menu * _menu;

public:

    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();

    bool treatEvents();
    void treatKeyState();
    void synchronize();

    void setPositionCenter() const;
    void updateBallShadow(GraphicElement * element);

    sf::Sprite * loadSprite(sf::Texture & texture, sf::Sprite &sprite, const std::string & path);
    GraphicElement &loadSprite(sf::Texture & texture, GraphicElement * elem, const std::string & path); // à finir (voir .cpp)
    sf::Font * loadFont(sf::Font font, const std::string & path);

};
#endif
