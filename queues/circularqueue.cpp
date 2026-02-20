/* Cpp code to implement the circular queue using arrays*/
#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear;
    int capacity;
    int curSize;

public:
    CircularQueue(int capacity)
    {
        arr = new int[capacity];

        front = 0;
        rear = -1;
        this->capacity = capacity;
        curSize = 0;
    }
    void push(int data)
    {
        if (curSize == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        curSize++;
    }
    void pop()
    {
        if (curSize == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % capacity;
        curSize--;
    }
    int frontValue()
    {
        if (curSize == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        return curSize == 0;
    }

    void print()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % capacity)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    CircularQueue q(4);
    q.push(21);
    q.push(23);
    q.push(6);
    q.push(9);
    q.push(521);
    q.print();
    cout << q.frontValue() << endl;
    q.pop();
    q.print();
    return 0;
}
