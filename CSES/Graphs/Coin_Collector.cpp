#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n, m; cin >> n >> m;

    
    /*
    Each SCC can be considered one of the start and end points
    perform dfs and find max possible result
    find all sccs


    EZ LESGOOO
    */

    vector<ll> coins(n);

    for(ll & i : coins)
        cin >> i;
    
    vector<vector<int>> G(n), rev(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        u--, v--;

        G[u].push_back(v);
        rev[v].push_back(u);
    }


    vector<bool> vis(n, false);
    function<void(int)> topodfs;


    vector<int> V;

    topodfs = [&](int u) -> void {
        vis[u] = true;

        for(int v : G[u]){
            if(!vis[v])
                topodfs(v);
        }

        V.push_back(u);
    };

    for(int i = 0; i < n; i++){
        if(!vis[i])
            topodfs(i);
    }



    vector<int> scc_no(n);
    fill(vis.begin(), vis.end(), false);
    int cno = 0;

    
    for(int i = n - 1; i >= 0; i--){
        int node = V[i];

        if(!vis[node]){
            vis[node] = true;
            
            queue<int> q;
            q.push(node);

            while(!q.empty()){
                int u = q.front();
                scc_no[u] = cno;
                q.pop();

                for(int v : rev[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            cno++;
        }
    }

    function<ll(int)> dfs;

    vector<ll> dp(cno, 0), base(cno, 0);

    for(int i = 0; i < n; i++){
        base[scc_no[i]] += coins[i];
    }

    vector<bool> vis2(n, false);

    dfs = [&](int u) -> ll {
        vis2[u] = true;
        ll curr = base[scc_no[u]];

        for(int v : rev[u]){
            

            if(!vis2[v]){
                if(scc_no[v] == scc_no[u])
                    curr = max(curr, dfs(v));
                else
                    curr = max(curr, base[scc_no[u]] + dfs(v));
            }
            else{
                if(scc_no[v] == scc_no[u])
                    curr = max(curr, dp[scc_no[v]]);
                else
                    curr = max(curr, base[scc_no[u]] + dp[scc_no[v]]);
            }
        }

        return curr;
    };

    
    
    for(int i = n - 1; i >= 0; i--){
        int u = V[i];
        if(!vis2[u]){
            dp[scc_no[u]] = max(dp[scc_no[u]], dfs(u));
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << nline;
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