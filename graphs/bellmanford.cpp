/* Cpp code to implement the bellman-ford algorithm*/

#include <bits/stdc++.h>
using namespace std;

class EdgeList
{
public:
    int v;
    int wt;

    EdgeList(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void BellmanFord(int src, vector<int> &dist, vector<vector<EdgeList>> graph)
{
    dist[src] = 0;
    for (int i = 0; i < graph.size() - 1; i++)
    {
        for (int u = 0; u < graph.size(); u++)
        {
            vector<EdgeList> edges = graph[u];
            for (EdgeList e : edges)
            {
                if (dist[e.v] > dist[u] + e.wt)
                {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<EdgeList>> graph(V);
    graph[0].push_back(EdgeList(1, 2));
    graph[0].push_back(EdgeList(2, 4));
    graph[1].push_back(EdgeList(2, -4));
    graph[2].push_back(EdgeList(3, 2));
    graph[3].push_back(EdgeList(4, 4));
    graph[4].push_back(EdgeList(1, -1));
    vector<int> dist(V, INT_MAX);
    BellmanFord(0, dist, graph);
    for (int i = 0; i < V; i++)
    {
        cout << "Distance from source to " << i << " is " << dist[i] << endl;
    }

    // for (int i = 0; i < V; i++)
    // {
    //     for (EdgeList e : graph[i])
    //     {
    //         cout << i << "->" << e.v << " wt: " << e.wt << endl;
    //     }
    // }
}