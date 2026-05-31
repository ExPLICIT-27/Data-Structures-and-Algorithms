#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int cnt = 1;
        ans.push_back(nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1])
                cnt++;
            else
                cnt = 1;
            if(cnt > k)
                continue;
            ans.push_back(nums[i]);
        }

        return ans;
    }
};