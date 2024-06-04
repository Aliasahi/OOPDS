// Robot.h
#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include "battlefield.h"

class Robot {
protected:
    int posX, posY;
    int lives;
    std::string name;
    char symbol;
    Battlefield* battlefield;

public:
    Robot(int x, int y, std::string name, char symbol, Battlefield* battlefield)
        : posX(x), posY(y), name(name), symbol(symbol), battlefield(battlefield), lives(3) {}

    virtual void look(int x, int y) = 0;
    virtual void move() = 0;
    virtual void fire(int x, int y) = 0;
    virtual void takeTurn();
};

#endif
