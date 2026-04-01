#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();


        string ans(n + m - 1, 'a');

        vector<bool> used(n + m - 1, false);

        for(int i = 0; i < n; i++){
            if(s1[i] == 'T'){
                for(int j = i; j < i + m; j++){
                    if(!used[j]){
                        used[j] = true;
                        ans[j] = s2[j - i];
                    }
                    else{
                        if(ans[j] != s2[j - i])
                            return "";
                    }
                }
            }
        }


        for(int i = 0; i < n; i++){
            if(s1[i] == 'F'){
                bool ok = false;
                int last_free = -1;
                for(int j = i; j < i + m; j++){
                    if(!used[j])
                        last_free = j;

                    if(ans[j] != s2[j - i])
                        ok = true;
                }
                if(ok)
                    continue;
                if(last_free != -1){
                    used[last_free] = true;
                    ans[last_free] = 'b';
                }
                else{
                    return "";
                }
            }
        }

        return ans;

    }
};


