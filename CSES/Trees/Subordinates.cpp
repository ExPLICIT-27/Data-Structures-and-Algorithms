#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    // basically return the cnt back in dfs
    
    int n; cin >> n;

    vector<vector<int>> G(n);

    for(int i = 0; i < n - 1; i++){
        int u; cin >> u;
        u--;
        G[u].push_back(i + 1);
    }

    function<int(int)> dfs;


    vector<int> cnt(n, -1);

    dfs = [&](int u) -> int {
        if(cnt[u] != -1)
            return cnt[u];


            
        int ans = 0;

    
        for(int v : G[u])
            ans += dfs(v);
        
        return cnt[u] = 1 + ans;
    };

    dfs(0);


    for(int i : cnt)
        cout << i - 1 << " ";


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