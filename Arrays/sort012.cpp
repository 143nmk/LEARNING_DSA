/* Cpp code to sort the array of 0's,1's and 2's */

#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int> &v, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid], v[high]);
            high--;
        }
    }
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
     sort012(v, n);
    for (int it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}