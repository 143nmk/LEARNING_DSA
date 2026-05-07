#include<bits/stdc++.h>
using namespace std;

int unboundedknapsackTab(vector<int> val, vector<int> wt, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i-1][w], val[i - 1] + dp[i][w - wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int W = 7;
    int n = wt.size();
    cout<<unboundedknapsackTab(val,wt,W,n)<<endl;
    return 0;
}