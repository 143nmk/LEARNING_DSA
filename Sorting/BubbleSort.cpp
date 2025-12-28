/* Cpp code to demostrate the bubble sort
  input: array
  output: sorted array

*/

#include <iostream>
using namespace std;
// Function to perform bubble sort in ascending order
void bubbleSort_Asc(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Function to perform bubble sort in descending order
void bubbleSort_Desc(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
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
    bubbleSort_Asc(a, n);
    cout << "\nSorted array in ascending order is:";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    bubbleSort_Desc(a, n);
    cout << "Sorted array in descending order is:";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    return 0;
}