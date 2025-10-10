/*
do bfs, applying the reverse condition from both pacific and atlantic and see the intersection of 
the visited arrays
*/
#include <bits/stdc++.h>

using namespace std;

bool isValid(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> result;
    // pacific
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for(int j = 0; j < m; j++){
        q.push({0, j});
        vis[0][j] = true;
    }
    for(int i = 1; i < n; i++){
        q.push({i, 0});
        vis[i][0] = true;
    }
    int dirx[] = {-1, 1, 0, 0};
    int diry[] = {0, 0, -1, 1};
    while(!q.empty()){
        auto u = q.front();
        
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = u.first + dirx[i];
            int newy = u.second + diry[i];
            if(isValid(newx, newy, n, m) && !vis[newx][newy] && heights[newx][newy] >= heights[u.first][u.second]){
                q.push({newx, newy});
                vis[newx][newy] = true;
            }
        }
            
    }

    // atlantic
    vector<vector<bool>> vis2(n, vector<bool>(m, false));
    queue<pair<int, int>> q2;
    for(int j = 0; j < m; j++){
        q2.push({n - 1, j});
        vis2[n - 1][j] = true;
    }
    for(int i = 0; i < n - 1; i++){
        q2.push({i, m - 1});
        vis2[i][m - 1] = true;
    }
    
    while(!q2.empty()){
        auto u = q2.front();
        
        q2.pop();
        for(int i = 0; i < 4; i++){
            int newx = u.first + dirx[i];
            int newy = u.second + diry[i];
            if(isValid(newx, newy, n, m) && !vis2[newx][newy] && heights[newx][newy] >= heights[u.first][u.second]){
                q2.push({newx, newy});
                vis2[newx][newy] = true;
            }
        }  
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] && vis2[i][j])
                result.push_back({i, j});
        }
    }
    return result;

}
int main(){
    return 0;
}