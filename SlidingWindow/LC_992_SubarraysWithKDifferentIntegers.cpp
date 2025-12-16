#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int LOE(vector<int> &nums, int k){
        if(k == 0)
            return 0;
        unordered_map<int, int> mp;
        int l = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return LOE(nums, k) - LOE(nums, k - 1);
    }
};