#include <bits/stdc++.h>

using namespace std;



int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int top = nums[0] - k;
    int result = 1;
    for(int i = 1; i < nums.size(); i++){
        int adder = top + 1 - nums[i];
        if(adder >= -k && adder <= k){
            top++;
            result++;
        }
        else{
            if(adder < 0){
                top = nums[i] - k;
                result++;
            }
        }
    }
    return result;
}