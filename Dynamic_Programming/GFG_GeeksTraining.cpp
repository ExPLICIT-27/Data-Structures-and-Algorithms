/*
Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .
*/

#include <bits/stdc++.h>

using namespace std;
// make sure to call both naive and memoized for all 3 different starting cases

// naive recursion
int naive(vector<vector<int>> &arr, int day, int p){
    int ac1 = (p + 1)%3;
    int ac2 = (p + 2)%3;

    if(day == 0)
        return max(arr[0][ac1], arr[0][ac2]);
    
    int choose_first = arr[day][ac1] + naive(arr, day - 1, ac1);
    int choose_second = arr[day][ac2] + naive(arr, day - 1, ac2);

    return max(choose_first, choose_second);
}

// memoized
int memoized(vector<vector<int>> &arr, int day, int p, vector<vector<int>> &dp){
    int ac1 = (p + 1)%3;
    int ac2 = (p + 2)%3;

    if(day == 0)
        return max(arr[0][ac1], arr[0][ac2]);
    
    if(dp[day][p] != -1)
        return dp[day][p];
    
    int choose_first = arr[day][ac1] + memoized(arr, day - 1, ac1, dp);
    int choose_second = arr[day][ac2] + memoized(arr, day - 1, ac2, dp);

    return dp[day][p] = max(choose_first, choose_second);
}

// tabulated
int tabulated(vector<vector<int>> &arr){

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i = 1; i < n; i++){
        dp[i][0] = arr[i][0] + max(dp[i][1], dp[i][2]);
        dp[i][1] = arr[i][1] + max(dp[i][0], dp[i][2]);
        dp[i][2] = arr[i][2] + max(dp[i][0], dp[i][1]);
    }

    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

// space optimized
int optimized(vector<vector<int>> &arr){
    int n = arr.size();

    int p1 = arr[0][0];
    int p2 = arr[0][1];
    int p3 = arr[0][2];

    for(int i = 1; i < n; i++){
        int n1 = arr[i][0] + max(p2, p3);
        int n2 = arr[i][1] + max(p1, p3);
        int n3 = arr[i][2] + max(p1, p2);

        p1 = n1, p2 = n2, p3 = n3;
    }

    return max({p1, p2, p3});
}
int main(){
    return 0;
}