/* Cpp code to find the fibonacci value */

#include <bits/stdc++.h>
using namespace std;

int fibonacciRecursion(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int fibonacciMemorisation(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fibonacciMemorisation(n - 1, dp) + fibonacciMemorisation(n - 2, dp);
    return dp[n];
}

int fibonacciTabulation(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 8;
    cout << "Fibonacci value using recursion: " << fibonacciRecursion(n) << endl;
    vector<int> dp(n + 1, -1);
    cout << "Fibonacci value using memorisation: " << fibonacciMemorisation(n, dp) << endl;
    cout << "Fibonacci value using tabulation: " << fibonacciTabulation(n) << endl;
    return 0;
}