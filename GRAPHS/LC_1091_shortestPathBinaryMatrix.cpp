/*
Given a binary matrix, find the shortest path from 0,0 to n-1, n-1
you are allowed to travel only through 0s and in in any of the 8 directions

note that this is similar to a directed graph with unit weights
since the weights are unit, a normal queue with bfs would work
*/

#include <bits/stdc++.h>

using namespace std;

bool isValid(int x, int y, int n){
    return (x >= 0 && y >= 0 && x < n && y < n);
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    int n = grid.size();

    // base case if the starting or ending path do not have 0, impossible to visit
    if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;

    // direction arrays for all 8 dirns
    int dirx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int diry[] = {0, 0, -1, 1, -1, 1, -1, 1};

    //diStance matrix storing shortest path
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = 1; // starting node

    queue<pair<int, int>> q;
    q.push({0, 0});

    // begin bfs
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int newx = x + dirx[i];
            int newy = y + diry[i];

            if(isValid(newx, newy, n) && !grid[newx][newy] && dist[newx][newy] > dist[x][y] + 1){
                dist[newx][newy] = 1 + dist[x][y];
                q.push({newx, newy});
            }

        }
    }

    // return the value if obtained, else -1
    return dist[n - 1][n - 1] == INT_MAX ? -1 : dist[n - 1][n - 1];


}
int main(){
    return 0;
}