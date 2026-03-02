/// LSFGOOOO by far one of my best contest solves ^^^^^^^^^^^^

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

// ---------- Loops ----------
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define repd(i,a,b) for (int i = (a); i >= (b); i--)

// ---------- Constants ----------
const ll MOD = 998244353;
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
// binary exponentiation
ll binexp(ll a, ll b, ll M){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans*a)%M;
        b >>= 1;
        a = (a * a)%M;
    }

    return ans;
}
void dfs(vector<vi> &G, vector<bool> &vis, int u){
    vis[u] = true;

    for(int v : G[u]){
        if(!vis[v])
            dfs(G, vis, v);
    }
}
void dfs2(vector<vi> &G, vector<bool> &vis, int u, vector<int> &c){
    vis[u] = true;
    c.pb(u);

    for(int v : G[u]){
        if(!vis[v])
            dfs2(G, vis, v, c);
    }
}
void solve(){
    int n, m; cin >> n >> m;

    vector<pii> edges(m);

    for(auto &p : edges){
        cin >> p.ff >> p.ss;
        p.ff--, p.ss--;
    }
    int L = 0, R = m;

    while(L <= R){
        int M = (L + R)/2;

        vector<vector<int>> G(n);

        for(int i = M; i < m; i++){
            auto &p = edges[i];
            G[p.ff].pb(p.ss);
            G[p.ss].pb(p.ff);
        }

        vector<bool> vis(n, false);
        int comps = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                comps++;
                dfs(G, vis, i);
            }
        }

        if(comps > 1)
            R = M - 1;
        else
            L = M + 1;
    }

    // L -> if you delete edges from 0 to L - 1, you will guaranteed get 2 discon components
    // cout << L << nline;
    vector<vi> G(n);
    for(int i = L; i < m; i++){
        auto &p = edges[i];
        G[p.ff].pb(p.ss);
        G[p.ss].pb(p.ff);
    }
    set<int> S;
    for(int i = 0; i < L; i++)
        S.insert(i);
    
    vector<vi> comps;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vector<int> comp;
            dfs2(G, vis, i, comp);
            comps.pb(comp);
        }
    }
    map<int, int> mp;

    for(int i = 0; i < sz(comps); i++){
        // cout << i << " : ";
        for(int j : comps[i]){
            mp[j] = i;
            // cout << j << " ";
        }
        cout << nline;
    }

    for(int i = L - 1; i >= 0; i--){
        if(mp[edges[i].ff] == mp[edges[i].ss])
            S.erase(i);
    }

    ll ans = 0;


    for(int i : S){
        ans = (ans + binexp(2ll, 1ll*(i + 1), MOD))%MOD;
    }

    cout << ans << nline;
}
int main(){
    ExPLICIT_27;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    return 0;
}