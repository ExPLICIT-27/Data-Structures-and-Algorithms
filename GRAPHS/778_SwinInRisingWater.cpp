/*
use a prioirty queue to process it rather than a normal one, so that you visit each cell using the smallest
possible path at any instant
*/
#include <bits/stdc++.h>

using namespace std;

bool isValid(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int swimInWater(vector<vector<int>>& grid) {
    set<pair<int, int>> states;
    int n = grid.size(), m = grid[0].size();
    int dirx[] = {1, -1, 0, 0};
    int diry[] = {0, 0, -1, 1};
    priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
    q.push({grid[0][0], 0, 0});
    int result = INT_MAX;
    states.insert({0, 0});

    while(!q.empty()){
        auto u = q.top();
        q.pop();
        if(u[1] == n - 1 && u[2] == m - 1)
            return u[0];// reached first, since its a min heap, smallest possible method to reach
        for(int i = 0; i < 4; i++){
            int newx = u[1] + dirx[i];
            int newy = u[2] + diry[i];
            if(isValid(newx, newy, n, m) && !states.count({newx, newy})){
                states.insert({newx, newy});
                q.push({max(u[0], grid[newx][newy]), newx, newy});
            }
        }
    }
    return -1;
}
int main(){
    return 0;
}