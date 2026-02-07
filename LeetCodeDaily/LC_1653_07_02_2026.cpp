#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int minimumDeletions(string s) {
        int  n = s.size();
        int acnt = 0, bcnt = 0;

        for(char c : s){
            if(c == 'a')
                acnt++;
        }
        
        int ans = acnt;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b')
                bcnt++;
            else
                acnt--;
            ans = min(ans, acnt + bcnt);
        }

        return ans;

    }
};