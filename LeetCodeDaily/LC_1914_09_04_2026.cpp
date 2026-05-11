#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        /*
        it goes from 0 to cols/2

        */
        int rows = grid.size(), cols = grid[0].size();

        int rlim = rows, clim = cols;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        for(int st = 0; st < cols/2 && rlim > st && clim > st; st++){
            // take everything into a 1D array, rotate it then, put it back?
            vector<int> tmp;

            // right
            for(int i = st, j = st; j < clim; j++)
                tmp.push_back(grid[i][j]);
            if(tmp.empty())
                break;
            tmp.pop_back();

            // down
            for(int i = st, j = clim - 1; i < rlim; i++)
                tmp.push_back(grid[i][j]);
            tmp.pop_back();
            
            //left
            for(int i = rlim - 1, j = clim - 1; j >= st; j--)
                tmp.push_back(grid[i][j]);
            tmp.pop_back();
            for(int i = rlim - 1, j = st; i >= st; i--)
                tmp.push_back(grid[i][j]);
            tmp.pop_back();

            
            int n = tmp.size();
            int rot = k%n;

            // rotate
            
            reverse(tmp.begin(), tmp.end());
            reverse(tmp.begin(), tmp.begin() + (n - rot));
            reverse(tmp.begin() + (n - rot), tmp.end());


            
            // insert everythin back
            int idx = 0;
            for(int i = st, j = st; j < clim; j++)
                ans[i][j] = tmp[idx++];
            idx--;

            // down
            for(int i = st, j = clim - 1; i < rlim; i++)
                ans[i][j] = tmp[idx++];
            idx--;
            
            //left
            for(int i = rlim - 1, j = clim - 1; j >= st; j--)
                ans[i][j] = tmp[idx++];
            idx--;

            for(int i = rlim - 1, j = st; i > st; i--)
                ans[i][j] = tmp[idx++];
            idx--;

            
        
            rlim--, clim--;

        }


        return ans;
    }
};

/*
1, 2, 3, 4, 5
by 2
3,4,5,1,2

40,10,20,30
10,20,30,40


30,20,10,40
10,20,30,40

*/