// brilliant qn on Binary Search
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    bool isValid(int x, int y, int r, int c){
        return (x >= 0 && x < r && y >= 0 && y < c);
    }
    bool pathExists(vector<vector<bool>> &G){
        queue<pair<int, int>> Q;
        int r = G.size(), c = G[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        for(int j = 0; j < c; j++){
            if(!G[0][j]){
                Q.push({0, j});
                vis[0][j] = true;
            }
        }
        while(!Q.empty()){
            auto [x, y] = Q.front();
            Q.pop();
            if(x == r - 1)
                return true;
            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(isValid(nx, ny, r, c) && !G[nx][ny] && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int L = 1, R = cells.size();

        while(L <= R){
            int M = (L + R)/2;
            vector<vector<bool>> G(row, vector<bool>(col, 0));
            for(int i = 0; i < M; i++){
                G[cells[i][0] - 1][cells[i][1] - 1] = true;
            }
            if(pathExists(G))
                L = M + 1;
            else
                R = M - 1;
        }
        return R;
    }
};