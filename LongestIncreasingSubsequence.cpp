#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Problem Description

    Given an array arr[] of size n, the task is to find the length of the Longest Increasing Subsequence (LIS) i.e., 
    the longest possible subsequence in which the elements of the subsequence are sorted in increasing order.
*/

/*
 Naive Brute Force(top - down), for every idx,
 go from j = 0 to idx-1, if arr[j] < arr[idx] , set
 mx = max(mx, naive(arr, j) + 1)
*/

int NaiveBruteForce(vector<int> &arr, int idx){
    if(idx == 0) return 1;

    int mx = 1;
    for(int prev = 0; prev < idx; prev++){
        if(arr[prev] < arr[idx]){
            mx = max(mx, NaiveBruteForce(arr, prev) + 1);
        }
    }
    return mx;
}
/*
    Memoized version, using a memo table
*/
int Memoized(vector<int> &arr, int idx, vector<int> &memo){
    if(idx == 0) return 1;
    if(memo[idx] != -1) return memo[idx];

    int mx = 1;
    for(int prev = 0; prev < idx; prev++){
        if(arr[prev] < arr[idx]){
            mx = max(mx, Memoized(arr, prev, memo) + 1);
        }
    }
    return memo[idx] = mx;
}
/*
 Bottom up tabulated DP, same logic as before, using a dp array,
 return the largest element in the dp array,
 printing the LIS as well
*/
void TabulatedDP(vector<int> &arr){
    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> parents(n, -1);

    int lastidx = -1, maxLen = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
                parents[i] = j;
            }
        }
        if(dp[i] > maxLen){
            maxLen = dp[i];
            lastidx = i;
        }
    }

    cout << "Length of LIS : " << maxLen << endl;
    cout << "LIS : ";
    vector<int> lis;
    for(int i = lastidx; i != -1; i = parents[i]){
        lis.push_back(arr[i]);
    }
    reverse(lis.begin(), lis.end());
    for(int el : lis){
        cout << el << " ";
    }
}
int main(){
    vector<int> arr{10, 22, 9, 33, 21, 50, 41, 60};
    cout << NaiveBruteForce(arr, arr.size() - 1) << endl;
    vector<int> memo(arr.size(), -1);
    cout << Memoized(arr, arr.size() - 1, memo) << endl;
    TabulatedDP(arr);
    return 0;
}