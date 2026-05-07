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

    void bfs(int start = 0)
    {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v : graph[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
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
    g.bfs(1);
    return 0;
}