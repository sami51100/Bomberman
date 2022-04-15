#ifndef __MONSTER__
#define __MONSTER__

#include "Ennemi.h"

/**
 * @brief classe du monstre
 *
 */
class Monster : public Ennemi
{

public:
    /**
     * @brief Construct a new Monster object
     * @author sami DRIOUCHE
     */
    Monster();

    /**
     * @brief Construct a new Monster object
     * @author sami DRIOUCHE
     * @param x
     * @param y
     */
    Monster(int x, int y);

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param b
     */
    void attaquerPlayer(Bomberman &b);

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param boom
     */
    void recevoirDegat(Bomb &boom);

    /**
     * @brief
     *
     * @param os
     * @param p
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Monster &p);

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param is
     * @param p
     * @return std::istream&
     */
    friend std::istream &operator>>(std::istream &is, Monster &p);
};

#endif