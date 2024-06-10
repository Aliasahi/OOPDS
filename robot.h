#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include "battlefield.h"

using namespace std;

class Robot {
private:
    int posX, posY, lives;
    string name;
    char symbol;
    Battlefield* battlefield;
public:
    Robot(int x, int y, string name, char symbol, Battlefield* battlefield);
    virtual void look(int x, int y) = 0;
    virtual void move() = 0; 
    virtual void fire(int x, int y) = 0; 
    void takeTurn();
};
#endif