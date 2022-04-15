#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/Ghost.h"

// constructeur par defaut
Ghost::Ghost() : Ennemi()
{
    this->x = 2;
    this->y = 2;
    this->valeur = 4;
    this->Vivant = true;
    this->tmp = 0;
    this->nbvie = 30;
    this->nbattaque = 30;
}

Ghost::Ghost(int x, int y) : Ennemi()
{
    this->x = x;
    this->y = y;
    this->valeur = 4;
    this->Vivant = true;
    this->tmp = 0;
    this->nbvie = 30;
    this->nbattaque = 30;
}

void Ghost::attaquerPlayer(Bomberman &b)
{
    b.setVie(b.getVie() - nbattaque);
}

/**
 * @brief surcharge de l'opérateur cout
 *
 * @param os
 * @param p
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Ghost &p)
{
    os << "Ghost :\npoint de vie :" << p.nbvie << "\nposition : ( " << p.x << " ; " << p.y << " ) " << std::endl
       << std::endl;
    return os;
}

/**
 * @brief surcharge de l'opérateur cin
 *
 * @param is
 * @param p
 * @return std::istream&
 */
std::istream &operator>>(std::istream &is, Ghost &p)
{
    cout << "entrez la position x du ghost.\n";
    is >> p.x;
    cout << "entrez la position y du ghost.\n";
    is >> p.y;

    return is;
}

void Ghost::recevoirDegat(Bomb &boom)
{
    nbvie -= boom.getDegat();
}