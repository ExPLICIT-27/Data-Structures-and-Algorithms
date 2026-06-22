#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'


vector<vector<ll>> G;
vector<int> parent;

int V;

ll bfs(){
    fill(parent.begin(), parent.end(), -1);
    parent[1] = 1;

    queue<pair<int, ll>> q;

    q.push({1, LLONG_MAX});

    while(!q.empty()){

        auto [u, flow] = q.front();
        q.pop();

        for(int v = 1; v <= V; v++){
            if(parent[v] == -1 && G[u][v]){
                ll nflow = min(G[u][v], flow);
                
                parent[v] = u;
                if(v == V)
                    return nflow;
                
                q.push({v, nflow});
            }
        }
    }

    return 0;
}
void solve() {
    int n, m; cin >> n >> m;
    V = n;
    /*
    NAHHHHHHHHHHHHHHHHHHHHHHHH
    data can split up and travel along all paths

    yup speed is a really stupid word here
    its BANDWIDTH which is the AMOUNT of data which can be sent in a FIXED amount of time

    the way to go here is using Edmond karps -> max flow from source to sink, src, sink being 1 and N
    */


    G.assign(V + 1, vector<ll>(V + 1, 0));
    parent.resize(V + 1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;

        G[u][v] += w; 
    }

    ll maxFlow = 0; 
    ll currFlow;

    while(currFlow = bfs()){
        maxFlow += currFlow;

        int curr = V;

        while(curr != 1){
            G[parent[curr]][curr] -= currFlow;
            G[curr][parent[curr]] += currFlow;

            curr = parent[curr];
        }
    }

    cout << maxFlow;
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