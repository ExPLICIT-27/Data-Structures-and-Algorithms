#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int inv_count = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1])
                inv_count++;
        }
        if(nums[0] < nums[n - 1])
            inv_count++;
        return inv_count <= 1;
    }
};