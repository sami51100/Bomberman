#ifndef __MOREBOMB__
#define __MOREBOMB__

#include "Item.h"

using namespace std;

/**
 * @brief classe morebomb
 *
 */
class MoreBomb : public Item
{

public:
    /**
     * @brief Construct a new More Bomb object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    MoreBomb();

    /**
     * @brief Construct a new More Bomb object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param x
     * @param y
     */
    MoreBomb(int x, int y);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     */
    void effetPlayer(Bomberman &b);
};

#endif