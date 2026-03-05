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
ll dp[19][11][2];
ll helper(string &num, int i, int prev, bool tight){
    if(i == sz(num))
        return 1;
    
    if(dp[i][prev + 1][tight] != -1)
        return dp[i][prev + 1][tight];
    
    int ub = tight? num[i] - '0' : 9;
    ll ans = 0;
    for(int dig = 0; dig <= ub; dig++){
        if(prev == -1){
            // leading zeros are allowed
            if(dig == 0)
                ans += helper(num, i + 1, -1, (tight && (dig == ub)));
            else
                ans += helper(num, i + 1, dig, (tight && (dig == ub)));
        }
        else if(prev != dig)
            ans += helper(num, i + 1, dig, (tight && (dig == ub)));
    }

    return dp[i][prev + 1][tight] = ans;
}
void solve(){
    ll A, B; cin >> A >> B;


    string L = to_string(A - 1), R = to_string(B);

    // generate valid from 0 to left, then 0 to right, and subtract both
    memset(dp, -1, sizeof(dp));
    ll right = helper(R, 0, -1, 1);

    memset(dp, -1, sizeof(dp));
    ll left = helper(L, 0, -1, 1);


    cout << right - left << nline;

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