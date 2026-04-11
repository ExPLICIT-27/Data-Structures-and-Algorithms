#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;
    int xorAfterQueries(vector<int>& N, vector<vector<int>>& Q) {
        int n = N.size(), m = Q.size();

        for(auto &q : Q){
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for(int i = l; i <= r; i += k){
                N[i] = 1ll*N[i]*v%M;
            }
        }

        int xr = N[0];

        for(int i = 1; i < n; i++)
            xr ^= N[i];
        
        return xr;
    }
};