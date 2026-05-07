/* Cpp code to find the union and intersection of two arrays*/

#include <bits/stdc++.h>
using namespace std;

void unionarray(vector<int> &a1, vector<int> &a2)
{
    unordered_set<int> s;
    for (int i = 0; i < a1.size(); i++)
    {
        s.insert(a1[i]);
    }
    for (int i = 0; i < a2.size(); i++)
    {
        s.insert(a2[i]);
    }

    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
}

void intersection(vector<int> &a1, vector<int> &a2)
{
    unordered_set<int> s;
    for (int i = 0; i < a1.size(); i++)
    {
        s.insert(a1[i]);
    }
    for (int i = 0; i < a2.size(); i++)
    {
        if (s.find(a2[i]) != s.end())
        {
            cout << a2[i] << " ";
            s.erase(a2[i]);
        }
    }
    cout << endl;
}

int main()
{
    vector<int> a1 = {1, 2, 4, 5, 2};
    vector<int> a2 = {2, 3, 5, 7, 4};

    unionarray(a1, a2);
    intersection(a1, a2);

    return 0;
}