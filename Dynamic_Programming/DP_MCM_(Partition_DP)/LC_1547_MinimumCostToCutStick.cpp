/*
the array consists of possible indices to be cut, so you have to handle the case of i == j as well here
also if you cut at an index k, then left half is on k - 1, and right on k + 1
*/
#include <bits/stdc++.h>

using namespace std;

// memoized
int memoized(vector<int> &cuts, int i, int j, vector<vector<int>> &dp){
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mcost = 1e9;
    for(int k = i; k <= j; k++){
        mcost = min(mcost, cuts[j + 1] - cuts[i - 1] + memoized(cuts, i, k - 1, dp) + memoized(cuts, k + 1, j, dp));
    }
    return dp[i][j] = mcost;
}

// tabulated
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    for(int i = m - 2; i >= 1; i--){
        for(int j = i; j <= m - 2; j++){
            int mincost = 1e9;
            for(int k = i; k <= j; k++){
                mincost = min(mincost, cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
            }
            dp[i][j] = mincost;
        }
    }
    return dp[1][m - 2];
}
int main(){
    return 0;
}