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

    // longest path in a DAG -> toposort and relax nodes in that order
    int n, m; cin >> n >> m;

    vector<vi> G(n);
    vi in(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;

        cin >> u >> v;

        u--, v--;

        G[u].pb(v);
        in[v]++;
    }

    // toposort
    queue<int> Q;
    vi nodes;

    for(int u = 0; u < n; u++){
        if(in[u] == 0){
            Q.push(u);
            nodes.push_back(u);
        }
    }


    while(!Q.empty()){
        int u = Q.front();
        Q.pop();


        for(int v : G[u]){
            in[v]--;

            if(in[v] == 0){
                Q.push(v);
                nodes.pb(v);
            }
        }
    }

    vll dist(n, INT_MIN);
    dist[0] = 0;
    vi par(n, -1);
    for(int u : nodes){
        for(int v : G[u]){
            if(dist[v] < dist[u] + 1){
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }

    if(dist[n - 1] < 0){
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << dist[n - 1] + 1 << nline;

    vi ans;

    for(int i = n - 1; i != -1; i = par[i])
        ans.pb(i + 1);

    reverse(all(ans));

    for(int i : ans)
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