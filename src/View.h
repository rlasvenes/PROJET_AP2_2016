#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <map>
#include <iomanip>
#include <cassert>



#include "Ball.h"
#include "Model.h"
#include "GraphicElement.h"
#include "SlidingBackground.h"
#include "TcpClient.h"
#include "Menu.h"
#include "Audio.h"
#include "LogFile.h"
#include "XOR_EncryptDecryption.h"
#include "SplashText.h"
#include "Bonus.h"
#include "AnimatedGraphicElement.h"

#include "constantes.h"

/*

    Voir library Thor :: bromeon

*/

class Model;
class GraphicElement;
class SlidingBackground;
class Menu;
class Audio;
class XOR_EncryptDecryption;
class SplashText;

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

        // map obstacle
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

    sf::Texture _backButton;
    GraphicElement * _backButtonElm;

    sf::Texture _shopButton;
    GraphicElement * _shopButtonElm;

    Menu * _pauseMenu;
    Menu * _scoreMenu;

    // polices + texte + temps
    sf::Font _font;
    sf::Text _texte;
    sf::Text _getTime;

    // horloge temps (chronomètre)
    sf::Clock _clock;
    sf::Time _time;
    int temps;

    // affichage + audio + couleur
    float _i, _j, _k;

    sf::Sound m;
    sf::SoundBuffer sb;

    //SplashText * splash;

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
    GraphicElement & loadSprite(sf::Texture & texture, GraphicElement * elem, const std::string & path); // à finir (voir .cpp)
    sf::Font * loadFont(sf::Font font, const std::string & path);

    unsigned int getStateMode() const;

    void loadMenu();
    void loadGame();



    // méthodes de mis à jours des données du jeu


        // synchronisation
    void synchronizeGame();

        // traitement
    void treatEventMenu(sf::Event event);
    void treatEventScoreMenu(sf::Event event);
    void treatEventGame(sf::Event event);
    void treatEventGameOver(sf::Event event);

        // update
    void updateGame();

        // draw
    void drawFadedColor();
    void drawMenu();
    void drawScoreMenu();
    void drawGame();
    void drawGameOver();

};
#endif
