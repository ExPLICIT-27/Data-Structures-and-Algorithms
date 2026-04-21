#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long countGoodIntegersOnPath(long long l, long long r, string dirn) {
        /*
        basically, in the 4*4 grid, we dont care about anything except the path the dirn
        array dictates
        hence the digits at positions not in the path can be anything
        and the digits at positions in the path must be strictly increasing
        */


        // get indices of the needed values

        unordered_set<int> decr;
        decr.insert(0);
        auto enc = [&](int x, int y) -> int {
            return x*4 + y;
        };

        
        int x = 0, y = 0;
        for(int i = 0; i < 6; i++){
            if(dirn[i] == 'D')
                x++;
            else
                y++;
            decr.insert(enc(x, y));
        }

        // ok, so now just digit DP?
        string L = to_string(l - 1), R = to_string(r);

        reverse(L.begin(), L.end());
        reverse(R.begin(), R.end());

        int lsz = L.size(), rsz = R.size();

        for(int i = 0; i < 16 - lsz; i++)
            L += '0';
        for(int i = 0; i < 16 - rsz; i++)
            R += '0';

        reverse(L.begin(), L.end());
        reverse(R.begin(), R.end());

        ll dp[16][2][10];
        memset(dp, -1, sizeof(dp));
        
        auto cnt = [&](auto &&self, string &s, int i, bool tight, int prev) -> ll {
            if(i == s.size())
                return 1;

            if(dp[i][tight][prev] != -1)
                return dp[i][tight][prev];
            
            ll ans = 0;
            if(decr.count(i)){
                int st = prev;
                int en = (tight)? s[i] - '0' : 9;

                for(int d = st; d <= en; d++){
                    ans += self(self, s, i + 1, (tight && (d == en)), d);
                }
            }
            else{
                int st = 0;
                int en = (tight)? s[i] - '0' : 9;

                for(int d = st; d <= en; d++){
                    ans += self(self, s, i + 1, (tight && (d == en)), prev);
                }
            }

            return dp[i][tight][prev] = ans;
        };

        ll left = cnt(cnt, L, 0, true, 0);
        memset(dp, -1, sizeof(dp));
        ll right = cnt(cnt, R, 0, true, 0);

        return right - left;

        
        
    }
};