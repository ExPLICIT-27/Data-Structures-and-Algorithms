/*
Kosarajus algorithm to find strongly connected components

SCCs are only valid for directed graphs

SCC
each vertex in a SCC can travel to any other vertex within the SCC, hence the wording strongly connected

Note : Each node by itself is a SCC


Kosaraju's Algorithm
- Sort the edges based on finishing time (so that you can start from the first SCC)
- Reverse the edges (SCCs will still be intact as they are SCCs, but now you cant travel from one SCC to another due to the reversed edge, 
thereby making it easier to differentiate between SCCs)
- Now count the disconnected components, they will be the SCCs
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  // toposort for correct order of bfs/dfs
    void topodfs(vector<vector<int>> &adj, int u, vector<int> &vis, stack<int> &stk){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v])
                topodfs(adj, v, vis, stk);
        }
        stk.push(u);
    }
    // main logic
    int kosaraju(vector<vector<int>> &adj) {

        // toposort setup
        int V = adj.size();
        stack<int> stk;
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i])
                topodfs(adj, i, vis, stk);
        }


        fill(vis.begin(), vis.end(), 0);
        // reversing the edges
        vector<vector<int>> rev(V);
        for(int u = 0; u < V; u++){
            for(int v : adj[u])
                rev[v].push_back(u);
        }
        //count the disconnected components (strongly connected individually)
        int res = 0;
        while(!stk.empty()){
            int u = stk.top();
            stk.pop();
            if(!vis[u]){
                res++;
                queue<int> q;
                q.push(u);
                while(!q.empty()){
                    int ui = q.front();
                    q.pop();
                    for(int v : rev[ui]){
                        if(!vis[v]){
                            q.push(v);
                            vis[v] = true;
                        }
                    }
                }
            }
        }
        return res;
    }
};
int main(){
    return 0;
}