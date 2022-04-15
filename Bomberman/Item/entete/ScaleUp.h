#ifndef __SCALEUP__
#define __SCALEUP__
#include "Item.h"

using namespace std;

/**
 * @brief classe scaleup
 *
 */
class ScaleUp : public Item
{

public:
    /**
     * @brief Construct a new Scale Up object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    ScaleUp();

    /**
     * @brief Construct a new Scale Up object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param x
     * @param y
     */
    ScaleUp(int x, int y);

    /**
     * @brief
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     * @param b
     */
    void effetBomb(Bomb &b);
};

#endif