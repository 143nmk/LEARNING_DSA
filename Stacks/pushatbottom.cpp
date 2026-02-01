/* Cpp code to push an element to the bottom of the satck */

#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }
    int ele = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(ele);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    pushAtBottom(s, 4);
    cout << s.size() << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}