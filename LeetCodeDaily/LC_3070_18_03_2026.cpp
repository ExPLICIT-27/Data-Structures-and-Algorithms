#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    /*
    7 13 16
    13 25 
    */
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        if(grid[0][0] <= k)
            ans++;
        for(int i = 1; i < n; i++){
            grid[i][0] += grid[i - 1][0];
            if(grid[i][0] <= k)
                ans++;
        }
        
        for(int j = 1; j < m; j++){
            grid[0][j] += grid[0][j - 1];
            if(grid[0][j] <= k)
                ans++;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                grid[i][j] = grid[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                if(grid[i][j] <= k)
                    ans++;
            }
        }

        return ans;
    }
};