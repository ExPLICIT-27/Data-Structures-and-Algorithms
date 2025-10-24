/*
keep track of both max and min, as a sign change can convert max to min and vice verse
*/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long mip = nums[0];
        long long mxp = nums[0];
        long long ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            long long mip1 = mip;
            mip = min({1ll*nums[i], mip*nums[i], mxp*nums[i]});
            mxp = max({1ll*nums[i], mxp*nums[i], mip1*nums[i]});
            ans = max(ans, mxp);
        }
        return ans;
    }
};