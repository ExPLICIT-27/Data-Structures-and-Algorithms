#include <bits/stdc++.h>
using namespace std;
 
// ---------- Typedefs ----------
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define uset unordered_set
#define umap unordered_map
 
// ---------- Macros ----------
#define nline '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define vmax(a) (*max_element(all(a)))
#define vmin(a) (*min_element(all(a)))
#define vsum(a) (accumulate(all(a), 0LL))
#define vsumd(a) (accumulate(all(a), 0.0))
 
// ---------- Fast IO ----------
#define ExPLICIT_27 ios::sync_with_stdio(false); cin.tie(nullptr)
 
// ---------- Constants ----------
const ll MOD = 1e9+7;
const ll INF = 1e18;
 
// ---------- PBDS ---------- policy based data strcutures, faster sets and maps
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
// Ordered Set (no duplicates)
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 
// Ordered Multiset (allows duplicates using unique IDs)
template<typename T>
using ordered_multiset = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 
// Ordered Map (key → value)
template<typename K, typename V>
using ordered_map = tree<
    pair<K,V>,
    null_type,
    less<pair<K,V>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
 

void solve(){
    int n, m; cin >> n >> m;

    vector<vi> G(n);


    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        u--, v--;

        G[u].pb(v);
        G[v].pb(u);
    }

    // since wt is only 1, no need of pq

    auto djikstras = [&](int src, int dest) -> pair<int, vector<int>> {

        queue<int> Q;
        Q.push(src);

        vector<int> parents(n, -1);
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;


        while(!Q.empty()){

            auto u = Q.front();
            Q.pop();

            for(int v : G[u]){
                
                if(1 + dist[u] < dist[v]){
                    parents[v] = u;
                    dist[v] = 1 + dist[u];
                    Q.push(v);
                }
            }
        }

        if(dist[dest] == INT_MAX)
            return make_pair(-1, vector<int>());
        
        vector<int> path;
        path.pb(dest + 1);

        for(int i = parents[dest]; i != -1; i = parents[i]){
            path.pb(i + 1);
        }

        reverse(all(path));


        return make_pair(dist[dest], path);

    };


    auto ans = djikstras(0, n - 1);


    if(ans.ff == -1){
        cout << "IMPOSSIBLE" << nline;
        return;
    }

    cout << ans.ff + 1 << nline;
    for(int i : ans.ss)
        cout << i << " ";
    cout << nline;
}
int main(){
    ExPLICIT_27;
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
 
    return 0;
}