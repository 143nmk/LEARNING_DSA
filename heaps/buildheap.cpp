#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> v;

public:
    void insert(int data)
    {
        v.push_back(data);
        int curridx = v.size() - 1;
        int parentidx = (curridx - 1) / 2;

        while (curridx > 0 && v[parentidx] < v[curridx])
        {
            swap(v[parentidx], v[curridx]);
            curridx = parentidx;
            parentidx = (curridx - 1) / 2;
        }
    }
    void pop()
    {
        if (isempty())
        {
            cout << "Heap is empty" << endl;
            return;
        }
        v[0] = v[v.size() - 1];
        v.pop_back();
        heapify(0);
    }
    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < v.size() && v[left] > v[largest])
        {
            largest = left;
        }

        if (right < v.size() && v[right] > v[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(v[index], v[largest]);
            heapify(largest);
        }
    }
    int top()
    {
        return v[0];
    }
    bool isempty()
    {
        return v.size() == 0;
    }
};

int main()
{
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(15);
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    return 0;
}