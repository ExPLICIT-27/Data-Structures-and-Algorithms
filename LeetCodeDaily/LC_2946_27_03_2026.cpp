#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int n = mat.size(), m = mat[0].size();
        int mul = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int _j = ((j + mul*k)%m + m)%m;
                if(mat[i][j] != mat[i][_j])
                    return false;
            }
            mul *= -1;
        }

        return true;
    }
};