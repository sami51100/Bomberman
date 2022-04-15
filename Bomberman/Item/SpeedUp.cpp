#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/SpeedUp.h"

// constructeur par defaut
SpeedUp::SpeedUp() : Item()
{
    this->x = 0;
    this->y = 0;
    this->valeur = 12;
}

SpeedUp::SpeedUp(int x, int y) : Item()
{
    this->x = x;
    this->y = y;
    this->valeur = 12;
}

void SpeedUp::effetPlayer(Bomberman &b)
{
    b.setVitesse(b.getVitesse() + 1);
}