#ifndef _MODEL_
#define _MODEL_

#include "View.h"

class Ball;
class MovableElement;

class Model {

private:

    int _w, _h;
    Ball * _ball;

    std::vector<MovableElement *> _element;
    std::vector<const MovableElement *> _new_elements;

public:

    Model(int w, int h);
    ~Model();

    void nextStep();

    Ball * getBall();
    void getBallPosition(int &x, int &y);
    void drawGraphicPositionBall(int x, int y, sf::Font &font, sf::RenderWindow * window);

    void moveBall(bool left);
    void stopBall();
    void jumpBall();

    std::vector<const MovableElement *> getNewMovableElements() const;
    void addElement(); // doit maj _element et _new_elements
    int getSize() const;

};
#endif
