/* Cpp code to implement the dijstras algorithm*/

#include <bits/stdc++.h>
#include <queue>
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

void DijkstraAlgo(int src, vector<int> &dist, vector<vector<EdgeList>> graph)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (pq.size() > 0)
    {
        int u = pq.top().second;
        pq.pop();
        vector<EdgeList> edges = graph[u];
        for (EdgeList e : edges)
        {
            if (dist[e.v] > dist[u] + e.wt)
            {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }
}

int main()
{
    int V = 6;
    vector<vector<EdgeList>> graph(V);
    graph[0].push_back(EdgeList(1, 2));
    graph[0].push_back(EdgeList(2, 4));
    graph[1].push_back(EdgeList(2, 1));
    graph[1].push_back(EdgeList(3, 7));
    graph[2].push_back(EdgeList(4, 3));
    graph[3].push_back(EdgeList(5, 1));
    graph[4].push_back(EdgeList(3, 2));
    graph[4].push_back(EdgeList(5, 5));

    vector<int> dist(V, INT_MAX);
    DijkstraAlgo(0, dist, graph);
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