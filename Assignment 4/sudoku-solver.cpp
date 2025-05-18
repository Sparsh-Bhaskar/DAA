#include <iostream>

using namespace std;

#define SIZE 9 // Size of the Sudoku grid

bool isNumberSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check if the number can be placed in the cell
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num || 
            grid[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) { // 0 means the cell is empty
                for (int num = 1; num <= 9; num++) {
                    if (isNumberSafe(grid, row, col, num)) {
                        grid[row][col] = num; // Place the number
                        if (solveSudoku(grid)) {
                            return true; // Continue solving
                        }
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Sudoku solved
}

void printSudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    int sudokuGrid[SIZE][SIZE] = {
        {3, 0, 6, 5, 7, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 8, 6, 3, 0, 0}
    };

    if (solveSudoku(sudokuGrid)) {
        printSudoku(sudokuGrid);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}