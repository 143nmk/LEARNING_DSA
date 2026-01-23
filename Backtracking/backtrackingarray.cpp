/* Cpp, code to perform backtracking on an array*/

#include <iostream>
#include <vector>
using namespace std;

void backtrackingArray(vector<int> &v, int n, int index)
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    v[index] = index + 1;
    backtrackingArray(v, n, index + 1);
    v[index] = v[index] - 2;
}

int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> v(n);
    // cout << "Enter the elements of the array:";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }
    backtrackingArray(v, n, 0);
    cout << "The modified array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}