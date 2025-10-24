#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k){
                int curr_sum = nums[i] + nums[j] + nums[k];
                if(curr_sum > 0){
                    k--;
                }
                else if(curr_sum < 0)
                    j++;
                else{
                    res.push_back({nums[i], nums[j], nums[k]});
                    int first = nums[j], second = nums[k];
                    while(j < k && nums[j] == first)
                        j++;
                    while(j < k && nums[k] == second)
                        k--;
                }
            }
        }
        return res;
    }
};