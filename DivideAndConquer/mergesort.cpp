/* Cpp code to perform the merge sort on the given array */

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int low, int high, int mid)
{
    int i = low, j = mid + 1, k = 0;
    vector<int> temp(high - low + 1);
    while (i <= mid && j <= high)
    {
        if (v[i] < v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = v[i++];
    }
    while (j <= high)
    {
        temp[k++] = v[j++];
    }
    for (int i = 0; i < k; i++)
    {
        v[low + i] = temp[i];
    }
}

void mergeSort(vector<int> &v, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, high, mid);
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

    mergeSort(v, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}