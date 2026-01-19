/* Cpp code to sort the array of 0's,1's and 2's */

#include <iostream>
#include <vector>
using namespace std;

vector<int> sort012(vector<int> v, int n)
{
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
    vector<int> ans = sort012(v, n);
    for (int it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}