#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n != m)
            return false;
        
        
        /*
        abcdba
        cabdab

        0,1,2,4,5
        */

        vector<int> _s1e(26, 0), _s1o(26, 0), _s2e(26, 0), _s2o(26, 0);

        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                if(i & 1){
                    _s1o[s1[i] - 'a']++;
                    _s2o[s2[i] - 'a']++;
                }
                else{
                    _s1e[s1[i] - 'a']++;
                    _s2e[s2[i] - 'a']++;
                }
            }
        }

        return _s1e == _s2e && _s1o == _s2o;
        
    }
};