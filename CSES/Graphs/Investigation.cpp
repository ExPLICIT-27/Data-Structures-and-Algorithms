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


    vector<vector<pii>> G(n);


    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;

        G[u].emplace_back(v, w);
    }

    
    vll dist(n, LLONG_MAX);
    /*
    dp on graphs basically

    need cnt array for counting no of ways to reach a particular node with shortest path
    need min and max len array for tracking min and max length
    */

    vi cnt(n, 0), min_len(n, INT_MAX), max_len(n, INT_MIN);

    cnt[0] = 1;
    min_len[0] = max_len[0] = 0;
    dist[0] = 0;


    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 0});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u])
            continue;
        
        for(auto &[v, w] : G[u]){
            if(dist[v] > dist[u] + w){

                // overwrite for better bath
                dist[v] = w + dist[u];
                cnt[v] = cnt[u];
                min_len[v] = min_len[u] + 1;
                max_len[v] = max_len[u] + 1;
                pq.push({dist[v], v});
            }
            else if(dist[v] == dist[u] + w) {

                // merger for same kinda ones
                cnt[v] = (cnt[u] + cnt[v])%MOD;
                min_len[v] = min(min_len[v], 1 + min_len[u]);
                max_len[v] = max(max_len[v], 1 + max_len[u]);
            }
        }
    }

    cout << dist[n - 1] << " " << cnt[n - 1] << " " << min_len[n - 1] << " " << max_len[n - 1] << nline;
    
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