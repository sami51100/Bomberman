#ifndef __MAP__
#define __MAP__
#include <windows.h>
#include <sstream>
#include <cstring>
#include <iostream>

#include "../../Item/entete/MoreLife.h"
#include "../../Item/entete/SpeedUp.h"
#include "../../Item/entete/MoreBomb.h"
#include "../../Item/entete/ScaleUp.h"
#include "../../Item/entete/PowerUp.h"

#include "Sand.h"
#include "Wall.h"

#include "../../Ennemi/entete/Monster.h"
#include "../../Ennemi/entete/Ghost.h"
#include "../../Ennemi/entete/Bowman.h"

/**
 * @brief classe Map
 *
 */
class Map
{
public:
    int const static nbligne = 14;
    int const static nbcolonne = 14;
    int tab[nbligne][nbcolonne];
    std::string nom;

    Monster mons;
    Ghost ghos;
    Bowman bowm;

    Bomberman player1;
    Bomb bomb1;

    Wall wall;
    Sand sand;

    MoreLife morL;
    MoreBomb morB;
    SpeedUp spee;
    ScaleUp scal;
    PowerUp power;

    std::vector<Ennemi *> tabM;

    /**
     * @brief Construct a new Map object
     * @author sami DRIOUCHE
     * @param nom
     */
    Map(std::string nom);

    /**
     * @brief
     * @author sami DRIOUCHE
     */
    void afficher();

    /**
     * @brief
     * @author sami DRIOUCHE
     *
     */
    void creerMap();

    /**
     * @brief
     * @author sami DRIOUCHE
     *
     * @param i
     * @param j
     * @return std::string
     */
    std::string convertir(int i, int j);

    /**
     * @brief
     * @author Walid AIT ERRAMI
     *
     * @param w
     */
    void remplirMur(Tile w);

    /**
     * @brief
     * @author Walid AIT ERRAMI
     *
     * @param w
     */
    void remplirSable(Tile w);

    /**
     * @brief
     * @author sami DRIOUCHE
     *
     * @param k
     */
    void remplirItem(Item &k);

    /**
     * @brief
     * @author sami DRIOUCHE
     *
     * @param b
     */
    void remplirPlayer(Bomberman &b);

    /**
     * @brief
     * @author sami DRIOUCHE
     * @param b
     * @param bomb
     * @param k1
     * @param k2
     * @param k3
     * @param k4
     * @param k5
     */
    void mouvementPlayer(Bomberman &b, Bomb &bomb, Item &k1, Item &k2, Item &k3, Item &k4, Item &k5);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @param b
     */
    void remplirMonstre(Ennemi &b);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     * @param bo
     */
    void mouvementMonstre(Ennemi &b, Bomberman &bo);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     * @param bo
     * @param DI
     * @param DJ
     * @param deplacement
     */
    void effetMonstre(Ennemi &b, Bomberman &bo, int DI, int DJ, int deplacement);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     * @param bomb
     */
    void explosionBombe(Bomberman &b, Bomb &bomb);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     * @param bomb
     * @param k1
     * @param k2
     * @param k3
     * @param k4
     * @param k5
     * @param i
     * @param j
     */
    void effetItem(Bomberman &b, Bomb &bomb, Item &k1, Item &k2, Item &k3, Item &k4, Item &k5, int i, int j);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    void tuerMonstre();

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return true
     * @return false
     */
    bool victoire();
};

#endif