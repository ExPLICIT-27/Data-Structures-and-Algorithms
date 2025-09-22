/*
utilizing the bottom up code from lcs
we only need to update the dp table if there is a match
return the maximum value in the dp table
*/
#include <bits/stdc++.h>

using namespace std;

int lcsub(string &s1, string &s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int result = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            result = max(result, dp[i][j]);
        }
    }
    return result;
}
int main(){
    return 0;
}