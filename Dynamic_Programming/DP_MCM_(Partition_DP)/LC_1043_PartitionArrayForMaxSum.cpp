/*
Bottom up was more intuitive, went ahead with that directly
*/
#include <bits/stdc++.h>

using namespace std;


int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++){
        int maxval = arr[i];
        dp[i] = maxval;
        // main logic
        for(int p = 0; (p < k) && (i - p) >= 0; p++){
            maxval = max(maxval, arr[i - p]);
            if(i - p - 1 >= 0)
                dp[i] = max(dp[i], maxval*(p + 1) + dp[i - p - 1]);
            else
                dp[i] = max(dp[i], maxval*(p + 1));
        }
    }
    return dp[n - 1];
}
int main(){
    return 0;
}