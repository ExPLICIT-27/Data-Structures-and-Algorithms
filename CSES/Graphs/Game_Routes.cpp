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
    int n, m; cin >> n >> m;

    vector<vi> G(n);

    vi in(n, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        u--, v--;

        G[u].pb(v); // directed edge
        in[v]++;
    }


    // i should toposort and perform the cnting in that order, lesgoo
    /*
    basically assing cnt of reaching level 1, aka node 0 as 1
    toposort and peform counting on the adjacency list of those nodes
    */
    queue<int> q;

    vi order;
    for(int i = 0; i < n; i++){
        if(!in[i]){
            q.push(i);
            order.pb(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();


        for(int v : G[u]){
            in[v]--;

            if(in[v] == 0){
                q.push(v);
                order.pb(v);
            }
        }
    }



    vi cnt(n, 0);
    cnt[0] = 1;


    for(int u : order){
        for(int v : G[u])
            cnt[v] = (cnt[u] + cnt[v])%MOD;
    }

    cout << cnt[n - 1] << nline;

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