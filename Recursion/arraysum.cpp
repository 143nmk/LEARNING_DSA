/* Cpp cdoe to calculate the sum of elements in an array using recursion */

#include <iostream>
#include <vector>
using namespace std;

int arraySum(vector<int> &v, int i)
{
    if (i == v.size())
        return 0;
    return v[i] + arraySum(v, i + 1);
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
    cout << "The sum of elements of the array is:" << arraySum(v, 0);
}