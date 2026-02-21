/* Cpp code to implement the interleave of two queues*/

#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> &org)
{
    int n = org.size();
    queue<int> q;
    for (int i = 0; i < n / 2; i++)
    {
        q.push(org.front());
        org.pop();
    }
    while (!q.empty())
    {
        org.push(q.front());
        q.pop();
        org.push(org.front());
        org.pop();
    }
}

int main()
{
    queue<int> org;
    for (int i = 1; i <= 10; i++)
    {
        org.push(i);
    }
    interleave(org);
    while (!org.empty())
    {
        cout << org.front() << " ";
        org.pop();
    }
    cout << endl;
    return 0;
}