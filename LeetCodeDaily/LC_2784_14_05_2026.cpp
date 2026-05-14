#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mx = nums[n - 1];

        if(n != mx + 1)
            return false;

        for(int i = 1; i < n; i++){
            if(nums[i - 1] != i)
                return false;
        }
        
        return true;
    }
};