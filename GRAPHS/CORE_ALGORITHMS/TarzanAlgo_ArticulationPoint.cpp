/*
This is the algorithm used to solve lec 1192 -> critical network connections (bridges in a graph)
now using the same to solve articulation points in a graph


the only difference between this and the bridge code is handling the case separately for the starting node,
using a 'mark' array to identify the articulation points and the condition of the articulation being less lenient
 >= now, rather than just >
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:
    vector<int> vis, mark, tin, low;
    int timer = 0;
    void dfs(vector<vector<int>> &adj, int u, int parent){
        vis[u] = true;
        tin[u] = low[u] = timer++;
        
        int children = 0; // handling the parent case separately by counting its 
        // children
        for(int v : adj[u]){
            if(v == parent) continue;
            
            if(!vis[v]){
                dfs(adj, v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= tin[u] && parent != -1)
                    mark[u] = 1;
                children++;
            }
            else
                low[u] = min(low[u], tin[v]); // another big difference from the bridge code
        }
        if(parent == -1 && children > 1)
            mark[u] = 1;
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vis.resize(V, 0);
        mark.resize(V, 0);
        tin.resize(V);
        low.resize(V);
        
        for(int i = 0; i < V; i++){
            if(!vis[i])
                dfs(adj, i, -1);
        }
        
        vector<int> res;
        for(int i = 0; i < V; i++){
            if(mark[i])
                res.push_back(i);
        }
        
        if(res.empty())
            return {-1};
        return res;
    }
};
int main(){
    return 0;
}