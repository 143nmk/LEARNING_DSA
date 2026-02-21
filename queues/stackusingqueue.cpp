/* Cpp code to implement a stack using queue*/

#include <iostream>
#include <queue>
using namespace std;
void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
class Stack
{
    queue<int> q1, q2;

public:
    void push(int data)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.pop();
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }
    bool empty()
    {
        return q1.empty();
    }
    void printStack()
    {
        print(q1);
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.printStack();
    s.pop();
    cout << s.top() << endl;
    s.printStack();

    return 0;
}