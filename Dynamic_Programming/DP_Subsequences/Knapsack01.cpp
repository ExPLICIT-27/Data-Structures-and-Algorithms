

#include <bits/stdc++.h>

using namespace std;

int KnapSackBrute(vector<pair<int, int>> &items, int n, int W)
{
    if (n == 0 || W == 0)
        return 0;

    int pick = 0;
    if (items[n - 1].second <= W)
    {
        pick = items[n - 1].first + KnapSackBrute(items, n - 1, W - items[n - 1].second);
    }
    int notPick = KnapSackBrute(items, n - 1, W);
    return max(pick, notPick);
}
int KnapSackMemoized(vector<pair<int, int>> &items, int n, int W, vector<vector<int>> &memo)
{
    if (n == 0 || W == 0)
        return 0;
    if (memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;
    if (items[n - 1].second <= W)
    {
        pick += items[n - 1].first + KnapSackMemoized(items, n - 1, W - items[n - 1].second, memo);
    }
    int notPick = KnapSackMemoized(items, n - 1, W, memo);
    return memo[n][W] = max(pick, notPick);
}
int Tabulated(vector<pair<int, int>> &items, int W)
{
    int n = items.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int pick = 0;
            if (items[i - 1].second <= j)
            {
                pick += items[i - 1].first + dp[i - 1][j - items[i - 1].second];
            }
            int notPick = dp[i - 1][j];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cout << "\nEnter the number of items : ";
    cin >> n;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cout << "\nEnter the value and weight of the item: ";
        cin >> value >> weight;
        items.push_back({value, weight});
    }
    int W;
    cout << "\nEnter the weight of the knapsack : ";
    cin >> W;
    cout << "\nMaximum Profit Brute Force: " << KnapSackBrute(items, n, W);
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    cout << "\nMaximum Profit Memoized : " << KnapSackMemoized(items, n, W, memo);
    cout << "\nMaximum Profit Tabulated : " << Tabulated(items, W);
    return 0;
}