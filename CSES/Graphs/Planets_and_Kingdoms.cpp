#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    
    /*
    just find all SCCs and print them
    */

    int n, m; cin >> n >> m;

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

    
    fill(vis.begin(), vis.end(), false);

    vector<vector<int>> sccs;

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
                scc.push_back(u);
                q.pop();

                for(int v : rev[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            sccs.push_back(scc);
        }
    }

    vector<int> ans(n + 1);
    int comps = sccs.size();
    for(int i = 0; i < comps; i++){
        for(int u : sccs[i])
            ans[u] = i + 1;
    }

    cout << comps << nline;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << nline;
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