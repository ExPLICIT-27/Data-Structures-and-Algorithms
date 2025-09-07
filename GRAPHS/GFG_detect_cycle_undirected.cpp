/*
detecting cycle in an undirected graph
Visit Striver's G-11 video for the best possible explanation

Logic: 
Only in the case of a cycle can you visit a node from two different directions
hence while performing bfs/dfs if you can store parents along with the node
while checking condition 
if the node has already been visited and it has a different parent than the current node being traversed ;
cycle exists

Handle the case of disconnected graph components as well by calling the detect cycle function on all the broken components
*/
#include <bits/stdc++.h>

using namespace std;
// bfs version -> meets somebody already visited by someone else
bool isCyclicHelperBFS(unordered_map<int, vector<int>> &adjList, vector<bool> &visited, int src){
    visited[src] = true;
    queue<pair<int, int>> q; // parent - child node combo

    q.push({src, -1}); // src has no parent
    while(!q.empty()){
        auto [u, parent] = q.front();
        q.pop();

        for(int v : adjList[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push({v, u});
            }
            else if(v != parent) // already been visited by someone else -> means cycle
                return true;
        }
    }
    return false;
}
// dfs version -> visits an already visited node 
bool isCyclicDFS(unordered_map<int, vector<int>> &G, int src, int parent, vector<bool> &visited){
    visited[src] = true;
    for(int v : G[src]){
        if(!visited[v]){
            if(isCyclicDFS(G, v, src, visited))
                return true;
        }
        else if(v != parent)
            return true;
    }
    return false;
}
bool isCyclicMain(unordered_map<int, vector<int>> &adjList, int V){
    vector<bool> visited(V, true);
    // this loop is to handle disconnected componetnts
    for(int i = 0; i < V; i++){
        if(!visited[i] && isCyclicHelperBFS(adjList, visited, i))
            return true;
    }
    return false;
    
}

int main(){
    return 0;
}