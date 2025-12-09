#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        vector<int> mp(1e5 + 1, 0);

        for(int i : nums)
            mp[i]++;
        long long ans = 0;
        vector<int> mp2(1e5 + 1, 0);
        for(int i : nums){
            mp[i]--;
            long long left = (2*i <= 1e5) ? mp2[2*i] : 0;
            long long right = (2*i <= 1e5) ? mp[2*i] : 0;
            mp2[i]++;
            ans = (ans + right*left%MOD)%MOD;
        }
        return ans;
    }
};