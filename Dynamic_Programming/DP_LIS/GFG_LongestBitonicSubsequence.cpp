/*
Calculate LIS from the front and back and add their values at each index to find the length of the longest
bitonic subsequence
*/

#include <bits/stdc++.h>

using namespace std;

int LongestBitonicSequence(int n, vector<int> &nums) {
    // code here
    vector<int> dpfront(n, 1), dpback(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])
                dpfront[i] = max(dpfront[i], 1 + dpfront[j]);
        }
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(nums[i] > nums[j])
                dpback[i] = max(dpback[i],  1 + dpback[j]);
        }
    }
    for(int i = 1; i < n; i++){
        dpfront[i] = max(dpfront[i - 1], dpfront[i]);
        dpback[n - i - 1] = max(dpback[n - i - 1], dpback[n - i]);
    }
    if(dpfront.back() == 1 || dpback[0] == 1)
        return 0;
    int res = 0;
    for(int i = 1; i < n - 1; i++){
        if(dpfront[i] != 1 && dpback[i] != 1) // it is specified that the length of the LIS from the front and back must be greater than 1
            res = max(res, dpfront[i] + dpback[i] - 1);
    }
    return res;
}
int main(){
    return 0;
}