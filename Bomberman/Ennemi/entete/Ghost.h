#ifndef __GHOST__
#define __GHOST__
#include "Ennemi.h"

/**
 * @brief classe du Ghost
 *
 */
class Ghost : public Ennemi
{

protected:
public:
    /**
     * @brief Construct a new Ghost object
     * @author sami DRIOUCHE
     */
    Ghost();

    /**
     * @brief Construct a new Ghost object
     * @author sami DRIOUCHE
     * @param x
     * @param y
     */
    Ghost(int x, int y);

    /**
     * @brief methode pour attaquer le player
     * @author Walid AIT ERRAMI
     * @param b
     */
    void attaquerPlayer(Bomberman &b);

    /**
     * @brief methode pour recevoir des degats
     * @author sami DRIOUCHE
     * @param boom
     */
    void recevoirDegat(Bomb &boom);

    /**
     * @brief surcharge operateur
     * @author sami DRIOUCHE
     * @param os
     * @param p
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Ghost &p);

    /**
     * @brief surcharge operateur
     * @author sami DRIOUCHE
     * @param is
     * @param p
     * @return std::istream&
     */
    friend std::istream &operator>>(std::istream &is, Ghost &p);
};

#endif