#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/Bowman.h"

// constructeur par defaut
Bowman::Bowman() : Ennemi()
{
    this->x = 2;
    this->y = 2;
    this->valeur = 5;
    this->Vivant = true;
    this->nbvie = 40;
    this->nbattaque = 40;
}

Bowman::Bowman(int x, int y) : Ennemi()
{
    this->x = x;
    this->y = y;
    this->valeur = 5;
    this->Vivant = true;
    this->nbvie = 40;
    this->nbattaque = 40;
}

void Bowman::attaquerPlayer(Bomberman &b)
{
    b.setVie(b.getVie() - 50);
}

std::ostream &operator<<(std::ostream &os, const Bowman &p)
{
    os << "Bowman :\npoint de vie :" << p.nbvie << "\nposition : ( " << p.x << " ; " << p.y << " ) " << std::endl
       << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Bowman &p)
{
    cout << "entrez la position x du Bowman.\n";
    is >> p.x;
    cout << "entrez la position y du Bowman.\n";
    is >> p.y;

    return is;
}

void Bowman::recevoirDegat(Bomb &boom)
{
    nbvie -= boom.getDegat();
}