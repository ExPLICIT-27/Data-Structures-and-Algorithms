#include <bits/stdc++.h>

using namespace std;


/*

Digit DP is used to solve 2 kinds of problems

1. count of numbers in the range 0, R that satisfy a certain functionality f(X), for eg sum of values of X = some target
2. count of numbers in range L, R that satisfy a certain functionality f(X)

note that if you have a function solve(x) which solves from 0 to x,
the ans to the second problem is basically solve(R) - solve(L - 1)


consider the problem
find numbers in range L, R whose digits sum upto x
0 <= L, R <= 1e18
x goes upto 180

dp state would be current digit position (n), current sum (x) and a tight boolean 

tight denotes whether we are constrained at this moment by the upper bound number

for eg if R = 5678
you are building the number and it is 56__
you will be constrained to use only till 7, hence tight will be true for this case
*/

// top down version
int64_t helper(string &num, int i, int x, bool tight, vector<vector<vector<int64_t>>> &dp){
    if(x < 0) 
        return 0;

    if(i == num.size()){
        return (x == 0)? 1 : 0;
    }

    if(dp[i][x][tight] != -1)
        return dp[i][x][tight];
    
    int upper_limit = tight ? num[i] - '0' : 9;
    int64_t ans = 0;

    for(int digit = 0; digit <= upper_limit; digit++){
        ans += helper(num, i + 1, x - digit, (tight && (digit == upper_limit)), dp); // condition for tight to be true : it was tight earlier and the digit passed now is equal to the upper bound
    }

    return dp[i][x][tight] = ans;
}
int main(){
    int l = 15, r = 785945;
    string L = to_string(l - 1), R = to_string(r);
    int x = 18;

    vector<vector<vector<int64_t>>> dp(R.size() + 1, vector<vector<int64_t>>(x + 1, vector<int64_t>(2, -1)));

    int64_t right = helper(R, 0, x, 1, dp);// its always tight initially
    // reset dp
    for(auto &v : dp){
        for(auto &vv : v)
            for(int64_t &i : vv)
                i = -1;
    }
    int64_t left = helper(L, 0, x, 1, dp);

    cout << right - left << endl;
    return 0;
}