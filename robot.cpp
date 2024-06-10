#include "robot.h"
#include "battlefield.h"
using namespace std;

Robot::Robot(int x, int y,string name, char symbol, Battlefield* battlefield) 
    : posX(x), posY(y), name(name), symbol(symbol), battlefield(battlefield), lives(3) {}

void Robot::takeTurn() {

    look(posX, posY);
    move();
    fire(posX, posY);
}

void Robot::look (int x, int y)
{
    court << name << "is looking around at position (" << x << ", " << y << ")." << endl;
}

void Robot::move()
{
    posX += 1 // move to the right
    court << name << " moved to position (" << posX << ", " << posY << ")." << endl;
}

void Robot::fire (int x, int y) 
{
    court << name << " fires at position (" << x << ", " << y << ")." << endl;
}
    
