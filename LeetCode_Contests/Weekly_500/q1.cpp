#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int e = 0, o = 0;

        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] & 1)
                o++;
            else
                e++;

            if(nums[i] & 1)
                ans[i] = e;
            else
                ans[i] = o;
        }

        return ans;
    }
};