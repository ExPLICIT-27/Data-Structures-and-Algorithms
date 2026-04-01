#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
For a directed acyclic graph (DAG), topo sort gives an optimal order for processing the nodes, (for normal graphs we need
to use priority queue to determine the optimal ordering)
After topo sorting the graph, perform the relaxation of the nodes exactly in that order

Note : This same method can be applied to find the longest path in a DAG from 1 node to another
Note 2 : Finding the same in a general graph is a NP hard problem.
note 3 : it works for -ve weights as well :)
*/

int main(){

    // V = vertices
    
    int V; cin >> V;

    // E = edges
    int E; cin >> E;

    vector<vector<pair<int, ll>>> G(V);

    vector<int> indeg(V, 0); // indegree for topo sorting
    for(int i = 0; i < E; i++){
        int u, v; cin >> u >> v;

        ll w; cin >> w;

        G[u].emplace_back(v, w); // directed edge
        indeg[v]++;
    }



    vector<int> topo_nodes; // nodes in the order of their topo sort


    queue<int> Q;

    for(int u = 0; u < V; u++){
        if(indeg[u] == 0){
            Q.push(u);
            topo_nodes.push_back(u);
        }
    }

    while(!Q.empty()){

        int u = Q.front();
        Q.pop();

        for(auto &nei : G[u]){
            int v = nei.first;
            indeg[v]--;

            if(indeg[v] == 0){
                topo_nodes.push_back(v);
                Q.push(v);
            }
        }
    }

    int src; cin >> src;

    vector<ll> dist(V, INT_MAX);
    dist[src] = 0;

    for(int u : topo_nodes){
        for(auto &[v, w] : G[u]){
            if(dist[v] > w + dist[u])
                dist[v] = w + dist[u];
        }
    }
    

    // print the shorest paths

    for(ll i : dist)
        cout << i << " ";
    return 0;
}