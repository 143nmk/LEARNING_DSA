/* Cpp code to solve N Queens problem */

#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col, vector<string> &board, int n)
{
    // check upper
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    // check upper left diagonal
    for (int i = row , j = col ; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // check upper right diagonal
    for (int i = row , j = col ; i >= 0 && j <= n - 1; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

int solveNQueens(vector<vector<string>> &res, vector<string> &board, int n, int row)
{
    if (row == n)
    {
        res.push_back(board);
        return 1;
    }
    int count = 0;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            count += solveNQueens(res, board, n, row + 1);
            board[row][col] = '.';
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    int count = solveNQueens(res, board, n, 0);
    cout << "Number of solutions for " << n << "-Queens: " << count << endl;
    cout << "Solutions is: " << endl;
    for (const auto &solution : res)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << "------------------------" << endl;
    }

    return 0;
}