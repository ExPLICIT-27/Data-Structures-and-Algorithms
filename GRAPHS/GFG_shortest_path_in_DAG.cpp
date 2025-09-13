/*
This is a directed acyclic graph
NOTE: where there is a DAG, there might be Kahn's Toposort

Only because this is a DAG
- You can apply toposort
- Then take the elements out from the toposort and relax them
- toposort ensures that the processing order is such that it ensures all paths found along are optimal as it goes

*/

#include <bits/stdc++.h>
using namespace std;
    
vector<int> shortestPath(int V, int E, vector<vector<int>> &edges){
    // adjacency list with node to {node, weight} storage
    vector<vector<pair<int, int>>> adjList(V);
    // measure indegrees for toposort
    vector<int> indegree(V, 0);

    for(auto edge : edges){
        int u = edge[0], v = edge[1], w = edge[2];

        adjList[u].push_back({v, w});
        indegree[v]++;
    }

    // perform toposort, Kahn's algorithm, extract the sources with indegree 0
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(!indegree[i])
            q.push(i);
    }
    
    // bfs for toposort
    vector<int> topoSort;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topoSort.push_back(u);

        for(auto [v, w] : adjList[u]){
            indegree[v]--;
            if(!indegree[v])
                q.push(v);
        }
    }
    // begin the bfs for calculating the minimum distances
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    for(int i = 0; i < topoSort.size(); i++){
        int u = topoSort[i];
        
        if(dist[u] != INT_MAX){
            for(auto [v, w] : adjList[u]){
                if(dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
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