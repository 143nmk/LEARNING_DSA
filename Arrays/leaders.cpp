/* Cpp code to find the leaders in an array */

#include <iostream>
#include <vector>
using namespace std;

vector<int> findLeaders(vector<int> &v, int n)
{
    vector<int> leaders;
    int maxi = v[n - 1];
    leaders.push_back(maxi);
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > maxi)
        {
            leaders.push_back(v[i]);
            maxi = v[i];
        }
    }
    return leaders;
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
    cout << "Leaders in the array are: ";
    vector<int> ans = findLeaders(v, n);
    for (int it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}