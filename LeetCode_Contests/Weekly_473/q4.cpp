
/*
this logic works only cause the array is sorted
- count along with duplicates using the same logic as subarray sum div k
- then for discounting the duplicates
    - make a freq map
    - in an any segment of elements [a,a,a,....a], number of segments of size k
    = len(segment) - k + 1
    eg: in [a,a,a,a,a], no. of size 2 arrs = 5 - 2 + 1 = 4
    hence iterate over the freq, the segment is divisible by k, then subtract len(segment) - k (just keep 1)

*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        // 1 2 3 

        unordered_map<int, int> mp = {{0,1}}, freq;
        long long res = 0;
        int curr = 0;


        // normal logic
        for(int i : nums){
            freq[i]++;
            curr = (curr + i)%k;
            
            if(mp.count(curr))
                res += mp[curr];
            mp[curr]++;
        }

        for(auto &pair : freq){
            for(int i = 1; i <= pair.second; i++){

                // only keep 1, remove others
                if(1ll*i*pair.first%k == 0)
                    res -= (pair.second - i);
            }
        }
        return res;

    }
};