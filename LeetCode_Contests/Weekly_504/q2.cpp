#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        /*
        sum(chosen prices) = budget
        i can do O(n^2)
        i just need to buy as many copies as possible

        pre compute how many items i will get if i buy the ith item
        */

        int n = items.size();
        vector<int> extras(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                if(items[j][0]%items[i][0] == 0)
                    extras[i]++;
            }
        }

        function<int(int, int, bool)> F;

        int dp[n][budget + 1][2];

        memset(dp, -1, sizeof(dp));
        
        F = [&](int i, int rem, bool same) -> int {
            if(i == n)
                return 0;

            if(dp[i][rem][same] != -1)
                return dp[i][rem][same];
            
            // choose to buy or not to buy
            if(items[i][1] > rem)
                return dp[i][rem][same] = F(i + 1, rem, true);

            int buy = 1 + same*extras[i] + F(i, rem - items[i][1], false);
            int notBuy = F(i + 1, rem, true);

            return dp[i][rem][same] = max(buy, notBuy);
        };

        return F(0, budget, true);
    }
};