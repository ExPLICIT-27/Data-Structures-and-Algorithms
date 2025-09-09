
#include <bits/stdc++.h>

using namespace std;

bool isValid(int x, int y, int m, int n){
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}
int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    // push the boundaries as multi source and count the 
    // total enclaves and subtract while performing bfs
    int enclaves = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                if(!visited[i][j] && grid[i][j]){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
            else if(grid[i][j])
                enclaves++;
        }
    }
    
    // perform multisource bfs
    int dirx[] = {-1, 1, 0, 0};
    int diry[] = {0, 0, 1, -1};
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(isValid(newx, newy, m, n) && !visited[newx][newy] && grid[newx][newy]){
                q.push({newx, newy});
                visited[newx][newy] = true;
                enclaves--;
            }
        }
    }
    return enclaves;
}
int main(){
    return 0;
}