#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        /*
        nlog(n) can only be achieved by considering this another version of 2D LIS
        with additional constraints
        for an element x at index i, 
        the since fixed point requires x to be i
        if i > x, impossible, ignore this
        else
            you need to delete (i - x) elements b4 it
        additional constraint
        if there is some y at j for which you need (j - y) deletions
        the following conditions must hold

        0 <= i - x <= j - y
        also x < y

        hence sorting all valid (i -x, x) and doing LIS on it will yield the right answer
        */

        int n = nums.size();
        vector<pair<int, int>> valid;
        for(int i = 0; i < n; i++){
            if(i < nums[i])
                continue;
            valid.push_back(make_pair(i - nums[i], nums[i]));
        }

        sort(valid.begin(), valid.end());

        vector<int> dp;

        for(auto &[d, x] : valid){
            if(dp.empty() || x > dp.back()){
                dp.push_back(x);
                continue;
            }

            auto it = lower_bound(dp.begin(), dp.end(), x);
            dp[it - dp.begin()] = x;
        }

        return dp.size();
    }
};