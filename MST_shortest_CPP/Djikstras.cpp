// OOPS Approach to Djikstras shortest path algorithm
#include <bits/stdc++.h>
#include <climits>

using namespace std;
class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adjList; // node and weight
    

public:
    Graph(int v) : V(v)
    {
        adjList.resize(V);
    }
    void addEdge(int u, int v, int w)
    {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    void printPath(vector<int> parents, int dest){
        if(parents[dest] == -1){
            cout  << dest;
            return;
        }
        printPath(parents, parents[dest]);
        cout << " -> " << dest;
    }
    void DjikstrasAlgo(int src, int dest)
    {
        vector<int> dist(V, INT_MAX);
        vector<int> parents(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // weight first, for the priority queue comparator
        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v, weight] : adjList[u]){
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    parents[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        cout << "\nDistance from " << src << " to " << dest << " : " << dist[dest];
        cout << "\nPath : ";
        printPath(parents, dest);
        cout << "\n";
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