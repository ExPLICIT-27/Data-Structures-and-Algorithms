#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'


class DSU{

    public:


    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }


    int findParent(int u){
        if(u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]);
    }


    void UBR(int u, int v){
        int u_p = findParent(u), v_p = findParent(v);

        if(u_p == v_p)
            return;

        if(rank[u_p] > rank[v_p]){
            parent[v_p] = u_p;
        }
        else if(rank[v_p] > rank[u_p]){
            parent[u_p] = v_p;
        }
        else{
            parent[v_p] = u_p;
            rank[u_p]++;
        }
    }
};


struct Edge{
    int u, v, w;

    Edge(){}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};
void solve() {
    /*
    this seems like a direct implementation of spanning tree

    lets go for kruskals + DSU
    if i remember correctly, 
    its basically sorting the edges and adding it such that it does not create a cycle
    */

    int n, m; cin >> n >> m;

    vector<Edge> E(m);

    for(auto &e : E){
        cin >> e.u >> e.v >> e.w;

        e.u--, e.v--;
    }


    sort(E.begin(), E.end(), [](Edge &a, Edge &b){
        return a.w < b.w;
    });


    
    ll cost = 0;

    DSU ds(n);
    vector<bool> conn(n, false);
    for(int i = 0; i < m; i++){
        int u_p = ds.findParent(E[i].u);
        int v_p = ds.findParent(E[i].v);

        if(u_p == v_p)
            continue;
        
        ds.UBR(E[i].u, E[i].v);
        conn[E[i].u] = conn[E[i].v] = true;
        cost += E[i].w;
    }

    int all_p = ds.findParent(0);

    for(int i = 1; i < n; i++){
        if(ds.findParent(i) != all_p){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    cout << cost << nline;

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