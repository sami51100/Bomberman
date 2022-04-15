#ifndef __TILE__
#define __TILE__

using namespace std;

/**
 * @brief classe mère Tile
 *
 */
class Tile
{
protected:
    int x;
    int y;
    int valeur = 2;

public:
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
     * @brief Get the Valeur object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @return int
     */
    int getValeur() const;

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
};

#endif
