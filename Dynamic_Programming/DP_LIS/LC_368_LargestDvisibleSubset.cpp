/*
just perform longest increasing subsequence with the given condition
*/

#include <bits/stdc++.h>

using namespace std;


vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    vector<int> parents(n, -1);
    int lidx = 0, maxlen = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if((nums[i]%nums[j] == 0) && (dp[j] + 1 > dp[i])){
                dp[i] = 1 + dp[j];
                parents[i] = j;
            }
        }
        if(dp[i] > maxlen){
            maxlen = dp[i];
            lidx = i;
        }
    }
    vector<int> res;
    for(int i = lidx; i != -1; i = parents[i])
        res.push_back(nums[i]);
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    return 0;
}