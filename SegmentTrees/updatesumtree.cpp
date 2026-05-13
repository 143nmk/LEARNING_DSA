/* Cpp code to create a sum segment tree with update functionality*/
/* Cpp code to create a sum segment tree*/

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
    vector<int> tree;

public:
    SegmentTree(vector<int> arr)
    {
        int n = arr.size();
        tree.resize(4 * n);
    }

    void buildTree(vector<int> arr, int start, int end, int index)
    {
        if (start == end)
        {
            tree[index] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(arr, start, mid, 2 * index + 1);
        buildTree(arr, mid + 1, end, 2 * index + 2);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    void print()
    {
        for (int i = 0; i < tree.size(); i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    void helper(int index, int newVal, int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = newVal;
            return;
        }

        int mid = start + (end - start) / 2;
        if (index >= start && index <= mid)
        {
            helper(index, newVal, start, mid, 2 * node + 1);
        }
        else
        {
            helper(index, newVal, mid + 1, end, 2 * node + 2);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int index, int newVal)
    {
        helper(index, newVal, 0, tree.size() / 4 - 1, 0);
    }
};

int main()
{
    int n;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree st(arr);
    st.buildTree(arr, 0, arr.size() - 1, 0);
    st.print();
    st.update(2, 10);
    st.print();
    return 0;
}