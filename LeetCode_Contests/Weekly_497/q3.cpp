#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        /*
        at most 1 swap
        means i can make only substrings that are imbalanced by 1 missing balanced
        then select the balanced substr in s
        
        +2 and -2 are the ones to target
        0110001
         1     
        (1,0) (1,1) (1,2) (2,2) (3,2) (4,2) (4, 3)
        how to find currently largest balanced substr? by mp?
        nah distance between 0s 

        only 1 swap, prefix suffix cnts?


        lets break the problem down

        if i need to find the longest balanced substring?
        use hashmap cnts
        

        go to approach:
        handle all the cases
        to handle the first normal case without swaps

        - use a normal prefix hashmap => done for now

        - swapping 0 out with a 1
        if current cnt is C, then if you swap a zero with a one => the count becomes C + 2 ( +1 for throwing the zero, +1 for the 1 that comes in)
        so you need to see if a prefix exists with C - 2 (so that we can remove that) also THAT prefix MUST have A 1 which we will be using for the swap process
        use another prefix map, which tracks prefixes with at least one 1 in it
        now we can also swap a 1 in from the right side, for that just precompute the total and see if there are any 1s on the right

        - swapping 1 out with 0
        if current cnt is C, the cnt becomes C - 2 when you swap out with a zero
        for left side, do the same thing as 1 cnt, keep a map which tracks prefixes with at least 1 zero in it
        for right side, check if any 0s are left or not
        */

        int n = s.size();
        
        int total_ones = 0, total_zeros = 0; // total cnt of 1s and 0s, ill use for checkin if we have 1
        // or 0 on RIGHT side

        for(char c : s){
            if(c == '1')
                total_ones++;
            else
                total_zeros++;
        }

        unordered_map<int, int> mp, mp1, mp0; // normal prefix map, to see what max balanced is without swaps, followed by map with at least one 1, one 0

        int curr_ones = 0, curr_zeros = 0, cnt = 0;
        int ans = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cnt++;
                curr_ones++;
            }
            else{
                cnt--;
                curr_zeros++;
            }

            // normal check without swaps
            if(mp.count(cnt))
                ans = max(ans, i - mp[cnt]);
            
            
            // swap 0 with 1
            int tar = cnt + 2;

            // left side
            if(mp1.count(tar))
                ans = max(ans, i - mp1[tar]);
            // right side
            if(mp.count(tar) && curr_ones < total_ones)
                ans = max(ans, i- mp[tar]);
            
            // swap 1 with 0
            tar = cnt - 2;
            // left side
            if(mp0.count(tar))
                ans = max(ans, i - mp0[tar]);
            // right side
            if(mp.count(tar) && curr_zeros < total_zeros)
                ans = max(ans, i - mp[tar]);
            
            if(!mp.count(cnt))
                mp[cnt] = i;
            if(curr_ones && !mp1.count(cnt))
                mp1[cnt] = i;
            if(curr_zeros && !mp0.count(cnt))
                mp0[cnt] = i;
        }

        return ans;

    }
};