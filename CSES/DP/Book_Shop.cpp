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

ll helper(int x, vector<pii> &B, int i){
    if(i == -1 || x == 0)
        return 0;

    ll take = (x - B[i].ff >= 0) ? B[i].ss + helper(x - B[i].ff, B, i - 1) : 0;
    ll notTake = helper(x, B, i - 1);

    return max(take, notTake);
}
void solve(){
    int n, x; cin >> n >> x;

    vector<pii> B(n);

    for(auto &p : B)
        cin >> p.ff;
    for(auto &p : B)
        cin >> p.ss;
    
    // cout << helper(x, B, n - 1) << nline;
    // vector<vector<ll>> dp(n + 1, vll(x + 1, 0));
    vll curr(x + 1, 0), prev(x + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= x; c++){
            if(c - B[i - 1].ff >= 0)
                curr[c] = max(curr[c], B[i - 1].ss + prev[c - B[i - 1].ff]);
            curr[c] = max(curr[c], prev[c]);
        }
        prev = curr;
    }

    cout << curr[x] << nline;

}
int main(){
    fastio;
    solve();
    // int T;
    // cin >> T;
    // while(T--){
    //     solve();
    // }

    return 0;
}