#include "View.h"
#include "Model.h"
#include "Ball.h"
#include "GraphicElement.h"
#include "Menu.h"
#include "Audio.h"

#include <fstream>
#include <sstream>
#include <iostream>

#define PI 3.14159265359*1.f
#define Console _model->console
#define BLACK sf::Color(0, 0, 0)
#define GRIS sf::Color(0, 0, 0, 168)

using namespace std;

AnimatedGraphicElement * ag;
AnimatedGraphicElement * ag2;

//=======================================
// Constructeur
//=======================================
View::View(int w, int h, unsigned int mode)
    : _w(w), _h(h), _mode(mode), _slidingSpeed(5), temps(0), _i(1) , _j(0) , _k(0)
{
    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner - Projet POO 2015/2016", sf::Style::Close);
    _window->setFramerateLimit(FRAME_LIMIT);

    loadSprite(_background, _backgroundSprite, PATH_BACKGROUND_IMAGE);
    _slideBackground = new SlidingBackground(_background, _w, _h, _slidingSpeed/4);

    loadSprite(_foreground, _foregroundSprite, PATH_FOREGROUND_IMAGE);
    _slideForeground = new SlidingBackground(_foreground, _w, _h, _slidingSpeed/2);


    if (!sb.loadFromFile(PATH_SOUND_TEST))
        std::cerr << "ERROR LOADING SOUND " << std::endl;
    else
    {
        m.setBuffer(sb);

        m.setLoop(true);
        m.play();
    }

    _pauseMenu = nullptr;

    switch (_mode)
    {
    case 1:
        loadGame();
        loadMenu();
        break;

    case 2:  break;

    default: break;
    }
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

    delete _model;
    delete &_slideBackground;

    delete &_background;
    delete &_backgroundSprite;

    // premier plan
    delete _slideForeground;

    delete &_foreground;
    delete &_foregroundSprite;

    // obstacle
    delete &_obstacle;
    delete &_obstacleSprite;

    delete &_ball;

    delete _ballElm;
    delete _shadow;
}

//=======================================
// Accesseurs en écriture
//=======================================
void View::setModel(Model * model){
    _model = model;

    Console->log("Initialisation modèle/vue");
}

//=======================================
// Fonction de dessin principale
//=======================================
void View::draw() {

    drawFadedColor();

    switch (_mode) {

    case 1: drawMenu();         break;
    case 2: drawGame();         break;
    case 3: drawScoreMenu();    break;

    default:                    break;

    }

    _window->display();
}

//=======================================
// Traitement des evenements
//=======================================
bool View::treatEvents(){

    bool result = false;
    if(_window->isOpen()){
        {
            _i += (2 * PI) / 555 ;      _j += (2 * PI) / 666;    _k += (2 * PI) / 777;

            switch (_mode) {

            case 1: /* do nothing */    break;
            case 2: updateGame();   break;
            case 3: /* do nothing */    break;

            default:                    break;

            }
            result = true;
        }

        sf::Event event;
        while (_window->pollEvent(event)) {

            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && ((event.key.code == sf::Keyboard::Escape)) && ((_mode == 1) || (_mode == 2))))
            {
                _window->close();
                result = false;
            }

            switch (_mode) {

            case 1: treatEventMenu(event);      break;
            case 2: treatEventGame(event);      break;
            case 3: treatEventScoreMenu(event); break;

            default :
                break;
            }
        }
    }

    return result;
}

void View::treatKeyState()
{
    switch (_mode) {

    case 1:
        break;

    case 2:
    {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && !_model->getPauseState())
        {
            _model->moveBall(false);
            _ballElm->rotate(0.1);
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !_model->getPauseState())
        {
            _model->moveBall(true);
            _ballElm->rotate(2);
        }

        _shadow->setPosition(_ballElm->getPosition().x, _shadow->getPosition().y);

    }
        break;

    case 3:
        break;

    default:
        break;
    }
}    

void View::synchronize()
{
    switch (_mode) {

    case 1: /* do nothing */    break;
    case 2: synchronizeGame();  break;
    case 3: /* do nothing */    break;

    default:                    break;

    }
}

void View::setPositionCenter() const
{
    int screen_width = (sf::VideoMode::getDesktopMode().width - _w)/2;
    int screen_height = (sf::VideoMode::getDesktopMode().height - _h)/2;

    _window->setPosition(sf::Vector2i(screen_width, screen_height));
}

void View::updateBallShadow(GraphicElement * element)
{
    if (_model->getBall()->isJumping())
    {
        if (_model->getBall()->getDeltaY() > 0)
        {
            element->resize(element->getSizeWidth() + 3,
                            element->getSizeHeight() + 3);
            element->setOpacity(element->getOpacity() - 1);
            element->setColor(sf::Color(128, 128, 128, element->getOpacity()));
        }
        else if (_model->getBall()->getDeltaY() < 0)
        {
            element->resize(element->getSizeWidth() - 3,
                            element->getSizeHeight() - 3);
            element->setOpacity(element->getOpacity() + 2);
            element->setColor(sf::Color(128, 128, 128, element->getOpacity() ));
        }
    }
    else
    {
        element->setOpacity(50);
        element->resize(70, 45);
    }
}

unsigned int View::getStateMode() const { return _mode; }

void View::loadMenu()
{
    loadSprite(_menuTexture, _menuIntro, PATH_MENU_IMAGE);

    _menuIntro = new GraphicElement(_menuTexture, 0, 0, 0, 0);
    _menuIntro->setPosition((_w - _menuIntro->getTexture()->getSize().x) / 2,
                            ((_h - _menuIntro->getTexture()->getSize().y) / 2) - 200);

    XOR_EncryptDecryption Encrypt; // see https://www.stringencrypt.com/
    std::string res = Encrypt.encrypt("password");
    Console->log(" \"password\" become : " + res);

    ag = new AnimatedGraphicElement(200, 200, 50, 50, PATH_ANIMATED_BALL, 0);
    ag2 = new AnimatedGraphicElement(255, 200, 50, 50, PATH_ANIMATED_BALL, 3);

    // chargement des images des bouttons

    loadSprite(_playButton, _playButtonElm, PATH_PLAY_BTN_IMAGE);
    _playButtonElm = new GraphicElement(_playButton, 0, _h/3, 0, 0);
    _playButtonElm->setTextureRect(sf::IntRect(196, 0, 202, 82));
    _playButtonElm->setPosition(_w/2 - _playButtonElm->getTextureRect().width, _h/3);

    loadSprite(_quitButton, _quitButtonElm, PATH_QUIT_BTN_IMAGE);
    _quitButtonElm = new GraphicElement(_quitButton, _playButtonElm->getPosition().x + _playButtonElm->getTextureRect().width , _h/3, 0, 0);
    _quitButtonElm->setTextureRect(sf::IntRect(196, 0, 202, 82));

    loadSprite(_shopButton, _shopButtonElm, PATH_SHOP_BTN_IMAGE);

    loadSprite(_scoreButton, _scoreButtonElm, PATH_SCORE_BTN_IMAGE);
    _scoreButtonElm = new GraphicElement(_scoreButton, 200, _h/3 + _playButtonElm->getTexture()->getSize().y + 10, 0, 0);
    _scoreButtonElm->setTextureRect(sf::IntRect(390, 0, 400, 92));
    _scoreButtonElm->setPosition((_w - _scoreButtonElm->getTexture()->getSize().x/2)/2, _scoreButtonElm->getPosition().y);
}

void View::loadGame()
{
    // ========================== JEU =============================

    loadSprite(_backButton, _backButtonElm, PATH_BACK_BTN_IMAGE);
    _backButtonElm = new GraphicElement(_backButton, 50, 50, 0, 0);

    _scoreMenu = new Menu(_w - 100, _h - 100 - 180, _w/2, _h/2, sf::Color(0, 0, 0, 128), "BEST SCORES"); // 100 <=> margin

    loadSprite(_ball, _ballElm, PATH_BALL_IMAGE);
    _ballElm = new GraphicElement(_ball, 100, SOL, 70 ,70);
    _ballElm->setOrigin(_ballElm->getTexture()->getSize().x/2, _ballElm->getTexture()->getSize().y/2);
    _ballElm->resize(70, 70);

    _shadow = new GraphicElement(_ball, 50, SOL + 25, 70, 70); // 25 es le nb de pixel de diff entre ball et ombre
    _shadow->setOrigin(_shadow->getTexture()->getSize().x/2, _shadow->getTexture()->getSize().y/2);
    _shadow->resize(70, 45);
    _shadow->setOpacity(50);
    _shadow->setColor(sf::Color(128, 128, 128, _shadow->getOpacity()));

    loadSprite(_obstacle, _obstacleSprite, PATH_OBSTACLE_IMAGE);

    // ================================ DÉBUT TESTS ================================

    if (!_font.loadFromFile(PATH_FONT))
        std::cout << "ERREUR LORS DU CHARGEMENT DE " << PATH_FONT << std::endl;

    _getTime.setFont(_font);
    _getTime.setPosition(40, 25);
    _getTime.setColor(sf::Color::White);

    // ================================= FIN TESTS ==================================

    // faire un sf::Text, et faire diminuer l'opacity jusqu'à 0
}



//synchro
void View::synchronizeGame()
{
    int x, y;
    _model->getBallPosition(x, y);
    _ballElm->setPosition(x, y);

    for (const auto it : _model->getNewMovableElements())
    {
        GraphicElement * elm = new GraphicElement(_obstacle, it->getPositionX(), it->getPositionY(), 50, 50);
        elm->resize(50, 50);
        _elementToGraphicElement[it] = elm;

        if ((it->getPositionX() + _elementToGraphicElement.at(it)->getSizeWidth() < 0))
        {
            _elementToGraphicElement.erase(it);
        }
    }
}



//treat
void View::treatEventMenu(sf::Event event)
{
    if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && (_playButtonElm->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)))
    {
        Console->log("Click \"play\" button ");
        _clock.restart();
        _mode = 2;
        _slideForeground->setDistanceTraveled(0);
    }

    if (((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && (_quitButtonElm->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))))
    {
        Console->log("Click \"quit\" button");
        Console->log("spent " + std::to_string(_clock.getElapsedTime().asSeconds()) + "seconds at menu");
        _window->close();
    }

    if (((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && (_scoreButtonElm->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))))
    {
        Console->log("Click \"best scores\" button");
        _mode = 3;
    }

    if ((event.type == sf::Event::MouseMoved) && (_quitButtonElm->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)))
    {
        _quitButtonElm->setColor(sf::Color(128, 128, 128, 168));
    }
    else
    {
        _quitButtonElm->setColor(sf::Color(255, 255, 255, 255));
    }

    if ((event.type == sf::Event::MouseMoved) && (_playButtonElm->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)))
    {
        _playButtonElm->setColor(sf::Color(128, 128, 128, 168));
    }
    else
    {
        _playButtonElm->setColor(sf::Color(255, 255, 255, 255));
    }

    if ((event.type == sf::Event::MouseMoved) && (_scoreButtonElm->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)))
    {
        _scoreButtonElm->setColor(sf::Color(128, 128, 128, 168));
    }
    else
    {
        _scoreButtonElm->setColor(sf::Color(255, 255, 255, 255));
    }
}

void View::treatEventScoreMenu(sf::Event event)
{
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
    {
        _mode = 1;
    }

    if (((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && (_backButtonElm->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))))
    {
        Console->log("Click \"best scores\" button");
        _mode = 1;
    }

    if ((event.type == sf::Event::MouseMoved) && (_backButtonElm->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)))
    {
        _backButtonElm->setColor(sf::Color(128, 128, 128, 168));
    }
    else
    {
        _backButtonElm->setColor(sf::Color(255, 255, 255, 255));
    }
}

void View::treatEventGame(sf::Event event)
{
    if (((event.type == sf::Event::KeyPressed) &&
         (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up) &&
         _model->getBall()->getPositionY() == SOL) && !_model->getPauseState()) // 500 == SOL
    {
        _model->getBall()->setJump(true);
        _model->getBall()->setDeltaY(_model->getBall()->maxJump());
    }

    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::P))
    {
        _model->setPauseState(!_model->getPauseState());

        if (_model->getPauseState())
            _pauseMenu = new Menu(_w/2, _h/2, _w/2, _h/2, GRIS, "PAUSE");
        else
            _pauseMenu = nullptr;

    }

    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Add))
    {
        _model->addElement();
    }

    if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left) && (_ballElm->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)))
    {
        _model->getBall()->setTarget(true);
    }

    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::B))
    {
        Bonus * b = new Bonus();
        Console->log("Valeur de l'identifiant du Bonus : " + std::to_string(b->getType()));
    }
}

void View::treatEventGameOver(sf::Event event)
{

}



//update
void View::updateGame()
{
    int p = _clock.getElapsedTime().asSeconds();
    _getTime.setString("[ TIME : " + std::to_string( p ) + " ]");

    _ballElm->rotate(3 * !(_model->getPauseState()));
    _slideBackground->setSpeed((_slidingSpeed/4) * !_model->getPauseState());
    _slideForeground->setSpeed((_slidingSpeed/2) * !_model->getPauseState());

    if (p !=  temps)
    {
        if (temps % (rand()%3+1) == 0)
        {
            _model->addElement();
            Console->log("adding an element");
        }

        temps++;
    }

    if (!_model->getPauseState())
        updateBallShadow(_shadow);
}



//draw
void View::drawMenu()
{
    _menuIntro->draw(_window);
    _playButtonElm->draw(_window);
    _quitButtonElm->draw(_window);
    _scoreButtonElm->draw(_window);

    // splash->draw(_window);

    ag->draw(_window);
    ag2->draw(_window);
}

void View::drawGame()
{
    _shadow->draw(_window);
    _ballElm->draw(_window);

    _window->draw(_texte);
    _window->draw(_getTime);

    for (auto it : _elementToGraphicElement)
    {
        _window->draw(*it.second);
        if (_model->getBall()->treatColision(it.first)) // faire un find et si il trouve pas faire un _elementToGrtaphicElement.erase(it.first)
        {
            Console->log("collision");
            _elementToGraphicElement.erase(it.first);
        }
    }

    if (_pauseMenu != nullptr)
        _pauseMenu->draw(_window);


    _model->drawGraphicPositionBall(350, 10, _font, _window);
}

void View::drawScoreMenu()
{
    _backButtonElm->draw(_window);
    _scoreMenu->draw(_window);
}

void View::drawFadedColor()
{
    _window->clear(sf::Color(abs(255*sin(_i)), abs(255*sin(_j)), abs(255*sin(_k)), 0)); // affichage fond ecran dynamique
    _slideBackground->draw(_window);
    _slideForeground->draw(_window);
}
