#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<string> res;
    bool check(string &ip){
        stringstream ss(ip);
        string token;

        while(getline(ss, token, '.')){
            if(token.empty() || token.size() > 3 || stoi(token) > 255)
                return false;
            if(token[0] == '0' && token.size() > 1)
                return false;
            
        }

        return true;
    }
    void helper(string &s, string &curr, int i, int dots){
        if(i == s.size()){
            if(dots == 0 && check(curr))
                res.push_back(curr);
            return;
        }
        // add and go forward
        curr += s[i];
        helper(s, curr, i + 1, dots);
        curr.pop_back();
        if(dots > 0){
            curr += '.';
            helper(s, curr, i, dots - 1);
            curr.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12)
            return {};
        string curr;
        helper(s, curr, 0, 3);
        return res;
    }
};


int main(){

    return 0;
}