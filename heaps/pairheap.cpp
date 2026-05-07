#include <bits/stdc++.h>
using namespace std;
struct comparePair
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

int main()
{
    // priority_queue<pair<int, int>> p;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparePair> p;
    p.push({10, 1});
    p.push({20, 2});
    p.push({5, 3});
    p.push({15, 4});

    while (!p.empty())
    {
        pair<int, int> p1 = p.top();
        cout << p1.first << " " << p1.second << endl;
        p.pop();
    }
}