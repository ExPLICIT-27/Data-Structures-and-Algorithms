#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // im thinking either L or either R
        int currL = 0, currR = 0;

        for(char c : moves){
            if(c == 'R')
                currL++;
            else
                currL--;
            
            if(c == 'L')
                currR--;
            else
                currR++;
            
        }

        return max(abs(currL), abs(currR));
    }
};