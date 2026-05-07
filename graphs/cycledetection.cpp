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
    bool dfs(int src, int parent, vector<bool> &visited)
    {
        visited[src] = true;
        for (auto v : graph[src])
        {
            if (!visited[v])
            {
                if (dfs(v, src, visited))
                    return true;
            }
            else if (v != parent)
                return true;
        }
        return false;
    }
    bool cycleundirected()
    {
        vector<bool> visited(n, false);
        if (dfs(0, -1, visited))
            return true;
        else
            return false;
    }
    bool dfs(int src, int dest, vector<bool> &visited, vector<bool> &path)
    {
        visited[src] = true;
        path[src] = true;
        for (auto v : graph[src])
        {
            if (!visited[v])
            {
                if (dfs(v, dest, visited, path))
                {
                    return true;
                }
            }
            else if (path[v])
            {
                return true;
            }
        }
        path[src] = false;
        return false;
    }

    bool cycleDirected()
    {
        vector<bool> visited(n, false);
        vector<bool> path(n, false);
        for (int i = 0; i < n; i++)
        {
            if (dfs(0, -1, visited, path))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Graph g(5, true);
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    // g.addEdge(4, 9);
    // g.addEdge(4, 3);
    // g.addEdge(3, 8);
    // g.addEdge(8, 7);
    cout << g.cycleDirected() << endl;
    return 0;
}