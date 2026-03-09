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
struct Node{
    int u, v, w;

    Node(){};
    Node(int u, int v, int w) : u(u), v(v), w(w) {};
};
void solve(){
    int n, m; cin >> n >> m;

    vector<Node> E(m);

    for(auto &node : E){
        cin >> node.u >> node.v >> node.w;
        node.u--, node.v--;
    }

    /*
    we do not care about shortest paths here
    all we care about is detecting a negative cycle
    it can be reachable from any node
    so every node must be treated as a starting point by marking its current distance to be 0
    it messes up the shortest path, but we do not care as we are concerned only with negative cycles
    the node that relaxes again at the n-th iteration is guaranteed to be part of the negative cycle

    we rebuild the cycle from that node
     */

    vll dist(n, 0);// every node is treated as src, marking only node 0 to be 0, we will only find cycles reachable from 0
    vi par(n, -1);
    int x;
    for(int i = 0; i < n; i++){
        x = -1; // if this changes to something else after the last iteration, we have a neg cycle with this node in it
        for(auto &e : E){
            if(dist[e.v] > dist[e.u] + e.w){
                dist[e.v] = dist[e.u] + e.w;
                par[e.v] = e.u;
                x = e.v;
            }
        }
    }

    
    if(x == -1){
        cout << "NO\n";
        return;
    }


    cout << "YES\n";

    // it is now guaranteed that x is either part of the cycle or reachable from the cycle
    // since the cycle len is guaranteed to be <= n, if you move x to its parent n times, you will land inside the cycle
    for(int i = 0; i < n; i++)
        x = par[x];
    vi cycle;
    int curr = x;
    int iter = 0;

    do{
        
        cycle.pb(curr);
        curr = par[curr];
    }while(curr != x);

    reverse(all(cycle));


    for(int i : cycle)
        cout << i + 1 << " ";
    cout << cycle[0] + 1 << nline;

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