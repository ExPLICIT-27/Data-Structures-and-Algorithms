/*
if the sum of all elements in the array is not even, its impossible
else try to find half the value of the target in the array (the other half is automatically the unselected elements)
*/

#include <bits/stdc++.h>

using namespace std;

//naive - ensure to check if total is even or not before even calling the naive or recusrive functions
bool findSum(vector<int> &nums, int idx, int target){
    if(target == 0)
        return true;
    if(idx == 0)
        return nums[0] == target;
    if(target < 0)
        return false;

    return findSum(nums, idx - 1, target - nums[idx]) || findSum(nums, idx - 1, target);
}

// memoized
bool findSum(vector<int> &nums, int idx, int target, vector<vector<int>> &dp){
    if(target == 0)
        return true;
    if(idx == 0)
        return nums[0] == target;
    if(target < 0)
        return false;
    if(dp[idx][target] != -1)
        return dp[idx][target];
    return dp[idx][target] = findSum(nums, idx - 1, target - nums[idx], dp) || findSum(nums, idx - 1, target, dp);
}

// tabulated
bool optimized(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if(total%2)
        return false;
    int target = total/2;
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for(int i = 0; i < n; i++)
        dp[i][0] = true;

    if(nums[0] <= target)
        dp[0][nums[0]] = true;

    for(int i = 1; i < n; i++){
        for(int req = 1; req <= target; req++){
            dp[i][req] = dp[i - 1][req];
            if(req >= nums[i])
                dp[i][req] = dp[i][req] || dp[i - 1][req - nums[i]];
        }
    }
    return dp[n - 1][target];
}

// optimized
bool optimized(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if(total%2)
        return false;
    int target = total/2;
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    vector<bool> prev(target + 1, false);
    prev[0] = true;

    if(nums[0] <= target)
        prev[nums[0]] = true;
    vector<bool> curr(target + 1, false);
    for(int i = 1; i < n; i++){
        for(int req = 1; req <= target; req++){
            curr[req] = prev[req];
            if(req >= nums[i])
                curr[req] = curr[req] || prev[req - nums[i]];
        }
        prev = curr;
    }
    return prev[target];
}
int main(){
    return 0;
}