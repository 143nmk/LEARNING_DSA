/* Cpp code to find the maximum length of pairs that can be formed such that each pair is disjoint */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> intervals = {{5, 24}, {39, 60}, {5, 28}, {27, 40}, {50, 90}};
    sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    int ans = 1;
    int currend = intervals[0].second;

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].first >= currend)
        {
            ans++;
            currend = intervals[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}