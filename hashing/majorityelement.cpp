/* Cpp cdoe to calculate the majority element*/

#include <bits/stdc++.h>
using namespace std;

void majorityElement(vector<int> &nums)
{
    unordered_map<int, int> count;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        count[nums[i]]++;
    }
    for (auto it : count)
    {
        cout << it.first << " " << it.second << endl;
    }
    for (pair<int, int> p : count)
    {
        if (p.second > n / 3)
        {
            cout << p.first << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 2, 4, 2, 5, 3, 6, 2, 7, 2, 2, 2, 1, 3, 1, 1, 3, 1};

    majorityElement(nums);

    return 0;
}