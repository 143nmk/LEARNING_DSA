/* Cpp code to implement the linear search on arrays*/

#include <iostream>
using namespace std;

int LinearSearch(int *a, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of arrays:";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the target value:";
    int target;
    cin >> target;
    cout << "The index of the target " << target << " is " << LinearSearch(a, n, target) << endl;
    return 0;
}