// Battlefield.h
#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <iostream>
#include "LinkedList.h"

class Robot; // Forward declaration

class Battlefield {
private:
    int rows, cols;
    char** grid;
    LinkedList<Robot*> robots;

public:
    Battlefield(int m, int n);
    ~Battlefield();
    void display();
    void updatePosition(int oldX, int oldY,int newX, int newY, char symbol);
    bool isOccupied(int x, int y);
    bool isInBounds(int x, int y);
    int getRows();
    int getCols();
};

#endif
