/*
Given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.
For example:

If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Note: Print -1 if you can’t reach the end of the array.
*/
#include <bits/stdc++.h>

using namespace std;

// Naive Solution
// for each index containing the number of jumps you can take,
// try out each jump O(2^n)
int Naive(vector<int> &jumps, int idx)
{
    if (idx == jumps.size() - 1)
        return 0;
    if (jumps[idx] == 0)
        return INT_MAX;
    int res = INT_MAX;
    for (int i = 1; i <= jumps[idx] && idx + i < jumps.size(); i++)
    {
        int curr = min(res, Naive(jumps, idx + i));
        if (curr != INT_MAX)
            res = min(res, curr + 1);
    }
    return res;
}
// Memoized - for each index, we calculate the min moves required from that point
// O(n^2)
int Memoized(vector<int> &jumps, int idx, vector<int> &memo)
{
    if (idx == jumps.size() - 1)
        return 0;
    if (jumps[idx] == 0)
        return INT_MAX;
    if (memo[idx] != -1)
        return memo[idx];
    int res = INT_MAX;
    for (int i = 1; i <= jumps[idx] && idx + i < jumps.size(); i++)
    {
        int curr = min(res, Memoized(jumps, idx + i, memo));
        if (curr != INT_MAX)
            res = min(res, curr + 1);
    }
    return memo[idx] = res;
}
// Tabulated
int Tabulated(vector<int> &jumps)
{
    int n = jumps.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= jumps[i] && i + j < n; j++)
        {
            if (dp[i + j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i + j] + 1);
            }
        }
    }
    return (dp[0] == INT_MAX) ? -1 : dp[0];
}
// greedy, ill update
int main()
{
    vector<int> jumps{1, 4, 3, 2, 6, 7};
    int n = jumps.size();
    int result = Naive(jumps, 0);
    (result == INT_MAX) ? cout << -1 : cout << result;
    cout << endl;
    vector<int> memo(n + 1, -1);
    result = Memoized(jumps, 0, memo);
    (result == INT_MAX) ? cout << -1 : cout << result;
    cout << endl;
    cout << Tabulated(jumps) << endl;
    return 0;
}