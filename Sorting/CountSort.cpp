/* Cpp code to sort the array using count sort */

#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &v, int n)
{
    int max = v[0];
    for (int i = 1; i < n; i++)
    {
        if (max < v[i])
        {
            max = v[i];
        }
    }
    vector<int> frequency(max + 1, 0);
    for (int i = 0; i < n; i++)
    {
        frequency[v[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j < frequency[i]; j++)
        {
            v[index++] = i;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array:" << endl;
    cin >> n;
    cout << "Enter the elements of the array:" << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countSort(arr, n);
    cout << "Sorted array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}