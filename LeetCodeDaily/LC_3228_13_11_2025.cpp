#include <bits/stdc++.h>

using namespace std;

// logic : count number of ones before every block of 0
class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int ones = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                ones++;
            else{
                if(i + 1 >= n || s[i + 1] != '0')
                    ans += ones;
            }
        }
        return ans;
    }
};