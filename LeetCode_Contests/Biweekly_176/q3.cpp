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
    ll helper(vector<int> &nums, int i, vll &dp){
        if(i >= sz(nums))
            return 0ll;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(1ll*nums[i] + helper(nums, i + 2, dp), 1ll*helper(nums, i + 1, dp));
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        // perform house robber on each same color segment?
        vector<vector<int>> S;
        vector<int> curr;
        curr.pb(nums[0]);

        int n = sz(nums);
        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i - 1])
                curr.pb(nums[i]);
            else{
                S.pb(curr);
                curr = {};
                curr.pb(nums[i]);
            }
        }
        S.pb(curr);

        ll ans = 0;
        for(auto &V : S){
            int m = sz(V);
            vll dp(m, -1);
            ans += helper(V, 0, dp);
        }

        return ans;
    }
};