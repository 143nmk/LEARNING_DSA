/* Cpp code to compute the union of two sorted arrays */

#include <iostream>
#include <vector>
using namespace std;
vector<int> unionOfArrays(vector<int> &a, vector<int> &b, int m, int n)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
    }
    while (i < m)
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < n)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    int m, n;
    cout << "Enter the size of the arrays:";
    cin >> m >> n;
    vector<int> v1(m);
    vector<int> v2(n);
    cout << "Enter the elements of the first array in sorted:";
    for (int i = 0; i < m; i++)
    {
        cin >> v1[i];
    }
    cout << "Enter the elements of the second array in sorted:";
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    vector<int> v = unionOfArrays(v1, v2, m, n);
    cout << "The union of two arrays is:";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}