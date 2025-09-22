/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

#include <bits/stdc++.h>

using namespace std;

// naive
int minCoins(vector<int> &coins, int amount, int i){
    if(i == 0){
        if(amount == 0)
            return 0;
        if(amount == coins[0])
            return 1;
        if(amount%coins[0] == 0) // important case, since you have infinite supplies of each coin
            return amount/coins[0];
        return INT_MAX;
    }
    if(amount < 0)
        return INT_MAX;
   
    int take = minCoins(coins, amount - coins[i], i);
    int notTake = minCoins(coins, amount, i - 1);
    if(take != INT_MAX)
        take++;
    return min(take, notTake);

}
// memoized
int minCoins(vector<int> &coins, int amount, int i, vector<vector<int>> &dp){
    if(i == 0){
        if(amount == 0)
            return 0;
        if(amount == coins[0])
            return 1;
        if(amount%coins[0] == 0)
            return amount/coins[0];
        return INT_MAX;
    }
    if(amount < 0)
        return INT_MAX;
    if(dp[i][amount] != -1)
        return dp[i][amount];
    int take = minCoins(coins, amount - coins[i], i, dp);
    int notTake = minCoins(coins, amount, i - 1, dp);
    if(take != INT_MAX)
        take++;
    return dp[i][amount] = min(take, notTake);

}

// tabulated
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    if(amount == 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
    for(int amt = 0; amt <= amount; amt++){
        if(amt%coins[0] == 0)
            dp[0][amt] = amt/coins[0];
    }

    for(int i = 0; i < n; i++){
        for(int amt = 0; amt <= amount; amt++){
            if(i - 1 >= 0)
                dp[i][amt] = dp[i - 1][amt];
            if(amt - coins[i] >= 0 && dp[i][amt - coins[i]] != INT_MAX)
                dp[i][amt] = min(dp[i][amt], 1 + dp[i][amt - coins[i]]);
        }
    }

    return dp[n - 1][amount] == INT_MAX? -1 : dp[n - 1][amount];
}
int main(){
    return 0;
}