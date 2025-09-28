/*
variant of 3, instead of 2, its k
*/
#include <bits/stdc++.h>

using namespace std;


// memoized
int f(vector<int> &p, int i, bool canBuy, int k, vector<vector<vector<int>>> &dp){
    if(k == 0)
        return 0;
    if(i == p.size())
        return 0;
    if(dp[i][k][canBuy] != -1)
        return dp[i][k][canBuy];
    if(canBuy){
        int buy = -p[i] + f(p, i + 1, !canBuy, k, dp);
        int notBuy = f(p, i + 1, canBuy, k, dp);

        return dp[i][k][canBuy] = max(buy, notBuy);
    }
    int skip = f(p, i + 1, canBuy, k, dp);
    int sell = p[i] + f(p, i + 1, !canBuy, k - 1, dp);
    return dp[i][k][canBuy] = max(skip, sell);
}

// tabulated
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    for(int i = n - 1; i >= 0; i--){
        for(int j = k - 1;  j >= 0; j--){
            dp[i][j][0] = max(prices[i] + dp[i + 1][j + 1][1], dp[i + 1][j][0]);
            dp[i][j][1] = max(-prices[i] + dp[i + 1][j][0], dp[i + 1][j][1]);
        }
    }
    return dp[0][0][1];
    
}

// optimized
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    vector<vector<int>> prev(k + 1, vector<int>(2, 0)), curr(k + 1, vector<int>(2, 0));
    for(int i = n - 1; i >= 0; i--){
        for(int j = k - 1;  j >= 0; j--){
            curr[j][0] = max(prices[i] + prev[j + 1][1], prev[j][0]);
            curr[j][1] = max(-prices[i] + prev[j][0], prev[j][1]);
        }
        prev = curr;
    }
    return prev[0][1];
    
}
int main(){
    return 0;
}