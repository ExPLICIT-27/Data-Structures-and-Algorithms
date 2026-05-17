#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'

#define ll long long
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        /*
        if k is one, then its r - l + 1
        k is 2 root(n) ez
        */

        if(k == 1)
            return r - l + 1;

        auto getPow = [&](ll i) -> ll {
            ll res = 1;
            for(int j = 0; j < k; j++){
                res *= i;

                if(res > r)
                    return res;
            }

            return res;
        };

        int ans = 0;
        for(ll i = 0; getPow(i) <= r; i++){
            ll curr = getPow(i);
            if(curr >= l && curr <= r)
                ans++;
        }

        return ans;
        
    }
};