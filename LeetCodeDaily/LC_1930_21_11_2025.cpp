#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<int, pair<int, int>> mp;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(!mp.count(s[i])){
                mp[s[i]] = {i, -1};
            }
            else
                mp[s[i]].second = i;
        }
        int ans = 0;
        for(auto &p : mp){
            if(p.second.second == -1)
                continue;
            int i = p.first;
            unordered_set<int> st;
            for(int j = mp[i].first + 1; j < mp[i].second; j++){
                st.insert(s[j]);
            }
            ans += st.size();
        }

        return ans;
    }
};