/*
similar logic to boolean paranthesization, result construction is different
*/
#include <bits/stdc++.h>

using namespace std;


// memoized
// helper func
vector<int> ans(vector<string> &exprs, int i, int j, vector<vector<vector<int>>> &dp){
    if(i == j)
        return {stoi(exprs[i])};
    if(!dp[i][j].empty())
        return dp[i][j];
    vector<int> res;
    for(int k = i + 1; k < j; k += 2){
        auto left = ans(exprs, i, k - 1, dp);
        auto right = ans(exprs, k + 1, j, dp);
        for(int l : left){
            for(int r : right){
                if(exprs[k] == "*")
                    res.push_back(l*r);
                else if(exprs[k] == "+")
                    res.push_back(l + r);
                else
                    res.push_back(l - r);
            }
        }
    }
    return dp[i][j] = res;
}

// main func
vector<int> diffWaysToCompute(string expression) {
    vector<string> exprs;
    string tmp = "";
    for(char c : expression){
        if(c >= '0' && c <= '9'){
            tmp += c;
        }
        else{
            exprs.push_back(tmp);
            tmp = "";
            tmp += c;
            exprs.push_back(tmp);
            tmp = "";
        }
    }
    exprs.push_back(tmp);
    for(string str : exprs){
        cout << str << " ";
    }
    int n = exprs.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
    return ans(exprs, 0, exprs.size() - 1, dp);
}
int main(){
    return 0;
}