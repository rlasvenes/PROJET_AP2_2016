#include "Bonus.h"

unsigned int Bonus::_id = 0;

Bonus::Bonus()
    : _currentId(_id++)
{

}

Bonus::Bonus(unsigned int type)
    : _currentId(_id++), _type(type)
{
    // faire un switch (type)
}

unsigned int Bonus::getType() const
{
    return _currentId;
}

void Bonus::updateHeal()
{
    // va ajouter de la vie au joueur si .contains(ballElm) == true
}

void Bonus::updateCoins()
{
    //va incrémenter le nb de pièce ramassé par joueur si picked == true
}

void Bonus::updateDoubleScore()
{
    // va mettre un booléen _doubleScore à true, OU

    // si picked == true, alors, _valeurPiece *= 2 durant 10 secondes;
}
