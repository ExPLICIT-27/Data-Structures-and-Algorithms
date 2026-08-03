/*
This algorithm is used to solve problems related to maximum flow that can be
achieved in a graph, given a source node and a sink node

the maxmimum flow in a path is limited by the edge with the smallest 
capacity in that path

the algorithm tries to find augmenting paths (a path from the source to the sink with a non zero edge capacity)
and then updates the edge capacity by subtracting the bottleneck value from all the edges in the path.
Updating the edge involves updating reversed edges as well (it acts as a method to undo the flow in the actual direction and redirect
it elsewhere)
The augmenting paths are found via BFS for better time complexity



Now I had two questions while learning this.
1. How does an algorithm that depends on the bottleneck value of the edge not have the capacity as part of its time complexity?
2. What is a reverse edge even, what does it stand for why is it there?


Answer to the first Question.

-> Monotonically Increasing Distances: Because we use BFS, the distance (in number of edges) from the source to any node in the residual graph never decreases. It only ever goes up or stays the same.

-> The Critical Edge: In every augmenting path, at least one edge is the "bottleneck." We call this the critical edge. Once we push flow through it, its residual capacity drops to zero, and it vanishes from our residual graph.

-> The Reappearance Rule: For that vanished edge (u, v) to ever reappear in the residual graph, we have to push flow backwards across its reversed edge (v, u).

-> The Catch: We can only push flow backwards if the BFS distance to u has strictly increased since the last time (u, v) was critical.

-> The Upper Bound: Because the distance from the source to any node can't exceed the total number of vertices V(you use bfs, you dont visit a visited vertex again), any specific edge can only become critical a maximum of V/2 (each crit path kind of removes one vertex (it becomes full) and it comes down to a max of V/2 only)

Since there are $E$ edges, and each can be critical at most V/2 times, the absolute maximum number of augmenting paths is bounded by O(VE)

Finding a path via BFS takes O(E). Multiply them together, and you get a strict time complexity of O(VE^2).The algorithm guarantees termination based purely on the network's shape, not its edge weights


Question 2
- Well there are graphs in which it's simply impossible to find the optimal solution without undoing the flow
and redirecting it via the reversed edge (can use google to find such graphs, there's one present in stackOverflow)
*/

//implementation

#include <bits/stdc++.h>
#define ll long long
#define nline '\n'
#define INF INT_MAX

using namespace std;

vector<vector<int>> G; // i can use an adjacency matrix here instead of list (V^2 is cheaper than V.E^2)
vector<int> parent;

int V, E;

int bfs(int source, int sink){
    fill(parent.begin(), parent.end(), -1);

    queue<pair<int, int>> q;
    q.push({source, INF});

    // we have to track the minflow along each path    
    while(!q.empty()){
        
        auto [u, flow] = q.front();
        q.pop();

        for(int v = 0; v < V; v++){ // change it 0/1 depending on whether its 1 based or 0 based
            if(parent[v] == -1 && G[u][v]){
                int nflow = min(flow, G[u][v]);

                parent[v] = u;
                if(v == sink)  
                    return nflow;
                
                q.push({v, nflow});
            }
        }
    }

    return 0;
}
ll EdmondKarp(int source, int sink){
    // find an augmenting path via BFS
    parent.resize(V + 1, -1);


    ll maxFlow = 0;

    int newFlow;

    while(newFlow = bfs(source, sink)){
        maxFlow += newFlow;

        int curr = sink;

        while(curr != source){
            G[parent[curr]][curr] -= newFlow;
            G[curr][parent[curr]] += newFlow; // update reversed edge as well
            curr = parent[curr];

        }
    }

    return maxFlow;
}

int main(){

    cin >> V >> E;

    G.resize(V + 1, vector<int>(V + 1, 0));

    for(int i = 0; i < E; i++){
        int u, v, w; cin >> u >> v >> w;

        G[u][v] += w; // += in case there are multiple edges from the same node to the other
        // setting G[v][u] to 0 is already done via the resize, reversed edge is already added
    }

    int source, sink; cin >> source >> sink;

    ll maxFlow = EdmondKarp(source, sink);

    cout << "Max flow : " << maxFlow;
    return 0;
}