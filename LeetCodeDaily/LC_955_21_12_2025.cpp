#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool> SR(n, false);
        int ans = 0;
        for(int i = 0; i < m; i++){
            bool ok = true;
            for(int j = 1; j < n; j++){
                if(!SR[j] && strs[j][i] < strs[j - 1][i]){
                    ok = false;
                    break;
                }
            }
            if(!ok)
                ans++;
            else{
                for(int j = 1; j < n; j++){
                    if(strs[j][i] > strs[j - 1][i])
                        SR[j] = true;
                }
            }
        }
        return ans;
    }
};