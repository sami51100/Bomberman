#ifndef __SPEEDUP__
#define __SPEEDUP__
#include "Item.h"

using namespace std;

/**
 * @brief classe speedup
 *
 */
class SpeedUp : public Item
{

public:
    /**
     * @brief Construct a new Speed Up object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    SpeedUp();

    /**
     * @brief Construct a new Speed Up object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param x
     * @param y
     */
    SpeedUp(int x, int y);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     */
    void effetPlayer(Bomberman &b);
};

#endif