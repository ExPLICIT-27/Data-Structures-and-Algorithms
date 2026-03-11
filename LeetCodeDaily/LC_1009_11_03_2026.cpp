#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int p = 0;
        int ans = 0;
        if(n == 0)
            return 1;
        while(n){
            if(n & 1 ^ 1)
                ans |= (1 << p);
            n >>= 1;
            p++;
        }

        return ans;
    }
};