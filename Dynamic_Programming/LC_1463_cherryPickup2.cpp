/*
Similar logic to the first version, 
except we have more branches to consider
*/

#include <bits/stdc++.h>

using namespace std;

// memoized
bool isValid(int i, int j, int k, int m, int n){
    return (i >= 0 && i < n && j >= 0 && j < m && k >= 0 && k < m);
}
int memoized(vector<vector<int>> &grid, int i, int j, int k, int m, int n, vector<vector<vector<int>>> &dp){
    if(!isValid(i, j, k, m, n))
        return INT_MIN;
    // last row, return sum of values or single value if they are on the same cell
    if(i == n - 1){
        if(j == k)
            return grid[i][j];
        return grid[i][j] + grid[i][k];
    }

    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    int best = INT_MIN;
    // try going all valid directions
    for(int u = -1; u <= 1; u++){
        for(int v = -1; v <= 1; v++){
            best = max(best, memoized(grid, i + 1, j + u, k + v, m, n, dp));
        }
    }
    
    
    if(best == INT_MIN)
        return dp[i][j][k] = INT_MIN;
    int value = grid[i][j];
    if(k != j)
        value += grid[i][k];
    // return the accumulated sum
    return dp[i][j][k] = value + best;
}

// tabulated
int tabulated(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for(int j = 0; j < m; j++){
        for(int k = 0; k < m; k++){
            if(j == k)
                dp[n - 1][j][k] = grid[n - 1][j];
            else
                dp[n - 1][j][k] = grid[n - 1][j] + grid[n - 1][k];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            for(int k = m - 1; k >= 0; k--){
                int best = 0;
                for(int u = -1; u <= 1; u++){
                    for(int v = -1; v <= 1; v++){
                        if(isValid(i + 1, j + u, k + v, m, n)){
                            best = max(best, dp[i + 1][j + u][k + v]);
                        }
                    }
                }
                int value = grid[i][j];
                if(j != k)
                    value += grid[i][k];
                dp[i][j][k] = value + best;
            }
        }
    }
    return dp[0][0][m - 1];
}
// space optimized
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> prev(m, vector<int>(m, 0));
    for(int j = 0; j < m; j++){
        for(int k = 0; k < m; k++){
            if(j == k)
                prev[j][k] = grid[n - 1][j];
            else
                prev[j][k] = grid[n - 1][j] + grid[n - 1][k];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for(int j = m - 1; j >= 0; j--){
            for(int k = m - 1; k >= 0; k--){
                int best = 0;
                for(int u = -1; u <= 1; u++){
                    for(int v = -1; v <= 1; v++){
                        if(isValid(i + 1, j + u, k + v, m, n)){
                            best = max(best, prev[j + u][k + v]);
                        }
                    }
                }
                int value = grid[i][j];
                if(j != k)
                    value += grid[i][k];
                curr[j][k] = value + best;
            }
        }
        prev = curr;
    }
    return prev[0][m - 1];
}