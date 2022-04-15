#ifndef __WALL__
#define __WALL__
#include "Tile.h"

/**
 * @brief classe wall
 *
 */
class Wall : public Tile
{
public:
    /**
     * @brief Construct a new Wall object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     *
     */
    Wall();

    /**
     * @brief Construct a new Wall object
     * @author sami DRIOUCHE & walid AIT ERRAMI
     * @param x
     * @param y
     */
    Wall(int x, int y);
};

#endif
