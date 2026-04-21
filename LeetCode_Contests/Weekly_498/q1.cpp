#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prmx(n);
        vector<int> sfmn(n);

        prmx[0] = nums[0];
        sfmn[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++){
            prmx[i] = max(prmx[i - 1], nums[i]);
            sfmn[n - i - 1] = min(sfmn[n - i], nums[n - i - 1]);
        }

        for(int i = 0; i < n; i++){
            if(prmx[i] - sfmn[i] <= k)
                return i;
        }

        return -1;
    }
};