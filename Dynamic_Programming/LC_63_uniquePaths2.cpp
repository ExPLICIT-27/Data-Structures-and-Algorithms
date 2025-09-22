/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/
// Note : in the main function, if the start or end position is not reachable, return 0 immediately

#include <bits/stdc++.h>

using namespace std;

// naive
bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
}
int naive(vector<vector<int>> &grid, int i, int j, int m, int n){
    if(!isValid(i, j, m, n) || grid[i][j])
        return 0;
    if(i == 0 && j == 0)
        return 1;
    return naive(grid, i - 1, j, m, n) + naive(grid, i, j - 1, m, n);
    
}
// memoized
int memoized(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp){
    if(!isValid(i, j, m, n) || grid[i][j])
        return 0;
    if(i == 0 && j == 0)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = memoized(grid, i - 1, j, m, n, dp) + memoized(grid, i, j - 1, m, n, dp);    
}
// tabulated
int tabulated(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if(grid[0][0] || grid[m - 1][n - 1])
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j])
                continue;
            if(i - 1 >= 0)
                dp[i][j] += dp[i - 1][j];
            
            if(j - 1 >= 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

// space optimized
int optimized(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if(grid[0][0] || grid[m - 1][n - 1])
        return 0;
    vector<int> prev(n, 0);
    prev[0] = 1;

    for(int i = 0; i < m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++){
            if(grid[i][j])
                continue;
            curr[j] += prev[j];
            if(j - 1 >= 0)
                curr[j] += curr[j - 1];
        }
        prev = curr;
    }

    return prev[n - 1];
}
int main(){
    return 0;
}