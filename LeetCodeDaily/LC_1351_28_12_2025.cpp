#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        int j = 0;
        for(int i = n - 1; i >= 0; i--){
            if(grid[i][j] < 0)
                cnt += (m - j);
            else{
                while(j < m && grid[i][j] >= 0)
                    j++;
                if(j >= m)
                    break;
                cnt += (m - j);
            }
        }
        return cnt;
    }
};