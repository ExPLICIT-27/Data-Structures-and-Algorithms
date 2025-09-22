#include <bits/stdc++.h>

using namespace std;

// memoized
int count(vector<int> &val, vector<int> &wt, int capacity, int idx, vector<vector<int>> &dp){
    if(idx == 0){
        if(wt[0] <= capacity)
            return (capacity/wt[0])*val[0];
        return 0;
    }
    if(dp[idx][capacity] != -1)
        return dp[idx][capacity];
    int take = 0;
    if(wt[idx] <= capacity)
        take = val[idx] + count(val, wt, capacity - wt[idx], idx, dp);
    int notTake = count(val, wt, capacity, idx - 1, dp);
    return dp[idx][capacity] = max(take, notTake);
}
// tabulated
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {

    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for(int j = 0; j <= capacity; j++){
        dp[0][j] = val[0]*(j/wt[0]);
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= capacity; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= wt[i])
                dp[i][j] = max(dp[i][j], dp[i][j - wt[i]] + val[i]);
        }
    }
    return dp[n - 1][capacity];
}
// optimized
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    int n = val.size();
    vector<int> prev(capacity + 1, 0);
    for(int j = 0; j <= capacity; j++){
        prev[j] = val[0]*(j/wt[0]);
    }
    vector<int> curr(capacity + 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= capacity; j++){
            curr[j] = prev[j];
            if(j >= wt[i])
                curr[j] = max(curr[j], curr[j - wt[i]] + val[i]);
        }
        prev = curr;
    }
    return prev[capacity];
}

int main(){
    return 0;
}