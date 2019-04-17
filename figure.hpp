#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "macros.cpp"
#include <vector>
#include <iostream>

using namespace std;

class Figure
{
public:
    Figure();
    ~Figure();
   // position of first point
    int posX_;
    int poxY_;

    int length_;

    pair<int, int> getBody(int position);
    void setBody(int position, int x, int y);
    void reserveTheLength(int length);
    int spawnX();
    void moveDown();
    void moveLeft();
    void moveRight();

private:

    vector<pair<int,int>> figBody_;
    int spawnPoint_;
};
#endif