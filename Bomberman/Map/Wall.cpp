#include <iostream>
#include <cstdlib>
#include "entete/Wall.h"
#include <string>

using namespace std;

// constructeur par defaut
Wall::Wall() : Tile()
{
    this->x = 0;
    this->y = 0;
    this->valeur = 2;
}

Wall::Wall(int x, int y) : Tile()
{
    this->x = x;
    this->y = y;
    this->valeur = 2;
}
