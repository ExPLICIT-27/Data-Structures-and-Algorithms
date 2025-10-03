/*
very similar to MCM
*/

#include <bits/stdc++.h>

using namespace std;
// memoized
int memoized(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
    if(i > j)
        return 0;
    int maxcost = INT_MIN;
    if(dp[i][j] != -1)
        return dp[i][j];
    for(int k = i; k <= j; k++){
        maxcost = max(maxcost, nums[i - 1]*nums[k]*nums[j + 1] + memoized(nums, i, k - 1, dp) + memoized(nums, k + 1, j, dp));
    }
    return dp[i][j] = maxcost;
}

// tabulated
int maxCoins(vector<int>& nums) {
    // handling the boundary condition
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // loop beginning and ending are based on the first recurrence calls : memoized(nums, 1, n - 2, dp)
    for(int i = n - 2; i >= 1; i--){
        for(int j = i; j <= n - 2; j++){
            int maxcost = INT_MIN;
            for(int k = i; k <= j; k++){
                maxcost = max(maxcost, nums[i - 1]*nums[k]*nums[j + 1] + dp[i][k - 1]  + dp[k + 1][j]);
            }
            dp[i][j] = maxcost;
        }
    }
    return dp[1][n - 2]; // where the memoized recurrence call begins, the tabulated dp ends
}
int main(){
    return 0;
}