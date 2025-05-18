#include <iostream>

using namespace std;

#define BOARD_SIZE 4

bool isPositionSafe(int board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false; // Check column
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
            return false; // Check left diagonal
        if (col + (row - i) < BOARD_SIZE && board[i][col + (row - i)] == 1)
            return false; // Check right diagonal
    }
    return true;
}

void displayBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeQueens(int board[BOARD_SIZE][BOARD_SIZE], int currentRow)
{
    if (currentRow >= BOARD_SIZE)
    {
        displayBoard(board);
        return true; // Found a solution
    }
    for (int col = 0; col < BOARD_SIZE; col++)
    {
        if (isPositionSafe(board, currentRow, col))
        {
            board[currentRow][col] = 1; // Place queen
            if (placeQueens(board, currentRow + 1))
            {
                return true; // Continue to place next queen
            }
            board[currentRow][col] = 0; // Backtrack
        }
    }
    return false; // No valid position found
}

int main()
{
    int chessBoard[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize the chessboard
    placeQueens(chessBoard, 0);
    return 0;
}