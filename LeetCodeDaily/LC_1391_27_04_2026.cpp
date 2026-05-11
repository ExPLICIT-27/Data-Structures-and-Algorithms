#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        /*

        1 : accept from left and from right
            can put to right or put to left
        2 : accept from top or bottom
            can put to bottom or top
        3 : accept from left or bottom
            can put to bottom or left
        4 : accept from bottom or right
            can put to right or bottom
        5 : accept from left or top
            can put to top or left
        6 : accept form top or right
            can put to right or top

        */

        int dx[][2] = {{}, {0, 0}, {1, -1}, {1, 0}, {1, 0}, {-1, 0}, {-1, 0}};
        int dy[][2] = {{}, {1, -1}, {0, 0}, {0, -1}, {0, 1}, {0, -1}, {0, 1}};

        

        vector<vector<bool>> vis(r, vector<bool>(c, false));
        vis[0][0] = true;


        queue<pair<int, int>> q;
        q.push({0, 0});

        auto isValid = [&](int x, int y, char dirn) -> bool {
            bool ok1 = (x >= 0 && x < r && y >= 0 && y < c);

            if(!ok1)
                return false;
            
            int nxt = grid[x][y];
            if(dirn == 'U')
                return (nxt == 2 || nxt == 4 || nxt == 3);
            if(dirn == 'R')
                return (nxt == 3 || nxt == 5 || nxt == 1);
            if(dirn == 'L')
                return (nxt == 4 || nxt == 6 || nxt == 1);
            
            return (nxt == 5 || nxt == 6 || nxt == 2);
        };

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 2; i++){
                int incx = dx[grid[x][y]][i], incy = dy[grid[x][y]][i];

                char dirn;
                if(incx == 0 && incy == 1)
                    dirn = 'R';
                else if(incx == 0 && incy == -1)
                    dirn = 'L';
                else if(incx == 1 && incy == 0)
                    dirn = 'D';
                else
                    dirn = 'U';

                int nx = x + incx, ny = y + incy;
                if(!isValid(nx, ny, dirn) || vis[nx][ny])
                    continue;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return vis[r - 1][c - 1];
    }
};