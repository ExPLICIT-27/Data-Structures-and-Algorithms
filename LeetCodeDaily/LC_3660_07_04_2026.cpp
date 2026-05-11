#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        /*
        start building from the right
        maintain pre max and suf mins

        if my current pr[i] > suf[i + 1]
        then it means current ans can be merged with the right segment(from i + 1)(the righter 
        the segment higher the ans due to pref max)

        otherwise just set curr result to nums[i]
        */

        int n = nums.size();

        vector<int> prmax(n), sfmin(n);
        prmax[0] = nums[0], sfmin[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++){
            prmax[i] = max(prmax[i - 1], nums[i]);
            sfmin[n - i - 1] = min(sfmin[n - i], nums[n - i - 1]);
        }

        vector<int> res(n);
        res[n - 1] = prmax[n - 1];

        for(int i = n - 2; i >= 0; i--){
            if(prmax[i] > sfmin[i + 1])
                res[i] = res[i + 1];
            else
                res[i] = prmax[i];
        }

        return res;
    }
};