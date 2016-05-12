#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

class MovableElement // a compléter avec atelier
{

protected:

    int _x;
    int _y;

    int _width;
    int _height;

    int _deltaX;
    int _deltaY;

    unsigned int _slidingSpeed;

public:

    MovableElement();
    MovableElement(int x, int y, int w, int h);

    ~MovableElement();

    void setDeltaX(int deltaX);
    void setDeltaY(int deltaY);

    int getDeltaX() const;
    int getDeltaY() const;

    int getPositionX() const;
    int getPositionY() const;

    float getSizeWidth() const;
    float getSizeHeight() const;

    void move();
    unsigned int getSlidingSpeed() const;
    void setSlidingSpeed(unsigned int value);
};

#endif // MOVABLEELEMENT_H
