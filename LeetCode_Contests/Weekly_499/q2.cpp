#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {

        vector<int> f(26, 0);

        string tmp = "";
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        unordered_set<char> used;
        for(char c : s){
            if(st.count(c) && !used.count(c)){
                tmp += c;
                used.insert(c);
            }
            f[c - 'a']++;
        }
        
        stable_sort(tmp.begin(), tmp.end(), [&](char a, char b){
            return f[a - 'a'] > f[b - 'a'];
        });

        string t2 = "";

        for(char c : tmp){
            for(int i = 0; i < f[c - 'a']; i++)
                t2 += c;
        }

        string ans = "";

        int j = 0;
        for(char c : s){
            if(st.count(c))
                ans += t2[j++];
            else
                ans += c;
        }
        return ans;
        
    }
};