// OOPS Approach to Djikstras shortest path algorithm
#include <bits/stdc++.h>
#include <climits>

using namespace std;
class Graph
{
private:
    int V;
    vector<vector<int>> adjMatrix;
    int minDist(vector<int> &dist, vector<bool> &visited)
    {
        int mindist = INT_MAX, minidx = -1;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < mindist)
            {
                mindist = dist[i], minidx = i;
            }
        }
        return minidx;
    }
    void printPath(vector<int> &parents, int dest)
    {
        if (parents[dest] == -1)
        {
            cout << dest;
            return;
        }
        printPath(parents, parents[dest]);
        cout << " -> " << dest;
    }

public:
    Graph(int v) : V(v)
    {
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v, int w)
    {
        adjMatrix[u][v] = adjMatrix[v][u] = w;
    }
    void DjikstrasAlgo(int src, int dest)
    {
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parents(V, -1);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            int u = minDist(dist, visited);
            visited[u] = true;
            for (int v = 0; v < V; v++)
            {
                if (adjMatrix[u][v] && !visited[v] && (adjMatrix[u][v] + dist[u] < dist[v]))
                {
                    dist[v] = adjMatrix[u][v] + dist[u];
                    parents[v] = u;
                }
            }
        }
        cout << "\nDistance from " << src << " to " << dest << " : " << dist[dest];
        cout << "\nPath : ";
        printPath(parents, dest);
    }
};
int main()
{
    int vertices;
    cout << "\nEnter the number of vertices : ";
    cin >> vertices;
    Graph g = Graph(vertices);
    cout << "\nEnter the number of edges: ";
    int edges;
    cin >> edges;
    while (edges--)
    {
        int u, v, w;
        cout << "\nEnter the edge connection and the weight: ";
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.DjikstrasAlgo(0, vertices - 1);
    return 0;
}