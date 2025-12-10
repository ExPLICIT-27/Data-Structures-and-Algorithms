#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string &s){
        int l = 0, r = s.size() - 1;

        while(l < r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void helper(vector<string> &temp, string curr, string &s, int i){
        if(i == s.size()){
            if(isPalindrome(curr) && !curr.empty()){
                temp.push_back(curr);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        curr += s[i];
        if(isPalindrome(curr)){
            temp.push_back(curr);
            helper(temp, "", s, i + 1);
            temp.pop_back();
        }
        helper(temp, curr, s, i + 1);
    }
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        helper(tmp, "", s, 0);
        return res;
    }
};