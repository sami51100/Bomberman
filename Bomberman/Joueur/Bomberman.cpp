#include <iostream>
#include <cstdlib>
#include "entete/Bomberman.h"

Bomberman::Bomberman()
{
    this->nom = "sami";
    this->x = 5;
    this->y = 5;
    tabB.assign(nbBomb, boom);
    this->Vivant = true;
}

Bomberman::Bomberman(std::string nom, int vie, int x, int y, int vitesse, int nbBomb, Bomb boom)
{
    this->nom = nom;
    this->x = x;
    this->y = y;
    this->vitesse = vitesse;
    this->vie = vie;
    this->nbBomb = nbBomb;
    tabB.assign(nbBomb, boom);
    this->Vivant = true;
}

int Bomberman::getVie() const
{
    return vie;
}

void Bomberman::setVie(int vie)
{
    this->vie = vie;
}

int Bomberman::getX() const
{
    return x;
}

int Bomberman::getY() const
{
    return y;
}
int Bomberman::getVitesse() const
{
    return vitesse;
}
int Bomberman::getNbBomb() const
{
    return nbBomb;
}
int Bomberman::getValeur() const
{
    return valeur;
}

void Bomberman::setX(int x)
{
    this->x = x;
}

void Bomberman::setY(int y)
{
    this->y = y;
}

void Bomberman::setVitesse(int vitesse)
{
    this->vitesse = vitesse;
}

void Bomberman::setNbBomb(int nbBomb)
{
    this->nbBomb = nbBomb;
}

std::ostream &operator<<(std::ostream &os, const Bomberman &p)
{
    os << "Bomberman : " << p.nom << "\n"
       << char(3) << char(3) << char(3) << " : " << p.vie << "\nposition : ( " << p.x << " ; " << p.y << " ) "
       << "\nnombre de bombe : " << p.nbBomb << "\nvitesse : " << p.vitesse << std::endl
       << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Bomberman &p)
{
    cout << "entrez le nom du Bomberman.\n";
    is >> p.nom;
    cout << "entrez la position x du bomberman.\n";
    is >> p.x;
    cout << "entrez la position y du bomberman.\n";
    is >> p.y;

    return is;
}
