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
// top down
int helper(int i, int j, string &A, string &B, vector<vi> &dp){
    if(i == -1)
        return j + 1;
    if(j == -1)
        return i + 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    if(A[i] == B[j])
        return helper(i - 1, j - 1, A, B, dp);
    
    int insertA = helper(i, j - 1, A, B, dp);
    int insertB = helper(i - 1, j, A, B, dp);
    int replaceAB = helper(i - 1, j - 1, A, B, dp);

    return dp[i][j] = 1 + min(insertA, min(insertB, replaceAB));
}
void solve(){
    string A, B;

    cin >> A >> B;

    // no need to delete except for the extra chars, if it doesnt match, ill either insert or replace always

    // bottom up
    int n = sz(A), m = sz(B);
    vector<vi> dp(n + 1, vi(m + 1, 0));
    for(int j = 0; j <= m; j++)
        dp[0][j] = j;
    for(int i = 0; i <= n; i++)
        dp[i][0] = i;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    

    // space optimized
    vector<int> dp1(m + 1, 0), dp2(m + 1, 0);

    for(int j = 0; j <= m; j++)
        dp1[j] = j;
    for(int i = 1; i <= n; i++){
        dp2[0] = i;
        for(int j = 1; j <= m; j++){
            if(A[i - 1] == B[j - 1])
                dp2[j] = dp1[j - 1];
            else
                dp2[j] = 1 + min(dp1[j], min(dp2[j - 1], dp1[j - 1]));
        }
        dp1 = dp2;
    }

    cout << dp1[m] << nline;

    
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