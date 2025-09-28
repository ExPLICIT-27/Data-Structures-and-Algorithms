/*
just introduce an additional tries variable
*/
#include <bits/stdc++.h>

using namespace std;


// naive
int findMax(vector<int> &prices, int i, bool canBuy, int tries){
    if(tries == 2) // already sold twice
        return 0;
    if(i == prices.size())
        return 0;

    if(canBuy){ // same logic as stock2
        int buy = -prices[i] + findMax(prices, i + 1, false, tries);
        int dontbuy = findMax(prices, i + 1, true, tries);
        return max(buy, dontbuy);
    }
    int skip = findMax(prices, i + 1, false, tries);
    int sell = prices[i] + findMax(prices, i + 1, true, tries + 1);

    return max(skip, sell);
}


// memoized
int findMax(vector<int> &prices, int i, bool canBuy, int tries, vector<vector<vector<int>>> &dp){
    if(tries == 2)
        return 0;
    if(i == prices.size())
        return 0;
    if(dp[i][canBuy][tries] != -1)
        return dp[i][canBuy][tries];
    if(canBuy){
        int buy = -prices[i] + findMax(prices, i + 1, false, tries, dp);
        int dontbuy = findMax(prices, i + 1, true, tries, dp);
        return dp[i][canBuy][tries] = max(buy, dontbuy);
    }
    int skip = findMax(prices, i + 1, false, tries, dp);
    int sell = prices[i] + findMax(prices, i + 1, true, tries + 1, dp);

    return dp[i][canBuy][tries] = max(skip, sell);
}

// tabulated
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy < 2; buy++){
            for(int tries = 0; tries < 2; tries++){
                if(buy){
                    dp[i][buy][tries] = max(dp[i + 1][buy][tries], -prices[i] + dp[i + 1][1 - buy][tries]);
                }
                else
                    dp[i][buy][tries] = max(dp[i + 1][buy][tries], prices[i] + dp[i + 1][1 - buy][tries + 1]);
            }
        }
    }

    return max({dp[0][1][0], dp[0][1][1]}); // 1 cause stock must be sold, 0 or 1 cause AT MOST once it should be sold
} 

// optimized
int optimized(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy < 2; buy++){
            for(int tries = 0; tries < 2; tries++){
                if(buy){
                    curr[buy][tries] = max(prev[buy][tries], -prices[i] + prev[1 - buy][tries]);
                }
                else
                    curr[buy][tries] = max(prev[buy][tries], prices[i] + prev[1 - buy][tries + 1]);
            }
        }
        prev = curr;
    }
    return max({prev[1][0], prev[1][1]});
}
int main(){
    return 0;
}