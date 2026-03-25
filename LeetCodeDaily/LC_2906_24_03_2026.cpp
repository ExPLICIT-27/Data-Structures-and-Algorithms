#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        /*
        The 1D version is solved by prefix suffix products
        convert the array to 1D. problem solved
        */
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();

        int sz = n*m;
        vector<ll> P(sz), S(sz);
        int idx = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                P[idx] = grid[i][j];
                S[idx++] = grid[i][j];
            }
        }

        for(int i = 1; i < sz; i++){
            P[i] = (P[i]*P[i - 1])%MOD;
        }

        for(int i = sz - 2; i >= 0; i--){
            S[i] = (S[i]*S[i + 1])%MOD;
        }

        vector<ll> ans(sz);
        ans[0] = S[1];
        ans[sz - 1] = P[sz - 2];

        for(int i = 1; i < sz - 1; i++)
            ans[i] = (P[i - 1]*S[i + 1])%MOD;
        
        vector<vector<int>> res(n, vector<int>(m));

        idx = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                res[i][j] = ans[idx++]%MOD;
        }

        return res;
    }
};