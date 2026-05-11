#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        ll asc = nums[0];

        int n = nums.size();
        int i;
        for(i = 1; i < n; i++){
            if(nums[i] > nums[i - 1])
                asc += nums[i];
            else
                break;
        }

        i--;
        ll desc = 0;
        for(; i < n; i++)
            desc += nums[i];

        return (asc > desc)? 0 : (asc == desc)? -1 : 1;
    }
};