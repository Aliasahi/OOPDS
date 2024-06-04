
// Battlefield.cpp
#include "battlefield.h"
#include "robot.h"

Battlefield::Battlefield(int m, int n) : rows(m), cols(n) {
    grid = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = '.';
        }
    }
}

Battlefield::~Battlefield() {
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Battlefield::display() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void Battlefield::updatePosition(int oldX, int oldY,int newX, int newY, char symbol) {
    if (isInBounds(newX, newY)) {
        grid[newY][newX] = symbol;
    }
}

bool Battlefield::isOccupied(int x, int y) {
    return grid[y][x] != '.';
}

bool Battlefield::isInBounds(int x, int y) {
    return x >= 0 && x < cols && y >= 0 && y < rows;
}

int Battlefield::getRows() {
    return rows;
}

int Battlefield::getCols() {
    return cols;
}

