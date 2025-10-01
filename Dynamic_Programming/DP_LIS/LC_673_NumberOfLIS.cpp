/*
Keep an additional count array to keep track of the LIS values
while updating the dp table
if dp[i] < 1 + dp[j]
inherit the count[j] = count[i] // there is only one new way to reach the current subsequence
as dp[i] is less than dp[j] + 1, just take the count for reaching the prev element
if it is equal (dp[i] = 1 + dp[j])
then add count[j] to count[i]
*/
#include <bits/stdc++.h>

using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int res = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if((nums[i] > nums[j]) && (dp[j] + 1 >= dp[i])){
                if(dp[i] < 1 + dp[j]) // inherit if greater
                    count[i] = count[j];
                else
                    count[i] += count[j]; // add if equal
                dp[i] = 1 + dp[j];
            }
            
        }
        res = max(res, dp[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == res) // return total ways to reach the max length subsequence
            ans += count[i];
    }
    return ans;
}
int main(){
    return 0;
}