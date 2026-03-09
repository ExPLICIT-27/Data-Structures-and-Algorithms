#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        /*
        for some stupid reason (all blame to leetcode), the 3D Dp code which 
        should pass within the given constraints is not passing

        ok the idea for 2D dp (keeping in mind what the third statement means is no more than limit consecutive 1s and 0s)
        as usual (same logic for 3D, we are skipping the limit dimension here)
        let dp[i][j][1] => number of arrays with i zeros, j ones ending with 1
        dp[i][j][0] => number of arrays with i zeros, j ones ending with 0

        base case
        there is exactly one way to build a prefix of the type
        0000...
        1111...
        and the length of this is min(zero, limit) and min(one, limit) 
        so for the 000.. case
        we set dp[0..min(zero, limit)][0][0] to 1
        and for the 111... case
        we set dp[0][0...min(one, limit)][1] to 1


        so now for the transitions
        case 1, when i <= limit and j <= limit
            if we want to add a 0 to the curr array, we can add it to both types ending with 1 and 0
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1]
            same applies for adding 1
            dp[i][j][1] = dp[i][j - 1][0] + dp[i][j - 1][1]
        case 2, when i > limit or j > limit
            you cannot arbitrarily do dp[i][j][0] = dp[i - 1][j][0] when i > limit as you might end up adding more than limit zeros to the array
            so 1 thing you can do is subtract the arrays which are using limit zeros already after adding both dp[i - 1][j][0] + dp[i - 1][j][1]
            what is the location of this array previously using limit zeros?
            provided you are using i zeros, you want to go to a case like
            10000...(limit zeros), you want to go the location of the 1
            so you know its gonna be dp[something][j][1]

            to something means -> currently you are about to add the ith zero, hence the array has
            i - 1 zeros, you need to go back where limit zeros has been used
            so just go back limit times from i - 1, 
            i - 1 - limit 
            hence
            transition for adding 0 when i > limit
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1]
            for adding 1 when j > limit
            dp[i][j][1] = dp[i][j - 1][0] + dp[i][j - 1][1] - dp[i][j - limit - 1][0]
        */
        const int MOD = 1e9 + 7;
        ll dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));

        // base cases
        for(int i = 0; i <= min(limit, zero); i++)
            dp[i][0][0] = 1;

        for(int j = 0; j <= min(limit, one); j++)
            dp[0][j][1] = 1;
        
        for(int i = 1; i <= zero; i++){
            for(int j = 1; j <= one; j++){
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1])%MOD;

                if(i > limit)
                    dp[i][j][0] = ((dp[i][j][0] - dp[i - limit - 1][j][1])%MOD + MOD)%MOD;
                
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1])%MOD;

                if(j > limit)
                    dp[i][j][1] = ((dp[i][j][1] - dp[i][j - limit - 1][0])%MOD + MOD)%MOD;

            }
        }

        return (dp[zero][one][0] + dp[zero][one][1])%MOD;
    }
};