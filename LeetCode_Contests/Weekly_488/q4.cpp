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
class Solution {
public:
    // top down, first AC during contest
    ll helper(vi &nums1, vi &nums2, int i, int j, int k, vector<vector<vll>> &dp){
        if(i == sz(nums1) || j == sz(nums2)){
            if(k == 0)
                return 0ll;
            return -1e16;
        }
        if(k == 0)
            return 0ll;
        if(dp[i][j][k] != LLONG_MIN)
            return dp[i][j][k];
        ll ans = 1ll*nums1[i]*nums2[j] + helper(nums1, nums2, i + 1, j + 1, k - 1, dp);

        ans = max(ans, helper(nums1, nums2, i + 1, j, k, dp));
        ans = max(ans, helper(nums1, nums2, i, j + 1, k, dp));

        return dp[i][j][k] = ans;     
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = sz(nums1), m = sz(nums2);
        vector<vector<vector<ll>>> dp(n + 1, vector<vll>(m + 1, vector<ll>(k + 1, LLONG_MIN)));

        // return helper(nums1, nums2, 0, 0, k, dp);

        // post contest, bottom up
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j][0] = 0;
            }
        }
        ll ans = LLONG_MIN;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int c = 1; c <= k; c++){
                    if(dp[i - 1][j - 1][c - 1] != LLONG_MIN)
                        dp[i][j][c] = max(dp[i][j][c], 1ll*nums1[i - 1]*nums2[j - 1] + dp[i - 1][j - 1][c - 1]);
                    if(dp[i - 1][j][c] != LLONG_MIN)
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c]);
                    if(dp[i][j - 1][c] != LLONG_MIN)
                        dp[i][j][c] = max(dp[i][j][c], dp[i][j - 1][c]);
                    
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
        
        return ans;
    }
};