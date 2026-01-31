/* Cpp code to implement the stack data structure using linked list */

#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "The element " << v.back() << " is removed." << endl;
        return v.pop_back();
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return v[v.size() - 1];
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements:" << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    int n;
    cout << "Enter the size of stack:";
    cin >> n;
    int ele;
    cout << "Enter the elementws of the stack:";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        s.push(ele);
    }
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    return 0;
}