#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int minFlips(string s) {
        /*
        011
        001-> which is valid
        or 
        010 -> can lead to a 110
        111 -> 
        100-> it becomes valid

        0 11 11 0
        there can be at most 1 1 between every two zeros

        cannot be more than 1 '1' before and after a zero


        111111111111111111
        for every 011 or 110, flips += 1
        */

        

        
        int n = s.size();

        // flip everything to the same one, undo flips if it doesnt affect
        //000000000000001
        // 0011010101
        int z = 0, o = 0;

        for(char c : s){
            if(c == '0')
                z++;
            else
                o++;
        }

        int ans = min(o, z); // all zeros / ones

        ans = min(ans, max(0, o - 1)); // just 1 one



        // all zeros in middle, 2 ones at end

        int cnt = 0;

        for(int i = 1; i < n - 1; i++){
            if(s[i] == '1')
                cnt++;
        }
        

        return min(ans, cnt);
    }
};