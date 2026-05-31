#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        /*
        brute force?
        O(n^3)

        30
        */

        int ans = INT_MAX;
        int n = nums.size();
        for(int x = 0; x < k; x++){
            for(int y = 0; y < k; y++){

                if(x == y)
                    continue;
                int curr = 0;

                for(int i = 0; i < n; i++){
                    if(i & 1)
                        curr += min(((nums[i]%k - y)%k + k)%k, ((y - nums[i]%k)%k + k)%k);
                    else
                        curr += min(((nums[i]%k - x)%k + k)%k, ((x - nums[i]%k)%k + k)%k);
                }
                
                ans = min(ans, curr);
            }
        }

        return ans;
    }
}; 

/*
(a - x)%k = y
a%k - y = x%k
*/