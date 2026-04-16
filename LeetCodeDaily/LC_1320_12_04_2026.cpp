#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumDistance(string word) {
        
        

        /*
        I see no advantage of starting anywhere but the beginning

        i need to track the current position of finger 1, and finger 2
        26*26, followed by the word cost
        O(300*26*26)


        */

        auto calcCost = [&](int curr, int dest) -> int {
            if(curr == -1)
                return 0;
            curr -= 'A', dest -= 'A';
            int x1 = curr/6, y1 = curr%6;
            int x2 = dest/6, y2 = dest%6;

            return abs(x1 - x2) + abs(y1 - y2);
        };

        int n = word.size();
        int dp[n][27][27];
        memset(dp, -1, sizeof(dp));


        auto helper = [&](auto &&self, int i, int l, int r) -> int {
            if(i == n)
                return 0;
            
            int _l = ((l == -1)? 26 : l - 'A'), _r = ((r == -1)? 26 : r - 'A');

            if(dp[i][_l][_r] != -1)
                return dp[i][_l][_r];
            
            return dp[i][_l][_r] = min(calcCost(l, word[i]) + self(self, i + 1, word[i], r), calcCost(r, word[i]) + self(self, i + 1, l, word[i]));
        };

        return helper(helper, 0, -1, -1);
    }
};