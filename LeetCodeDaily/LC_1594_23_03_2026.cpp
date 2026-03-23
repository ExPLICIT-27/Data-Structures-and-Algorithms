#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(m));

        dp[0][0].first = dp[0][0].second = grid[0][0];

        for(int i = 1; i < n; i++)
            dp[i][0].first = dp[i][0].second = grid[i][0]*dp[i - 1][0].first;
        
        for(int j = 1; j < m; j++)
            dp[0][j].first = dp[0][j].second = grid[0][j]*dp[0][j - 1].first;

        const int MOD = 1e9 + 7;

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                ll tMin = min(grid[i][j]*dp[i - 1][j].first, grid[i][j]*dp[i - 1][j].second);
                ll lMin = min(grid[i][j]*dp[i][j - 1].first, grid[i][j]*dp[i][j - 1].second);

                ll tMax = max(grid[i][j]*dp[i - 1][j].first, grid[i][j]*dp[i - 1][j].second);
                ll lMax = max(grid[i][j]*dp[i][j - 1].first, grid[i][j]*dp[i][j - 1].second);

                dp[i][j].first = min(tMin, lMin);
                dp[i][j].second = max(tMax, lMax);
            }
        }

        
        ll ans = dp[n - 1][m - 1].second;

        return ans < 0? -1 : ans%MOD;
    }
};