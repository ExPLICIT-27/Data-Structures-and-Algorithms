/*
same question as frog jump, but here you are allowed to jump till the i + k th index
*/

#include <bits/stdc++.h>

using namespace std;

// naive recursion
int rec(vector<int> &height, int k, int n){
    if(n == 0)
        return 0;
    int minCost = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(n - i < 0)
            break;
        minCost = min(minCost, abs(height[n] - height[n - i]) + rec(height, k, n - i));
    }
    return minCost;
}

// memoized
int memoized(vector<int> &height, int k , int n, vector<int> &dp){
    if(n == 0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    int minCost = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(n - i < 0)
            break;
        minCost = min(minCost, abs(height[n] - height[n - i]) + memoized(height, k, n - i, dp));
    }

    return dp[n] = minCost;
}
// tabulated
int tabulated(vector<int> &height, int k){
    int n = height.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i - j < 0)
                break;
            dp[i] = min(dp[i], abs(height[i] - height[i - j]) + dp[i - j]);
        }
    }

    return dp[n - 1];

}
int main(){
    return 0;
}