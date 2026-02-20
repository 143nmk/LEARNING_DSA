/*Cpp code to implement the queue using stl*/

#include <iostream>
#include <queue>
using namespace std;
void printQueue(queue<string> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<string> q;
    q.push("Maha");
    q.push("Sai");
    q.push("Jeevan");
    q.push("Kavya");
    cout << "The front element of the queue is: " << q.front() << endl;
    cout << "The back element of the queue is: " << q.back() << endl;
    cout << "The size of the queue is: " << q.size() << endl;
    printQueue(q);
    q.pop();
    cout << "The front element of the queue after pop is: " << q.front() << endl;
    printQueue(q);
    return 0;
}