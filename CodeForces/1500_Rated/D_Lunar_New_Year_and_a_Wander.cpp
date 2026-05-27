#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    undirected and completely connected graph
    there can be self loops
    can be cycles
    I need to find the smallest ordering of visits
    */

    int n; cin >> n;

    int e; cin >> e;

    vector<vector<int>> G(n);


    while(e--){
        int u, v; cin >> u >> v;

        u--, v--;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(0);
    vector<bool> vis(n, false);
    vis[0] = true;
    

    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        cout << u + 1 << " ";

        for(int v : G[u]){
            if(!vis[v]){
                pq.push(v);
                vis[v] = true;
            }
        }
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