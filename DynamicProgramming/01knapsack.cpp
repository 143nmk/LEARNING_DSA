/* Cpp code to imlpement the 0-1 knapsack */

#include <bits/stdc++.h>
using namespace std;

int knapsackRec(vector<int> val, vector<int> wt, int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    int itemwt = wt[n - 1];
    int itemval = val[n - 1];
    if (itemwt > W)
        return knapsackRec(val, wt, W, n - 1);
    return max(knapsackRec(val, wt, W, n - 1), itemval + knapsackRec(val, wt, W - itemwt, n - 1));
}
int knapsackMemo(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    int itemwt = wt[n - 1];
    int itemval = val[n - 1];
    if (itemwt > W)
        return dp[n][W] = knapsackMemo(val, wt, W, n - 1, dp);
    return dp[n][W] = max(knapsackMemo(val, wt, W, n - 1, dp), itemval + knapsackMemo(val, wt, W - itemwt, n - 1, dp));
}

int knapsackTab(vector<int> val, vector<int> wt, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> wt = {2, 5, 1, 3, 4};
    vector<int> val = {15, 14, 10, 45, 30};

    int W = 7;
    int n = wt.size();
    cout << knapsackRec(val, wt, W, n) << endl;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << knapsackMemo(val, wt, W, n, dp) << endl;
    cout << knapsackTab(val, wt, W, n) << endl;
    return 0;
}