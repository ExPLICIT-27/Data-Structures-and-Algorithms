
#include <bits/stdc++.h>

using namespace std;
// memo
int memoized(vector<int> &nums, int target, int idx, vector<vector<int>> &dp){
    if(idx == 0){
        if(target == 0 && nums[0] == 0)
            return 2;
        if(target - nums[idx] == 0)
            return 1;
        if(target == 0)
            return 1;
        return 0;
    }
    if(target < 0)
        return 0;
    if(dp[idx][target] != -1)
        return dp[idx][target];
    return dp[idx][target] = memoized(nums, target - nums[idx], idx - 1, dp) + memoized(nums, target, idx - 1, dp);
}
//optimized
int optimized(vector<int>& nums, int target) {
    long long total = accumulate(nums.begin(), nums.end(), 0LL);

    if( (total + target)%2  || (total + target) < 0)
        return 0;
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>((total + target)/2 + 1, 0));
    int req = (total + target)/2;
    vector<int> prev(req + 1, 0);
    if(nums[0]== 0)
        prev[nums[0]] = 2;
    else{
        prev[0] = 1;
        if(nums[0] <= req)
            prev[nums[0]]++;
    }
    vector<int> curr(req + 1, 0);
    for(int i = 1; i < n; i++){
        for(int sum = 0; sum <= req; sum++){
            curr[sum] = prev[sum];
            if(sum >= nums[i])
                curr[sum] += prev[sum - nums[i]];
            
        }
        prev = curr;
    }
    return prev[req];
}
int main(){
    return 0;
}