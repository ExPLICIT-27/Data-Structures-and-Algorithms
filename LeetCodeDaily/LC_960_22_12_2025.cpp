#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // LIS, but 2D instead of 1D
        int n = strs.size(), m = strs[0].size();
        vector<int> dp(m, 1);
        int ans = m - 1;
        for(int i = 1; i < m; i++){
            for(int j = 0; j < i; j++){
                bool ok = true;
                for(int k = 0; k < n; k++){
                    if(strs[k][i] < strs[k][j]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = min(ans, m - dp[i]);
                }
            }
        }
        return ans;
    }
};