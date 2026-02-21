/* Cpp code to find the next greater element in an array */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextGreaterElement(vector<int> &v)
{
    int ans[v.size()];
    stack<int> s;
    int n = v.size() - 1;
    ans[n] = -1;
    s.push(v[n]);
    for (int i = n - 1; i >= 0; i--)
    {
        int ele = v[i];
        while (!s.empty() && ele >= s.top())
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(ele);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {6, 8, 0, 1, 3};
    // for(auto it: v){
    //     cout<<it<<" ";
    // }
    cout << endl;
    nextGreaterElement(v);
    return 0;
}