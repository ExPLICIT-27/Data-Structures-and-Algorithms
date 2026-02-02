#include <bits/stdc++.h>

using namespace std;

#define ll long long


class Solution {
public:
    void adjust(multiset<ll> &S1, multiset<ll> &S2, int k, ll &csum){
        
        while(S1.size() > k){
            auto it = prev(S1.end());
            S2.insert(*it); 
            csum -= *it;
            S1.erase(it);
        }

        while(S1.size() < k && !S2.empty()){
            auto it = S2.begin();
            S1.insert(*it);
            csum += *it;
            S2.erase(it);
        }
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<ll> S1, S2;
        int n = nums.size();
        ll ans = LLONG_MAX;
        ll curr = 0;

        // first window 
        for(int i = 1; i <= dist + 1 && i < n; i++){
            if(S1.empty() || *prev(S1.end()) >= nums[i]){
                S1.insert(nums[i]);
                curr += nums[i];
            }
            else
                S2.insert(nums[i]);
            
            adjust(S1, S2, k - 1, curr);
        }
        ans = min(ans, curr + nums[0]);

        for(int i = dist + 2; i < n; i++){
            if(S1.find(nums[i - dist - 1]) != S1.end()){
                S1.erase(S1.find(nums[i - dist - 1]));
                curr -= nums[i - dist - 1];
            }
            else{
                S2.erase(S2.find(nums[i - dist - 1]));
            }

            if(S1.empty() || *prev(S1.end()) >= nums[i]){
                S1.insert(nums[i]);
                curr += nums[i];
            }
            else
                S2.insert(nums[i]);
            
            adjust(S1, S2, k - 1, curr);

            ans = min(ans, curr + nums[0]);
        }

        return ans;
    }
};