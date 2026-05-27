#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfSpecialChars(string word) {
        int inf = 2*1e5 + 3;
        vector<int> up(26, -1), low(26, inf);

        int n = word.size();

        for(int i = 0; i < n; i++){
            if(islower(word[i])){
                low[word[i] - 'a'] = i;
            }
            else{
                if(up[word[i] - 'A'] == -1) 
                    up[word[i] - 'A'] = i;
            }
        }

        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(low[i] < up[i])
                ans++;
        }

        return ans;
    }
};