// this code TLEs, failed to do this, cannot understand the optimal solution

#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<ll>> pr(n + 1, vector<ll>(n + 2, 0));


        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                pr[i + 1][j + 2] = grid[i][j];
                pr[i + 1][j + 2] += pr[i][j + 2];
            }
        }

        /*

        im thinking prefix sum dp on this
        for each column -> decide till which row ill paint black
        then for each adjacently white column to the left
        add its prefix score?

        */

        ll INF = -1e18;
        vector<vector<vector<ll>>> dp(n + 2, vector<vector<ll>>(n + 1, vector<ll>(n + 1, INF)));


        ll ans = 0;
        dp[1][0][0] = 0;
        for(int col = 2; col < n + 2; col++){
            for(int r = 0; r <= n; r++){
                for(int prev_r = 0; prev_r <= n; prev_r++){
                    ll cmax = INF;

                    for(int prev_2r = 0; prev_2r <= n; prev_2r++){
                        ll pcw = 0;

                        if(r <= prev_r){
                            pcw += (pr[prev_r][col] - pr[r][col]);
                        }
                        else{
                            pcw += (pr[r][col - 1] - pr[prev_r][col - 1]);
                            // remove the overcnts
                            if(prev_2r > prev_r)
                                pcw -= (pr[min(prev_2r, r)][col - 1] - pr[prev_r][col - 1]);

                        }

                        cmax = max(cmax, pcw + dp[col - 1][prev_r][prev_2r]);
                    }

                    dp[col][r][prev_r] = cmax;

                    if(col == n + 1)
                        ans = max(ans, dp[col][r][prev_r]);
                }
            }
        }

        return ans;
    }
};