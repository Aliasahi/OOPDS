// Robot.cpp
#include "robot.h"

void Robot::takeTurn() {
    look(posX, posY);
    move();
    fire(posX, posY);
}

void Robot::decreaseLife() {
    if (lives > 0) lives--;
}

void Robot::setPosition(int x, int y) {
    posX = x;
    posY = y;
}
