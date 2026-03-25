#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll total = 0;


        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++){
            total += accumulate(grid[i].begin(), grid[i].end(), 0ll);
        }

        
        if(total & 1)
            return false;
        
        ll target = total/2;
        ll curr = 0;
        for(int i = 0; i < n - 1; i++){
            curr += accumulate(grid[i].begin(), grid[i].end(), 0ll);
            if(curr == target)
                return true;
        }
        
        curr = 0;

        for(int j = 0; j < m - 1; j++){
            for(int i = 0; i < n; i++)
                curr += grid[i][j];
            
            if(curr == target)
                return true;
        }

        return false;
    }
};