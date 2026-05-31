#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zc = 0;

        for(int i : nums){
            if(!i)
                zc++;
        }

        int n = nums.size();
        int ans = 0;
        for(int i = n - 1; i >= (n - zc); i--){
            if(nums[i])
                ans++;
        }

        return ans;
    }
};