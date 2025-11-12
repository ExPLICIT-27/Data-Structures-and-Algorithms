#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // memoized version
    int helper(vector<pair<int, int>> &zo, int m, int n, int i, vector<vector<vector<int>>> &dp){
        if(i < 0)
            return 0;
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        if(zo[i].first <= m && zo[i].second <= n)
            return dp[i][m][n] = max(1 + helper(zo, m - zo[i].first, n - zo[i].second, i - 1, dp), helper(zo, m, n, i - 1, dp));
        return dp[i][m][n] = helper(zo, m, n, i - 1, dp);
    }
    // bottom up
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        int i = 1;
        for(auto &s : strs){
            int z = count(s.begin(), s.end(), '0');
            int o = s.size() - z;
            for(int mc = 0; mc <= m; mc++){
                for(int nc = 0; nc <= n; nc++){
                    if(z <= mc && o <= nc)
                        dp[i][mc][nc] = max(1 + dp[i - 1][mc - z][nc - o], dp[i - 1][mc][nc]);
                    else
                        dp[i][mc][nc] = dp[i - 1][mc][nc];
                }
            }
            i++;
        }
        return dp.back().back().back();
    }
};
