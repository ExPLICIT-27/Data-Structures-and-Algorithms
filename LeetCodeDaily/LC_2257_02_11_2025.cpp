#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // guard 1, wall 2
        for(auto &v : guards){
            grid[v[0]][v[1]] = -1;
        }
        for(auto &v : walls){
            grid[v[0]][v[1]] = -2;
        }

        
        for(auto &vec : guards){
            int i = vec[0], j = vec[1];
            int u = i, v = j + 1;
            // go right
            while(isValid(u, v, m, n) && grid[u][v] != -2 && grid[u][v] != -1){
                vis[u][v++] = 1;
            }
            v = j - 1;
            // go left
            while(isValid(u, v, m, n)  && grid[u][v] != -2 && grid[u][v] != -1)
                vis[u][v--] = 1;
            // go up
            u = i + 1, v = j;
            while(isValid(u, v, m, n)  && grid[u][v] != -2 && grid[u][v] != -1)
                vis[u++][v] = 1;
            u = i - 1;
            // go down
            while(isValid(u, v, m, n)  && grid[u][v] != -2 && grid[u][v] != -1)
                vis[u--][v] = 1;
        }
        int cnt = 0;
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j])
                    cnt++;
            }
        }
        return cnt - walls.size() - guards.size();
    }
};