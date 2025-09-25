/*
choices you have:
- insert a character
- delete a character
- replace a character

you perform those actions only if the elements are not matching
so for any i, j where s1[i] equals s2[j] you dont perform any operations and just move ahead
otherwise you return 1 + min of all those operations 
insertion - staying at i(you inserted before i virtually so you are still at i), moving j as it matched with i
deletion - move i, keep j (did not match anything)
replace - move i and j
*/

#include <bits/stdc++.h>

using namespace std;

// naive
int naive(string &s1, string &s2, int i, int j){
    if(j == 0)
        return i;
    if(i == 0)
        return j;

    if(s1[i - 1] == s2[j - 1])
        return naive(s1, s2, i - 1, j - 1);
    return 1 + min({naive(s1, s2, i - 1, j - 1), naive(s1, s2, i, j - 1), naive(s1, s2, i - 1, j)});
}

// memoized
int memoized(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    if(j == 0)
        return i;
    if(i == 0)
        return j;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s1[i - 1] == s2[j - 1])
        return memoized(s1, s2, i - 1, j - 1, dp);
    return dp[i][j] = 1 + min({memoized(s1, s2, i - 1, j - 1, dp), memoized(s1, s2, i, j - 1, dp), memoized(s1, s2, i - 1, j, dp)});
}

// tabulated
int tabulated(string s1, string s2) {
    int n = s1.length(),  m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i <= n; i++)
        dp[i][0] = i;
    for(int j = 0; j <= m; j++)
        dp[0][j] = j;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else{
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }
    return dp[n][m];
}

// optimIzed
int minDistance(string s1, string s2) {
    int n = s1.length(),  m = s2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for(int j = 0; j <= m; j++)
        prev[j] = j;
    
    for(int i = 1; i <= n; i++){
        curr[0] = i;
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1];
            else{
                curr[j] = 1 + min({prev[j - 1], curr[j - 1], prev[j]});
            }
        }
        prev = curr;
    }
    return prev[m];
}
int main(){
    return 0;
}