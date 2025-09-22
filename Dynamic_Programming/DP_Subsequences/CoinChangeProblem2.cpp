/*
Problem statement
Given an array of coins[] of size n and a target value sum, where coins[i] represent the coins of different denominations.
You have an infinite supply of each of the coins. The task is to find the minimum number
of coins required to make the given value sum.
 If it is not possible to form the sum using the given coins, return -1.
*/

#include <bits/stdc++.h>

using namespace std;

// Naive Approach ; i do the same approach except, i count how many coins are used in both
// take and not take case, then return the min of both
int countMinCoins(vector<int> &coins, int currSum, int currIdx)
{
    if (currSum == 0)
        return 0;
    if (currSum < 0 || currIdx >= coins.size())
        return INT_MAX;
    int take = INT_MAX;
    if (coins[currIdx])
    {
        take = countMinCoins(coins, currSum - coins[currIdx], currIdx);
        if (take != INT_MAX)
            take++; // keep incrementing take from the point currsum becomes 0 to the first coin
        // chosen to make it 0
    }
    int notTake = countMinCoins(coins, currSum, currIdx + 1);
    return min(notTake, take);
}
// memoized
int Memoized(vector<int> &coins, int currSum, int currIdx, vector<vector<int>> &memo)
{
    if (currSum == 0)
        return 0;
    if (currSum < 0 || currIdx >= coins.size())
        return INT_MAX;
    if (memo[currIdx][currSum] != -1)
        return memo[currIdx][currSum];
    int take = INT_MAX;
    if (coins[currIdx])
    {
        take = Memoized(coins, currSum - coins[currIdx], currIdx, memo);
        if (take != INT_MAX)
            take++;
    }
    int notTake = Memoized(coins, currSum, currIdx + 1, memo);
    return memo[currIdx][currSum] = min(take, notTake);
}
// tabulated
int tabulated(vector<int> &coins, int reqSum)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(reqSum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= reqSum; j++)
        {
            dp[i][j] = INT_MAX;
            int take = INT_MAX, notTake = INT_MAX;
            if (j >= coins[i] && dp[i][j - coins[i]] != INT_MAX)
            {
                take = dp[i][j - coins[i]] + 1;
            }
            if (i - 1 >= 0)
                notTake = dp[i - 1][j];

            dp[i][j] = min(notTake, take);
        }
    }
    return (dp[n - 1][reqSum] == INT_MAX) ? -1 : dp[n - 1][reqSum];
}
int main()
{
    vector<int> coins{25, 10, 5};
    int reqSum = 30;
    cout << countMinCoins(coins, reqSum, 0) << endl;
    vector<vector<int>> memo(coins.size() + 1, vector<int>(reqSum + 1, -1));
    cout << Memoized(coins, reqSum, 0, memo) << endl;
    cout << tabulated(coins, reqSum) << endl;
    return 0;
}