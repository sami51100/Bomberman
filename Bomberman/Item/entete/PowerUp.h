#ifndef __POWERUP__
#define __POWERUP__

#include "Item.h"

using namespace std;

/**
 * @brief classe powerup
 *
 */
class PowerUp : public Item
{

public:
    /**
     * @brief Construct a new Power Up object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    PowerUp();

    /**
     * @brief Construct a new Power Up object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param x
     * @param y
     */
    PowerUp(int x, int y);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     */
    void effetBomb(Bomb &b);
};

#endif