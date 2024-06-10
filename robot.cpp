#include "robot.h"

Robot::Robot(int x, int y, std::string name, char symbol, Battlefield* battlefield) 
    : posX(x), posY(y), name(name), symbol(symbol), battlefield(battlefield), lives(3) {}

void Robot::takeTurn() {

    look(posX, posY);
    move();
    fire(posX, posY);
}