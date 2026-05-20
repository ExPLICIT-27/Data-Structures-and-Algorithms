#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

class Edge{
    public:
    int u, v, i;
    Edge(){}
    Edge(int u, int v, int i) : u(u), v(v), i(i) {}
};

void solve() {
    /*
    I am thinking, putting lower numbers to the edges connected to nodes with 
    lower indegree, lets go with that first
    */
    int n; cin >> n;

    vector<Edge> E(n - 1);

    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--, v--;

        E[i].u = u, E[i].v = v, E[i].i = i;
    }


    vector<vector<Edge>> G(n);

    vector<int> indeg(n);


    for(auto &e : E){
        G[e.u].push_back(e);
        G[e.v].push_back(e);

        indeg[e.u]++;
        indeg[e.v]++;
    }


    vector<int> nodes(n);

    iota(nodes.begin(), nodes.end(), 0);

    
    sort(nodes.begin(), nodes.end(), [&](int a, int b){
        return indeg[a] < indeg[b];
    });

    vector<int> ans(n - 1, -1);

    int curr = 0;

    for(int u : nodes){
        for(auto &e : G[u]){
            if(ans[e.i] != -1)
                continue;
            ans[e.i] = curr++;
        }
    }

    for(int i : ans)
        cout << i << nline;
    
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