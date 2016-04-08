#include "Model.h"

#include <iostream>
#include <fstream>

using namespace std;

//=======================================
// Constructeurs
//=======================================
Model::Model(int w, int h)
    :  _w(w), _h(h)
{
    _ball = new Ball(20, 500, 35, 35, 0, 0);
}

//=======================================
// Destructeurs
//=======================================
Model::~Model(){}

//=======================================
// Calcul la prochaine étape
//=======================================
void Model::nextStep()
{
    _ball->setDeltaY(_ball->getDeltaY() - 1);
}

void Model::getBallPosition(int &x, int &y)
{
    x = _ball->getPositionX();
    y = _ball->getPositionY();
}

void Model::drawGraphicPositionBall(int x, int y, sf::Font & font, sf::RenderWindow * window) // centrage pas parfait
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

    text.setPosition(rect.getPosition().x + (rect.getSize().x - text.getString().getSize() * text.getCharacterSize()/2) / 2 , rect.getPosition().y + 10);

    window->draw(rect);
    window->draw(text);
}

Ball * Model::getBall()
{
    return _ball;
}

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

void Model::stopBall()
{
    this->_ball->stop();
}

void Model::jumpBall()
{
    _ball->jump();
    std::cout << "SAUT !! DeltaY = " << _ball->getDeltaY() << std::endl;
}

