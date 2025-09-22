/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

#include <bits/stdc++.h>

using namespace std;

// memoized
bool isValid(int i, int j, int n){
    return (i >= 0 && i < n && j >= 0 && j < n);
}
// call it for every possible starting
int memoized(vector<vector<int>> &matrix, int i, int j, int n, vector<vector<int>> &dp){
    if(!isValid(i, j, n))
        return INT_MAX;
    if(i == 0)
        return matrix[0][j];
    if(dp[i][j] != INT_MAX)
        return dp[i][j];
    int up = memoized(matrix, i - 1, j, n, dp);
    int left = memoized(matrix, i - 1, j - 1, n, dp);
    int right = memoized(matrix, i - 1, j + 1, n, dp);

    return dp[i][j] = matrix[i][j] + min({up, left, right});
}

// tabulated
int tabulated(vector<vector<int>> &matrix){
    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for(int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j];
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int left = INT_MAX, up = dp[i - 1][j], right = INT_MAX;

            if(j - 1 >= 0)
                left = dp[i - 1][j - 1];
            
            if(j + 1 < n)
                right = dp[i - 1][j + 1];
            
            dp[i][j] = matrix[i][j] + min({left, right, up});
        }
    }

    return *min_element(dp.back().begin(), dp.back().end());
}

// space optimized
int optimized(vector<vector<int>> &matrix){
    int n = matrix.size();

    vector<int> prev(n), curr(n);

    for(int j = 0; j < n; j++)
        prev[j] = matrix[0][j];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int up = prev[j];
            int left = INT_MAX;
            if(j - 1 >= 0)
                left = prev[j - 1];
            int right = INT_MAX;
            if(j + 1 < n)
                right = prev[j + 1];
            curr[j] = matrix[i][j] + min({up, left, right});
        }
        prev = curr;
    }
    return *min_element(prev.begin(), prev.end());
}
int main(){
    return 0;
}