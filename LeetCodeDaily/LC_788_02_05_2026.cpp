#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int rotatedDigits(int n) {
        auto chck = [](int x) -> bool {
            int ok = false;

            while(x){
                int d = x%10;

                if(d == 2 || d == 5 || d == 6 || d == 9)
                    ok = true;
                if(d == 3 || d == 4 || d == 7)
                    return false;
                x /= 10;
            }

            return ok;
        };

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += chck(i);
        }

        return ans;
    }
};