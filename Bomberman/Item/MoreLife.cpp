#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/MoreLife.h"

// constructeur par defaut
MoreLife::MoreLife() : Item()
{
    this->x = 0;
    this->y = 0;
    this->valeur = 7;
}

MoreLife::MoreLife(int x, int y) : Item()
{
    this->x = x;
    this->y = y;
    this->valeur = 7;
}

void MoreLife::effetPlayer(Bomberman &b)
{
    b.setVie(b.getVie() + 100);
}
