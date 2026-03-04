#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> R(n, 0), C(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]){
                    R[i]++;
                    C[j]++;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)  
                if(mat[i][j] && R[i] == 1 && C[j] == 1){
                    ans++;
                }
        }


        return ans;
    }
};