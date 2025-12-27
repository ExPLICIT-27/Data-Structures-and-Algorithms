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
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

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
pii dfs(vector<vi> &G, int u, vi &vis, string &S, ll &ans){
    vis[u] = true;
    int bc = 0, wc = 0;
    if(S[u] == 'W')
        wc++;
    else
        bc++;
    for(int v : G[u]){
        if(!vis[v]){
            auto out = dfs(G, v, vis, S, ans);
            wc += out.ff, bc += out.ss;
        }
    }
    if((wc == bc) && wc > 0)
        ans++;

    return {wc, bc};
}
void solve(){
    int n;

    cin >> n;
    ll ans = 0;
    vector<vi> G(n);
    rep(i, 0, n - 1){
        int t;
        cin >> t;
        G[t - 1].pb(i + 1);
    }
    string S;
    cin >> S;

    
    vi vis(n, false);
    dfs(G, 0, vis, S, ans);

    cout << ans << nline;
}
int main(){
    fastio;
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}