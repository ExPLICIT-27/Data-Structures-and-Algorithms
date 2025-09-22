/*
the method written here is unique to this problem
this can also be solved by subtracting the length of longest palindromic subsequence from the length of the string
(we need to create more to match characters not part of the longest palindromic subsequence)
*/

#include <bits/stdc++.h>

using namespace std;

// memoized
int minIns(string &s, int i, int j, vector<vector<int>> &dp){
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == s[j])
        return dp[i][j] = minIns(s, i + 1, j - 1, dp);
    return dp[i][j] = 1 + min(minIns(s, i, j - 1, dp), minIns(s, i + 1, j, dp));
}
int main(){
    return 0;
}