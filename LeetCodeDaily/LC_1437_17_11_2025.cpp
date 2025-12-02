#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -k - 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i]){
                if(i - prev <= k)
                    return false;
                prev = i;
            }
        }
        return true;
    }
};