#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>> &G, int i, int j, int s){
        // rows
        int sm = 0;
        for(int r = 0; r < s; r++){
            int curr = 0;
            for(int c = 0; c < s; c++){
                curr += G[i + r][j + c];
            }
            if(sm == 0)
                sm = curr;
            else if(sm != curr)
                return false;
        }
        // cols
        for(int c = 0; c < s; c++){
            int curr = 0;
            for(int r = 0; r < s; r++){
                curr += G[i + r][j + c];
            }   
            if(sm != curr)
                return false;
        }
        // d1
        int curr = 0, c2 = 0;
        for(int d = 0; d < s; d++){
            curr += G[i + d][j + d];
            c2 += G[i + d][j + (s - d - 1)];
        }

        if(curr != sm || c2 != sm)
            return false;
        
        return true;

    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int sq = ans + 1; sq <= min(n, m); sq++){
                    if(i + sq > m || j + sq > n)
                        break;
                    if(check(grid, i, j, sq))
                        ans = sq;
                }
            }
        }
        return ans;
    }
};