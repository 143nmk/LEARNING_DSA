/* Cpp code to print the matrix in spiral order */

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix1(vector<vector<int>> &matrix)
{
    // Code from strivers SDE sheet
    int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
    vector<int> result;
    while (top <= bottom && left <= right)
    {
        // top
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        // right
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        // bottom
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        // left
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left--;
        }
    }
    return result;
}

vector<int> spiralMatrix2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int srow = 0, scol = 0, erow = n - 1, ecol = m - 1;
    vector<int> ans;
    while (srow <= erow && scol <= ecol)
    {
        for (int i = scol; i <= ecol; i++)
        {
            ans.push_back(matrix[srow][i]);
        }
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(matrix[i][ecol]);
        }
        if (srow != erow)
        {
            for (int i = ecol - 1; i >= scol; i--)
            {
                ans.push_back(matrix[erow][i]);
            }
        }
        if (ecol != scol)
        {
            for (int i = erow - 1; i > srow; i--)
            {
                ans.push_back(matrix[i][scol]);
            }
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> matrix;
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int element;
            cin >> element;
            row.push_back(element);
        }
        matrix.push_back(row);
    }
    vector<int> result1 = spiralMatrix1(matrix);
    cout << "Spiral Order (Method 1): ";
    for (int val : result1)
    {
        cout << val << " ";
    }
    vector<int> result2 = spiralMatrix2(matrix);
    cout << "Spiral Order (Method 2): ";
    for (int val : result2)
    {
        cout << val << " ";
    }
    return 0;
}