#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
/*
                        QUESTION DESCRIPTION
    Given a 2d matrix cost[][], task is to calculate minimum cost path to reach m,n
    from (0, 0)
    We can only move down, right, or diagonally low
*/
/*
Naive Brute force O(3^(m + n)) Top down approach

since the possible directions include right (i, j+1),
down (i+1, j) and diagonally right down (i+1, j+1)
reversed (since its top down) would be:
(i, j-1), (i-1, j) and (i-1, j-1)
Recurrence relation minCost(m, n) = cost[m][n] + min(minCost(m, n-1), minCost(m-1, n), minCost(m-1, n-1))
*/
int NaiveBruteForce(vector<vector<int>> &cost, int m, int n){
    if(n < 0 || m < 0) return INT_MAX;
    if(n == 0 && m == 0) return cost[0][0];

    return cost[m][n] + min({NaiveBruteForce(cost, m, n-1), NaiveBruteForce(cost, m-1, n-1), NaiveBruteForce(cost, m-1, n)});
}
/*
Memoized Approach (O(n*m) time and space)
maintain a memo and utilize its value if it is pre calculated
*/
int MemoizedApproach(vector<vector<int>> &cost, vector<vector<int>> &memo, int m, int n){
    if(n < 0 || m < 0) return INT_MAX;
    if(n == 0 && m == 0) return cost[0][0];

    if(memo[m][n] != -1) return memo[m][n];

    memo[m][n] = cost[m][n] + min({MemoizedApproach(cost, memo, m, n-1), MemoizedApproach(cost, memo, m-1, n-1), MemoizedApproach(cost, memo, m-1, n)});
    return memo[m][n];
}
/*
Dynamic Programming (Bottom Up Tabulation) O(m*n) space and time
Note : First row, you can not take previous value from top or top left, only from left
First column only top, no top-left and no left
*/
int DynamicTabulation(vector<vector<int>> &cost, int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = cost[0][0];

    // first row
    for(int i = 1; i < n; i++){
        dp[0][i] = cost[0][i] + dp[0][i-1];
    }
    // first column
    for(int j = 1; j < m; j++){
        dp[j][0] = cost[j][0] + dp[j-1][0];
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = cost[i][j] + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[m-1][n-1];
}
int main(){
    vector<vector<int>> cost = { { 1, 2, 3 },
                                 { 4, 8, 2 },
                                 { 1, 5, 3 } };
    int m = cost.size();
    int n = cost[0].size();
    cout << NaiveBruteForce(cost, m-1, n-1) << endl;
    vector<vector<int>> memo(m, vector<int>(n, -1));
    cout << MemoizedApproach(cost, memo, m-1, n-1) << endl;
    cout << DynamicTabulation(cost, m, n);
    return 0;
}