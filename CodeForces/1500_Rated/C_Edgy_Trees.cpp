#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

const int M = 1e9 + 7;


int binpow(int base, int p){
    int ans = 1;

    while(p){
        if(p & 1)
            ans = 1ll*ans*base%M;
        
        base = 1ll*base*base%M;
        p >>= 1;
    }

    return ans;
}
void solve() {
    int n, k; cin >> n >> k;


    /*
    logic is to exclude black edges, so you get only red components
    ans = n^k - (compsize^k for every red component)
    modulo M
    */
    vector<vector<int>> G(n);


    for(int i = 0; i < n - 1; i++){
        int u, v, x; cin >> u >> v >> x;

        u--, v--;

        if(x == 1)// only make red comsp
            continue;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }


    int invalid = 0;

    vector<bool> vis(n, false);
    auto dfs = [&](auto &&self, int u, int &cnt) -> void {
        vis[u] = true;
        cnt++;
        

        for(int v : G[u])
            if(!vis[v])
                self(self, v, cnt);
        
    };
    

    for(int u = 0; u < n; u++){
        if(!vis[u]){
            int cnt = 0;
            dfs(dfs, u, cnt);
            invalid = (invalid + 1ll*binpow(cnt, k))%M;
        }
    }

    cout << ((1ll*binpow(n, k) - invalid)%M + M)%M << nline;

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