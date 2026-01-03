#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int encode(vector<int> &R){
        int mask = 0;
        for(int i = 0;i < 3; i++){
            mask = mask*3 + ((R[i] == -1)? 0 : R[i]);
        }
        return mask;
    }
    int helper(int r, int c, vector<int> &pRow, vector<int> &cRow, vector<vector<vector<vector<int>>>> &dp){
        if(r == 0)
            return 1;
        if(c < 0){
            vector<int> T(3, -1);
            return helper(r - 1, 2, cRow, T, dp)%MOD;
        }
        int ans = 0;
        int pe = encode(pRow);
        int ce = encode(cRow);

        if(dp[r][c][pe][ce] != -1)
            return dp[r][c][pe][ce];
        for(int i = 0; i < 3; i++){
            if((c == 2 || cRow[c + 1] != i) && pRow[c] != i){
                cRow[c] = i;
                ans = (ans + helper(r, c - 1, pRow, cRow, dp))%MOD;
                cRow[c] = -1;
            }
        }
        return dp[r][c][pe][ce] = ans%MOD;
    }
   
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(3, vector<vector<int>>(27, vector<int>(27, -1))));
        vector<int> pr(3, -1), cr(3, -1);
        return helper(n, 2, pr, cr, dp);
    }
};