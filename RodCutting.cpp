#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 PROBLEM DESCRIPTION
 -------------------

 Given an array containing the price of each cut of a rod,
 find the optimal way to cut it
Input: price[] =  [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation:  The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
*/


/*
 Naive Brute force Top down approach

 Recurrence relation,
 optimal = 0
 for j = 1 to i:
    optimal = max(optimal, prices[j-1]) + cutRod(i-j))
*/
int NaiveBruteForce(vector <int> &prices, int i){
    if(i == 0) return 0;

    int optimal = 0;
    for(int j = 1; j <= i; j++){
        optimal = max(optimal, prices[j-1] + NaiveBruteForce(prices, i-j));
    }
    return optimal;
}
/*
Memoized approach, just use a memo table
*/

int Memoized(vector <int> &prices, int i, vector<int> &memo){
    if(i == 0) return 0;

    if(memo[i-1] != -1) return memo[i-1];

    int optimal = 0;
    for(int j = 1; j <= i; j++){
        optimal = max(optimal, prices[j-1] + Memoized(prices, i-j, memo));
    }
    memo[i-1] = optimal;
    return optimal;
}
/*
 Utilizing a bottom up approach with a dp table
 for i = 0 to n-1:
    for j = 1 to i:
        dp[i] = max(prices[j-1], dp[i-j])
*/
int TabulatedDp(vector<int> &prices){
    int n = prices.size();

    vector<int> dp(n + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], prices[j-1] + dp[i-j]);
        }
    }
    return dp[n];
}
int CutsMade(vector <int> &prices, vector<int> &cutsMade){
    int n = prices.size();
    vector<int> dp(n + 1, 0);
    vector<int> cuts(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(dp[i] < prices[j-1] + dp[i-j]){
                dp[i] = prices[j-1] + dp[i-j];
                cuts[i] = j;
            }
        }
    }
    int len = n;
    while(len > 0){
        cutsMade.push_back(cuts[len]);
        len -= cuts[len];
    }
    return dp[n];
}
int main(){
    vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20};
    cout << NaiveBruteForce(prices, prices.size()) << endl;
    vector<int> memo(prices.size(), -1);
    cout << Memoized(prices, prices.size(), memo) << endl;
    cout << TabulatedDp(prices) << endl;
    vector<int> cutsMade;
    cout << CutsMade(prices, cutsMade) << endl;
    cout << "Cuts Made : ";
    for(int i = 0; i < cutsMade.size(); i++){
        cout << cutsMade[i] << " ";
    }
    return 0;
}


