#ifndef __MORELIFE__
#define __MORELIFE__
#include "Item.h"

using namespace std;

/**
 * @brief classe morelife
 *
 */
class MoreLife : public Item
{

public:
    /**
     * @brief Construct a new More Life object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    MoreLife();

    /**
     * @brief Construct a new More Life object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param x
     * @param y
     */
    MoreLife(int x, int y);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     */
    void effetPlayer(Bomberman &b);
};

#endif