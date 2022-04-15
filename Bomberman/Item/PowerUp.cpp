#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/PowerUp.h"

// constructeur par defaut
PowerUp::PowerUp() : Item()
{
    this->x = 0;
    this->y = 0;
    this->valeur = 9;
}

PowerUp::PowerUp(int x, int y) : Item()
{
    this->x = x;
    this->y = y;
    this->valeur = 9;
}

void PowerUp::effetBomb(Bomb &b)
{
    b.setDegat(b.getDegat() + 20);
}
