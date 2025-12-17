#include <bits/stdc++.h>
using namespace std;

// top down
#define ll long long
class TopDown {
public:
    ll helper(vector<int> &prices, int i, int k, int type, vector<vector<vector<ll>>> &dp){
        if(k == 0)
            return 0;
        if(i == prices.size()){
            if(type == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][k][type] != -1)
            return dp[i][k][type];
        ll ans = 0;
        if(type == 0){// can skip, short or long
            ans = max({prices[i] + helper(prices, i + 1, k, 1, dp), -prices[i] + helper(prices, i + 1, k, 2, dp), helper(prices, i + 1, k, 0, dp)});
        }
        else if(type == 1){// skip, buy
            ans = max(-prices[i] + helper(prices, i + 1, k - 1, 0, dp), helper(prices, i + 1, k, 1, dp));
        }
        else{
            ans = max(prices[i] + helper(prices, i + 1, k - 1, 0, dp), helper(prices, i + 1, k, 2, dp));
        }
        return dp[i][k][type] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k + 1, vector<ll>(3, -1)));
        return helper(prices, 0, k, 0, dp);
    }
};
#define ll long long

class BottomUp {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n = prices.size();
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(K + 1, vector<ll>(3, 0)));
        for(int k = 0; k <= K; k++){
            dp[0][k][1] = INT_MIN;// cant gain profit from thin air without buying
        }
        for(int i = 1; i <= n; i++){
            for(int k = K; k >= 1; k--){
                dp[i][k][0] = max({prices[i - 1] + dp[i - 1][k][1], -prices[i - 1] + dp[i - 1][k][2], dp[i - 1][k][0]});
                dp[i][k][1] = max(-prices[i - 1] + dp[i - 1][k - 1][0], dp[i - 1][k][1]);
                dp[i][k][2] = max(prices[i - 1] + dp[i - 1][k - 1][0], dp[i - 1][k][2]);
            }
        }
        ll maxprofit = 0;
        for(int i = 1; i <= K; i++){
            maxprofit = max(maxprofit, dp[n][i][0]);
        }
        return maxprofit;
    }
};