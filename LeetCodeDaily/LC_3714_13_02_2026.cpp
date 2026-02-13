#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cntDouble(string &s, int n, char c1, char c2){
        unordered_map<int, int> mp;
        mp[0] = -1;

        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == c1)
                cnt++;
            else if(s[i] == c2)
                cnt--;
            else{
                cnt = 0;
                mp = {{0, i}};
            }

            if(mp.count(cnt))
                ans = max(ans, i - mp[cnt]);
            else
                mp[cnt] = i;
        }

        return ans;
    }
    int longestBalanced(string s) {
        // single char
        int ans = 1, curr = 1, ch = s[0];
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(s[i] == ch)
                curr++;
            else{
                curr = 1;
                ch = s[i];
            }
            ans = max(ans, curr);
        }

        // doubles
        ans = max(ans, max(cntDouble(s, n, 'a', 'b'), max(cntDouble(s, n, 'a', 'c'), cntDouble(s, n, 'b', 'c'))));

        // triples : inc a when its a, inc b when its b, dec both if its c

        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        int a = 0, b = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a')
                a++;
            else if(s[i] == 'b')
                b++;
            else{
                a--, b--;
            }

            if(mp.count({a, b}))
                ans = max(ans, i - mp[{a, b}]);
            else
                mp[{a, b}] = i;
        }

        return ans;
    }
};