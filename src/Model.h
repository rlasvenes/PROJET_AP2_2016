#ifndef _MODEL_
#define _MODEL_

#include "View.h"

class Ball;
class Model {

private:

    int _w, _h;
    Ball * _ball;

public:

    Model(int w, int h);
    ~Model();

    void nextStep();

    void getBallPosition(int &x, int &y);

    void moveBall(bool left);
    void jumpBall();

};
#endif
