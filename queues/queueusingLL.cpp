/* Cpp code to implement the queue operations using a linked list*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    int frontValue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        return front == NULL;
    }

    void printQueue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        Node *temp = front;
        while (!temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    Queue q;
    q.push(1);
    q.push(2);
    q.printQueue();
    cout << q.frontValue() << endl;
    q.pop();
    q.printQueue();
    return 0;
}