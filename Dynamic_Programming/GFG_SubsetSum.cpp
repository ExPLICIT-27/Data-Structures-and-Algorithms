/*
return true if there exists a subset which yields a specific sum
*/
#include <bits/stdc++.h>

using namespace std;

// naive
bool helper(vector<int> &arr, int idx, int target){
    if(target == 0)
        return true;
    if(idx < 0 || target < 0)
        return false;
    
    return helper(arr, idx - 1, target) || helper(arr, idx - 1, target - arr[idx]);    
    
}
// memoized
bool memoized(vector<int> &arr, int idx, int target, vector<vector<int>> &dp){
    if(target == 0)
        return true;
    if(idx == 0) return arr[0] == target;
    if(dp[idx][target] != -1)
        return dp[idx][target];
    return dp[idx][target] = memoized(arr, idx - 1, target, dp) || memoized(arr, idx - 1, target - arr[idx], dp);    
    
}
// tabulated
bool tabulated(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    // base case; sum = 0 is true for every index
    for(int i = 0; i < n; i++)
        dp[i][0] = true;
    // base case 2, check if arr[0] <= target
    if(arr[0] <= sum)
        dp[0][arr[0]] = true;
    for(int i = 1; i < n; i++){
        for(int target = 0; target <= sum; target++){
            dp[i][target] = dp[i - 1][target];
            if(target - arr[i] >= 0){
                dp[i][target]  |=  dp[i - 1][target - arr[i]];
            }
        }
    }
    
    return dp[n - 1][sum];
}
// space optimized
bool optimized(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<bool> prev(sum + 1, false);
    prev[0] = true;
    if(arr[0] <= sum)// if within bounds
        prev[arr[0]] = true;
    for(int i = 1; i < n; i++){
        vector<bool> curr(sum + 1, false);
        
        for(int target = 0; target <= sum; target++){
            curr[target] = prev[target];
            if(target - arr[i] >= 0){
                curr[target] = curr[target] || prev[target - arr[i]];
            }
        }
        prev = curr;
    }
    
    return prev[sum];
}
int main(){
    return 0;
}