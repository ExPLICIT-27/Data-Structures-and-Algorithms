/*

Partition dp with the following essense

at each step you are returning the number of ways to make true and false respectively

if the operator is an or,
    the number of trues is incremented by number of ways to make true in left * number of ways to make false in right,
    number of ways to make true in both left and right, and number of ways to make false in left, true in right
    and false is incremented by number of ways to make false in left and right
similarly apply the conditions for the other operators

*/

#include <bits/stdc++.h>
using namespace std;


// naive
pair<long long, long long> count(string &exprs,int i, int j){
    // base case, when i == j, you check if it is currently true or false and return the pairs accordingly
    if(i == j){
        if(exprs[i] == 'T')
            return {1, 0};
        else
            return {0, 1};
    }
    long long trues = 0, falses = 0;
    for(int k = i + 1; k < j; k += 2){
        auto left = count(exprs, i, k - 1);
        auto right = count(exprs, k + 1, j);
        // condition for and, or and xor respectively
        if(exprs[k] == '&'){
            trues += left.first*right.first;
            falses += (left.first*right.second + left.second*right.first + left.second*right.second);
        }
        else if(exprs[k] == '|'){
            trues += (left.first*right.second + left.second*right.first + left.first*right.first);
            falses += left.second*right.second;
        }
        else{
            trues += (left.first*right.second + left.second*right.first);
            falses += (left.first*right.first + left.second*right.second);
        }
    }
    // return cumulative result
    return {trues, falses};
}

// memoized
pair<long long, long long> count(string &exprs,int i, int j, vector<vector<pair<long long, long long>>> &dp){
    if(i == j){
        if(exprs[i] == 'T')
            return {1, 0};
        else
            return {0, 1};
    }

    if(dp[i][j].first != -1)
        return dp[i][j];

    long long trues = 0, falses = 0;

    for(int k = i + 1; k < j; k += 2){
        auto left = count(exprs, i, k - 1, dp);
        auto right = count(exprs, k + 1, j, dp);

        if(exprs[k] == '&'){
            trues += left.first*right.first;
            falses += (left.first*right.second + left.second*right.first + left.second*right.second);
        }
        else if(exprs[k] == '|'){
            trues += (left.first*right.second + left.second*right.first + left.first*right.first);
            falses += left.second*right.second;
        }
        else{
            trues += (left.first*right.second + left.second*right.first);
            falses += (left.first*right.first + left.second*right.second);
        }

    }
    
    return dp[i][j] = {trues, falses};
}
int main(){
    return 0;
}