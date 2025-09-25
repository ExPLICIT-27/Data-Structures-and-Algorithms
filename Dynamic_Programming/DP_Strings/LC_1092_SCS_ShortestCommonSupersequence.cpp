/*
SCS = string1 + string2 - LCS
ordering is what matters now
You need to use the dp table to solve this
key is picking the lcs characters only once, and picking the others in order
*/
#include <bits/stdc++.h>

using namespace std;

string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.length(), m = s2.length();

    // find the lcs
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    string result = "";
    while(i > 0 && j > 0){
        // take the lcs characters only once
        if(s1[i - 1] == s2[j - 1]){
            result += s2[j - 1];
            i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){ // take the element not part of the sequence in the right time and move on
            result += s1[i - 1];
            i--;
        }
        else{
            result += s2[j - 1];
            j--;
        }
    }
    // exhaust remaining characters in both the strings that are not part of the lcs
    while(i > 0){
        result += s1[i - 1];
        i--;
    }
    while(j > 0){
        result += s2[j - 1];
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
    }
int main(){
    return 0;
}