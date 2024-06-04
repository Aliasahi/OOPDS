#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Struct to store robot data
struct Robot {
    string name;
    string model;
    int x;
    int y;
};

// Function to read and parse the file
void readFile(const string &filename, int &M, int &N, int &steps, int &numRobots, Robot robots[]) {
    ifstream infile(filename);
    string line;

    if (infile.is_open()) {
        // Read M by N
        getline(infile, line);
        stringstream ss(line);
        string temp;
        ss >> temp >> temp;  // Skip "M by N :"
        ss >> M >> N;

        // Read Steps
        getline(infile, line);
        ss.clear();
        ss.str(line);
        ss >> temp >> steps;  // Skip "Steps:"

        // Read number of robots
        getline(infile, line);
        ss.clear();
        ss.str(line);
        ss >> temp >> numRobots;  // Skip "Robots:"

        // Read robots data
        int robotIndex = 0;
        while (getline(infile, line) && robotIndex < numRobots) {
            ss.clear();
            ss.str(line);
            string name, model;
            string xStr, yStr;
            int x, y;

            ss >> name >> model >> xStr >> yStr;

            if (xStr == "random") {
                x = rand() % M;
            } else {
                x = stoi(xStr);
            }

            if (yStr == "random") {
                y = rand() % N;
            } else {
                y = stoi(yStr);
            }

            robots[robotIndex].name = name;
            robots[robotIndex].model = model;
            robots[robotIndex].x = x;
            robots[robotIndex].y = y;
            robotIndex++;
        }

        infile.close();
    } else {
        cerr << "Unable to open file";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    const string filename = "input.txt";
    int M, N, steps, numRobots;

    // Assume a maximum of 100 robots for the sake of this example
    Robot robots[100];

    readFile(filename, M, N, steps, numRobots, robots);

    // Output the read data
    cout << "Grid size: " << M << " by " << N << endl;
    cout << "Steps: " << steps << endl;
    cout << "Number of robots: " << numRobots << endl;
    for (int i = 0; i < numRobots; ++i) {
        cout << "Robot " << i + 1 << ": " << robots[i].name << " " << robots[i].model
             << " (" << robots[i].x << ", " << robots[i].y << ")" << endl;
    }

    return 0;
}
