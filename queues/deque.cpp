/*Cpp code to demonstrate the deque */

#include <iostream>
#include <deque>
using namespace std;
void print(deque<int> d)
{
    while (!d.empty())
    {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;
}

int main()
{
    deque<int> d;
    d.push_front(1);
    d.push_front(2);
    d.push_back(3);
    d.push_back(4);
    print(d);
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_front();
    print(d);
    d.pop_back();
    print(d);
}