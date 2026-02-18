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

ll helper(int i, vi &A, int prev, int m, vector<vll> &dp){
    if(i == -1)
        return 1;
    
    if(dp[i][prev] != -1)
        return dp[i][prev];
    ll ans = 0;
    if(i == sz(A) - 1){
        if(A[i] == 0){
            for(int j = 1; j <= m; j++)
                ans = (ans + helper(i - 1, A, j, m, dp))%MOD;
        }
        else
            ans = (ans + helper(i - 1, A, A[i], m, dp))%MOD;
    }
    else{
        if(A[i] == 0){

            int c1 = prev - 1, c2 = prev, c3 = prev + 1;
            if(c1 > 0)
                ans = (ans + helper(i - 1, A, c1, m, dp))%MOD;
            ans = (ans + helper(i - 1, A, c2, m, dp))%MOD;
            if(c3 <= m)
                ans = (ans + helper(i - 1, A, c3, m, dp))%MOD;
        }
        else{
            if(abs(A[i] - prev) > 1)
                return 0;
            ans = helper(i - 1, A, A[i], m, dp);
        }
    }

    return dp[i][prev] = ans;
}
void solve(){
    int n, m; cin >> n >> m;

    vi A(n);

    for(int &i : A)
        cin >> i;
    vector<vll> dp(n + 1, vll(m + 2, 0));
    

    // base case, if A[0] = 0, then put 1 way for every number from 1 to m
    // otherwise whenever A[j] = j (j over 1 to m), set it to 1
    // i, j represents number of ways to make a valid array ending at i with number j

    for(int i = 1; i <= m; i++){
        if(A[0] == 0 || A[0] == i)
            dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i - 1] == 0 || A[i - 1] == j){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1])%MOD; // dp[0][0] is empty, alr handles case of j being 0
                dp[i][j] = (dp[i][j] + dp[i - 1][j])%MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1])%MOD;// alr 0 for > m cases

            }
        }
    }

    ll ans = 0;
    // cnt for each j
    for(int j = 1; j <= m; j++)
        ans = (ans + dp[n][j])%MOD;
    
    cout << ans << nline; 

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