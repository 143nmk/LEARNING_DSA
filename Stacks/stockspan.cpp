/* Cpp code to calculate the stock span */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpan(vector<int> &v)
{
    vector<int> span;
    stack<int> s;
    s.push(0);
    span.push_back(1);
    for (int i = 1; i < v.size(); i++)
    {
        while (!s.empty() && v[s.top()] <= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            span.push_back(i + 1);
        }
        else
        {
            span.push_back(i - s.top());
        }
        s.push(i);
    }
    for (int it : span)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 85, 100};
    stockSpan(v);
    return 0;
}