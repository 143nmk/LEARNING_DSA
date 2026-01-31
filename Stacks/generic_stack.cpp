/* Cpp code to implement the generic stack usiung class template */

#include <iostream>
#include <vector>
using namespace std;

template <class T>

class Stack
{
    vector<T> v;

public:
    void push(T val)
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

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return T();
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
    Stack<char> s;
    // int n;
    // cout << "Enter the size of stack:";
    // cin >> n;
    char ele;
    cout << "Enter the elementws of the stack:";
    while (true)
    {
        cin >> ele;
        if (ele == '.')
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