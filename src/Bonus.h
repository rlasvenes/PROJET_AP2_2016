#ifndef BONUS_H
#define BONUS_H

#include "View.h"

class Bonus
{
private:

    static unsigned int _id;
    unsigned int _currentId;

    unsigned int _type;

public:

    Bonus();
    Bonus(unsigned int type);

    unsigned int getType() const; // chaque bonus a un type

    void updateHeal(); // bonus qui redonne de la vie
    void updateCoins(); // correspond aux pièces jaune
    void updateDoubleScore(); // bonus qui double les points amassés

};

#endif // BONUS_H
