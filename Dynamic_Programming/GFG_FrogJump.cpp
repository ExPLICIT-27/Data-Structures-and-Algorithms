/*
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.
*/

#include <bits/stdc++.h>

using namespace std;

// O(2^n) no memoization
int rec(vector<int> &height, int n){
    if(n == 0)
        return 0;
    int noSkip = abs(height[n] - height[n - 1]) + rec(height, n - 1);
    int skip = INT_MAX;
    if(n - 2 >= 0)
        skip = abs(height[n] - height[n - 2]) + rec(height, n - 2);
    
    return min(skip, noSkip);
}

// O(n) memoized
int memoized(vector<int> &height, int n, vector<int> &dp){
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    int noSkip = abs(height[n] - height[n - 1]) + rec(height, n - 1);
    int skip = INT_MAX;
    if(n - 2 >= 0)
        skip = abs(height[n] - height[n - 2]) + rec(height, n - 2);
    
    return dp[n] = min(skip, noSkip);

}
int minCost(vector<int>& height){
    // tabulated
    int n = height.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + abs(height[i] - height[i - 1]);
        if(i > 1)
            dp[i] = min(dp[i], dp[i - 2] + abs(height[i] - height[i - 2]));
    }

    cout << dp[n - 1]  << " ";

    // space optimized
    int first = 0, second = 0;
    int curr;
    for(int i = 1; i < n; i++){
        curr = first + abs(height[i] - height[i - 1]);
        if(i > 1)
            curr = min(curr, second + abs(height[i] - height[i - 2]));

        second = first;
        first = curr;
    }
    return curr;
}
int main(){
    return 0;
}