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

vector<vll> dp(1e6 + 1, vll(2));
/*
consider the problem in a different height

at each index you have a block, it can be a block of width 2 or 2 blocks of width 1

Case 1 : Single block of width 2, the choices are:
    - keep extending the block forward (still in case 1)
    - stop the current block, start a new block of width 2 (still in case 1)
    - stop the current block, start 2 new blocks of width 1 (taken from case 2)

Case 2 : Two blocks of width 1, the choices are:
    - keep extending the 2 blocks forward (still in case 2)
    - stop one block, start new one ; keep extending the other (still in case 2, from the next row its the same thing)
    - keep extending the first one, stop the other and start a new one (still in case 2)
    - stop both blocks, start two blocks of width 1 (still in case 2)
    - stop both blocks, start 1 block of width 2 (taken from case 1)

all the extensions within case 1 and case 2 are taken from the previous 2 cases only, i.e either a case of two blocks or one block

the recurrence would be (0 - first case, 1 - second case)

base case, start one of either type
dp[0][0] = dp[0][1] = 1

dp[i][0] = dp[i - 1][0]*2 + dp[i - 1][1]
dp[i][1] = dp[i - 1][1]*4 + dp[i - 1][0]

finally ans would be
dp[n][0] + dp[n][1]
*/
void solve(){

    int n; cin >> n;

    dp[0][0] = dp[0][1] = 1;

    for(int i = 1; i < n; i++){
        dp[i][0] = (dp[i - 1][0]*2 + dp[i - 1][1])%MOD;
        dp[i][1] = (dp[i - 1][1]*4 + dp[i - 1][0])%MOD;
    }

    // space optimization : just take prev1, prev2

    cout <<  (dp[n - 1][0] + dp[n - 1][1])%MOD << nline;

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