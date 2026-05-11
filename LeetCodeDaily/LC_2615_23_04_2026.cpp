#include <bits/stdc++.h>

using namespace std;



#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        int n = nums.size();
        vector<ll> ans(n);

        unordered_map<int, ll> cntfr, sumfr, cntbk, sumbk;

        for(int i = 0; i < n; i++){
            
            int j = n - i - 1;
            ans[i] += (cntfr[nums[i]]*i - sumfr[nums[i]]);
            ans[j] += (sumbk[nums[j]] - cntbk[nums[j]]*j);

            cntfr[nums[i]]++;
            sumfr[nums[i]] += i;
            cntbk[nums[j]]++;
            sumbk[nums[j]] += j;
        }
        return ans;
    }
};