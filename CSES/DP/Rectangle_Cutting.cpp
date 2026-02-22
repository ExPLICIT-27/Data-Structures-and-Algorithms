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
ll helper(int a, int b, vector<vll> &dp){
    if(a == b)
        return 0;
    
    if(dp[a][b] != -1)
        return dp[a][b];

    ll ans = LLONG_MAX;
    for(int i = 1; i < a; i++){
        ans = min(ans, 1 + helper(a - i, b, dp) + helper(i, b, dp));
    }


    for(int i = 1; i < b; i++){
        ans = min(ans, 1 + helper(min(a, b - i), max(a, b - i), dp) + helper(min(i, a), max(i, a), dp));
    }
    return dp[a][b] = ans;

}
void solve(){
    int a, b;
    cin >> a >> b;
    vector<vll> dp(a + 1, vll(b + 1, INF));
    // cout << helper(min(a, b), max(a, b), dp) << nline;

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            // horizontal cuts
            for(int h = 1; h < i; h++)
                dp[i][j] = min(dp[i][j], 1 + dp[h][j] + dp[i - h][j]);
            //vertical
            for(int v = 1; v < j; v++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][v] + dp[i][j - v]);
        }
    }

    cout << dp[a][b] << nline;

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