/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time
*/
#include <bits/stdc++.h>

using namespace std;

// naive
int naive(vector<vector<int>> &grid, int i, int j){
    if(i < 0 || j < 0)
        return INT_MAX;
    if(i == 0 && j == 0)
        return grid[i][j];
    
    return grid[i][j] + min(naive(grid, i - 1, j), naive(grid, i, j - 1));
}

// memoized
int memoized(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
    if(i < 0 || j < 0)
        return INT_MAX;
    if(i == 0 && j == 0)
        return grid[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(memoized(grid, i - 1, j, dp), memoized(grid, i, j - 1, dp));
}

// tabulated
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = grid[0][0];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int left = INT_MAX, up = INT_MAX;
            if(i - 1 >= 0)
                up = dp[i - 1][j];
            if(j - 1 >= 0)
                left = dp[i][j - 1];
            dp[i][j] =  min(1LL*dp[i][j], 1LL*grid[i][j] + min(left, up));
        }
    }
    return dp[m - 1][n - 1];
}

// space optimized
int optimized(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> prev(n, INT_MAX);
    prev[0] = grid[0][0];

    for(int i = 0; i < m; i++){
        vector<int> curr(n, INT_MAX);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                curr[j] = grid[0][0];
                continue;
            }
            int left = INT_MAX, up = INT_MAX;
            up = prev[j];
            if(j - 1 >= 0)
                left = curr[j - 1];
            curr[j] = min(1LL*curr[j], 1LL*grid[i][j] + min(left, up));
        }
        prev = curr;
    }
    return prev[n - 1];
}
int main(){
    return 0;
}