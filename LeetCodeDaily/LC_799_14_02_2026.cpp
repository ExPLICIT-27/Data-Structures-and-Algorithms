#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currT(1, 1.0*poured);
        
        for(int i = 0; i < query_row; i++){
            vector<double> nxt(i + 2, 0.0);
            for(int j = 0; j <= i; j++){
                double glass = currT[j] - 1;
                if(glass <= 0)
                    continue;
                nxt[j] += (glass/2.0);
                nxt[j + 1] += (glass/2.0);
            }
            currT = nxt;
        }
        
        
        return min(1.0, currT[query_glass]);
    }
};