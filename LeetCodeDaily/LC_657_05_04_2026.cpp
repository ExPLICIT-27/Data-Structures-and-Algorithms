#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;

        for(char c : moves){
            switch(c){
                case 'U':
                    x--;
                    break;
                case 'D':
                    x++;
                    break;
                case 'L':
                    y--;
                    break;
                case 'R':
                    y++;
                    break;
                default:
                    return 1;
            }
        }

        return x == 0 && y == 0;
    }
};