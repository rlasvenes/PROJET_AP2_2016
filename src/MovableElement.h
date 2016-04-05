#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

class MovableElement
{

private:

    int _x;
    int _y;

    int _width;
    int _height;

    int _deltaX;
    int _deltaY;

public:

    MovableElement();

    void setDeltaX(int deltaX);
    void setDeltaY(int deltaY);

    int getPositionX() const;
    int getPositionY() const;
};

#endif // MOVABLEELEMENT_H
