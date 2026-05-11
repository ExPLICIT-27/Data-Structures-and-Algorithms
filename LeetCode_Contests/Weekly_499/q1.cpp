#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
    
        vector<int> tmp(n, 0);

        tmp[0] = nums[0], tmp[n - 1] = nums[n - 1];

        int pmax = nums[0], smax = nums[n - 1];
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > pmax)
                tmp[i] = nums[i];

            if(nums[n - i - 1] > smax)
                tmp[n - i - 1] = nums[n - i - 1];

            pmax = max(pmax, nums[i]);
            smax = max(smax, nums[n - i - 1]);
        }

        vector<int> ans;

        for(int i : tmp){
            if(i)
                ans.push_back(i);
        }

        return ans;
    }
};