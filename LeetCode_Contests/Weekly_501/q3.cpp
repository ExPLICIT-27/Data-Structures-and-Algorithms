#include <bits/stdc++.h>

using namespace std;



#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        /*
        need to minimize the sum, after
        */

        int limit = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;

        vector<bool> vis(limit + 1, false);

        for(ll i = 1; i <= limit; i++){
            if(vis[i] || !mp.count(i))
                continue;

            for(ll j = i + i; j <= limit; j += i){
                
                if(!mp.count(j) || vis[j])
                    continue;
            
                
                mp[i] += mp[j];
                mp.erase(j);
                vis[j] = true;
                
            }
        }

        ll ans = 0;

        for(auto &[x, y] : mp)
            ans += 1ll*x*y;

        return ans;
    }
};