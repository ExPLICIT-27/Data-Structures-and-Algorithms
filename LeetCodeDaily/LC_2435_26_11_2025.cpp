#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // memoized
    const int MOD = 1e9 + 7;
    int m, n;
    bool isValid(int i, int j){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int helper(vector<vector<int>> &grid, int i, int j, int c, int k, vector<vector<vector<int>>> &dp){
        if((i == m - 1 && j == n - 1) && ((c + grid[i][j])%k == 0))
            return 1;
        int ans = 0;
        if(dp[i][j][c] != -1)
            return dp[i][j][c];
        if(isValid(i + 1, j))
            ans = (ans + helper(grid, i + 1, j, (c + grid[i][j])%k, k, dp))%MOD;
        if(isValid(i, j + 1))
            ans = (ans + helper(grid, i, j + 1, (c + grid[i][j])%k, k, dp))%MOD;
        return dp[i][j][c] = ans%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        // tabulated
        dp[0][0][grid[0][0]%k] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int c = 0; c < k; c++){
                    if(i - 1 >= 0 && dp[i - 1][j][c]){
                        int nc = (c + grid[i][j])%k;
                        dp[i][j][nc] = (dp[i][j][nc] + dp[i - 1][j][c])%MOD;
                    }
                    if(j - 1 >= 0 && dp[i][j - 1][c]){
                        int nc = (c + grid[i][j])%k;
                        dp[i][j][nc] = (dp[i][j][nc] + dp[i][j - 1][c])%MOD;
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};