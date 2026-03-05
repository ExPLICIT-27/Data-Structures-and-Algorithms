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
 
ll helper(int i, int n, int k, int prev){
    if(i == k)
        return 1;
    
    ll ans = 0;

    for(int j = prev; j <= n; j += prev){
        ans = (ans + helper(i + 1, n, k, j))%MOD;
    }

    return ans;
}
void solve(){
    int n, k; cin >> n >> k;


    // no of sequences of length k with numbers in the range n...1 such that the sequence is good
    /*
    good sequence => a[i]%a[i - 1] == 0

    K slots

    _ _ _ _ _ 
    if i place 1 in the first place, my choices for the others are 1,2,3,4,5..9
    
    */

    vector<vi> dp(k + 1, vi(n + 1, 0));
    auto helper = [&](auto &&self, int i, int prev) -> ll {
        if(i == k)
            return 1;
        if(dp[i][prev] != -1)
            return dp[i][prev];
        
        ll ans = 0;

        for(int j = prev; j <= n; j += prev){
            ans = (ans + self(self, i + 1, j))%MOD;
        }

        return dp[i][prev] = ans;
    };


    // cout << helper(helper, 0, 1) << nline;

    for(int i = 1; i <= n; i++)
        dp[0][i] = 1;

    for(int i = 1; i <= k; i++){
        for(int prev = 1; prev <= n; prev++){
            for(int j = prev; j <= n; j += prev)
                dp[i][prev] = (dp[i][prev] + dp[i - 1][j])%MOD;
        }
    }

    cout << dp[k][1] << nline;
    
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