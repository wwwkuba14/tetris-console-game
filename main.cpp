#include <iostream>
#include "plane.hpp"
#include "figure.hpp"
#include "square.hpp"
#include "Lfigure.hpp"
#include "unistd.h"
#include <unistd.h>  //_getcher
#include <termios.h> //_getcher

using namespace std; 

bool gameOver = false; 

void turn(Figure &figure, char dir);
char getcher();
void randFigure();

Figure *figPointer;
char dir = 'n';

int main()
{

    Plane plansza; 
    
    figPointer = new Lfigure; 
    

    while (!gameOver)
    {
        dir = getcher();
        plansza.clearMap();
        turn(*figPointer, dir);
        plansza.updateMap(*figPointer);
        figPointer->moveDown();
        if(plansza.bottomCheck(*figPointer))
        {
            delete figPointer;
            randFigure();
            cout << " BOTTOM ! " << endl;
        }
        //

        cout << endl;
        cout << endl;




        plansza.drawMap();

        usleep(PAUSE_LENGTH);
    }
    

    return 0;
}

void randFigure()
{
    int random = rand() % 2;

    switch (random)
    {
    case 0:
        figPointer = new Square;
        break;
    case 1:
        figPointer = new Lfigure;
        break;
    }
}



void turn(Figure &figure, char dir)
{
    switch (dir)
    {
    case 'a':
    case 'A':

    figure.moveLeft();
        break;

    case 'd':
    case 'D':
    figure.moveRight();
        break;
    }

    dir = 'n';
}





//////////// this part of a code comes from:
// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux/7469410#7469410
char getcher()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 0;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);
 

    return buf;
}