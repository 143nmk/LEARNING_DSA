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

    int rangeSum(int qi, int qj, int start, int end, int index)
    {
        if (qi < start || qi > end)
        {
            return 0;
        }

        if (qi <= start && qj >= end)
        {
            return tree[index];
        }

        int mid = start + (end - start) / 2;
        int leftSum = rangeSum(qi, qj, start, mid, 2 * index + 1);
        int rightSum = rangeSum(qi, qj, mid + 1, end, 2 * index + 2);
        return leftSum + rightSum;
    }

    int Query(int qi, int qj, vector<int> arr)
    {
        return rangeSum(qi, qj, 0, arr.size() - 1, 0);
    }
};

int main()
{
    int n;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree st(arr);
    st.buildTree(arr, 0, arr.size() - 1, 0);
    cout << st.Query(2, 5, arr) << endl;
    return 0;
}