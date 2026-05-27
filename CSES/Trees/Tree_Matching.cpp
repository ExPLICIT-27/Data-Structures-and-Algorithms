#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    first good lesson to dp on trees
    dp[node][0] -> i am not choosing this node, hence ans is simply max(dp[child][0], dp[child][1]) for all children of node

    dp[node][1] -> if i am choosing the edge which connects node->c_i, then you cant choose dp[c_i][1]
    then dp[node][1] = dp[node][0] - max(dp[c_i][0], dp[c_i][1]) + dp[c_i][0] + 1; // +1 for choosin the edge
    */

    int n; cin >> n;

    vector<vector<int>> G(n);

    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--, v--;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    function<void(int, int)> dfs;

    int dp[n][2];
    memset(dp, 0, sizeof(dp));

    dfs = [&](int u, int par) -> void {
        
        for(int v : G[u]){
            if(v == par)
                continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }

        for(int v : G[u]){
            if(v == par)
                continue;
            dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
        }
    };

    dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]) << nline;
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