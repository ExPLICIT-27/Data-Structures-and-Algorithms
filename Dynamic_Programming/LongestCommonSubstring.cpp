/*
Find the longest common substring among 2 given strings
*/
#include <bits/stdc++.h>

using namespace std;
// O(m*n*min(n ,m))
int NaiveIter(string &s1, string &s2)
{
    int n = s1.length(), m = s2.length();

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int curr = 0;
            while ((i + curr) < n && (j + curr) < m && s1[i + curr] == s2[j + curr])
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}
// DP O(m*n) time and space
int dp1(string &s1, string &s2)
{
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;

            res = max(res, dp[i][j]);
        }
    }
    return res;
}
int main()
{
    string s1 = "Hello", s2 = "helloWorld";
    cout << NaiveIter(s1, s2) << endl;
    cout << dp1(s1, s2) << endl;
    return 0;
}