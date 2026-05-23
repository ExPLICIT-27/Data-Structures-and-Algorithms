#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'


class DSU{
    public:

    vector<int> parent, size;

    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);


        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }


    int findParent(int u){
        if(u == parent[u])
            return u;
        
        return parent[u] = findParent(parent[u]);
    }

    void UBS(int u, int v){
        int u_p = findParent(u), v_p = findParent(v);

        if(u_p == v_p)
            return;
        
        if(size[u_p] > size[v_p]){
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
        else{
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
    }
};
void solve() {
    int n, m; cin >> n >> m;

    DSU ds(n);

    int maxsz = 1, comps = n;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        int u_p = ds.findParent(u), v_p = ds.findParent(v);
        if(u_p != v_p){
            ds.UBS(u, v);
            comps--;
            maxsz = max(maxsz, ds.size[ds.findParent(u)]);
        }

        cout << comps << " " << maxsz << nline;
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