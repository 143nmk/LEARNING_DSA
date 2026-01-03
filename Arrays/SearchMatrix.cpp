/* Cpp coded to search for an element in a sorted matrix */

#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
bool searchMatrix1(int matrix[100][100], int n, int m, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// Better Approach
bool searchMatrix2(int matrix[100][100], int n, int m, int target)
{

    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (matrix[i][mid] == target)
            {
                return true;
            }
            else if (matrix[i][mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return false;
}
// Optimal Approach
bool searchMatrix3(int matrix[100][100], int n, int m, int target)
{
    int i = 0;
    int j = m - 1;
    int cell;
    while (i < n && j >= 0)
    {
        cell = matrix[i][j];
        if (cell == target)
        {
            return true;
        }
        else if (cell > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    int matrix[100][100];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter the target element to search: ";
    cin >> target;
    cout << "Brute Force Approach: " << searchMatrix1(matrix, n, m, target) << endl;
    cout << "Better Approach: " << searchMatrix2(matrix, n, m, target) << endl;
    cout << "Optimal Approach: " << searchMatrix3(matrix, n, m, target) << endl;
    return 0;
}