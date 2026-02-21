/* Cpp code to implement the queue using stack*/

#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

class Queue
{
    stack<int> s1, s2;

public:
    void push(int data)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        s1.pop();
    }
    int front()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.top();
    }
    bool empty()
    {
        return s1.empty();
    }
    void printQueue()
    {
        print(s1);
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.printQueue();
    q.pop();
    cout << q.front() << endl;
    q.printQueue();
    return 0;
}