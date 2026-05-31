#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> lo, up, dig, spcl;

        int points = 0;

        for(char c : password){
            if(c >= 'a' && c <= 'z'){
                if(lo.count(c))
                    continue;
                lo.insert(c);
                points += 1;
            }
            else if(c >= 'A' && c <= 'Z'){
                if(up.count(c))
                    continue;
                up.insert(c);
                points += 2;
            }
            else if(c >= '0' && c <= '9'){
                if(dig.count(c))
                    continue;
                dig.insert(c);
                points += 3;
            }
            else{
                if(spcl.count(c))
                    continue;
                spcl.insert(c);
                points += 5;
            }
        }

        return points;
    }
};