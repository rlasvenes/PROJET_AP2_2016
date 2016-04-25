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
const std::string PATH_OBSTACLE_IMAGE = "../img/obstacle.png";

const std::string PATH_SOUND_TEST = "../sounds/runner_theme.wav";
const std::string PATH_FONT = "../fonts/8_bit_font2.ttf";

const std::string PATH_MENU_IMAGE = "../img/Runner3.png";
const std::string PATH_PLAY_BTN_IMAGE = "../img/play_button.png";
const std::string PATH_QUIT_BTN_IMAGE = "../img/quit_button.png";
const std::string PATH_SHOP_BTN_IMAGE = "../img/shop_button.png";
const std::string PATH_SCORE_BTN_IMAGE = "../img/scores_button.png";

const int FRAME_LIMIT = 600;

class Model;
class GraphicElement;
class SlidingBackground;
class Menu;
class Audio;

class View {

private:

    int _w, _h;

    sf::RenderWindow * _window;

    Model * _model;

    unsigned int _mode;

    // éléments graphique

        // arrière-plan
    SlidingBackground * _slideBackground;

    sf::Texture _background;
    sf::Sprite _backgroundSprite;

        // premier plan
    SlidingBackground * _slideForeground;

    sf::Texture _foreground;
    sf::Sprite _foregroundSprite;

        // obstacle
    sf::Texture _obstacle;
    sf::Sprite _obstacleSprite;

        // vitesse de défilement
    unsigned int _slidingSpeed;

    sf::Texture _ball;

    GraphicElement * _ballElm; // sprite de la balle avec sa texture
    GraphicElement * _shadow; // ombre de la balle

    std::map<const MovableElement *, GraphicElement * > _elementToGraphicElement;

        // menu + bouttons
    sf::Texture _menuTexture;
    GraphicElement * _menuIntro;

    sf::Texture _playButton;
    GraphicElement * _playButtonElm;

    sf::Texture _quitButton;
    GraphicElement * _quitButtonElm;

    sf::Texture _scoreButton;
    GraphicElement * _scoreButtonElm;

    sf::Texture _shopButton;
    GraphicElement * _shopButtonElm;

    // polices + texte + temps
    sf::Font _font;
    sf::Text _texte;
    sf::Text _getTime;

    // horloge temps (chronomètre)
    sf::Clock _clock;
    sf::Time _time;

    // affichage + audio + couleur
    float _i, _j, _k;
    Audio * _audio;

public:

    View(int w, int h, unsigned int mode);
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

    unsigned int getStateMode() const;
    void loadGame();

};
#endif
