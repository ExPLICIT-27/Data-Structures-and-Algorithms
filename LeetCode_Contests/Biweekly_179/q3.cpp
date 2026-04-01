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
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        /*
        only 11 max bits are there
        try to see if you can keep the ith bit unset as you go down
        */
        
        int n = sz(grid), m = sz(grid[0]);

        int dp[n][m][1025];

        memset(dp, -1, sizeof(dp));

        auto F = [&](auto &&self, int i, int j, int curr) -> int {
            if(i == n - 1 && j == m - 1)
                return curr;
            

            int dwn = INT_MAX, ri = INT_MAX;

            if(dp[i][j][curr] != -1)
                return dp[i][j][curr];

            if(i + 1 < n)
                dwn = self(self, i + 1, j, curr^grid[i + 1][j]);
            
            if(j + 1 < m)
                ri = self(self, i, j + 1, curr^grid[i][j + 1]);

            return dp[i][j][curr] = min(dwn, ri);
        };

        return F(F, 0, 0, grid[0][0]);
    }
};