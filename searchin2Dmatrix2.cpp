#include <bits/stdc++.h>
using namespace std;

// Class to perform staircase search in a 2D sorted matrix
class MatrixSearch {
private:
    vector<vector<int>> matrix; // 2D matrix

public:
    // Constructor to initialize the matrix
    MatrixSearch(vector<vector<int>>& mat) {
        matrix = mat;
    }

    // Function to search for target in matrix using staircase search
    bool searchElement(int target) {
        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        int row = 0;        // Start from first row
        int col = m - 1;    // Start from last column (top-right corner)

        // Traverse the matrix
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true; // Found target
            } 
            else if (matrix[row][col] < target) {
                row++; // Move down to next row
            } 
            else {
                col--; // Move left to previous column
            }
        }

        return false; // Target not found
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    MatrixSearch ms(matrix);
    bool found = ms.searchElement(8);
    cout << (found ? "true\n" : "false\n");
}
