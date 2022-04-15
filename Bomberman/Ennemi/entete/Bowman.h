#ifndef __BOWMAN__
#define __BOWMAN__

#include "Ennemi.h"

/**
 * @brief classe du bowman
 *
 */
class Bowman : public Ennemi
{

public:
    /**
     * @brief Construct a new Bowman object
     *
     */
    Bowman();

    /**
     * @brief Construct a new Bowman object
     * @author Walid AIT ERRAMI
     * @param x
     * @param y
     */
    Bowman(int x, int y);

    /**
     * @brief methode pour attaquer le player
     * @author Walid AIT ERRAMI
     * @param b
     */
    void attaquerPlayer(Bomberman &b);

    /**
     * @brief methode pour recevoir les degats de la bombe
     * @author Walid AIT ERRAMI
     * @param boom
     */
    void recevoirDegat(Bomb &boom);

    /**
     * @brief surcharge de l'operateur de sortie cout
     *
     * @param os
     * @param p
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Bowman &p);

    /**
     * @brief surcharge de l'operateur d'entrée cin
     *
     * @param is
     * @param p
     * @return std::istream&
     */
    friend std::istream &operator>>(std::istream &is, Bowman &p);
};

#endif