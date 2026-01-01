#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>> &G, int r, int c){
        vector<int> C(10, 0);
        // 1 - 9 check
        for(int i = r; i < r + 3; i++){
            for(int j = c; j < c + 3; j++){
                if(G[i][j] >= 1 && G[i][j] <= 9 && !C[G[i][j]])
                    C[G[i][j]]++;
                else
                    return false;
            }
        }
        // each row check
        int psum = -1;
        for(int i = r; i < r + 3; i++){
            int csum = 0;
            for(int j = c; j < c + 3; j++){
                csum += G[i][j];
            }
            if(psum == -1)
                psum = csum;
            else if(csum != psum)
                return false;
        }
        // cols
        for(int j = c; j < c + 3; j++){
            int csum = 0;
            for(int i = r; i < r + 3; i++){
                csum += G[i][j];
            }
            if(csum != psum)
                return false;
        }
        // diag
        int csum = 0;
        for(int i = r, j = c; i < r + 3 && j < c + 3; i++, j++){
            csum += G[i][j];
        }
        if(csum != psum)
            return false;
        csum = 0;
        for(int i = r, j = c + 2; i < r + 3 && j >= c; i++, j--){
            csum += G[i][j];
        }

        return csum == psum;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int ans = 0;
        for(int i = 0; i < N - 2; i++){
            for(int j = 0; j < M - 2; j++){
                if(check(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};