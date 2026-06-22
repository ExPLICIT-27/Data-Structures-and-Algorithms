/*
conditions for the existence of a eulerian path is:
all nodes except the start nodes must have degree even
for directed graphs
start node -> outdeg - indeg = 1
end node -> indeg - outdeg = 1
for all others indeg = outdeg

for undirected graphs -> exactly 2 nodes with odd degree, others with even deg
for whether there exists a eulerian path starting from 1 and ending at n in a directed graph (n nodes in the graph)
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> G(n + 1);
    vector<int> in(n + 1), out(n + 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        G[u].push_back(v);
        out[u]++, in[v]++;
    }


    bool flag = true;
    // check for 
    for(int i = 2; i < n && flag; i++){
        if(in[i] != out[i])
            flag = false;
    }

    
    if(out[1] - in[1] != 1 || in[n] - out[n] != 1 || !flag){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;

    function<void(int)> dfs;

    dfs = [&](int u) -> void {
        while(!G[u].empty()){
            int v = G[u].back();
            G[u].pop_back();

            dfs(v);
        }

        path.push_back(u);
    };

    dfs(1);
    reverse(path.begin(), path.end());
    if(path.size() != m + 1 || path.back() != n){
        cout << "IMPOSSIBLE\n";
    }
    else{
        for(int i : path)
            cout << i << " ";
        cout << nline;
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