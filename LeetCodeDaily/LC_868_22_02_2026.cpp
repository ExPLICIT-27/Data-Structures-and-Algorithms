#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        if(__builtin_popcount(n) <= 1)
            return 0;
        
        while(!(n & 1))
            n >>= 1;
        
        int ans = 1, cnt = 1;
        n >>= 1;
        while(n){
            if(n & 1)
                cnt = 1;
            else
                cnt++;
            n >>= 1;
            ans = max(ans, cnt);
        }

        return ans;
    }
};