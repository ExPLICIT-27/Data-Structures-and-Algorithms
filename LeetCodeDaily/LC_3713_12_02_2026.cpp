#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();


        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> F(26, 0);
            for(int j = i; j < n; j++){
                bool ok = true;
                F[s[j] - 'a']++;
                int curr = F[s[j] - 'a'];
                for(int k = 0; k < 26; k++){
                    if(F[k] && F[k] != curr){
                        ok = false;
                        break;
                    }
                }
                if(ok)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};