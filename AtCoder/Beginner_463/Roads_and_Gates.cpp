#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

void solve() {
    /*
    N cities, M roads
    undirected graph
    seems like direct djikstras

    ABSOLUTE GOLDMINE OF A QUESTION

    the graph is dense due to the x graph
    how to make it sparese?

    the brilliant idea


    create a dummy node -> at position n + 1

    the cost for each node to go to this dummy node would be Xi
    the reverse cost (cost of leaving this dummy and arriving at i) can be Xi + y

    now it becomes standard djikstras
    */
    

    int n, m, y; cin >> n >> m >> y;


    // since there is no Node 0, im making 0 the dummy node
    vector<vector<pair<int, ll>>> G(n + 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        ll w; cin >> w;

        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vector<ll> x(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> x[i];
    
    // dummy node config
    for(int i = 1; i <= n; i++){
        G[i].emplace_back(0, x[i]);
        G[0].emplace_back(i, x[i] + y);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 1});
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;


    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(dist[u] < d)
            continue;
        
        for(auto [v, dv] : G[u]){
            if(dist[v] > dv + d){
                dist[v] = dv + d;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 2; i <= n; i++)
        cout << dist[i] << " ";
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