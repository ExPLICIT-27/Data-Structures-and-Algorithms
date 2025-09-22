/*
choose current house, skip next 
or
skip current 
*/

#include <bits/stdc++.h>

using namespace std;

// naive
int rec(vector<int> &nums, int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    
    // max of take, not take
    return max(nums[n] + rec(nums, n - 2), rec(nums, n - 1));
}
// memoized
int memoized(vector<int> &nums, int n, vector<int> &dp){
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];
    if(dp[n] != -1)
        return dp[n];
    
    return dp[n] = max(nums[n] + memoized(nums, n - 2, dp), memoized(nums, n - 1, dp));
}
// tabulated
int tabulated(vector<int> &nums, int n){
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int notTake = dp[i - 1];
        int take = nums[i];
        if(i > 1)
            take += dp[i - 2];
        dp[i] = max(take, notTake);
    }

    return dp[n - 1];
}
// space optimized
int optimal(vector<int> &nums, int n){
    int first = nums[0], second = 0;
    int curr;
    for(int i = 1; i < n; i++){
        curr = first;
        if(i > 1)
            curr = max(curr, nums[i] + second);
        else 
            curr = max(curr, nums[i]);
        second = first;
        first = curr;
    }
    return first;
}
int main(){
    return 0;
}