#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // top down helper func
    int LCS(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        
        if(i < 0){
            int sm = 0;
            for(int k = j; k >= 0; k--)
                sm += int(s2[k]);
            return sm;
        }

        if(j < 0){
            int sm = 0;
            for(int k = i; k >= 0; k--)
                sm += int(s1[k]);
            return sm;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = LCS(s1, s2, i - 1, j - 1, dp);
        
        return dp[i][j] = min(int(s1[i]) + LCS(s1, s2, i - 1, j, dp), int(s2[j]) + LCS(s1, s2, i, j - 1, dp));
    }
    // bottom up approach
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][1] = int(s2[0]);
        for(int j = 2; j <= m; j++){
            dp[0][j] = int(s2[j - 1]) + dp[0][j - 1];
        }

        dp[1][0] = int(s1[0]);
        for(int i = 2; i <= n; i++){
            dp[i][0] = int(s1[i - 1]) + dp[i - 1][0];
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(int(s1[i - 1]) + dp[i - 1][j], int(s2[j - 1]) + dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};