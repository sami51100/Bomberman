#include <iostream>
#include <cstdlib>
#include "entete/Bomb.h"

/**
 * @author Sami DRIOUCHE & Walid AIT-ERRAMI
 *
 */

/**
 * @brief Construct a new Bomb:: Bomb object
 *
 */
Bomb::Bomb()
{
    this->x = 0;
    this->y = 0;
    this->degat = 50;
}

Bomb::Bomb(int x, int y, int portee, int degat)
{
    this->x = x;
    this->y = y;
    this->portee = portee;
    this->degat = degat;
}

/**
 * @brief
 *
 * @return int
 */
int Bomb::getPortee() const
{
    return portee;
}

int Bomb::getX() const
{
    return x;
}

int Bomb::getY() const
{
    return y;
}
int Bomb::getDegat() const
{
    return degat;
}

int Bomb::getVarb() const
{
    return varb;
}
int Bomb::getBomb() const
{
    return bomb;
}
int Bomb::getExplosionH() const
{
    return explosionH;
}
int Bomb::getExplosionV() const
{
    return explosionV;
}
int Bomb::getCompteur() const
{
    return compteur;
}
int Bomb::getTmpi() const
{
    return tmpi;
}
int Bomb::getTmpj() const
{
    return tmpj;
}

void Bomb::setX(int x)
{
    this->x = x;
}

void Bomb::setY(int y)
{
    this->y = y;
}
void Bomb::setDegat(int degat)
{
    this->degat = degat;
}
void Bomb::setCompteur(int compteur)
{
    this->compteur = compteur;
}
void Bomb::setTmpi(int tmpi)
{
    this->tmpi = tmpi;
}
void Bomb::setTmpj(int tmpj)
{
    this->tmpj = tmpj;
}

/**
 * @brief
 *
 * @param portee
 */
void Bomb::setPortee(int portee)
{
    this->portee = portee;
}

void Bomb::BombePosee()
{
    poser = true;
}

/**
 * @brief surcharge de l'opérateur cout
 *
 * @param os
 * @param p
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const Bomb &p)
{
    os << "Bombe \ndegat : " << p.degat << "\nportee :" << p.portee << "\nposition : ( " << p.x << " ; " << p.y << " ) " << std::endl
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
std::istream &operator>>(std::istream &is, Bomb &p)
{
    cout << "entrez la position x de la bombe.\n";
    is >> p.x;
    cout << "entrez la position y de la bombe.\n";
    is >> p.y;

    return is;
}
