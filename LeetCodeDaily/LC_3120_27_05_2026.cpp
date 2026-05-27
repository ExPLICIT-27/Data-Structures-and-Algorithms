#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> up(26, false), low(26, false);
        
        for(char c : word){
            if(isupper(c))
                up[c - 'A'] = true;
            else
                low[c - 'a'] = true;
        }
        
        int ans = 0;
        
        for(int i = 0; i < 26; i++){
            if(up[i] && low[i])
                ans++;
        }
        
        return ans;
    }
};