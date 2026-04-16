#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();    
        int ans = n + 1;

        for(int i = 0; i < n; i++){
            if(nums[i] == target)
                ans = min(ans, abs(i - start));
        }

        return ans;


    }
};