/* Cpp code to  demonstarte two sum*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> twoSumBrute(vector<int> &v, int n, int target)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> twoSumBetter(vector<int> &v, int n, int target)
{
    map<int, int> m;
    int rem = 0;
    for (int i = 0; i < n; i++)
    {
        rem = target - v[i];
        if (m.find(rem) != m.end())
        {
            return {m[rem], i};
        }
        if (m.empty() == 1 || m.find(rem) == m.end())
        {
            m[v[i]] = i;
        }
    }
    return {-1, -1};
}

vector<int> twoSumOptimal(vector<int> &v, int n, int target)
{
    // Optimal approach works for only sorted arrays...
    sort(v.begin(), v.end());
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (v[i] + v[j] == target)
        {
            return {i, j};
        }
        else if (v[i] + v[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return {-1, -1};
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
    int target;
    cout << "Enter the target sum:";
    cin >> target;
    vector<int> ans = twoSumBrute(v, n, target);
    cout << "The indices are(Brute force): " << ans[0] << " and " << ans[1] << endl;
    ans = twoSumBetter(v, n, target);
    cout << "The indices are(Better): " << ans[0] << " and " << ans[1] << endl;
    ans = twoSumOptimal(v, n, target);
    cout << "The indices are(optimal): " << ans[0] << " and " << ans[1] << endl;
    return 0;
}