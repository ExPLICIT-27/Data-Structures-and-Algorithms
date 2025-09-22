/*
Given an array arr[] of non-negative integers and a value sum,
the task is to check if there is a subset of the given array whose sum is equal to the given sum.
*/
#include <bits/stdc++.h>
// Naive recursive approach (take, not take algorithm)

using namespace std;
bool subsetSum(vector<int> &arr, int currIdx, int currSum, int reqSum)
{
    if (currSum == reqSum)
        return true;
    if (currIdx >= arr.size() || currSum > reqSum)
        return false;
    return subsetSum(arr, currIdx + 1, currSum + arr[currIdx], reqSum) || subsetSum(arr, currIdx + 1, currSum, reqSum);
}
// Memoized, just use a memo table
bool memoized(vector<int> &arr, int currIdx, int currSum, int reqSum, unordered_map<string, bool> &memo)
{
    if (currSum == reqSum)
        return true;
    if (currSum > reqSum || currIdx >= arr.size())
        return false;
    string key = to_string(currIdx) + "," + to_string(currSum);
    if (memo.find(key) != memo.end())
        return memo[key];
    return memo[key] = memoized(arr, currIdx + 1, currSum + arr[currIdx], reqSum, memo) || memoized(arr, currIdx + 1, currSum, reqSum, memo);
}
// a dp table in which dp[i][j] represents whether it is possible to make a sum of
// j with the first i elements of the array
bool tabulated(vector<int> &arr, int reqSum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(reqSum + 1, false));

    // 0 sum is always possible, with any number of elements
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= reqSum; j++)
        {
            if (arr[i - 1] > j)
            {
                // exclude
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // include or exclude
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][reqSum];
}
int main()
{
    vector<int> arr{3, 34, 4, 12, 5, 2};
    cout << subsetSum(arr, 0, 0, 9) << endl;
    unordered_map<string, bool> memo;
    cout << memoized(arr, 0, 0, 34, memo) << endl;
    cout << tabulated(arr, 9) << endl;
    return 0;
}