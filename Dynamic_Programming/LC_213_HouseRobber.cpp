/*
perform the operation once using the 1st element and avoiding last
then using last, avoiding first
*/
#include <bits/stdc++.h>

using namespace std;
// naive -> call once with least = 1, n = length(nums) - 1; once with least = 0, n = length(nums) - 2
int rec(vector<int> &nums, int least, int n){
    if(n < least)
        return 0;
    if(n == least)
        return nums[least];
    
    return max(nums[n] + rec(nums, least, n - 2), rec(nums, least, n - 1));
}

// memoized
int rec(vector<int> &nums, int least, int n, vector<int> &dp){
    if(n < least)
        return 0;
    if(n == least)
        return nums[least];
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = max(nums[n] + rec(nums, least, n - 2, dp), rec(nums, least, n - 1, dp));
}

// tabulated
int tabulated(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    for(int i = 1; i < n - 1; i++){
        int skip = dp[i - 1];
        int notSkip = nums[i];
        if(i - 2 >= 0)
            notSkip += dp[i - 2];
        dp[i] = max(skip, notSkip);
    }
    int skipLast = dp[n - 2];
    fill(dp.begin(), dp.end(), -1);
    dp[1] = nums[1];
    for(int i = 2; i < n; i++){
        int skip = dp[i - 1];
        int notSkip = nums[i];
        if(i - 2 >= 1)
            notSkip += dp[i - 2];
        dp[i] = max(skip, notSkip);
    }

    return max(skipLast, dp[n - 1]);
}

// optimal
int optimal(vector<int> &nums){
    int n = nums.size();
    int first = nums[0], second = 0;
    int curr;
    for(int i = 1; i < n - 1; i++){
        curr = first;
        if(i - 2 >= 0)
            curr = max(curr, second + nums[i]);
        else
            curr = max(curr, nums[i]);
        second = first;
        first = curr;
    }
    int skipLast = first;
    first = nums[1], second = 0;
    for(int i = 2; i < n; i++){
        curr = first;
        if(i - 2 >= 1)
            curr = max(curr, second + nums[i]);
        else
            curr = max(curr, nums[i]);
        second = first;
        first = curr;
    }
    return max(skipLast, first);
}
int main(){
    return 0;
}