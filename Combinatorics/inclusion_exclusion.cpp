/*
Example usage of the inclusion exclusion principle 
Leetcode 3116
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        /*
        finding the number of unique multiples 
        i feel like inclusion exclusion will be used here

        given k, the number of multiples of x for every x in coins
        is at most k/x
        so all i need to do is, 
        compute the number of unique multiples which will be
        for example if coins are [x1, x2, x3]
        k/x1 + k/x2 + k/x3 - (k/lcm(x1, x2) + k/lcm(x2, x3) + k/lcm(x1, x3)) + k/lcm(x1, x2, x3)

        to compute the same efficiently, we need to use bitmasks over the array
        logic is quite simple iterate over 2^array_size - 1, if the number of bits set are odd
        answer is added, else subtracted (odd bits -> odd number of elements, it entails addition from
        the generalized formula, else it is subtracted)

        but wait, how do i arrive exactly at the right number?
        how do i answer a query of 3??

        2, 5 -> 1 (2)
        2, 4, 5, 10 -> 2 (4)
        2, 4, 5, 6, 10, 15 -> 3 (6)
        it increases by the amount equal to the array size

        there is another issue
        2, 5 means there is a 4 in between

        wait leave this shi,
        if i take the threshold of the binary search to be an arbitrary number
        then i can apply the exact logic to find the anwser
        */

        int N = coins.size();
        int range = (1 << N);
        ll L = 1, R = 1e11;


        auto inc_exc = [&](ll thresh) -> ll {
            ll cnt = 0;
            for(int i = 1; i < range; i++){
                ll _lcm = 1, bits = 0;
                for(int j = 0; j < N; j++){
                    if((i >> j) & 1){
                        bits++;
                        _lcm = lcm(_lcm, 1ll*coins[j]);
                    }
                }

                if(bits & 1)
                    cnt += thresh/_lcm;
                else
                    cnt -= thresh/_lcm;
            }

            return cnt;
        };

        while(L <= R){
            ll M = L + (R - L)/2;

            ll cnt = inc_exc(M);
            

            if(cnt >= k)
                R = M - 1;
            else
                L = M + 1;
        }

        return L;
    }
};