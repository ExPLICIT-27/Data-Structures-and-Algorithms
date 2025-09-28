/*
if i can buy, choose to buy or not buy
*/
#include <bits/stdc++.h>

using namespace std;

// naive
int findMax(vector<int> &prices, int i, bool canBuy){
    if(i == prices.size())
        return 0;
    if(canBuy){
        int buy = -prices[i] + findMax(prices, i + 1, false);
        int skip = findMax(prices, i + 1, true);
        return max(buy, skip);
    }
    int skip = findMax(prices, i + 1, false);
    int sell = prices[i] + findMax(prices, i + 1, true);
    return max(skip, sell);
}

// memoized
int findMax(vector<int> &prices, int i, bool canBuy, vector<vector<int>> &dp){
    if(i == prices.size())
        return 0;
    if(dp[i][canBuy] != -1)
        return dp[i][canBuy];
    if(canBuy){
        int buy = -prices[i] + findMax(prices, i + 1, false, dp);
        int skip = findMax(prices, i + 1, true, dp);
        return dp[i][canBuy] = max(buy, skip);
    }
    int skip = findMax(prices, i + 1, false, dp);
    int sell = prices[i] + findMax(prices, i + 1, true, dp);
    return dp[i][canBuy] = max(skip, sell);
}

// tabulated
int tabulated(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // only 0 or 1 for canBuy

    for(int i = n - 1; i >= 0; i--){
        dp[i][1] = max(dp[i + 1][1], -prices[i] + dp[i + 1][0]);
        dp[i][0] = max(dp[i + 1][0], prices[i] + dp[i + 1][1]);
    }
    return dp[0][1]; // stock must be sold by the end
}
// optimized
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // only 0 or 1 for canBuy
    int buy = 0, sell = 0;
    for(int i = n - 1; i >= 0; i--){
        int nbuy = max(buy, -prices[i] + sell);
        int nsell = max(sell, prices[i] + buy);
        buy = nbuy, sell = nsell;
    }
    return buy; // stock must be sold by the end
}
// best expected solution, buy it if its value is less than buy, otherwise keep waiting and sell it just before the prices starts falling
int maxProfit(vector<int>& prices) {
    
    int buy = prices[0];
    int result = 0;
    int i = 1;
    int n = prices.size();
    while(i < n){
        if(prices[i] > buy){
            while(i < n && prices[i] > prices[i - 1]) // wait for price to fall
                i++;
            result += prices[i - 1] - buy;
            buy = (i == n)? 0 : prices[i++];
        }
        else
            buy = prices[i++];
    }
    return result;
}

int main(){
    return 0;
}