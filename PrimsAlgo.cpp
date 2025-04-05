// Object oriented approach to Prims Minimum Spanning Tree Algorithm
#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adjcMatrix;

    int minDis(vector<int> &dist, vector<bool> &mstSet)
    {
        int mindist = INT_MAX, minidx = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mstSet[i] && dist[i] < mindist)
            {
                mindist = dist[i], minidx = i;
            }
        }
        return minidx;
    }
    void PrintMst(vector<int> &parents)
    {
        int mindist = 0;
        for (int i = 1; i < V; i++)
        {
            cout << parents[i] << " -> " << i << " Weight : " << adjcMatrix[parents[i]][i] << endl;
            mindist += adjcMatrix[parents[i]][i];
        }
        cout << "Minimum Spanning Connection: " << mindist;
    }

public:
    Graph(int v) : V(v)
    {
        adjcMatrix.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v, int w)
    {
        adjcMatrix[u][v] = adjcMatrix[v][u] = w;
    }
    void PrimsMST()
    {
        vector<int> dist(V, INT_MAX);
        vector<bool> mstSet(V, false);
        vector<int> parents(V, -1);

        dist[0] = 0;
        for (int count = 0; count < V - 1; count++)
        {
            int u = minDis(dist, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
            {
                if (!mstSet[v] && adjcMatrix[u][v] && adjcMatrix[u][v] < dist[v])
                {
                    parents[v] = u;
                    dist[v] = adjcMatrix[u][v];
                }
            }
        }
        PrintMst(parents);
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
    g.PrimsMST();
    return 0;
}