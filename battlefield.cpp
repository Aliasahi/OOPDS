#include "battlefield.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Robot {
    public:
    string type;
    string name;
    int x;  //m
    int y;  //n
};

void initialSimulation(const string& filename)
{
    fstream inSimulationFile;
    inSimulationFile.open(filename, ios::in);
    if(inSimulationFile.is_open())
    {
        string line;
        int M, N, Steps, numRobots;

        //read battlefield dimensions
        getline(inSimulationFile, line);
        istringstream iss(line);
        string temp;
        iss >> temp >> temp >> temp >> M >> N;

        //read number of steps
        getline(inSimulationFile, line);
        iss.clear();
        iss.str(line);
        iss >> temp >> Steps;

         //read number of robot 
        getline(inSimulationFile, line);
        iss.clear();
        iss.str(line);
        iss >> temp >> numRobots;

        //create an array of robot object
        Robot robots[numRobots];

        //read robot details
        for (int i = 0; i < numRobots; ++i)
        {
            getline(inSimulationFile, line);
            istringstream iss(line); 
            string x, y;
            iss >> robots[i].type >> robots[i].name >> x >> y;

            if(x == "random")
            {
                robots[i].x = rand() % M;    //generate random m
            } else {
                robots[i].x = stoi(x);
            }

            if(y == "random")
            {
                robots[i].y = rand() % N;    //generate random n
            } else {
                robots[i].y = stoi(y);
            }
        }

        inSimulationFile.close();

        cout << "M by N: " << M << " " << N << endl;
        cout << "Steps: " << Steps << endl;
        cout << "Robots: " << numRobots << endl;
        for (int i = 0; i < numRobots ; ++i)
        {
            cout << "Robot type: " << robots[i].type << ", Name: " << robots[i].name 
            << ", Position: (" << robots[i].x << "," << robots[i].y << ")" << endl;
        }
    } else {
        cerr << "ERROR: Couldn't open the file " << filename << endl;
    }
}

Battlefield::Battlefield (int m, int n)
{
    rows = m;
    cols = n;
    grid = new char [m*n];
    for(int i = 0; i < m*n; ++i)
    {
        grid[i] = ' ';
    }
}

Battlefield::~Battlefield()
{
    delete[] grid;
}

void Battlefield::displayBF()
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << grid[i * cols + j] << ' ';
        }
        cout << endl;
    }
}

void Battlefield::updatePosition(int oldX, int oldY, int newX, int newY, char symbol) {
    // update the position in the grid with the new symbol
    grid[oldX * cols + oldY] = ' ';
    grid[newX * cols + newY] = symbol;
}

bool Battlefield::isOccupied(int x, int y) {
    // check if the position (x, y) is occupied
    return grid[x * cols + y] != ' ';
}

bool Battlefield::isInBounds(int x, int y) {
    // check if the position (x, y) is within bounds
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

int Battlefield::getRows() {
    return rows;
}

int Battlefield::getCols() {
    return cols;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    string filename = "inSimulation.txt";
    initialSimulation(filename);
    return 0;
}