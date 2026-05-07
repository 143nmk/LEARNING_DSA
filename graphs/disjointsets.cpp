/* Cpp code to implement the disjoint set data structure*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    int n;
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int uparent = find(u);
        int vparent = find(v);

        if (rank[uparent] == rank[vparent])
        {
            parent[vparent] = uparent;
            rank[uparent]++;
        }
        else if (rank[uparent] > rank[vparent])
        {
            parent[vparent] = uparent;
        }
        else
        {
            parent[uparent] = vparent;
        }
    }
    void getInfo()
    {
        for (int i = 0; i < n; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DisjointSet ds(6);
    ds.unionByRank(0, 2);
    ds.unionByRank(1, 3);
    ds.unionByRank(2, 5);
    ds.unionByRank(0, 3);
    ds.unionByRank(0, 4);
    ds.getInfo();

    return 0;
}
