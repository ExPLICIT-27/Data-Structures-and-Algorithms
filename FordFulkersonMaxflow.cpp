// ford fulkerson algo for max flow problem using dfs
#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> capacity;

public:
    Graph(int v) : V(v)
    {
        adjMatrix.resize(V);
        capacity.resize(V, vector<int>(V, 0));
    }
    // updating the adjacency matrix as well the capacity matrix
    void addEdge(int u, int v, int f)
    {
        capacity[u][v] += f;
        adjMatrix[u].push_back(v), adjMatrix[v].push_back(u);
    }
    // finding augmenting paths (note : no updates to the capacity, all im doing is finding an exisiting path from source to sink)
    int dfs(int u, int t, vector<bool> &visited, vector<int> &parent)
    {
        visited[u] = true;
        if (u == t)
            return true;
        for (int v : adjMatrix[u])
        {
            if (!visited[v] && capacity[u][v] > 0)
            {
                parent[v] = u;
                if (dfs(v, t, visited, parent))
                    return true;
            }
        }
        return false;
    }
    // main part of the code, i keep finding augmenting paths and update the
    // the capacities till i cant find any more augmenting paths
    int fordFulkerson(int s, int t)
    {
        int maxFlow = 0;
        vector<int> parent(V);
        while (true)
        {
            vector<bool> visited(V, false);
            if (!dfs(s, t, visited, parent))
                break;

            int flow = INT_MAX;
            for (int v = t; v != s; v = parent[v])
            {
                int u = parent[v];
                flow = min(flow, capacity[u][v]);
            }
            for (int v = t; v != s; v = parent[v])
            {
                int u = parent[v];
                capacity[u][v] -= flow, capacity[v][u] += flow;
            }
            maxFlow += flow;
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
    cout << "Max flow : " << g.fordFulkerson(0, V - 1);
    return 0;
}