#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        /*
        what will be the worst case scenario
        array is completely decreasing
        10 5 1
        10

        can i make everything equal to the largest element?
        minimum sum of x values across all operations to make array non decreasing


         prefix maximums?
        / 
        */
        
        int n = nums.size();

        ll ans = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1])
                ans += (nums[i - 1] - nums[i]);
        }

        return ans;
    }
};