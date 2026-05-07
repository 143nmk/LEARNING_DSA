#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int i, int n)
{
    int parent = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
    int maxidx = parent;

    if (leftchild < n && v[leftchild] > v[maxidx])
    {
        maxidx = leftchild;
    }
    if (rightchild < n && v[rightchild] > v[maxidx])
    {
        maxidx = rightchild;
    }

    if (maxidx != parent)
    {
        swap(v[maxidx], v[parent]);
        heapify(v, maxidx, n);
    }
}

/*

//for descending order
void heapify(vector<int> &v, int i, int n)
{
    int parent = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
    int maxidx = parent;

    if (leftchild < n && v[leftchild] < v[maxidx])
    {
        maxidx = leftchild;
    }
    if (rightchild < n && v[rightchild] < v[maxidx])
    {
        maxidx = rightchild;
    }

    if (maxidx != parent)
    {
        swap(v[maxidx], v[parent]);
        heapify(v, maxidx, n);
    }
}
*/

void heapsort(vector<int> &v)
{
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, i, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}

int main()
{
    vector<int> v = {5, 2, 9, 1, 10, 6};
    heapsort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}