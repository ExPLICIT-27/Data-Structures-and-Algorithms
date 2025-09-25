/*
logic:
if any character of s matches with t, you can either choose to include it, or not, thereby consider both possibilities
otherwise try to find a match for t in s
*/
#include <bits/stdc++.h>

using namespace std;

// naive
int count(string &s, string &t, int i, int j){
    if(j == 0) // matched t
        return 1;
    if(i == 0) // out of bounds of s
        return 0;
    if(s[i - 1] == t[j - 1]){
        // decide to take, or not to take
        return count(s, t, i - 1, j - 1) + count(s, t, i - 1, j);
    }
    return count(s, t, i - 1, j);
    
}

// memoized
int count(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    if(j == 0) // matched t
        return 1;
    if(i == 0) // out of bounds of s
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i - 1] == t[j - 1]){
        // decide to take, or not to take
        return dp[i][j] = count(s, t, i - 1, j - 1, dp) + count(s, t, i - 1, j, dp);
    }
    return dp[i][j] = count(s, t, i - 1, j, dp);
    
}

// tabulated
int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

// space optimized
int optimized(string s, string t) {
    int n = s.length(), m = t.length();
    vector<unsigned long long> prev(m + 1, 0);
    vector<unsigned long long> curr(m + 1, 0);
    prev[0] = 1;
    for(int i = 1; i <= n; i++){
        curr[0] = prev[0];
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1] + prev[j];
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[m];
}

int main(){
    return 0;
}