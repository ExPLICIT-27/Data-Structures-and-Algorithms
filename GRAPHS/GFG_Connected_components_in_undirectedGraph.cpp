/*
given an undirected graph with 0 - V-1 vertices, find all the connected components
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &G, int u, vector<bool> &visited, vector<int> &connected){
    visited[u] = true;
    connected.push_back(u);

    for(int v : G[u]){
        if(!visited[v])
            dfs(G, v, visited, connected);
    }
}
vector<vector<int>> findConnected(vector<vector<int>> &edges, int V){
    unordered_map<int, vector<int>> G;

    for(auto edge : edges){
        G[edge[0]].push_back(edge[1]);
        G[edge[1]].push_back(edge[0]);    
    }
    vector<vector<int>> result;
    vector<bool> visited(V, false);

    for(int u = 0; u < V; u++){
        if(!visited[u]){
            vector<int> temp;
            dfs(G, u, visited, temp);
            result.push_back(temp);
        }
    }
    return result; 
}
int main(){
    return 0;
}