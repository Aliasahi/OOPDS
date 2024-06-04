#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Robot
{
    string type, name;
    int x, y;
};

int main()
{
    ifstream input_file("input.txt");
    if (!input_file.is_open())
    {
        cerr << "Could not open the input file." << endl;
        return 1;
    }

    int m, n, steps, num_robots;
    const int MAX_ROBOTS = 7; // Maximum number of robots
    Robot robots[MAX_ROBOTS];
    int robots_count = 0; // Counter for the number of robots read

    string line;

    // Read and parse each line
    while (getline(input_file, line))
    {
        stringstream ss(line);
        string temp;

        // Check if line contains battlefield dimensions
        if (line.find("M by N :") != string::npos)
        {
            ss >> temp >> temp >> m >> n;
        }
        // Check if line contains steps
        else if (line.find("Steps:") != string::npos)
        {
            ss >> temp >> steps;
        }
        // Check if line contains number of robots
        else if (line.find("Robots:") != string::npos)
        {
            ss >> temp >> num_robots;
        }
        // Otherwise, assume line contains robot information
        else
        {
            ss >> robots[robots_count].type >> robots[robots_count].name;

            // Read positions
            string posX, posY;
            ss >> posX >> posY;

            // Handle "random" positions
            if (posX == "random" && posY == "random")
            {
                robots[robots_count].x = -1; // Flag for random position
                robots[robots_count].y = -1;
            }
            else
            {
                robots[robots_count].x = stoi(posX);
                robots[robots_count].y = stoi(posY);
            }

            // Increment counter
            robots_count++;
        }
    }

    // Output the parsed information
    cout << "Battlefield dimensions: " << m << "x" << n << endl;
    cout << "Steps: " << steps << endl;
    cout << "Robots: " << endl;
    for (int i = 0; i < robots_count; ++i)
    {
        cout << robots[i].type << " " << robots[i].name << " (" << robots[i].x << ", " << robots[i].y << ")" << endl;
    }

    return 0;
}
