#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> P(n, vector<int>(m, 0));
        P[0][0] = mat[0][0];
        for(int i = 1; i < n; i++)
            P[i][0] = mat[i][0] + P[i - 1][0];
        
        for(int j = 1; j < m; j++)
            P[0][j] = mat[0][j] + P[0][j - 1];
        

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                P[i][j] = mat[i][j] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int sq = ans; sq < min(n, m); sq++){
                    if(i + sq >= n || j + sq >= m)
                        break;
                    int br, bc, tr, tc;

                    tr = i - 1, tc = j - 1;
                    br = i + sq, bc =j + sq;

                    int sqrsum = P[br][bc];
                    if(tr >= 0)
                        sqrsum -= P[tr][bc];
                    if(tc >= 0)
                        sqrsum -= P[br][tc];

                    if(tr >= 0 && tc >= 0)
                        sqrsum += P[tr][tc];

                    if(sqrsum <= threshold){
                        ans = sq + 1;
                    }
                }
            }
        }

        return ans;
    }
};