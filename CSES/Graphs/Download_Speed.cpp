/*
for detailed explanation of the algorithm in itself 
refer GRAPHS/CORE_ALGORITHMS/EdmondKarps.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

struct Edge{

    int to, rev;
    ll cap;

    Edge(){};

    Edge(int to, int rev, ll cap) : to(to), rev(rev), cap(cap) {}
};


int N, M;

vector<vector<Edge>> G;
vector<int> par_n, par_e; // parents of nodes, edge parent (how to reach the parent of the node)


ll bfs(){
    fill(par_e.begin(), par_e.end(), -1);
    fill(par_n.begin(), par_n.end(), -1);

    queue<pair<int, ll>> q;

    q.push({1, LLONG_MAX});

    while(!q.empty()){
        auto [u, cflow] = q.front(); q.pop();

        int sz = G[u].size();

        for(int i = 0; i < sz; i++){
            auto &e = G[u][i];

            if(par_n[e.to] == -1 && e.cap){
                ll nflow = min(cflow, e.cap);

                par_n[e.to] = u;
                par_e[e.to] = i;


                if(e.to == N)   
                    return nflow;

                q.push({e.to, nflow});
            }
        }
    }

    return 0;
}
void solve() {
    cin >> N >> M;

    G.assign(N + 1, vector<Edge>());
    par_n.resize(N + 1), par_e.resize(N + 1);


    for(int i = 0; i < M; i++){
        int u, v; cin >> u >> v;

        ll cap; cin >> cap;

        G[u].push_back({v, (int)G[v].size(), cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0});
    }

    ll maxFlow = 0, currFlow;


    while(currFlow = bfs()){
        maxFlow += currFlow;

        int curr = N;

        while(curr != 1){
            G[par_n[curr]][par_e[curr]].cap -= currFlow;
            int rev = G[par_n[curr]][par_e[curr]].rev;

            G[curr][rev].cap += currFlow;

            curr = par_n[curr];
        }
    }

    cout << maxFlow << endl;

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