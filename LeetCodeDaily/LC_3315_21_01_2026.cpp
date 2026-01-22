#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            if(nums[i] == 2)
                continue;
            int curr = nums[i];
            int d = 0;
            ans[i] = nums[i]^1;
            while(curr){
                if(curr & 1){
                    int x = nums[i]^(1 << d);
                    if((x | x + 1) == nums[i])
                        ans[i] = min(ans[i], x);
                }
                curr >>= 1;
                d++;
            }
        }

        return ans;
        
    }
};
/*

// last bit becomes set
100
101

*/