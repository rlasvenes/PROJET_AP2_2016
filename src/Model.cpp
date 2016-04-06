#include "Model.h"
#include <iostream>
#include <fstream>

using namespace std;

const int SPEED = 10;

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
void Model::nextStep(){}

void Model::getBallPosition(int &x, int &y)
{
     x = _ball->getPositionX();
     y = _ball->getPositionY();
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
        std::cout << "balle position X (true): " << _ball->getPositionX() << std::endl;
        break;

    case false:
        _ball->setDeltaX(-5);
        _ball->move();
        std::cout << "balle position X (false): " << _ball->getPositionX() << std::endl;
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
    _ball->jump(); // à modifier car non fonctionnel
}

