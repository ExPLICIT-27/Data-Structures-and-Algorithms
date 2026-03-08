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
    ll d;
    int u;
    bool used;
 
    Node(){};
    Node(ll d, int u, bool used) : d(d), u(u), used(used) {};
};
struct Comparator{
    bool operator()(const Node &a, const Node &b) const {
        return a.d > b.d;
    }
};
void solve(){
    int n, m; cin >> n >> m;
 
 
    vector<vector<pair<int, ll>>> G(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
 
        G[u].pb({v, w});
    }
 
    /*
    idea 1:
    i simply find the path from 1 to N and the original distance from 1 to N
    ans = min(ans, og - [x/2]) for every x in the path
 
    yep this doesnt work for all cases
 
    why not do something else
    calculate the normal full price
    then calculate price based on half pricing
    for each component in the half price, keep it half and add full for remaining to see what the ans would be
 
    this doesnt work either
 
    idea 2
    devise a formula to keep track of running max price obtainable
 
    it would be equal to current_price - max_price/2
    neither does this work -> breaks in cases where best prices are equal and you need to make an arbitrary decision
 
    final ans : keep djikstra in the following two states
    dist[u][0] -> coupon not used
    dist[u][1] -> coupon used
 
    for both the states do the following
    if(dist[v][used] > dist[u][used] + w)
        update
    then only for unused coupon states
    if(!used && dist[v][1] > dist[u][used] + w/2)
        update
    this works because this simply will always ensure a standard check as ensured by djikstras
    */
 
    vector<vll> dist(n, vll(2, LLONG_MAX));
 
    
    auto djikstras = [&](int src) {
        dist[src][0] = 0;
 
        priority_queue<Node, vector<Node>, Comparator> pq;
 
        pq.push({0, src, false});
 
 
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            if(u.d > dist[u.u][u.used])
                continue;
            
            for(auto &[v, w] : G[u.u]){
                if(dist[v][u.used] > dist[u.u][u.used] + w){
                    dist[v][u.used] = w + dist[u.u][u.used];
                    pq.push({dist[v][u.used], v, u.used});
                }
 
                if(!u.used && dist[v][1] > dist[u.u][0] + w/2){
                    dist[v][1] = dist[u.u][0] + w/2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }   
    };
 
    djikstras(0);
    // for(ll i : dist)
    //     cout << i << " ";
 
    cout << min(dist[n - 1][0], dist[n - 1][1]) << nline;
        
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