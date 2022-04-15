#include <iostream>
#include <string>
#include <cstdlib>
#include "entete/Monster.h"

// constructeur par defaut
Monster::Monster() : Ennemi()
{
    this->x = 2;
    this->y = 2;
    this->valeur = 6;
    this->Vivant = true;
    this->nbvie = 50;
}

Monster::Monster(int x, int y) : Ennemi()
{
    this->x = x;
    this->y = y;
    this->valeur = 6;
    this->Vivant = true;
    this->nbvie = 50;
}

void Monster::attaquerPlayer(Bomberman &b)
{
    b.setVie(b.getVie() - 40);
}

/**
 * @brief surcharge de l'opérateur cout
 *
 * @param os
 * @param p
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Monster &p)
{
    os << "Monstre :\npoint de vie :" << p.nbvie << "\nposition : ( " << p.x << " ; " << p.y << " ) " << std::endl
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
std::istream &operator>>(std::istream &is, Monster &p)
{
    cout << "entrez la position x du monstre.\n";
    is >> p.x;
    cout << "entrez la position y du monstre.\n";
    is >> p.y;

    return is;
}

void Monster::recevoirDegat(Bomb &boom)
{
    this->setNbvie(this->getNbvie() - boom.getDegat());
}