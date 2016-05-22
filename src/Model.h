#ifndef _MODEL_
#define _MODEL_

#include "View.h"

class Ball;
class MovableElement;
class Bonus;
class LogFile;

class Model {

private:

    int _w, _h;
    Ball * _ball;

    std::vector<MovableElement *> _element;
    std::vector<const MovableElement *> _new_elements;

    std::vector<Bonus *> _bonus;

    bool _pause;


public:

    Model(int w, int h);
    ~Model();

    void nextStep();

    // balle
    Ball * getBall();
    void getBallPosition(int &x, int &y);
    void drawGraphicPositionBall(int x, int y, sf::Font &font, sf::RenderWindow * window);

    void moveBall(bool left);
    void jumpBall();

    bool isJumping();
    void setJump(bool value);

    // obstacles
    std::vector<const MovableElement *> getNewMovableElements() const;
    void addElement(); // doit maj _element et _new_elements
    int getElementSize() const; // retourne _element.size()

    // bonus
    void addBonus(Bonus * b);

    // pause
    bool getPauseState() const;
    void setPauseState(bool value);

    // logfile
    LogFile * console;

};
#endif
