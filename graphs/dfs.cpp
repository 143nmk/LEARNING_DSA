#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    list<int> *graph;

public:
    Graph(int n)
    {
        this->n = n;
        graph = new list<int>[n];
    }
    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void print()
    {
        for (int u = 0; u < n; u++)
        {
            cout << u << " ";
            list<int> neighbors = graph[u];
            for (int v : neighbors)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void dfs(int u, vector<int> &visited)
    {
        visited[u] = 1;
        cout << u << " ";
        for (int v : graph[u])
        {
            if (!visited[v])
            {
                dfs(v, visited);
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    // g.print();
    vector<int> visited(5, 0);
    g.dfs(0, visited);
    return 0;
}