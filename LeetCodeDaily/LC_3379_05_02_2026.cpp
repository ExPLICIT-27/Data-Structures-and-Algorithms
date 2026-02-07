#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> R(n);

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                R[i] = nums[i];
            }
            else if(nums[i] > 0){
                R[i] = nums[(i + nums[i])%n];
            }
            else{
                R[i] = nums[((i + nums[i])%n + n)%n];
            }
        }

        return R;
    }
};