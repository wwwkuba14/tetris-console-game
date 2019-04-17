#include "Lfigure.hpp"

Lfigure::Lfigure()
{
    length_ = L_FIGURE_SIZE;

    reserveTheLength(length_);

    setBody(0,spawnX() - 1 , 0);
    setBody(1,spawnX() - 1 , 1);
    setBody(2,spawnX() , 1);
    setBody(3,spawnX() + 1 , 1);
    setBody(4,spawnX() + 2 , 1);
}