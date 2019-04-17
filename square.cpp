#include "square.hpp"
#include "macros.cpp"


Square::Square()
{
    length_ = SQUARE_SIZE;

    reserveTheLength(length_);

    setBody(0, spawnX(), 0);
    setBody(1, spawnX() + 1, 0);
    setBody(2, spawnX(), 1);
    setBody(3, spawnX() + 1, 1);
}

