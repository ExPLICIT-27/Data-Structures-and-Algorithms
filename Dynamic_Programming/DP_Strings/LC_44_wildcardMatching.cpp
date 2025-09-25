/*
if it is a match or if it is a question mark, you consider i to match with j and move back
if it is a '*' consider matching it and consider skipping over it
if it doesnt satisfy any of the above conditions it is false
*/
#include <bits/stdc++.h>

using namespace std;


//naive
bool naive(string &s, string &p, int i, int j){
    if(i == 0 && j == 0)
        return true;
    if(j == 0)
        return false;
    if(i == 0){
        for(int k = 0; k < j; k++){
            if(p[k] != '*') return false;
        }
        return true;
    }
    
    if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
        return naive(s, p, i - 1, j - 1);
    if(p[j - 1] == '*')
        return naive(s, p, i - 1, j) || naive(s, p, i, j - 1);
    return false;
}

// memoized
bool memoized(string &s, string &p, int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0)
        return true;
    if(j == 0)
        return false;
    if(i == 0){
        for(int k = 0; k < j; k++){
            if(p[k] != '*') return dp[i][j] = false;
        }
        return dp[i][j] = true;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
        return dp[i][j] = memoized(s, p, i - 1, j - 1, dp);
    if(p[j - 1] == '*')
        return dp[i][j] = memoized(s, p, i - 1, j, dp) || memoized(s, p, i, j - 1, dp);
    return dp[i][j] = false;
}

// tabulated
bool tabulated(string s, string p) {
    
    int n = s.length(), m = p.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        dp[i][0] = false;
    }
    for(int j = 1; j <= m && p[j - 1] == '*'; j++)
        dp[0][j] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// optimized
bool optimized(string s, string p) {
    
    int n = s.length(), m = p.length();
    vector<bool> prev(m + 1, false), curr(m + 1, false);
    prev[0] = true;
    for(int j = 1; j <= m && p[j - 1] == '*'; j++)
        prev[j] = true;
    for(int i = 1; i <= n; i++){
        curr[0] = false;
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                curr[j] = prev[j - 1];
            else if(p[j - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}
int main(){
    return 0;
}