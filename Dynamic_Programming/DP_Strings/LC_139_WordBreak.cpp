#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string &s, string curr, int i, unordered_set<string> &S, map<pair<string, int>, bool> &dp){
        if(i == s.size()){
            if(S.count(curr) || curr.empty())
                return true;
            return false;
        }
        if(dp.count({curr, i}))
            return dp[{curr, i}];
        curr += s[i];
        if(S.count(curr)){
            return dp[{curr, i}] = helper(s, "", i + 1, S, dp) || helper(s, curr, i + 1, S, dp);
        }
        return dp[{curr, i}] = helper(s, curr, i + 1, S, dp);
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> S(wordDict.begin(), wordDict.end());
        map<pair<string, int>, bool> dp;
        return helper(s, "", 0, S, dp);
    }
};