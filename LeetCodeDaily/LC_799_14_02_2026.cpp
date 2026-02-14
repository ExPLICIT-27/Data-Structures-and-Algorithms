#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(100);

        for(int i = 0; i < 100; i++){
            tower[i] = vector<double>(i + 1, 0.0);
        }
        tower[0][0] = poured;
        for(int i = 0; i < 99; i++){
            for(int j = 0; j <= i; j++){
                double rem = tower[i][j] - 1;
                if(rem <= 0)
                    continue;
                tower[i + 1][j] += (rem/2.0);
                tower[i + 1][j + 1] += (rem/2.0);
            }
        }
        
        
        return min(1.0, tower[query_row][query_glass]);
    }
};