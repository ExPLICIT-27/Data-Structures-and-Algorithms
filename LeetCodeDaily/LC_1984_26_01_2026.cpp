#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());


        int ans = nums[k - 1] - nums[0];
        int n = nums.size();

        for(int i = k; i < n; i++){
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }

        return ans;
    }
};