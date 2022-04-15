#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/Ennemi.h"

using namespace std;

int Ennemi::getX() const
{
    return x;
}

int Ennemi::getY() const
{
    return y;
}

int Ennemi::getNbvie() const
{
    return nbvie;
}
int Ennemi::getNbattaque() const
{
    return nbattaque;
}
int Ennemi::getValeur() const
{
    return valeur;
}

void Ennemi::setX(int x)
{
    this->x = x;
}

void Ennemi::setY(int y)
{
    this->y = y;
}
void Ennemi::setNbattaque(int nbattaque)
{
    this->nbattaque = nbattaque;
}

void Ennemi::setNbvie(int nbvie)
{
    this->nbvie = nbvie;
}

void Ennemi::attaquerPlayer(Bomberman &b)
{
    b.setVie(666);
}

void Ennemi::recevoirDegat(Bomb &boom)
{
}