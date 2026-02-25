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
ll countWays(ll target, int i, int n, vector<vll> &dp){
    if(target == 0)
        return 1;
    if(target < 0)
        return 0;
    if(i > n)
        return 0;
    
    if(dp[i][target] != -1)
        return dp[i][target];
    
    return dp[i][target] = (countWays(target, i + 1, n, dp) + countWays(target - i, i + 1, n, dp))%MOD;
}
void solve(){
    int n; cin >> n;

    ll total = 1ll*n*(n + 1)/2;

    if(total & 1){
        cout << 0 << nline;
        return;
    }
    // vector<vll> dp(n + 1, vll(total/2 + 1, 0));
    // ll ans = countWays(total/2, 1, n, dp);
    
    // we cannot just do ans/2, because we performed modular addition inside,
    // we need to do ans*inverse(2) modulo MOD
    // since 1e9 + 7 is prime, fermats theorem states 2^-1 mod (MOD) = pow(2, MOD - 2)%MOD (just do binary exp)

    // cout << ans*binexp(2, MOD - 2, MOD)%MOD << nline;

    // for(int i = 0; i <= n; i++)
    //     dp[i][0] = 1;

    ll target = total/2;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= target; j++){
    //         if(j - i >= 0)
    //             dp[i][j] = (dp[i][j] + dp[i - 1][j - i])%MOD;
    //         dp[i][j] = (dp[i][j] + dp[i - 1][j])%MOD;
    //     }
    // }

    // cout << dp[n][target]*binexp(2, MOD - 2, MOD)%MOD << nline;

    vll dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = target; j >= i; j--){
            dp[j] = (dp[j] + dp[j - i])%MOD;
        }
    }

    cout << dp[target]*binexp(2, MOD - 2, MOD)%MOD << nline;
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