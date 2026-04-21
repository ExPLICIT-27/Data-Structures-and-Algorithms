#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int mirrorDistance(int n) {
        auto rev = [&](int n) -> int {
            int r = 0;

            while(n){
                r = r*10 + n%10;
                n /= 10;
            }

            return r;
        };

        int ans = abs(n - rev(n));
        return ans;
    }
};