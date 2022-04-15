#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/ScaleUp.h"

// constructeur par defaut
ScaleUp::ScaleUp() : Item()
{
    this->x = 0;
    this->y = 0;
    this->valeur = 10;
}

ScaleUp::ScaleUp(int x, int y) : Item()
{
    this->x = x;
    this->y = y;
    this->valeur = 10;
}

void ScaleUp::effetBomb(Bomb &b)
{
    b.setPortee(b.getPortee() + 1);
}