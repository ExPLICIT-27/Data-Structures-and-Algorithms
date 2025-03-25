/*
Problem Description:
Given a fence with n posts and k colors, the task is to find out the number of ways of painting the fence
so that not more than two consecutive posts have the same
*/
#include <bits/stdc++.h>

using namespace std;

// Naive brute force
/*
for a given fence i could,
- choose to paint the fence with one color and the adjacent one with a different color,
thereby making it so that i have n-1 fences to paint and (k-1) different choices for each fence
- or paint 2 with the same color,: n-2 fences and k-1 diff colors
*/
int BruteForce(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    int paint1 = BruteForce(n - 1, k) * (k - 1);
    int paint2 = BruteForce(n - 2, k) * (k - 1);
    return paint1 + paint2;
}
int Memoized(int n, int k, vector<int> &memo)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = (k - 1) * (Memoized(n - 1, k, memo) + Memoized(n - 2, k, memo));
}
// Tabulated, same formula as before
int Tabulated(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k, dp[2] = k * k;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}
// from the dp relation we can see that we only care about the previous 2 values
int Optimized(int n, int k)
{
    int prev = k, curr = k * k;
    for (int i = 3; i <= n; i++)
    {
        int next = (k - 1) * (prev + curr);
        prev = curr, curr = next;
    }
    return curr;
}
int main()
{
    int n = 3, k = 2;
    cout << BruteForce(n, k) << endl;
    vector<int> memo(n + 1, -1);
    cout << Memoized(n, k, memo) << endl;
    cout << Tabulated(n, k) << endl;
    cout << Optimized(n, k) << endl;
    return 0;
}