/* Cpp code to demonstrate input and output of arrays */

#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Working with one dimensional array" << endl;
    cout << "Enter the size of the array:";
    cin >> n;
    int arr[n]; // Declaring a one dimensional array
    // input one dimensional array
    cout<<"Enter "<< n <<" elements:"<< endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // output one dimensional array
    cout << "The elements in the array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Working with two dimensional array" << endl;
    cout << "Enter number of rows and columns:";
    cin >> m >> n;
    int arr2[m][n];
    cout << "Enter " << m * n << " elements:" << endl;
    // input two dimensional array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr2[i][j];
        }
    }
    // output two dimensional array
    cout << "The elements in the array are:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "The elements in the array are formated in row major order" << endl;
    return 0;
}