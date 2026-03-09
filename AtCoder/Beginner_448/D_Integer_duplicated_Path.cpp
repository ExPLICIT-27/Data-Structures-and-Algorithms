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
    int n; cin >> n;

    vi A(n);

    for(int &i : A)
        cin >> i;
    
    vector<vi> G(n);

    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;

        u--, v--;

        G[u].pb(v);
        G[v].pb(u);
    }


    /*
    for every path from 1 to k, where k is from 1 -> n
    if there exists at least one duplicate, output yes, else no

    pass multiset, pop as you go out of the dfs
    */
    map<int, int> mp;
    set<pair<int, int>, greater<pii>> S;
    vector<int> vis(n, false);
    vector<int> ans(n, false);
    auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = true;
        if(mp.count(A[u])){
            S.erase({mp[A[u]], A[u]});
            S.insert({mp[A[u]] + 1, A[u]});
            mp[A[u]]++;
        }
        else{
            mp[A[u]] = 1;
            S.insert({1, A[u]});
        }

        if(S.begin()->ff > 1)
            ans[u] = true;
        
        for(int v : G[u]){
            if(!vis[v])
                self(self, v);
        }

        S.erase({mp[A[u]], A[u]});
        mp[A[u]]--;
        if(mp[A[u]] > 0){
            S.insert({mp[A[u]], A[u]});
        }
        else{
            mp.erase(A[u]);
        }
        
    };

    dfs(dfs, 0);

    for(bool i : ans){
        if(i)
            cout << "Yes\n";
        else
            cout << "No\n";
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