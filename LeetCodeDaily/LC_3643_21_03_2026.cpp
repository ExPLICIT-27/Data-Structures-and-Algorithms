#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int L = x, R = x + k - 1;

        while(L < R){
            for(int j = y; j < y + k; j++)
                swap(grid[L][j], grid[R][j]);
            R--, L++;
        }

        return grid;
    }
};