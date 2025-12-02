#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans;
        ans.reserve(n);
        int curr = 0;
        for(int i : nums){
            curr = (curr*2 + i)%5;
            if(!curr)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};