#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

class MovableElement // a compléter avec atelier
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
    MovableElement(int x, int y, int w, int h);

    void setDeltaX(int deltaX);
    void setDeltaY(int deltaY);

    int getDeltaX() const;
    int getDeltaY() const;

    int getPositionX() const;
    int getPositionY() const;

    void move();
};

#endif // MOVABLEELEMENT_H
