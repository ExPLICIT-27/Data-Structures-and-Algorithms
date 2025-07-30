#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Given 2 strings, return the length of the longest common subsequence,
Eg str1 = "abatd"
str2 = "bacd"
result = 3 ("bad")

*/
/*
    Naive Brute Force (O(2^(m*n))) (top down)
    Pass the strings and their lengths, 
    check if str[idx1] == str2[idx2]
    if so, return 1 + func(str1, str2, idx1-1, idx2-1)
    else, return max(func(str1, str2, idx1, idx2-1), func(str1, str2, idx-1, idx2))
*/

int NaiveBruteForce(string &str1, string &str2, int idx1, int idx2){
    if(idx1 < 0 || idx2 < 0) return 0;
    
    if(str1[idx1] == str2[idx2]){
        return 1 + NaiveBruteForce(str1, str2, idx1-1, idx2-1);
    }
    return max(NaiveBruteForce(str1, str2, idx1-1, idx2), NaiveBruteForce(str1, str2, idx1, idx2-1));
}
/*
memoized approach, use a memo table m*n
*/
int Memoized(string &str1, string &str2, int idx1, int idx2, vector<vector<int>> &memo){
    if(idx1 < 0 || idx2 < 0) return 0;
    if(memo[idx1][idx2] != -1) return memo[idx1][idx2];

    int res;
    if(str1[idx1] == str2[idx2]){
        res = 1 + Memoized(str1, str2, idx1-1, idx2-1, memo);
    }
    else{
        res = max(Memoized(str1, str2, idx1, idx2 - 1, memo), Memoized(str1, str2, idx1 - 1, idx2, memo));
    }
    memo[idx1][idx2] = res;
    return res;
}
/*
 Tabulated bottom up Dynamic programming approach, 
 instead of recursive memo, iterative bottom up dp table
 Along with the calculation of the length of the longest common substring,
 printing it as well.
*/
int TabulatedDp(string &str1, string &str2){
    int m = str1.length(), n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
string PrintLCS(string &str1, string &str2){
    int n = str1.length(), m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    string res = "";
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            res += str1[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    string str1 = "abatd", str2 = "bacd";
    cout << NaiveBruteForce(str1, str2, str1.length()-1, str2.length()-1) << endl;
    vector<vector<int>> memo(str1.length(), vector<int>(str2.length(), -1));
    cout << Memoized(str1, str2, str1.length()-1, str2.length()-1, memo) << endl;
    cout << TabulatedDp(str1, str2) << endl;
    cout << PrintLCS(str1, str2);
    return 0;
}