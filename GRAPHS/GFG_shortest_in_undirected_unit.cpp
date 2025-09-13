/*
This is an undirected graph with UNIT weights
The fact that the weights are unique is very important
of course djikstra would work well here

But we utilize a priority queue for djikstra which increases time complexity

If we think about it, the weights are always being updated by at max 1, since the weights are unique
so if we use a normal queue, while updating the weights, we'll already be pushing it into the queue in sorted
order.
Hence src to all other nodes can be achieved in O(V + E) time using blain BFS
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src){
    // set up the distance array
    int V = adj.size();
    vector<int> dist(V, INT_MAX);

    // src to src distance is 0
    dist[src] = 0;
    queue<int> q;

    q.push(src);

    // bfs
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(dist[u] + 1 < dist[v]){ // relaxation
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    // unreachable nodes are marked with distance -1 
    for(int &i : dist){
        if(i == INT_MAX)
            i = -1;
    }
    return dist;
}
int main(){
    return 0;
}