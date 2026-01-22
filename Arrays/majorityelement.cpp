/* Cpp code to find the majority element in an array */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement1(vector<int> &v, int n)
{
    unordered_map<int, int> countmap;
    for (int i = 0; i < n; i++)
    {
        countmap[v[i]]++;
    }
    for (auto it : countmap)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
    }
    return -1; // In case there is no majority element
}

int majorityElement2(vector<int> &v, int n)
{
    int candidate = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = v[i];
        }
        if (v[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    // Verify if the candidate is actually the majority element
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == candidate)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return candidate;
    }
    return -1; // In case there is no majority element
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
    int result = majorityElement1(v, n);
    cout << "The majority element is: " << result << endl;
    result = majorityElement2(v, n);
    cout << "The majority element is: " << result << endl;
    return 0;
}