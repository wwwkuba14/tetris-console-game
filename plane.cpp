#include "plane.hpp"
#include <iostream>



Plane::Plane()
{
    for (int i = 0; i < heigh_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            mapArray_[i][j] = PLANE_CHAR;
            figureArray_[i][j] = PLANE_CHAR;
        }
    }
}

Plane::~Plane()
{

}

void Plane::drawMap()
{
    for(int i = 0; i < heigh_; i++)
    {
        for(int j = 0; j < width_; j++)
        {
            std::cout << mapArray_[i][j] << " "; 
        }
        std::cout << endl;
    }
}

void Plane::updateMap(Figure &figure)
{
    for(int i = 0 ; i < heigh_; i++)
    {
        for(int j = 0; j < width_; j++)
        {
            for(int x = 0 ; x < figure.length_ ; x++)
            {
                if(figure.getBody(x).first == i && figure.getBody(x).second == j)
                {
                    mapArray_[j][i] = FIGURE_CHAR;
                }

                if(figureArray_[i][j]== FIGURE_CHAR)
                {
                    mapArray_[i][j] = FIGURE_CHAR;
                }
            }
        }
    }
}

void Plane::clearMap()
{
    for (int i = 0; i < heigh_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            mapArray_[i][j] = PLANE_CHAR;
        }
    }
}

bool Plane::bottomCheck(Figure &figure)
{
    bool bottom = false;

    for(int i = 0; i < PLANE_HEIGH; i++)
    {
        for(int j = 0 ; j < PLANE_WIDTH; j++)
        {
            for(int x = 0; x < figure.length_ ; x++)
            {
                // znalazł się na samym dole
                if(figure.getBody(x).second == PLANE_HEIGH)
                {
                    bottom = true ;
                    
                }
                else if(mapArray_[figure.getBody(x).second + 1][figure.getBody(x).first] == FIGURE_CHAR)
                {
                    bottom = true ; 
                }
                if(bottom)
                {
                    figArrayUpdate(figure);
                    return true;
                }
            }
        }
    }
    return false;
}

void Plane::figArrayUpdate(Figure &figure)
{
    for(int i = 0; i < figure.length_; i++)
    {
        figureArray_[figure.getBody(i).second -1][figure.getBody(i).first] = FIGURE_CHAR;
    }
}