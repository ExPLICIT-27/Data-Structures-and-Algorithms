// use binary search

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        int l = 1, r = x/2;

        while(l <= r){
            int m = (l + r)/2;

            if(1ll*m*m == x)
                return m;
            if(1ll*m*m > x)
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
};