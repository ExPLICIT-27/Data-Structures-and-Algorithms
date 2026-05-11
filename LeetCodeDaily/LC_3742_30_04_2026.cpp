#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, INT_MIN)));

        dp[0][1][0] = dp[1][0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int c = 0; c <= k; c++){
                    int nc = (grid[i - 1][j - 1])? c - 1 : c;
                    if(nc < 0)
                        continue;
                    
                    dp[i][j][c] = grid[i - 1][j - 1] + max(dp[i - 1][j][nc], dp[i][j - 1][nc]);
                    
                    
                }
            }
        }

        int ans = INT_MIN;

        for(int c = 0; c <= k; c++)
            ans = max(ans, dp[n][m][c]);
        
        return ans < 0 ? -1 : ans;
    }

    
};