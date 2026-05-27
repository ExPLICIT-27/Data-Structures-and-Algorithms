#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n, m; cin >> n >> m;

    /*
    i need to find a pair of flights which i cant reach


    basically check if the graph is strongly connected
    else just print out 2 nodes from 2 different SCCs



    kosarajus algo:
    - toposort it (to get the order of processing the SCCs)
    - reverse the edges so that the SCCs become disconnected from each other
    - find the SCCs

    better soln : just run 2 dfs, one from 1 to the end, the other from end to 1 (reversed edges)
    if you cant visit everything in either iteration, print them
    */


    vector<vector<int>> G(n + 1), rev(n + 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        G[u].push_back(v);
        rev[v].push_back(u);
    }


    vector<bool> vis(n + 1, false);
    stack<int> stk;

    function<void(int)> topodfs;

    topodfs = [&](int u) -> void {
        vis[u] = true;

        for(int v : G[u]){
            if(!vis[v])
                topodfs(v);
        }

        stk.push(u);
    };

    for(int i = 1; i <= n; i++){
        if(!vis[i])
            topodfs(i);
    }

    vector<vector<int>> sccs;
    fill(vis.begin(), vis.end(), false);

    while(!stk.empty()){
        int node = stk.top();
        stk.pop();

        if(!vis[node]){
            vis[node] = true;
            queue<int> q;
            q.push(node);

            vector<int> scc;

            while(!q.empty()){
                int u = q.front();
                q.pop();
                scc.push_back(u);

                for(int v : rev[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }


            sccs.push_back(scc);
        }
    }

   
    if(sccs.size() == 1)
        cout << "YES\n";
    else{
        cout << "NO\n";

        cout << sccs[1][0] << " " << sccs[0][0] << nline;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}