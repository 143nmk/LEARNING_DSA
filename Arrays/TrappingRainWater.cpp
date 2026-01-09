/* Cpp code to calculate the amount of water  trapped */

#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> &v, int n)
{
    int leftMax[n];
    int rightMax[n];
    leftMax[0] = v[0];
    rightMax[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], v[i - 1]);
        }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], v[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int currwater = min(leftMax[i], rightMax[i]) - v[i];
        if (currwater > 0)
        {
            ans += currwater;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the n value:";
    cin >> n;
    vector<int> v;
    cout << "Enter the heights of pillars:";
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    cout << "The maximum amount of rain water trapped is: " << trappingRainWater(v, n) << endl;
    return 0;
}