#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, weight;
};

void BellmanFord(int V, vector<Edge> &edges, int src)
{
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    for (int i = 1; i < V; i++)
    {
        for (auto edge : edges)
        {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    for (auto edge : edges)
    {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v])
        {
            cout << "Negative edge weight present!";
            return;
        }
    }

    cout << "Distance from " << src << " to all nodes";
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << src << " -> " << i << " Cannot be reached" << endl;
        }
        else
        {
            cout << src << " -> " << i << " : " << dist[i] << endl;
        }
    }
}
int main()
{
    int V = 5; // number of vertices
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    int src = 0;
    BellmanFord(V, edges, src);

    return 0;
}