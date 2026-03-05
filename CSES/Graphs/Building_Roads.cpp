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
    

    // no of roads = no of disconnected components - 1
    // for the road, just connect 1 comp to the other

    int n, m; cin >> n >> m;


    vector<vector<int>> G(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        u--, v--;

        G[u].pb(v);
        G[v].pb(u);
    }


    // find no of disconnected components and the components themselves
    vector<vector<int>> comps;

    vector<int> vis(n, false);


    // lambda funcs cannot be recursive, make a y combinator func for it


    auto dfs = [&](auto &&self, int u, vi &comp) -> void {
        vis[u] = true;
        comp.pb(u);

        for(int v : G[u]){
            if(!vis[v])
                self(self, v, comp);
        }
    };

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vi comp;

            dfs(dfs, i, comp);
            comps.pb(comp);
        }
    }


    int roads = sz(comps) - 1;

    cout << roads << nline;

    for(int i = 1; i <= roads; i++){
        cout << comps[i - 1][0] + 1 << " " << comps[i][0] + 1 << nline;
    }


    
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