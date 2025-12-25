/* Cpp code to calculate the maximum subarray for the given array
 */

#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySum1(int *a, int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum = 0;
            for (int k = i; k <= j; k++)
            {
                currSum += a[k];
            }
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}
int maximumSubarraySum2(int *a, int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += a[j];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}
int maximumSubarraySum3(int *a, int n)
{
    // Kadane's Algorithm
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "The maximum subarray sum(using brute force) is:" << maximumSubarraySum1(a, n) << endl;
    cout << "The maximum subarray sum(using brute force) is:" << maximumSubarraySum2(a, n) << endl;
    cout << "The maximum subarray sum(using brute force) is:" << maximumSubarraySum3(a, n) << endl;
    return 0;
}