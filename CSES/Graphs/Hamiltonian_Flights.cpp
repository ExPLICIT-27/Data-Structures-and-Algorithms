#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n, m; cin >> n >> m;

    /*
    basically I have a graph, i need to find ways in which i can visit all nodes
    exactly once from the given st and en-> hamiltonian path then
    lemme try brute force
    */

    vector<vector<int>> G(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;

        G[u].push_back(v);
    }

    function<int(int, int)> dfs;

    const int mod = 1e9 + 7;
    
    /*
    transitioning from 1 state to another
    i start with 00000..1
    then depending on my neighbors
    i can choose to move there or not
    if i move there, i set the bit and return
    */


    
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));

    dp[1][0] = 1; // bit mask 0000...1, node 0
    
    for(int mask = 1; mask < (1 << n); mask++){
        for(int u = 0; u < n; u++){
            if(!((mask >> u) & 1) || dp[mask][u] == 0)
                continue;
            
            for(int v : G[u]){
                if(((mask >> v) & 1))
                    continue;
                int nmask = (mask | (1 << v));

                dp[nmask][v] = (dp[mask][u] + dp[nmask][v])%mod;
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << nline;
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