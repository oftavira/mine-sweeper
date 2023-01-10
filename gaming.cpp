// E if a coordinate is grater than the given row or column

#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    // Read in the number of rows and columns
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Output the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}
