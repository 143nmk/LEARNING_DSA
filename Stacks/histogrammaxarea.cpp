/* Cpp code to calculate the max area of a histogram */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maxArea(vector<int> &v)
{
    stack<int> s;
    int leftMin[v.size()];
    int rightMin[v.size()];
    // left minimum
    leftMin[0] = -1;
    s.push(0);
    for (int i = 1; i < v.size(); i++)
    {
        int curr = v[i];
        while (!s.empty() && curr <= v[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            leftMin[i] = -1;
        }
        else
        {
            leftMin[i] = s.top();
        }
        s.push(i);
    }

    // right minimum
    while (!s.empty())
    {
        s.pop();
    }

    int n = v.size();
    rightMin[n - 1] = n;
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        int curr = v[i];
        while (!s.empty() && curr <= v[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            rightMin[i] = n;
        }
        else
        {
            rightMin[i] = s.top();
        }
        s.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        cout << leftMin[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << rightMin[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int ht = v[i];
        int width = rightMin[i] - leftMin[i] - 1;
        int area = ht * width;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << "Max Area: " << maxArea(v);
    return 0;
}