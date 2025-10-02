/*
read the readme file for the partition dp steps


starts from i = 1, to j = n - 1
it keeps shrinking
base case should be i == j
cost of multiplying a matrix with itself is 0
therefore if i == j, return 0
between i and j you have to try all partitions
k must run from i to j - 1, // if you run till j, then k + 1 goes beyond j
and the partition becomes f(i, k) and f(k + 1, j)

now these partitions will return costs say
cost1 = f(i, k)
cost2 = f(K + 1, j)
now you need to compute the cost of multiplying these two partitions as well
consider the array
10 20 30 40 50 
    i  k     j
i through k, the final dimension would be a[i-1]*a[k]
k + 1 through j, the final dimension would be a[k + 1 - 1]*a[j], which is a[k]*a[j]
so we need to multiply a[i-1]*a[k] and a[k]*a[j], and the cost for this would be
a[i-1]*a[k]*a[j]

hence final cost = c1 + c2  + a[i - 1]*a[k]*a[j]
*/

#include <bits/stdc++.h>

using namespace std;

// naive
int naive(vector<int> &dimensions, int i, int j){
    if(i == j)
        return 0; // cost of multiplying a matrix with itself is 0
    // run loop from i to j - 1
    int mincost = INT_MAX;
    for(int k = i; k < j; k++){
        int steps = dimensions[i - 1]*dimensions[k]*dimensions[j] + naive(dimensions, i, k) + naive(dimensions,  + 1, j);
        mincost = min(mincost, steps);
    }
    return mincost;
}

// memoized -> O(N^3) states
int memoized(vector<int> &dims, int i, int j, vector<vector<int>> &dp){
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mincost = INT_MAX;
    for(int k = i; k < j; k++){
        int steps = dims[i - 1]*dims[k]*dims[j] + memoized(dims, i, k, dp) + memoized(dims, k + 1, j, dp);
        mincost = min(mincost, steps);
    }
    return dp[i][j] = mincost;
}

// tabulated
int tabulated(vector<int> &dims){
    int n = dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));


    // in the memoized code, the i started from 1 and went ahead, and j started from n - 1 and went down
    // so in the bottom up code we will start i from n - 1 and go till 0
    // but for j, we cant start it from 0, as in the recurrence j is always > i, if it is equal then the ans is 0 and
    // j < i cases do not exist, hence we must start j from i + 1 and go till n
    // in conclusion : i from n - 1 to 1, j from i + 1 to n
    // then just copy the recurrence
    for(int i = n - 1; i >= 1; i--){
        for(int j = i + 1; j < n; j++){
            // just copy paste the recurrence
            int mincost = INT_MAX;
            for(int k = i; k < j; k++){
                int currcost = dims[i - 1]*dims[k]*dims[j] + dp[i][k] + dp[k + 1][j];
                mincost = min(mincost, currcost);
            }
            dp[i][j] = mincost;
        }
    }
    // recrurrence started from i = 1, and j = n - 1, hence result will also be stored in dp[1][n - 1];
    return dp[1][n - 1];
}
int main(){
    return 0;
}