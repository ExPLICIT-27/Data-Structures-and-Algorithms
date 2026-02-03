#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int tricnt = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1])
                return false;
            
            if(tricnt == 0 && nums[i] > nums[i - 1])
                tricnt++;
            else if(tricnt == 0 && nums[i] < nums[i - 1])
                return false;
            else if(tricnt == 1 && nums[i] > nums[i - 1])
                continue;
            else if(tricnt == 1 && nums[i] < nums[i - 1])
                tricnt++;
            else if(tricnt == 2 && nums[i] < nums[i - 1])
                continue;
            else if(tricnt == 2 && nums[i] > nums[i - 1])
                tricnt++;
            else if(tricnt == 3 && nums[i] > nums[i - 1])
                continue;
            else
                return false;
        }
        return tricnt == 3;
    }
};