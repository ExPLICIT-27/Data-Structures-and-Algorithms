/*
Problem Statement
Given an integer array of coins[] of size n representing different types of denominations and an integer sum,
the task is to count all combinations of coins to make a given value sum.
Note: Assume that you have an infinite supply of each type of coin.
*/
#include <bits/stdc++.h>

using namespace std;
// Naive recursive
int countCoins(vector<int> &denominations, int currSum, int currIdx)
{
    if (currSum == 0)
        return 1;
    if (currSum < 0 || currIdx < 0)
        return 0;

    return countCoins(denominations, currSum - denominations[currIdx], currIdx) + countCoins(denominations, currSum, currIdx - 1);
}
// memoized approach
int memoized(vector<int> &denominations, int currSum, int currIdx, vector<vector<int>> &memo)
{
    if (currSum == 0)
        return 1;
    if (currSum < 0 || currIdx < 0)
        return 0;
    if (memo[currIdx][currSum] != -1)
        return memo[currIdx][currSum];
    return memo[currIdx][currSum] = memoized(denominations, currSum - denominations[currIdx], currIdx, memo) + memoized(denominations, currSum, currIdx - 1, memo);
}
// tabulated approach
int tabulated(vector<int> &denominations, int reqSum)
{
    int n = denominations.size();
    vector<vector<int>> dp(n + 1, vector<int>(reqSum + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= reqSum; j++)
        {
            dp[i][j] += dp[i - 1][j];
            if (j >= denominations[i - 1])
            {
                dp[i][j] += dp[i][j - denominations[i - 1]];
            }
        }
    }
    return dp[n][reqSum];
}
int main()
{
    vector<int> coins{1, 2, 5};
    int sumreq = 11;
    cout << countCoins(coins, sumreq, coins.size() - 1) << endl;
    vector<vector<int>> memo(coins.size(), vector<int>(sumreq + 1, -1));
    cout << memoized(coins, sumreq, coins.size() - 1, memo) << endl;
    cout << tabulated(coins, 11) << endl;
    return 0;
}