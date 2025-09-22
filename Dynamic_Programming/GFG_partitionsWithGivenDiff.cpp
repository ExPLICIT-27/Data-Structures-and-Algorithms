/*
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

naive and memoized approaches written here work, but are difficult to convert to tabulated version
s1 - s2 = d
total - s2  - s2 = d
s2 = (total - d) /2
find all subsets with given sum
*/
#include <bits/stdc++.h>

using namespace std;

// naive method 1
int count(vector<int> &arr, int d, int sum1, int sum2, int idx){
    if(idx == 0){
        if(sum1 - sum2 == d && arr[0] == 0)
            return 2;
        if(sum1 + arr[idx] - sum2 == d)
            return 1;
        if(sum1 - (arr[idx] + sum2) == d)
            return 1;
        return 0;
    }

    return count(arr, d, sum1 + arr[idx], sum2, idx - 1) + count(arr, d, sum1, sum2 + arr[idx], idx - 1);
}

// memoized method 1
int count(vector<int> &arr, int d, int sum1, int sum2, int idx, vector<vector<int>> &dp){
    if(idx == 0){
        if(sum1 - sum2 == d && arr[0] == 0)
            return 2;
        if(sum1 + arr[idx] - sum2 == d)
            return 1;
        if(sum1 - (arr[idx] + sum2) == d)
            return 1;
        return 0;
    }
    if(dp[idx][sum1] != -1)
        return dp[idx][sum1];
    return  dp[idx][sum1] = count(arr, d, sum1 + arr[idx], sum2, idx - 1, dp) +
    count(arr, d, sum1, sum2 + arr[idx], idx - 1, dp);
}

// memoized method 2 (for naive just remove the dp array)
int count(vector<int> &arr, int target, int idx, vector<vector<int>> &dp){
    if(idx == 0){
        if(target == 0 && arr[0] == 0)
            return 2;
        if(target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if(target < 0)
        return 0;
    if(dp[idx][target] != -1)
        return dp[idx][target];
    
    return dp[idx][target] = count(arr, target - arr[idx], idx - 1, dp)
        + count(arr, target, idx - 1, dp);
}

// tabulated
int countPartitions(vector<int>& arr, int d) {
    // Code here
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    if((total - d) < 0 || (total - d)%2)
        return 0;
    int target = (total - d)/2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if(arr[0] == 0)
        dp[0][0] = 2;
    else{
        dp[0][0] = 1;
        if(arr[0] <= target)
            dp[0][arr[0]]++;
    }
    
    for(int i = 1; i < n; i++){
        for(int sum = 0; sum <= target; sum++){
            dp[i][sum] = dp[i - 1][sum];
            if(sum - arr[i] >= 0)
                dp[i][sum] += dp[i - 1][sum - arr[i]];
        }
    }
    
    return dp[n - 1][target];
}

// optimized
int countPartitions(vector<int>& arr, int d) {
    // Code here
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    if((total - d) < 0 || (total - d)%2)
        return 0;
    int target = (total - d)/2;
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