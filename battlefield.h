#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

class Battlefield{
    private:
    int rows;
    int cols;
    char* grid; 

public:
    Battlefield(int m, int n);
    ~Battlefield(); 
    void displayBF();
    void updatePosition(int oldX, int oldY, int newX, int newY, char symbol);
    bool isOccupied(int x, int y);
    bool isInBounds(int x, int y);
    int getRows();
    int getCols();
};

#endif