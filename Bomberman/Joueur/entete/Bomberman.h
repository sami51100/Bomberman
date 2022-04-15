#ifndef __BOMBERMAN__
#define __BOMBERMAN__
#include <string>
#include "Bomb.h"
#include <vector>

/**
 * @brief classe du bomberman
 * @author sami DRIOUCHE
 */
class Bomberman
{

protected:
        std::string nom;
        int vie = 100;
        int x;
        int y;
        int vitesse = 1;
        int nbBomb = 3;

        int valeur = 1;

public:
        bool Vivant = false;
        std::vector<Bomb> tabB;

        Bomb boom;

        /**
         * @brief Construct a new Bomberman object
         * @author sami DRIOUCHE
         * @param nom
         * @param vie
         * @param x
         * @param y
         * @param vitesse
         * @param nbBomb
         * @param boom
         */
        Bomberman(std::string nom, int vie, int x, int y, int vitesse, int nbBomb, Bomb boom);

        /**
         * @brief Construct a new Bomberman object
         * @author sami DRIOUCHE
         */
        Bomberman();

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
         * @brief Get the Vie object
         * @author sami DRIOUCHE
         * @return int
         */
        int getVie() const;

        /**
         * @brief Get the Vitesse object
         * @author sami DRIOUCHE
         * @return int
         */
        int getVitesse() const;

        /**
         * @brief Get the Nb Bomb object
         * @author sami DRIOUCHE
         * @return int
         */
        int getNbBomb() const;

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
         * @brief Set the Vie object
         * @author sami DRIOUCHE
         * @param vie
         */
        void setVie(int vie);

        /**
         * @brief Set the Vitesse object
         * @author sami DRIOUCHE
         * @param vitesse
         */
        void setVitesse(int vitesse);

        /**
         * @brief Set the Nb Bomb object
         * @author sami DRIOUCHE
         * @param nbBomb
         */
        void setNbBomb(int nbBomb);

        /**
         * @brief
         * @author sami DRIOUCHE
         * @param os
         * @param p
         * @return std::ostream&
         */
        friend std::ostream &operator<<(std::ostream &os, const Bomberman &p);

        /**
         * @brief
         * @author sami DRIOUCHE
         * @param is
         * @param p
         * @return std::istream&
         */
        friend std::istream &operator>>(std::istream &is, Bomberman &p);
};

#endif