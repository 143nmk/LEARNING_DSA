/* Cpp code to find the inetrsection of two sorted arrays */

#include <iostream>
#include <vector>
using namespace std;
vector<int> intersectionOfArrays(vector<int> &a, vector<int> &b, int m, int n)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
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
    vector<int> v = intersectionOfArrays(v1, v2, m, n);
    cout << "The union of two arrays is:";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}