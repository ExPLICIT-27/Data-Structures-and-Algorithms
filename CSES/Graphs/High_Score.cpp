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
struct E{
    int u, v;
    ll w;
    E(){}
    E(int u, int v, ll w) : u(u), v(v), w(w) {}
};
void solve(){
    // first idea : try bellman ford after making the weights opp
    // if negative weight (positive weight after reversing polarity) is present, return -1;
    /*
    ok this idea is only partially correct
    it successfully calculates the max score and detects cycles 
    but the cycle is relevant only if this cycle is reachable by both 1 and N

    we can easily detect nodes reachable by 1 via the last step of bellman ford

    now we need to check if the negative cycle can reach N
    or if we reverse the edges, we need to check if we can reach any
    of the negative cycle nodes from N
    do this precisely

    either do the above or
    just run bellman ford again and if at any instance you are able to relax a node u
    mark it indicating it will become -ve inf
    if finally the N-th node is also marked, we return -1 else -dist[n - 1]
    */

    int n, m; cin >> n >> m;

    vector<E> edges(m);

    for(int i = 0; i < m; i++){
        int u, v;
        ll w; 
        cin >> u >> v >> w;

        u--, v--;
        edges[i]  = E(u, v, -w);
    }


    // relax v - 1 times -> bellman ford
    vll dist(n, LLONG_MAX);
    dist[0] = 0;

    for(int i = 0; i < n - 1; i++){
        for(E &e : edges){
            if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    
    vi affectedNodes;
    for(E &e : edges){
        if(dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]){
            affectedNodes.pb(e.v);
        }
    }
    if(affectedNodes.empty())
        cout << -dist[n - 1] << nline;
    else{

        vector<vi> rev(n);

        for(auto &e : edges){
            rev[e.v].pb(e.u);
        }

        vector<bool> vis(n, false);

        auto dfs = [&](auto &&self, int u) -> void {
            vis[u] = true;

            for(int v : rev[u]){
                if(!vis[v])
                    self(self, v);
            }
        };

        dfs(dfs, n - 1); // chck from n - 1

        for(int i : affectedNodes){
            if(vis[i]){
                cout << -1 << nline; // can reach an affected node
                return;
            }
        }

        cout << -dist[n - 1] << nline;
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