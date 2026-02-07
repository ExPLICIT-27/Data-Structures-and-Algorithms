#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(3, -1e15));

        ll ans = -1e15;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                dp[i][0] = max(1ll*(nums[i] + nums[i - 1]), dp[i - 1][0] + 1ll*nums[i]);
                if(dp[i - 1][1] != -1e15)
                    dp[i][2] = max(dp[i][2], dp[i - 1][1] + 1ll*nums[i]);
                if(dp[i - 1][2] != -1e15)
                    dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1ll*nums[i]);
            }
            else if(nums[i] < nums[i - 1]){
                if(dp[i - 1][0] != -1e15)
                    dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1ll*nums[i]);
                if(dp[i - 1][1] != -1e15)
                    dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1ll*nums[i]);
            }
        }

        for(int i = 2; i < n; i++)
            ans = max(ans, dp[i][2]);

        return ans;
    }
};
/*
0
1
2
3
*/