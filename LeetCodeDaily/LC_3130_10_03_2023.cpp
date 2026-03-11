#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        // ystrdys O(n^2) works
        const int M = 1e9 + 7;

        ll dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));

        // base case 000... 111...
        for(int i = 0; i <= min(zero, limit); i++)
            dp[i][0][0] = 1;
        for(int j = 0; j <= min(one, limit); j++)
            dp[0][j][1] = 1;
        
        for(int i = 1; i <= zero; i++){
            for(int j = 1; j <= one; j++){
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1])%M;
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1])%M;

                if(i > limit)
                    dp[i][j][0] = ((dp[i][j][0] - dp[i - limit - 1][j][1])%M + M)%M;
                
                if(j > limit)
                    dp[i][j][1] = ((dp[i][j][1] - dp[i][j - limit - 1][0])%M + M)%M;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1])%M;
    }
};