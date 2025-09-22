/*
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.
*/
#include <bits/stdc++.h>

using namespace std;

// naive
int naive(vector<int> &arr, int target, int idx){
    // always go till end and check, dont break early with target == 0
    if(idx == 0){
        if(target == 0 && arr[0] == 0)
            return 2;
        if(target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if(target < 0)
        return 0;
    return naive(arr, target, idx - 1) + naive(arr, target - arr[idx], idx - 1);
}

// memoized
int memoized(vector<int> &arr, int target, int idx, vector<vector<int>> &dp){
    if(idx == 0){
        if(target == 0 && arr[0] == 0)
            return 2;
        if(target == 0 || arr[0] == target)
            return 1;
        return 0;
        
    }
    if(target < 0)
        return 0;
    if(dp[idx][target] != -1)
        return dp[idx][target];
        
    
    return dp[idx][target] = memoized(arr, target, idx - 1, dp) + memoized(arr, target - arr[idx], idx - 1, dp);
}

// tabulated
int tabulated(vector<int>& arr, int target) {

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // handle all base cases
    if(arr[0] == 0)
        dp[0][0] = 2;
    else{
        dp[0][0] = 1;
        if(arr[0] <= target)
            dp[0][arr[0]]++;
    }    
    for(int i = 1; i < n; i++){
        // start from 0 instread of 1 to handle 0s
        for(int sum = 0; sum <= target; sum++){
            dp[i][sum] += dp[i - 1][sum];
            if(sum - arr[i] >= 0)
                dp[i][sum] += dp[i - 1][sum - arr[i]];
        }
    }
    return dp[n - 1][target];
}
//optimal
int optimal(vector<int>& arr, int target) {

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    vector<int> prev(target + 1, 0);
    if(arr[0] == 0)
        prev[0] = 2;
    else{
        prev[0] = 1;
        if(arr[0] <= target)
            prev[arr[0]]++;
    }    
    vector<int> curr(target + 1, 0);
    for(int i = 1; i < n; i++){
        for(int sum = 0; sum <= target; sum++){
            curr[sum] = prev[sum];
            if(sum - arr[i] >= 0)
                curr[sum] += prev[sum - arr[i]];
        }
        prev = curr;
    }
    return prev[target];
}
int main(){
    return 0;
}