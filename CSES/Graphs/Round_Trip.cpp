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
    int n, m; cin >> n >> m;

    /*
    n cities, m roads

    I need to design a round trip
    that starts from a city and ends in the same city
    basically detect if there is a cycle of length >= 3 and print all the els 
    of the cycle

    DFS cycle detection
    i visit something i have already visited again -> yes

    keep track of nodes in there and see if the length >= 3?
    */

    vector<vi> G(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    vi vis(n, false);

    // the cycle detection is easy, now printing the cycle is the task
    /*
    keep an array components which will store all the elements of the cycle
    insert the node when you visit it
    pop from the array as you return false, cause the last node clearly is not part of the cycle
    then finally when you detect a cycle, insert the node and return true

    now elements of the cycle are the nodes present in comp from back, till you encounter the last node again
    
    */
    auto dfs = [&](auto &&self, int u, int par, vi &comp) -> bool {
        vis[u] = true;
        comp.pb(u);
        for(int v : G[u]){
            if(v == par)
                continue;
            if(vis[v] && v != par){
                comp.pb(v);
                return true;
            }
            if(!vis[v]){
                if(self(self, v, u, comp))
                    return true;
            }
        }
        comp.pop_back();
        return false;
    };
    vi ans;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vi comp;
            if(dfs(dfs, i, -1, comp)){
                ans = comp;
                break;
            }
        }
    }

    if(ans.empty())
        cout << "IMPOSSIBLE\n";
    else{
        vi output;
        int last = ans.back();
        output.pb(last + 1);
        for(int i = sz(ans) - 2; i >= 0; i--){
            output.pb(ans[i] + 1);
            if(ans[i] == last)
                break;
        }

        cout << sz(output) << nline;
        for(int i : output)
            cout << i << " ";
        cout << nline;
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