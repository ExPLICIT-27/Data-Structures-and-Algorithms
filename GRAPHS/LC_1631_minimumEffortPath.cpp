/*
LeetCode 1631 solution
It does seem like its a dynamic programming problem, but its complicated to sort out the 
recurrence relations and meet the condition of keeping track of maximum and finding minimum
Dp wont work here

Do priority queue based dfs
- min effort path is the path from 0,0 to m-1, n-1 such that the absolute difference between any two consecutive moves
is minimized 
*/

#include <bits/stdc++.h>

using namespace std;

// class for storing node information
class Node{
    public:
        int x, y, d;
        Node(int x, int y, int d){
            this->x = x, this->y = y, this->d = d;
        }
    
};
// comparator for the priority queue
struct Comparator{
    bool operator()(const Node &a, const Node &b) const {
        return a.d > b.d;
    }
};
// check validity of index
bool isValid(int x, int y, int n, int m){
    return (x >= 0 && y >= 0 && x < n && y < m);
}
int minimumEffortPath(vector<vector<int>>& heights){

    int n = heights.size(), m = heights[0].size();

    // initialize the conditions for dijkstra/bfs
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;
    priority_queue<Node, vector<Node>, Comparator> pq;
    pq.push({0, 0, 0});

    // set up dirn arrays
    int dirx[] = {-1, 1, 0, 0};
    int diry[] = {0, 0, -1, 1};
    while(!pq.empty()){
        auto node = pq.top();
        int x = node.x, y = node.y;
        pq.pop();

        for(int i = 0; i < 4; i++){
            int newx = x + dirx[i];
            int newy = y + diry[i];

            if(isValid(newx, newy, n, m)){
                // the cost function (VVIMP)
                int offset = max(abs(heights[newx][newy] - heights[x][y]), dist[x][y]);
                
                if(dist[newx][newy] > offset){
                    dist[newx][newy] = offset;
                    pq.push({newx, newy, offset});
                }
            }
        }
    }

    return dist[m - 1][n - 1];

}

int main(){
    return 0;
}
