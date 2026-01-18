#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double L = 0.0, R = 2.0*1e9;
        double ans = -1.0;
        while(R - L > 1e-6){
            double M = (L + R)/2.0;
            double top = 0, bottom = 0;

            for(auto &v : squares){
                if(v[1] >= M)
                    top += 1.0*v[2]*v[2];
                else if(v[1] + v[2] <= M)
                    bottom += 1.0*v[2]*v[2];
                else{
                    double total = v[1] + v[2];
                    double topside = 1.0*total - M, bottomside = M - v[1];
                    top += topside*v[2], bottom += bottomside*v[2];
                }
            }
            if(top > bottom)
                L = M;
            else{   
                if(top == bottom)
                    ans = R;
                R = M;
            }
        }
        return ans == -1.0 ? R : ans;
    }
};