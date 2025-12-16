#include <bits/stdc++.h>

using namespace std;

// brute force
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> copy;
        for(char c : t)
            copy[c]++;
        
        int n = s.size();
        int l = 0;
        int al = -1, ar = -1;
        int sz = n + 1;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            bool ok = true;
            for(auto &[x, y] : copy){
                if(!mp.count(x)){
                    ok = false;
                    break;
                }
                if(mp[x] < y){
                    ok = false;
                    break;
                }
            }
            if(ok){
                while((copy.count(s[l]) && mp[s[l]] > copy[s[l]]) || !copy.count(s[l])){
                    mp[s[l]]--;
                    l++;
                }
                if(i - l + 1 < sz){
                    sz = i - l + 1;
                    al = l, ar = i;
                }
            }
        }
        if(al == -1)
            return "";
        return s.substr(al, ar - al + 1);
    }
};          
// nearly same time complexity, faster solution
class Solution2 {
public:
    string minWindow(string s, string t) {
        vector<int> mp(256, 0);

        int n = s.size(), m = t.size();
        for(char c : t)
            mp[c]++;
        int l = 0;
        int al = -1;
        int mlen = n + 1;
        int cnt = 0;
        for(int r = 0; r < n; r++){
            if(mp[s[r]] > 0)
                cnt++;
            mp[s[r]]--;
            while(cnt == m){
                if(r - l + 1 < mlen){
                    al = l;
                    mlen = r - l + 1;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0)
                    cnt--;
                l++;
            }   
        }
        
        return al == -1? "" : s.substr(al, mlen);
    }
};          