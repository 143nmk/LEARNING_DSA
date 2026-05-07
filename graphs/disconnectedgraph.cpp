#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    list<int> *graph;
    bool directed;

public:
    Graph(int n, bool directed = false)
    {
        this->n = n;
        graph = new list<int>[n];
        this->directed = directed;
    }
    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        if (!directed)
        {
            graph[v].push_back(u);
        }
    }
    void dfs(int src, vector<bool> &visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto v : graph[src])
        {
            if (!visited[v])
            {
                dfs(v, visited);
            }
        }
    }
    void DisconnectedGraph()
    {
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited);
                cout << endl;
            }
        }
        
    }
};

int main()
{
    Graph g(10);
    g.addEdge(0, 2);
    g.addEdge(2, 5);
    g.addEdge(1, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 9);
    g.addEdge(4, 3);
    g.addEdge(3, 8);
    g.addEdge(8, 7);
    g.DisconnectedGraph();
    return 0;
}