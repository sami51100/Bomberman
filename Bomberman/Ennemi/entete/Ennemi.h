#ifndef __ENNEMI__
#define __ENNEMI__

#include "../../Joueur/entete/Bomberman.h"

using namespace std;

/**
 * @brief classe mère Ennemi
 *
 */
class Ennemi
{

protected:
    int x;
    int y;
    int nbvie = 20;
    int nbattaque = 50;
    int valeur = 6;

public:
    int tmp;
    bool Vivant = false;

    /**
     * @brief
     * @author Walid AIT ERRAMI
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
     * @brief Get the Nbvie object
     * @author Walid AIT ERRAMI
     * @return int
     */
    int getNbvie() const;

    /**
     * @brief Get the Nbattaque object
     * @author Walid AIT ERRAMI
     * @return int
     */
    int getNbattaque() const;

    /**
     * @brief Get the Valeur object
     * @author Walid AIT ERRAMI
     * @return int
     */
    int getValeur() const;

    /**
     * @brief setter
     * @author Walid AIT ERRAMI
     * @param x
     */
    void setX(int x);

    /**
     * @brief setter
     * @author Walid AIT ERRAMI
     * @param y
     */
    void setY(int y);

    /**
     * @brief Set the Nbvie object
     * @author Walid AIT ERRAMI
     * @param nbvie
     */
    void setNbvie(int nbvie);

    /**
     * @brief Set the Nbattaque object
     * @author Walid AIT ERRAMI
     * @param nbattaque
     */
    void setNbattaque(int nbattaque);

    /**
     * @brief methode virtual pour infliger des degats au joueur
     * @author Walid AIT ERRAMI
     * @param b
     */
    virtual void attaquerPlayer(Bomberman &b);

    /**
     * @brief methode virtual pour recevoir des degats
     * @author Walid AIT ERRAMI
     * @param boom
     */
    virtual void recevoirDegat(Bomb &boom);
};

#endif