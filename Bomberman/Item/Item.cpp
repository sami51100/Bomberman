#include "entete/Item.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Item::effetPlayer(Bomberman &b)
{
}

void Item::effetBomb(Bomb &b)
{
}

int Item::getX() const
{
    return x;
}

int Item::getY() const
{
    return y;
}
int Item::getValeur() const
{
    return valeur;
}

void Item::setX(int x)
{
    this->x = x;
}

void Item::setY(int y)
{
    this->y = y;
}

void Item::setValeur(int valeur)
{
    this->valeur = valeur;
}
