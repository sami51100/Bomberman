#ifndef __SAND__
#define __SAND__
#include "Tile.h"

using namespace std;

/**
 * @brief classe Sand
 *
 */
class Sand : public Tile
{

protected:
    int nbvie = 5;

public:
    bool Vivant = false;

    /**
     * @brief Construct a new Sand object
     * @author walid AIT ERRAMI
     *
     */
    Sand();

    /**
     * @brief Construct a new Sand object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @param x
     * @param y
     */
    Sand(int x, int y);

    /**
     * @brief Get the Nb Vie object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @return int
     */
    int getNbVie() const;

    /**
     * @brief Set the Nb Vie object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @param nbvie
     */
    void setNbVie(int nbvie);
};

#endif
