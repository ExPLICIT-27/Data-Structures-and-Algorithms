// backtracking approach
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool dfs(string current, unordered_map<string, vector<char>> &allowed, string &prev, int i){
        if(i == prev.size()){
            if(current.size() == 1)
                return true;
            return dfs("", allowed, current, 1);
        }
        string key = string(1, prev[i - 1]) + string(1, prev[i]);
        for(char c : allowed[key]){
            if(dfs(current + c, allowed, prev, i + 1))
                return true;
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(auto &str : allowed){
            mp[string(1, str[0]) + string(1, str[1])].push_back(str[2]);
        }
        
        return dfs("", mp, bottom, 1);
    }
};