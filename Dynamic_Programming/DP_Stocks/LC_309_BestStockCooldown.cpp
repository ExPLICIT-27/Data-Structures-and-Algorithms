/*
only difference is moving 2 indices forward rather than 1 after selling
*/

#include <bits/stdc++.h>

using namespace std;

// memoized
int findMax(vector<int> &prices, int i, bool canBuy, vector<vector<int>> &dp){
    if(i >= prices.size())
        return 0;
    if(dp[i][canBuy] != -1)
        return dp[i][canBuy];
    if(canBuy){
        int buy = -prices[i] + findMax(prices, i + 1, !canBuy, dp);
        int skip = findMax(prices, i + 1, canBuy, dp);
        return dp[i][canBuy] = max(buy, skip);
    }
    int skip = findMax(prices, i + 1, canBuy, dp);
    int sell = prices[i] + findMax(prices, i + 2, !canBuy, dp);

    return dp[i][canBuy] = max(skip, sell);
}

// tabulated
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for(int i = n - 1; i >= 0; i--){
        dp[i][0] = max(dp[i + 1][0], prices[i] + dp[i + 2][1]);
        dp[i][1] = max(dp[i + 1][1], -prices[i] + dp[i + 1][0]);
    }
    return dp[0][1];
}

// optimized
 int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> f1 = {0, 0}, f2 = {0, 0}, s = {0, 0};
    for(int i = n - 1; i >= 0; i--){
        s[0] = max(f1[0], prices[i] + f2[1]);
        s[1] = max(f1[1], -prices[i] + f1[0]);
        f2 = f1, f1 = s;
    }
    return s[1];
}
int main(){
    return 0;
}