/*
Extending the 1D logic here would fail due to the higher dimensional complexity of the water

What we have to do is use a min heap and process the lowest height cells first
the min heap must initially contain all the boundary cells as they can never contain water
Process the lowest height cell,
go to its neighbors,
if the neighbor has a lower height add the difference to the result,
push the maximum among both the currently processed cell height and neighbor height along with its coordinates to the priority queue
repeat till the queue becomes empty
*/

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int h, r, c;
        Node(int h, int r, int c){
            this->h = h, this->r = r, this->c = c;
        }
};
struct Comparator{
    bool operator()(const Node &a, const Node &b) const {
        return a.h > b.h; // min heap comparator
    }
};

bool isValid(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int trapRainWater(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    priority_queue<Node, vector<Node>, Comparator> pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // pushing the boundary cells
    for(int j = 0; j < m; j++){
        pq.push({grid[0][j], 0, j});
        visited[0][j] = true;
        if(n != 1){
            pq.push({grid[n - 1][j], n - 1, j});
            visited[n - 1][j] = true;
        }
    }
    for(int i = 1; i < n - 1; i++){
        pq.push({grid[i][0], i, 0});
        visited[i][0] = true;
        if(m != 1){
            pq.push({grid[i][m - 1], i, m - 1});
            visited[i][m - 1] = true;
        }
    }

    // bfs setup
    long long result = 0;
    int dirx[] = {0, 0, -1, 1};
    int diry[] = {1, -1, 0, 0};
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++){
            int newx = u.r + dirx[i];
            int newy = u.c + diry[i];
            if(isValid(newx, newy, n, m) && !visited[newx][newy]){
                visited[newx][newy] = true;

                if(grid[newx][newy] < u.h)
                    result += u.h - grid[newx][newy];
                pq.push({max(grid[newx][newy], u.h), newx, newy});
            }
        }
    }
        
    return result;
}
int main(){
    return 0;
}