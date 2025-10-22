/*
Utilzing Tarzan's algorithm for the same
complicated and non intuitive to come up with (striver has a pretty nice explanation)

brute force -> remove edge and see if it makes the graph disconnected
*/
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> tin, low, vis;

    int timer = 0;

    void dfs(vector<vector<int>> &adj, int node, int parent){
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for(int v : adj[node]){
            if(v == parent) continue;
            if(!vis[v]){
                dfs(adj, v, node);
                low[node] = min(low[node], low[v]);

                if(low[v] > tin[node])
                    res.push_back({node, v});
            }
            else
                low[node] = min(low[node], low[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>> adj(n);

        for(auto &e : conn){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.resize(n);
        low.resize(n);
        vis.resize(n, 0);

        dfs(adj, 0, -1);
        return res;

    }
};
int main(){
    return 0;
}
