#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Definitions of 
// Input file
// Pair, Vector
// Getline
// make_pair

pair<vector<pair<int,int>>, pair<int,int>> getInf(string filen) {
    
    ifstream inputFile(filen);
    vector<pair<int, int>> coordinates;
    int n, m;
    string line;

    if (inputFile.is_open()) {
        // Read the first line and store the size of the matrix
        getline(inputFile, line);
        sscanf(line.c_str(), "%d,%d", &n, &m);

        // Read the second line and store the pairs of coordinates
        getline(inputFile, line);
        int x, y;
        size_t prev = 0, pos;
        while ((pos = line.find(";", prev)) != string::npos) {
            sscanf(line.substr(prev, pos-prev).c_str(), "%d,%d", &x, &y);
            coordinates.push_back(make_pair(x, y));
            prev = pos + 1;
        }
        inputFile.close();

        // Writting the size and mines to the terminal
        // ----------------------------------------------
        // cout << "Matrix size: " << n << "x" << m << endl;
        // cout << "Coordinates: ";
        // for (auto coord : coordinates) {
        //     cout << "(" << coord.first << "," << coord.second << ") ";
        // }

    } else {
        cout << "Unable to open input file." << endl;
    }

    return make_pair(coordinates, make_pair(n, m));
}

int main() {
    
    //Reading the input file and storing the variables
    pair<vector<pair<int,int>>, pair<int,int>> inf = getInf("input.txt");
    vector<pair<int,int>> coordinates = inf.first;
    int n = inf.second.first;
    int m = inf.second.second;

    char matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = ' ';
        }
    }

    for (auto coord : coordinates) {
        matrix[coord.first][coord.second] = '#';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}