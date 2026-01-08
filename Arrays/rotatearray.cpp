/* Cpp code to left rotate an array by k positions */

#include <bits/stdc++.h>
using namespace std;
// Brute Force Approach
void rotateArray1(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n; // in case k is greater than n
    int a[k];
    for (int i = 0; i < k; i++)
    {
        a[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = a[i - n + k];
    }
}

// Optimal Approach
void rotateArray2(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n; // in case k is greater than n
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the number of positions to rotate the array:";
    cin >> k;
    rotateArray2(arr, k);
    cout << "Array after rotation:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}