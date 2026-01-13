/* Cpp code to return the length of the subarray that the sum of elements is equal to k */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubarrayWithK(vector<int> &v, int n, int k)
{
    map<int, int> m;
    int sum = 0;
    int maxlen = 0;
    int rem = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        rem = sum - k;
        if (m.find(rem) != m.end())
        {
            maxlen = max(maxlen, i - m[rem]);
        }
        if (m.find(rem) == m.end())
        {
            m[sum] = i;
        }
    }
    return maxlen;
}

int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    cout << "Enter the elements of the array:";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cout << "Enter the sum:";
    cin >> k;
    cout << "The longest subarray with sum equal to K is: " << longestSubarrayWithK(v, n, k);
    return 0;
}