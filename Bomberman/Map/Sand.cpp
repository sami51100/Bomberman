#include <iostream>
#include <cstdlib>
#include "entete/Sand.h"
#include <string>

using namespace std;

// constructeur par defaut
Sand::Sand() : Tile()
{
    this->x = 1;
    this->y = 1;
    this->valeur = 3;
    this->Vivant = true;
}

Sand::Sand(int x, int y) : Tile()
{
    this->x = x;
    this->y = y;
    this->valeur = 3;
    this->Vivant = true;
}

int Sand::getNbVie() const
{
    return nbvie;
}

void Sand::setNbVie(int nbvie)
{
    this->nbvie = nbvie;
}
