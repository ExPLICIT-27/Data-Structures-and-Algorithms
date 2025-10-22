#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + k + 2);
        for(int i : nums)
            freq[i]++;
        for(int i = 1; i < (mx + k + 2); i++)
            freq[i] += freq[i - 1];
        
        int res = 0;
        for(int i = 0; i <= mx; i++){
            int left = max(0, i - k);
            int right = min(mx + k + 1, i + k);
            int total = freq[right] - ((left - 1 < 0)? 0 : freq[left - 1]);
            int curr_fr = freq[i] - ((i - 1 < 0)? 0 : freq[i - 1]);
            res = max(res, curr_fr + min(numOperations, total - curr_fr));
        }
        return res;
    }
};