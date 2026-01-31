/* Cpp code to imlement the stack using linked list*/

#include <iostream>
#include <list>
using namespace std;

class Stack
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        if (ll.empty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        return ll.pop_front();
    }

    void print()
    {
        if (ll.empty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        for (auto it = ll.begin(); it != ll.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    int top()
    {
        if (ll.empty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return ll.front();
    }
};

int main()
{
    Stack s;
    // int n;
    // cout << "Enter the size of stack:";
    // cin >> n;
    int ele;
    cout << "Enter the elements of the stack:";
    while (true)
    {
        cin >> ele;
        if (ele == -1)
            break;
        s.push(ele);
    }
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    return 0;
}