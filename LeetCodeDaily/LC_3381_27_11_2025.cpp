#include <bits/stdc++.h>

using namespace std;

/*
1 2 -3 4 ans = 4
-4, -1, 4
*/

class Solution {
public:
    using ll = long long;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> invSum(k, LLONG_MAX/2);
        invSum[k - 1] = 0; // (i == k - 1, len is k (0 based index), hence it is divisible and shoudl be 0)
        ll csum = 0;
        ll ans = LLONG_MIN;
        for(int i = 0; i < n; i++){
            csum += nums[i];
            ans = max(ans, csum - invSum[i%k]);
            invSum[i%k] = min(invSum[i%k], csum);
        }
        return ans;
    }

};