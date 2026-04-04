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

// ---------- PBDS ----------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename K, typename V>
using ordered_map = tree<pair<K,V>, null_type, less<pair<K,V>>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    /*
    one outward edge ONLY for every node
    guaranteed to have at least one cycle

    can have disconnected components
    every single node is either part of a cycle or leads into one


    problem is basically detecting all cycles (lets say SCC's in this context whose lengths are > 1 or length = 1 with self loops)
    
    then from those SCC's calculating the shortest distance to singled out nodes if they exist

    wait the memory requirement becomes very complicated
    I need to store each SCC to see where theyll land up after k moves
    I need to store a map connecting each node to its SCC 
    I need another array which stores the distance from an SCC to a non SCC
    tf

    well absolute bs allat,
    its a direct binary lifting problem
    */

    int n, q; cin >> n >> q;

    vi A(n);

    for(int &i : A){
        cin >> i;
        i--;
    }
    
    
    // compute LOGN ancestors
    int LOG = 30;

    vector<vector<int>> up(n, vi(LOG));

    for(int v = 0; v < n; v++)
        up[v][0] = A[v];
    
    // precompute LOG ancestors
    for(int j = 1; j < LOG; j++){
        for(int v = 0; v < n; v++)
            up[v][j] = up[up[v][j - 1]][j - 1];
    }

    while(q--){
        int v, x; cin >> v >> x;
        v--;

        int ans = v;

        
        int p = 0;

        while(x){
            if(x & 1)
                ans = up[ans][p];
            x >>= 1;
            p++;
        }

        cout << ans + 1 << nline;
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