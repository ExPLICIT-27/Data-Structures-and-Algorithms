#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    vector<string> result;
    void dfs(string &num, int i, ll target, ll res, ll prev, string curr){
        if(i == num.size()){
            if(res == target){
                result.push_back(curr);
            }
            return;
        }

        for(int j = i; j < num.size(); j++){
            if(j > i && num[i] == '0') // leading 0
                break;
            ll cnum = stoll(num.substr(i, j - i + 1));
            if(i == 0){
                dfs(num, j + 1, target, cnum, cnum, curr + to_string(cnum));
            }
            else{
                string tmp = to_string(cnum);
                string c1 = curr + "+" + tmp;
                string c2 = curr + "-" + tmp;
                string c3 = curr + "*" + tmp;
                dfs(num, j + 1, target, res + cnum, cnum, c1);
                dfs(num, j + 1, target, res - cnum, -cnum, c2);
                dfs(num, j + 1, target, res - prev + cnum*prev, prev*cnum, c3);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        string t = "";
        dfs(num, 0, target, 0, 0, t);
        return result;
    }
};