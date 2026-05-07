/* Cpp code to implement the kruskals algorithm*/

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int wt;
    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph
{
public:
    int V;
    vector<Edge> edges;
    vector<int> parent;
    vector<int> rank;
    Graph(int V)
    {
        this->V = V;

        for (int i = 0; i < V ; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    void addEdge(Edge e)
    {
        edges.push_back(e);
    }

    int find(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void UnionbyRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);
        if (rank[parA] == rank[parB])
        {
            parent[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
        {
            parent[parB] = parA;
        }
        else
        {
            parent[parA] = parB;
        }
    }

    int KruskalMST()
    {
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)
             { return a.wt < b.wt; });
        int V = edges.size();
        int count = 0;
        int cost = 0;
        for (Edge e : edges)
        {
            if (count > V - 1)
            {
                break;
            }
            int paru = find(e.u);
            int parv = find(e.v);
            if (paru != parv)
            {
                cost += e.wt;
                UnionbyRank(paru, parv);
                count++;
            }
        }
        return cost;
    }
};

int main()
{
    Graph graph(4);
    graph.addEdge(Edge(0, 1, 10));
    graph.addEdge(Edge(0, 2, 15));
    graph.addEdge(Edge(0, 3, 30));
    graph.addEdge(Edge(1, 3, 40));
    graph.addEdge(Edge(2, 3, 50));
    cout << "Cost of MST is: " << graph.KruskalMST() << endl;
}