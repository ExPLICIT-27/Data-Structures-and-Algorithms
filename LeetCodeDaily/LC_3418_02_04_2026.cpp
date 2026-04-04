#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        int dp[n][m][3];
        /*
        i cant give extra row, col and let the robot start immediately from there, 
        gives it chance to get more coins by not starting from 0, 0
        hence base case will be the first row and first col
        */
        
        // first row
        for(int j = 0; j < m; j++){
            dp[0][j][0] = coins[0][j] + ((j - 1 < 0)? 0 : dp[0][j - 1][0]);

            for(int p = 1; p < 3; p++){
                if(coins[0][j] >= 0)
                    dp[0][j][p] = coins[0][j] + ((j - 1 < 0)? 0 : dp[0][j - 1][p]);
                else
                    dp[0][j][p] = max(((j - 1 < 0)? 0 : dp[0][j - 1][p - 1]), coins[0][j] + ((j - 1 < 0)? 0 : dp[0][j - 1][p]));

            }
        }

        // first column
        for(int i = 0; i < n; i++){
            dp[i][0][0] = coins[i][0] + ((i - 1 < 0)? 0 : dp[i - 1][0][0]);

            for(int p = 1; p < 3; p++){
                if(coins[i][0] >= 0)
                    dp[i][0][p] = coins[i][0] + ((i - 1 < 0)? 0 : dp[i - 1][0][p]);
                else
                    dp[i][0][p] = max(((i - 1 < 0)? 0 : dp[i - 1][0][p - 1]), coins[i][0] + ((i - 1 < 0)? 0 : dp[i - 1][0][p]));

            }
        }

        // inside
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j][0] = coins[i][j] + max(dp[i - 1][j][0], dp[i][j - 1][0]);
                for(int p = 1; p < 3; p++){
                    if(coins[i][j] >= 0)
                        dp[i][j][p] = coins[i][j] + max(dp[i - 1][j][p], dp[i][j - 1][p]);
                    else
                        dp[i][j][p] = max(dp[i - 1][j][p - 1], max(dp[i][j - 1][p - 1], coins[i][j] + max(dp[i - 1][j][p], dp[i][j - 1][p])));
                }
            }
        }

        return max(dp[n - 1][m - 1][0], max(dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]));
        

    }
};