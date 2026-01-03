/* Cpp code to calculate the sum of diagonals in a square matrix */

#include <bits/stdc++.h>
using namespace std;
// Function to calculate the sum of diagonals
// Time Complexity: O(n)
// Space Complexity: O(1)
int DiagonalSum(int (*matrix)[100], int n)
{
    int primarySum = 0;
    int secondarySum = 0;
    for (int i = 0; i < n; i++)
    {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][n - i - 1];
    }
    if (n % 2 == 1)
    {
        secondarySum -= matrix[n / 2][n / 2];
    }
    return primarySum + secondarySum;
}
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int DiagonalSum_BruteForce(int (*matrix)[100], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
            {
                totalSum += matrix[i][j];
            }
        }
    }
    return totalSum;
}
// Driver code
int main()
{
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;
    int matrix[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int sum = DiagonalSum(matrix, n);
    cout << "Sum of diagonals: " << sum << endl;
    int sum2 = DiagonalSum_BruteForce(matrix, n);
    cout << "Sum of diagonals (Brute Force): " << sum2 << endl;
    return 0;
}