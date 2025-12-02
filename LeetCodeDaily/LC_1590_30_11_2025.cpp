#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0ll);
        if(total%p == 0)
            return 0;
        unordered_map<long long, int> mp;
        long long csum = 0;
        int n = nums.size();
        int ans = n;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            csum += nums[i];
            long long t = ((csum - total)%p + p)%p;
            if(mp.count(t)){
                ans = min(ans, i - mp[t]);
            }
            mp[csum%p] = i;
        }
        return ans == n? -1 : ans;
    }
};