/* Cpp code to count the distinct elements in an array*/

#include <bits/stdc++.h>
using namespace std;

int countdistinct(vector<int> &arr)
{
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }

    return s.size();
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 3, 4, 5, 6, 7};

    cout << countdistinct(arr) << endl;

    return 0;
}