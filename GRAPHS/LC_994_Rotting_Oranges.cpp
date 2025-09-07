/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

algorithm:
- Perform bfs over the rotten apples, mark the adjacent fresh apples as rotten with a time = 1 + time taken for
the rotten apple that affects it to become rotten
- return -1 if it is not possible to rot all the apples
*/
#include <bits/stdc++.h>

using namespace std;

class Rotten{
    public:
        int x, y, t;
        Rotten(int x, int y, int t){
            this->x = x, this->y = y, this->t = t;
        }
    
};
bool isValid(int x, int y, int m, int n){
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}
int MinTimeToRot(vector<vector<int>> &grid){

    int m = grid.size(), n = grid[0].size();

    queue<Rotten> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    int freshCount = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                q.push({i, j, 0});
                visited[i][j] = true;
            }
            if(grid[i][j] == 1)
                freshCount++;
        }
    }

    if(!freshCount)
        return 0;
    
    // down = (1, 0), up = (-1, 0), right = (0, 1), left = (0, -1)
    int dirx[] = {1, -1, 0, 0};
    int diry[] = {0, 0, 1, -1};

    int maxTime = 0;
    while(!q.empty()){
        auto [x, y, t] = q.front();
        q.pop();
        maxTime = max(maxTime, t);
        for(int i = 0; i < 4; i++){
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(isValid(newx, newy, m, n) && !visited[newx][newy] && grid[newx][newy] == 1){
                q.push({newx, newy, 1 + t});
                visited[newx][newy] = true;
                freshCount--;
            }
        }
    }

    // fresh oranges left ? then return -1 else return the time taken to rot everything
    return freshCount ? -1  : maxTime;
}
int main(){
    return 0;
}
