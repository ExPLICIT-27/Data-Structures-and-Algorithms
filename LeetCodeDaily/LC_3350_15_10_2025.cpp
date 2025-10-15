#include <bits/stdc++.h>
using namespace std;


// the current and previous count logic can be used to solve this, the max functiond describes the same

int maxIncreasingSubarrays(vector<int>& nums) {
    int n = nums.size();
    int prevc = 0, currc = 1;
    int result = 1;
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i - 1])
            currc++;
        else{
            prevc = currc;
            currc = 1;
        }
        result = max({result, currc/2, min(prevc, currc)});
    }
    return max({result, currc/2, min(prevc, currc)});
}