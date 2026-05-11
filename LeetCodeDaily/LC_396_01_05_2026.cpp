#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        /*
        0 1 2 3
        1 2 3 0
        2 3 0 1
        3 0 1 2
        */

        int first = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            first += i*nums[i];
            total += nums[i];
        }
        
        int ans = first;
        for(int i = 0; i < n - 1; i++){
            int tin = n - i - 1;
            first = first + total - n*nums[tin];
            ans = max(ans, first);
        }

        return ans;
    }
};