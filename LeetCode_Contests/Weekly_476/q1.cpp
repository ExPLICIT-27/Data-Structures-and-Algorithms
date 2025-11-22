#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        return nums[n - 1] + nums[n - 2] - nums[0];
    }
};