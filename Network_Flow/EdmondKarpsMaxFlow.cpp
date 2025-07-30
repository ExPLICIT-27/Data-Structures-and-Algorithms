// edmond karps max flow algo
#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) : V(v)
    {
        adjMatrix.resize(V);
        capacity.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v, int f)
    {
        adjMatrix[u].push_back(v);
        adjMatrix[v].push_back(u);
        capacity[u][v] += f;
    }
    int bfs(int s, int t, vector<int> &parent)
    {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;

        q.push({s, INT_MAX});
        while (!q.empty())
        {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();
            for (int v : adjMatrix[u])
            {
                if (parent[v] == -1 && capacity[u][v] > 0)
                {
                    parent[v] = u;
                    int newFlow = min(flow, capacity[u][v]);
                    if (v == t)
                        return newFlow;
                    q.push({v, newFlow});
                }
            }
        }
        return 0;
    }
    int edmondsKarp(int s, int t)
    {
        int maxFlow = 0;
        vector<int> parent(V);

        int newFlow;
        while ((newFlow = bfs(s, t, parent)))
        {
            maxFlow += newFlow;
            int v = t;
            while (v != s)
            {
                int u = parent[v];
                capacity[u][v] -= newFlow;
                capacity[v][u] += newFlow;
                v = u;
            }
        }
        return maxFlow;
    }
};
int main()
{
    int V;
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    int edges;
    cout << "\nEnter the number of edges: ";
    cin >> edges;
    Graph g = Graph(V);
    while (edges--)
    {
        cout << "\nEnter edge connection and flow capacity(u, v, w): ";
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cout << "Max flow : " << g.edmondsKarp(0, V - 1);
    return 0;
}