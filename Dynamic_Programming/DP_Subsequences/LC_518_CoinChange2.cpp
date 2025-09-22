/*
count ways instead of minimum coins to make
*/


#include <bits/stdc++.h>

using namespace std;

// memoized
int count(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp){
    if(idx == 0){
        if(amount == 0 || amount%coins[idx] == 0)
            return 1;
        return 0;
    }
    if(amount < 0)
        return 0;
    if(dp[idx][amount] != -1)
        return dp[idx][amount];
    return dp[idx][amount] = count(coins, amount - coins[idx], idx, dp) + count(coins, amount, idx - 1, dp);
}

//tabulated
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));
    for(int amt = 0; amt <= amount; amt++){
        if(amt%coins[0] == 0)
            dp[0][amt] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= amount; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= coins[i])
                dp[i][j] += dp[i][j - coins[i]];
        }
    }
    return dp[n - 1][amount];
}
// optimized
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<unsigned long long> prev(amount + 1, 0);
    for(int amt = 0; amt <= amount; amt++){
        if(amt%coins[0] == 0)
            prev[amt] = 1;
    }
    vector<unsigned long long> curr(amount + 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= amount; j++){
            curr[j] = prev[j];
            if(j >= coins[i])
                curr[j] += curr[j - coins[i]];
        }
        prev = curr;
    }
    return prev[amount];
}
int main(){
    return 0;
}