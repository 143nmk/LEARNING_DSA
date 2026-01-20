/* Cpp code for quicksort */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    // pi is partitioning index, arr[pi] is now at right place
    int pi = partition(arr, low, high);

    // Recursively sort elements before partition and after partition
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
}

int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Original array: ";
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    quicksort(v, 0, n - 1);

    cout << "Sorted array: \n";
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}