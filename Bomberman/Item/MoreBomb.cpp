#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/MoreBomb.h"

// constructeur par defaut
MoreBomb::MoreBomb() : Item()
{
    this->x = 0;
    this->y = 0;
    this->valeur = 8;
}

MoreBomb::MoreBomb(int x, int y) : Item()
{
    this->x = x;
    this->y = y;
    this->valeur = 8;
}

void MoreBomb::effetPlayer(Bomberman &b)
{
    b.tabB.push_back(b.boom);
    b.setNbBomb(b.getNbBomb() + 1);
}
