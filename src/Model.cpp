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
    _ball = new Ball(50, 500, 70, 70, 0, 0);
}

//=========================================
// Destructeurs
//=========================================
Model::~Model(){}

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

        if ((it->getPositionX() + it->getSizeWidth() < 0))
        {
            _element.erase(_element.begin());
            _new_elements.erase(_new_elements.begin());
        }

        std::cout << "_element.size() = " << _element.size() << std::endl;
        std::cout << "_new_elements.size() = " << _new_elements.size() << std::endl;
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
void Model::drawGraphicPositionBall(int x, int y, sf::Font & font, sf::RenderWindow * window)
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

    MovableElement * elm = new MovableElement(_w, _h/2, 100, 100);
    _element.push_back(elm);
    _new_elements.push_back(elm);

}

std::vector<const MovableElement *> Model::getNewMovableElements() const
{
    return _new_elements;
}
//=========================================
// Getter taille du conteneur des éléments
//=========================================
int Model::getSize() const
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
