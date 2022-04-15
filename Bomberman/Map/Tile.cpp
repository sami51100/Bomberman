#include "entete/Tile.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int Tile::getX() const
{
    return x;
}

int Tile::getY() const
{
    return y;
}

int Tile::getValeur() const
{
    return valeur;
}

void Tile::setX(int x)
{
    this->x = x;
}

void Tile::setY(int y)
{
    this->y = y;
}
