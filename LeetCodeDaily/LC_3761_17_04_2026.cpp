#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;

        auto rev = [&](int n) -> int {
            int r = 0;

            while(n){
                r = r*10 + n%10;
                n /= 10;
            }

            return r;
        };

        int n = nums.size();
        int ans = n + 1;
       
        for(int i = 0; i < n; i++){
            int r = rev(nums[i]);

            if(mp.count(nums[i]))
                ans = min(ans, i - mp[nums[i]]);
            

            mp[r] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};