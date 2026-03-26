#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        /*
        consider only horizontal cuts, rotate by 90 each time to make it possible

        cases
        to handle the case where no deletion is involved, add 0 into the set

        if number of rows == 1, we cant cut horizontally just rotate and move on
        if cols == 1, we can only remove the current row or the first (removing last will be handled in one of the rotations) 
        */

        ll total = 0;

        for(auto &r : grid)
            total += accumulate(r.begin(), r.end(), 0ll);

        auto rotate = [&](int n, int m) -> vector<vector<int>> {
            vector<vector<int>> G(m, vector<int>(n));

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    G[i][j] = grid[j][i];
                }
            }
            for(auto &r : G)
                reverse(r.begin(), r.end());

            return G;

        };

        for(int rot = 0; rot < 4; rot++){// grid, grid + 90, grid + 180, grid + 270
            unordered_set<ll> S;
            ll curr, req;
            S.insert(0); // to handle the no removal case
            int r = grid.size(), c = grid[0].size();
            if(r == 1){
                grid = rotate(r, c);
                continue;
            }
            if(c == 1){
                // can only remove first and current element
                curr = 0;
                for(int i = 0; i < r - 1; i++){
                    curr += grid[i][0];

                    req = 2*curr - total;
                    if(req == grid[0][0] || req == grid[i][0] || req == 0)
                        return true;
                }
                grid = rotate(r, c);
                continue;
            }

            // if cut is made after first row, only removable element is the first (last el removal will be handled in some rotation)
            ll f_row = accumulate(grid[0].begin(), grid[0].end(), 0ll);
            
            if(((f_row - grid[0][0]) == (total - f_row)) || (f_row == (total - f_row)))
                return true;

            for(int i : grid[0])
                S.insert(i);

            curr = f_row;
            for(int i = 1; i < r - 1; i++){
                for(int j = 0; j < c; j++){
                    curr += grid[i][j];
                    S.insert(grid[i][j]);
                }

                req = 2*curr - total;
                if(S.count(req))
                    return true;
            }
            
            grid = rotate(r, c);
        }

        return false;
    }
    
};