#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // Variables to store the string and the x,y pairs
    string line1;
    vector<pair<int, int>> points;

    // Open the input file
    ifstream inputFile("input.txt");

    // Read the string from the first line
    getline(inputFile, line1);

    // Read the x,y pairs from the second line
    string line2;
    getline(inputFile, line2);
    stringstream ss(line2);
    string pairString;
    while (getline(ss, pairString, ';')) {
        int x, y;
        sscanf(pairString.c_str(), "%d,%d", &x, &y);
        points.push_back({x, y});
    }

    // Close the input file
    inputFile.close();

    // Print out the read values
    cout << "String: " << line1 << endl;
    cout << "Points:" << endl;
    for (const auto& point : points) {
        cout << point.first << ", " << point.second << endl;
    }
    return 0;
}
