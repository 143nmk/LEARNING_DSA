/* Cpp code to reverse agiven stack */

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
void reverseStack(stack<int> &s)
{

    if (s.empty())
    {
        return;
    }
    int ele = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, ele);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
