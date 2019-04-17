#ifndef PLANE_HPP
#define PLANE_HPP

#include "macros.cpp"
#include "figure.hpp"
#include <vector>
#include <iostream>

using namespace std; 

class Plane
{
public:
    Plane();
    ~Plane();

    void clearMap();
    void drawMap();
    void updateMap(Figure &figure);
    bool bottomCheck(Figure &figure);
    void figArrayUpdate(Figure &figure);

private:
    int width_ = PLANE_WIDTH;
    int heigh_ = PLANE_HEIGH;

    char mapArray_[PLANE_HEIGH][PLANE_WIDTH]; 
    char figureArray_[PLANE_HEIGH][PLANE_WIDTH];
    
};
#endif