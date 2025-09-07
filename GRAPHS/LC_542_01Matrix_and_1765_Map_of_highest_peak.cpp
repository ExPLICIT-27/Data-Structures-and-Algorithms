/*
solution to LC 542 and 1765 

542
you start from the source which is 0 then start assigning distance to neighbors
the other way round i.e searching for 0 from 1 wont be good

1765
same as 542, the distance from 0 is the peak
*/
#include <bits/stdc++.h>

using namespace std;
// 542, use same logic for 1765
class Node{
    public:
    int x, y, d;
    Node(int x, int y, int d){
        this->x = x, this->y = y, this->d = d;
    }
};
bool isValid(int x, int y, int m, int n){
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}
vector<vector<int>> BFS(vector<vector<int>> &grid){

    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> result(m, vector<int>(n, 0));
    queue<Node> q;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!grid[i][j]){
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }   
    }

    int dirx[] = {1, -1, 0, 0};
    int diry[] = {0, 0, 1, -1};
    while(!q.empty()){
        auto [x, y, d] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(isValid(newx, newy, m, n) && !visited[newx][newy] && grid[newx][newy]){
                result[newx][newy] = d + 1;
                visited[newx][newy] = true;
                q.push({newx, newy, d + 1});
            }
        }
    }
    return result;
}
int main(){
    return 0;
}