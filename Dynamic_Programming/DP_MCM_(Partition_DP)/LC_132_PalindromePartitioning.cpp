/*

*/

#include <bits/stdc++.h>

using namespace std;

int minCut(string s){
    int n = s.length();

    // precomputing palindrome indices
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1]))
                isPalindrome[i][j] = true;
        }
    }

    //dp table to store the result
    vector<int> dp(n);
    for(int i = 0; i < n; i++){
        if(isPalindrome[0][i])
            dp[i] = 0;
        else{
            dp[i] = 1;
            for(int j = 1; j <= i; j++){
                if(isPalindrome[j][i])
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n - 1];
}
int main(){
    return 0;
}