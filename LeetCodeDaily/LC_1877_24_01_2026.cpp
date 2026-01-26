#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 1, r = n - 2;

        int ans = nums[0] + nums[n - 1];

        while(l < r){
            ans = max(ans, nums[l++] + nums[r--]);
        }

        return ans;
    }
};