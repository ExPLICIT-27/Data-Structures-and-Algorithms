#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i : nums){
            if(i == 1)
                cnt++;
        }
        if(cnt)
            return n - cnt;
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            for(int j = i + 1; j < n; j++){
                curr = gcd(curr, nums[j]);
                if(curr == 1)
                    res = min(res, n + j - i - 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};