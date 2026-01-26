/* Cpp code to solve the sudoku puzzle*/

#include <iostream>
using namespace std;

bool isSafe(int board[9][9], int row, int col, int digit)
{
    // vertical
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == digit)
        {
            return false;
        }
    }
    // horizontal
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == digit)
        {
            return false;
        }
    }

    // 3 x 3 grid
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == digit)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[9][9], int row, int col)
{
    if (row == 9)
    {
        return true;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow++;
        nextCol = 0;
    }
    if (board[row][col] != 0)
    {
        return solveSudoku(board, nextRow, nextCol);
    }
    for (int digit = 1; digit <= 9; digit++)
    {
        if (isSafe(board, row, col, digit))
        {
            board[row][col] = digit;
            if (solveSudoku(board, nextRow, nextCol))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int board[9][9];
    cout << "Enter the Sudoku board (9x9) with 0 for empty cells:\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    // Function to print the board
    auto printBoard = [&](int board[9][9])
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    };
    cout << "-----------------" << endl;
    if (solveSudoku(board, 0, 0))
    {
        printBoard(board);
        cout << "Solved Sudoku board:\n";
    }
    else
    {
        cout << "No solution exists for the given Sudoku board.\n";
    }
    return 0;
}