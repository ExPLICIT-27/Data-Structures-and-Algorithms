#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    const int MOD = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long ans = 0;
        int len = 0;

        /*
        len increases every time you encounter a power of two, len being number of bits of the binary number
        to check if something is a power of two -> i & (i - 1) will be zero as 
        i will be 1000... and i - 1 will be 0111111. bitwise and will be zero

        then just left shift ans by len bits and do bitwise or with i
        i = 3
        current ans = 1101
        we need to get 110111
        so left shift by 2
        110100 and | with 3 to get 110111
        */
        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0)
                len++; // p 2 chck, all brackets are VIMP
            ans = ((ans << len) | i)%MOD;
        }
        return ans;
    }
};