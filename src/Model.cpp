#include "Model.h"

#include <iostream>
#include <fstream>

using namespace std;

//=========================================
// Constructeurs
//=========================================
Model::Model(int w, int h)
    :  _w(w), _h(h)
    , _pause(false)
{
    _ball = new Ball(50, _h/1.35, 70, 70, 0, 0);
    console = new LogFile();
}

//=========================================
// Destructeurs
//=========================================
Model::~Model()
{
    delete _ball;

    for (auto it : _element)
    {
        if (it != nullptr)
            delete it;
    }

    for (auto it : _new_elements)
    {
        if (it != nullptr)
            delete it;
    }

    delete console;
}

//=========================================
// Calcul la prochaine étape
//=========================================
void Model::nextStep()
{
    if (_ball->isJumping() && !getPauseState())
    {
        jumpBall();
        _ball->setDeltaY(_ball->getDeltaY() - 1);

        if (_ball->getDeltaY() < (_ball->maxJump()) * (-1))
        {
            _ball->setJump(false);
        }
    }

    for (auto it : _element)
    {

        it->move();

        if (this->getPauseState())
        {
            it->setSlidingSpeed(it->getSlidingSpeed()/5 * !this->getPauseState());
        }
        else
            it->setSlidingSpeed(-8);

        if ((it->getPositionX() + it->getSizeWidth() < 0))
        {
            _element.erase(_element.begin());
            _new_elements.erase(_new_elements.begin());
        }

        if (_ball->treatColision(it))        {
            vector<MovableElement *>::iterator it2 = find( _element.begin(), _element.end(), it );
            vector<const MovableElement *>::iterator it3 = find( _new_elements.begin(), _new_elements.end(), it );
            _element.erase(it2);
            _new_elements.erase(it3);
        }

    }
}

//=========================================
// Récupération coordonnées balle
//=========================================
void Model::getBallPosition(int &x, int &y)
{
    x = _ball->getPositionX();
    y = _ball->getPositionY();
}

//=========================================
// Affichage graphique coord. balle
//=========================================
void Model::drawGraphicPositionBall(int x, int y, sf::Font & font, sf::RenderWindow * window) // a optimiser avec un Menu::Menu()
{
    int bx, by;
    this->getBallPosition(bx, by);

    std::string posX = std::to_string(bx);
    std::string posY = std::to_string(by);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(26);
    text.setColor(sf::Color::White);
    text.setString("( " + posX + ", " + posY + " )");

    sf::RectangleShape rect;
    rect.setFillColor(sf::Color(0, 0, 0, 170));
    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(text.getString().getSize() * (text.getCharacterSize()), 60));

    text.setPosition(rect.getPosition().x + (text.getString().getSize() * text.getCharacterSize()) / 5, rect.getPosition().y + 10);

    window->draw(rect);
    window->draw(text);
}

//=========================================
// Récupération de l'objet Ball
//=========================================
Ball * Model::getBall()
{
    return _ball;
}

//=========================================
// Fonction de déplacement balle
//=========================================
void Model::moveBall(bool left)
{
    switch (left) {

    case true:
        _ball->setDeltaX(5);
        _ball->move();
        break;

    case false:
        _ball->setDeltaX(-5);
        _ball->move();
        break;

    default:
        break;
    }

}

//=========================================
// Fonction de saut balle
//=========================================
void Model::jumpBall()
{
    _ball->jump();
}


// ==============================================================================================================
//                                          ELEMENTS / OBSTACLES
// ==============================================================================================================

//=========================================
// Fonction ajout élément déplacable
//=========================================
void Model::addElement()
{

    MovableElement * elm = new MovableElement(_w, this->SOL - 15, 50, 50); // je ne sais pas pourquoi -15, mais y'a une diff entre sol et movable

    if (!this->getPauseState())
    {
        _element.push_back(elm);
        _new_elements.push_back(elm);
    }
}

std::vector<const MovableElement *> Model::getNewMovableElements() const
{
    return _new_elements;
}
//=========================================
// Getter taille du conteneur des éléments
//=========================================
int Model::getElementSize() const
{
    return _element.size();
}

bool Model::getPauseState() const
{
    return _pause;
}

void Model::setPauseState(bool value)
{
    _pause = value;
}
