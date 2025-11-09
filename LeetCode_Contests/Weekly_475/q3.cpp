
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
class Solution {
public:
    bool valid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    ll helper(vector<vi> &grid, int i, int j, int m, int n, int k, vector<vector<vector<int>>> &dp){
        if(grid[i][j] == 1 || grid[i][j] == 2)
            k--;
        if(k <= 0)
            return INT_MIN;
        if(i == m - 1 && j == n - 1)
            return grid[i][j];
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        ll ans = INT_MIN;
        if(valid(i, j + 1, m, n)){
            int cc = grid[i][j];
            if(cc == 0)
                ans = max(ans, helper(grid, i, j + 1, m, n, k, dp));
            else if(cc == 1)
                ans = max(ans, 1 + helper(grid, i, j + 1, m, n, k, dp));
            else
                ans = max(ans, 2 + helper(grid, i, j + 1, m, n, k, dp));
        }
        if(valid(i + 1, j, m, n)){
            int cc = grid[i][j];
            if(cc == 0)
                ans = max(ans, helper(grid, i + 1, j, m, n, k, dp));
            else if(cc == 1)
                ans = max(ans, 1 + helper(grid, i + 1, j, m, n, k, dp));
            else
                ans = max(ans, 2 + helper(grid, i + 1, j, m, n, k, dp));
        }
        return dp[i][j][k] = ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = sz(grid), m = sz(grid[0]);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 2, -1)));
        int ans = helper(grid, 0, 0, sz(grid), sz(grid[0]), k + 1, dp);
        return ans >= 0 ? ans : -1;
    }
};