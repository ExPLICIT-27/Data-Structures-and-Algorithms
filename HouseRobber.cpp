#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    There are n houses built in a line, each of which contains some money.
    A robber wants to steal money from these houses, but he cant steal
    from adjacent houses, find the maximum amount of money that can be stolen
    For example :
    houses = {6, 7, 1, 3, 8, 2, 4}
    output = 19
    sequence -> 6 + 1 + 8 + 4 (houses 1, 3, 5 and 7)
*/
/*
Naive approach O(2^n)
through recursion ->  start from the last house and;
choice 1: rob current house, skip the one just before it
choice 2: skip current house, move to the next house
*/
int NaiveApproach(vector<int> &houses, int n){
    if(n <= 0) return 0;
    if(n == 1) return houses[0];

    // pick or not pick
    int pick = houses[n-1] + NaiveApproach(houses, n-2); // note: n-2 becomes n-2-1 in the next call hence n-2 is not picked in the next call!
    int notPick = NaiveApproach(houses, n-1);

    return max(pick, notPick);
}
/*
 Memoized approach O(n) time and space
 store the best value for the ith index in a memo table of size n+1
*/
int MemoizedApproach(vector <int> &houses, int n, vector <int> &memo){
    if(n <= 0) return 0;
    if(n == 0) return houses[0];
    if(memo[n] != -1) return memo[n];
    
    int pick = houses[n-1] + MemoizedApproach(houses, n-2, memo);
    int notPick = MemoizedApproach(houses, n-1, memo);

    memo[n] = max(pick, notPick);
    return memo[n];
}
/*
 tabulated dp approach
 create a dp array of size n + 1,
 fill out dp[0] and dp[1]
 fill the rest using the formula dp[i] = max(house[i-1] + dp[i-2], dp[i-1])
*/
int TabulatedDP(vector <int> &house, int n){
    vector <int> dp(n+1, 0);

    dp[0] = 0, dp[1] = house[0];

    for(int i = 2; i <= n; i++){
        dp[i] = max(house[i-1] + dp[i-2], dp[i-1]);
    }
    return dp[n];
}
/*
    Space optimized dp approach
*/
int SpaceOptimized(vector <int> &house, int n){
    if(n == 0) return 0;
    if(n == 1) return house[0];
    

    int secondLast = 0, last = house[0];
    int res;
    for(int i = 1; i < n; i++){
        res = max(last, house[i] + secondLast);
        secondLast = last;
        last = res;
    }
    return res;
}
int main(){
    vector <int> arr{6, 7, 1, 3, 8, 2, 4};
    cout << NaiveApproach(arr, arr.size()) << endl;
    vector <int> memo(arr.size() + 1, -1);
    cout << MemoizedApproach(arr, arr.size(), memo) << endl;
    cout << TabulatedDP(arr, arr.size()) << endl;
    cout << SpaceOptimized(arr, arr.size());
    return 0;
}
