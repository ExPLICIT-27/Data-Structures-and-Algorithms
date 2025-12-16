#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string minWindow(string& s, string& t) {
        int n = s.size(), m = t.size();
        int l = -1, sz = n + 1;
        for(int i = 0; i < n; i++){
            if(s[i] != t[0])
                continue;
            int st = i;
            int c = 0;
            while(st < n && c < m){
                if(s[st] == t[c])
                    c++;
                st++;
            }
            if(c < m)
                break;
            int end = st - 1;
            c = m - 1;
            while(end >= i && c >= 0){
                if(s[end] == t[c])
                    c--;
                end--;
            }
            if(st - 1 - end < sz){
                sz = st - 1 - end;
                l = end + 1;
            }
        }
        
        return l == -1? "" : s.substr(l, sz);
    }
};
