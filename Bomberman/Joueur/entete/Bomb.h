#ifndef __BOMB__
#define __BOMB__

using namespace std;

/**
 * @brief classe de la bombe
 *
 */
class Bomb
{

protected:
    int portee = 1;
    int degat = 50;
    int x;
    int y;

    int varb = 11;
    int bomb = 111;
    int explosionH = 1111;
    int explosionV = 11111;

    int compteur = 0;
    int tmpi = -1;
    int tmpj = -1;

public:
    bool poser = false;
    /**
     * @brief Construct a new Bomb object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    Bomb();

    /**
     * @brief Construct a new Bomb object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @param x
     * @param y
     * @param degat
     * @param portee
     */
    Bomb(int x, int y, int degat, int portee);

    /**
     * @brief Get the Portee object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getPortee() const;

    /**
     * @brief Get the Degat object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getDegat() const;

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getX() const;

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getY() const;

    /**
     * @brief Get the Varb object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getVarb() const;

    /**
     * @brief Get the Bomb object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getBomb() const;

    /**
     * @brief Get the Explosion H object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getExplosionH() const;

    /**
     * @brief Get the Explosion V object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @return int
     */
    int getExplosionV() const;

    /**
     * @brief Get the Compteur object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getCompteur() const;

    /**
     * @brief Get the Tmpi object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getTmpi() const;

    /**
     * @brief Get the Tmpj object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @return int
     */
    int getTmpj() const;

    /**
     * @brief Set the Portee object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param portee
     */
    void setPortee(int portee);

    /**
     * @brief Set the Degat object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param degat
     */
    void setDegat(int degat);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param x
     */
    void setX(int x);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param y
     */
    void setY(int y);

    /**
     * @brief Set the Compteur object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param compteur
     */
    void setCompteur(int compteur);

    /**
     * @brief Set the Tmpi object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param tmpi
     */
    void setTmpi(int tmpi);

    /**
     * @brief Set the Tmpj object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param tmpj
     */
    void setTmpj(int tmpj);

    void BombePosee();

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param os
     * @param p
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Bomb &p);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param is
     * @param p
     * @return std::istream&
     */
    friend std::istream &operator>>(std::istream &is, Bomb &p);
};

#endif