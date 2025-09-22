/*
Logic:
going from 0,0 to n-1, n-1 and back is the same as allowing 2 people to start from 0,0 and go to n-1, n-1

so thats what we will do, hence the states would be (i, j) => position of person 1, (k, m) => position of person 2
one might think this entails to 4D dp, but it is actually 3d
why?
because i + j is always equal to k + m
hence if you have i, j, k you can find m = i + j - k;
*/
#include <bits/stdc++.h>

using namespace std;

// naive
bool isValid(int i, int j, int k, int m, int n){
    return (i >= 0 && i < n && j >= 0 && j < n && k >= 0 && k < n && m >= 0 && m < n);
}
int naive(vector<vector<int>> &grid, int i, int j, int k, int n){
    int m = (i + j) - k;
    // if invalid indexes or thorn, return INT_MIN
    if(!isValid(i, j, k, m, n) || grid[i][j] == -1 || grid[k][m] == -1)
        return INT_MIN;

    
    // since sum is equal k and m will also be 0 if i and j are 0
    if(i == 0 && j == 0)
        return grid[i][j];
    
    // both left, both up, one left-two up, one up-two left
    int l1l2 = naive(grid, i, j - 1, k, n);
    int u1u2 = naive(grid, i - 1, j, k - 1, n);
    int l1u2 = naive(grid, i, j - 1, k - 1, n);
    int u1l2 = naive(grid, i - 1, j, k, n);

    int best = max({l1l2, l1u2, u1u2, u1l2});

    // no path possible
    if(best == INT_MIN)
        return INT_MIN;
    
    // add both their cherry count if they are not on the same cell
    int value = grid[i][j];
    if(i != k || j != m)
        value += grid[i][j];
    
    return value + best;   
}

// memoized
int memoized(vector<vector<int>> &grid, int i, int j, int k, int n, vector<vector<vector<int>>> &dp){
    int m = (i + j) - k;
    if(!isValid(i, j, k, m, n) || grid[i][j] == -1 || grid[k][m] == -1)
        return INT_MIN;
    
    if(i == 0 && j == 0)
        return grid[i][j];
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    
    int l1l2 = memoized(grid, i, j - 1, k, n, dp);
    int l1u2 = memoized(grid, i, j - 1, k - 1, n, dp);
    int u1l2 = memoized(grid, i - 1, j, k, n, dp);
    int u1u2 = memoized(grid, i - 1, j, k - 1, n, dp);


    int best = max({l1l2, l1u2, u1l2, u1u2});
    if(best == INT_MAX)
        return dp[i][j][k] = INT_MIN;
    
    int value = grid[i][j];
    if(k != i || m != j)
        value += grid[k][m];
    
    return dp[i][j][k] = value + best;
}

// tabulated
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] == -1 || grid[n - 1][n - 1] == -1)
        return 0;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    dp[0][0][0] = grid[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0)
                continue;
            for(int k = 0; k < n; k++){
                int m = (i + j) - k;
                if(m < 0 || m >= n)
                    continue;
                if(grid[i][j] == -1 || grid[k][m] == -1)
                    continue;
                int value = grid[i][j];
                if(i != k || j != m)
                    value += grid[k][m];
                
                int best = INT_MIN;
                if(i - 1 >= 0)
                    best = max(best, dp[i - 1][j][k]);
                if(i - 1 >= 0 && k - 1 >= 0)
                    best = max(best, dp[i - 1][j][k - 1]);
                if(j - 1 >= 0)
                    best = max(best, dp[i][j - 1][k]);
                if(j - 1 >= 0 && k - 1 >= 0)
                    best = max(best, dp[i][j - 1][k - 1]);

                if(best == INT_MIN)
                    dp[i][j][k] = best;
                else
                    dp[i][j][k] = value + best;
            }
        }
    }

    return max(dp[n - 1][n - 1][n - 1], 0);
}

int main(){
    return 0;
}