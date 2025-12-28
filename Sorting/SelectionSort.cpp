/* Cpp code to demonstrate the Selection sort*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort_Asc(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxi = 0;
        for (int j = 1; j < n - i; j++)
        {
            if (a[j] > a[maxi])
            {
                maxi = j;
            }
        }
        swap(a[n - i - 1], a[maxi]);
    }
}

void selectionSort_Desc(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = 0;
        for (int j = 1; j < n - i; j++)
        {
            if (a[j] < a[mini])
            {
                mini = j;
            }
        }
        swap(a[n - i - 1], a[mini]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectionSort_Asc(a, n);
    cout << "Sorted array in Ascending order:";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    selectionSort_Desc(a, n);
    cout << "Sorted array in Descending order:";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
