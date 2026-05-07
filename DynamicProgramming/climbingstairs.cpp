/* Cpp code to find the fibonacci value */

#include <bits/stdc++.h>
using namespace std;

int climbingStairsRecursion(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return climbingStairsRecursion(n - 1) + climbingStairsRecursion(n - 2);
}

int climbingStairsMemorisation(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = climbingStairsMemorisation(n - 1, dp) + climbingStairsMemorisation(n - 2, dp);
    return dp[n];
}

int climbingStairsTabulation(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 6;
    cout << "Climbing Stairs value using recursion: " << climbingStairsRecursion(n) << endl;
    vector<int> dp(n + 1, -1);
    cout << "Climbing Stairs value using memorisation: " << climbingStairsMemorisation(n, dp) << endl;
    cout << "Climbing Stairs value using tabulation: " << climbingStairsTabulation(n) << endl;
    return 0;
}