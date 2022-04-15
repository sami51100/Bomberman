#ifndef __ITEM__
#define __ITEM__

#include "../../Joueur/entete/Bomberman.h"

using namespace std;

/**
 * @brief classe mère item
 *
 */
class Item
{

protected:
    int x;
    int y;
    int valeur = 7;

public:
    /**
     * @brief
     * @author sami DRIOUCHE
     * @return int
     */
    int getX() const;

    /**
     * @brief
     * @author sami DRIOUCHE
     * @return int
     */
    int getY() const;

    /**
     * @brief Get the Valeur object
     * @author sami DRIOUCHE
     * @return int
     */
    int getValeur() const;

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param x
     */
    void setX(int x);

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param y
     */
    void setY(int y);

    /**
     * @brief Set the Valeur object
     * @author sami DRIOUCHE
     * @param valeur
     */
    void setValeur(int valeur);

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param b
     */
    virtual void effetPlayer(Bomberman &b);

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param b
     */
    virtual void effetBomb(Bomb &b);
};

#endif