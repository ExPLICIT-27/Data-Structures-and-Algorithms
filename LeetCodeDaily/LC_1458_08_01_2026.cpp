#include <bits/stdc++.h>

using namespace std;

// top down
#define ll long long
class Solution {
public:
    ll helper(vector<int> &a1, vector<int> &a2, int i, int j, vector<vector<ll>> &dp){
        if(i == -1 || j == -1){
            return INT_MIN;
        }
        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        ll ans = INT_MIN;
        ans = max(ans, helper(a1, a2, i - 1, j, dp));
        ans = max(ans, helper(a1, a2, i, j - 1, dp));

        return dp[i][j] = max(ans, max(1ll*a1[i]*a2[j], 1ll*a1[i]*a2[j] + helper(a1, a2, i - 1, j - 1, dp)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<ll>> dp(n, vector<ll>(m, INT_MIN));
        return helper(nums1, nums2, n - 1, m - 1, dp);
    }
};

// bottom up
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < m; j++){
                int prod = nums1[i]*nums2[j];
                if(i - 1 >= 0)
                    prod = max(prod, dp[i - 1][j]);
                if(j - 1 >= 0)
                    prod = max(prod, dp[i][j - 1]);
                if(i - 1 >= 0 && j - 1 >= 0)
                    prod = max(1ll*prod, 1ll*nums1[i]*nums2[j] + 1ll*dp[i - 1][j - 1]);
                dp[i][j] = prod;
            }
        }

        return dp[n - 1][m - 1];
    }
};
// bottom up, optimized
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        vector<int> prev(m, INT_MAX), curr(m, INT_MAX);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int prod = nums1[i]*nums2[j];
                // int nmax = prod;
                if(i - 1 >= 0)
                    prod = max(prod, prev[j]);
                if(j - 1 >= 0)
                    prod = max(prod, curr[j - 1]);
                if(i - 1 >= 0 && j - 1 >= 0)
                    prod = max(1ll*prod, 1ll*nums1[i]*nums2[j] + 1ll*prev[j - 1]);
                curr[j] = prod;
            }
            prev = curr;
        }

        return prev[m - 1];

    }
};