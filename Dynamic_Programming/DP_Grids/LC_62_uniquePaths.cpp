/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

#include <bits/stdc++.h>

using namespace std;

// memoized (skipping naive as it is of no use except for building logic which is the same as in top down)
bool isValid(int i, int j, int m, int n){
    return (i >= 0 && i < m && j >= 0 && j < n);
}
int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
    if(!isValid(i, j, m, n))
        return 0;
    if(i == 0 && j == 0)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = countPaths(i, j - 1, m, n, dp) + countPaths(i - 1, j, m, n, dp);
}

// tabulated
int tabulated(int m, int n){

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i - 1 >= 0)
                dp[i][j] += dp[i - 1][j];
            
            if(j - 1 >= 0)
                dp[i][j] += dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

// space optimized
int optimized(int m, int n){
    vector<int> prev(n, 0);
    prev[0] = 1;
    for(int i = 0; i < m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++){
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