#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int dx[]= {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int r = grid.size(), c = grid[0].size();
        int sz = r*c;

        vector<bool> vis(sz, false);
        auto enc = [&](int x, int y) -> int {
            return x*c + y;
        };

        auto dec = [&](int pos) -> pair<int, int> {
            return make_pair(pos/c, pos%c);
        };

        auto isValid = [&](int x, int y, int curr) -> bool {
            return (x >= 0 && x < r && y >= 0 && y < c && (curr == -1 || grid[x][y] == grid[curr/c][curr%c]));
        };


        function<bool(int, int)> dfs;

        dfs = [&](int curr, int par) -> bool {
            vis[curr] = true;

            auto [x, y] = dec(curr);
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                
                if(!isValid(nx, ny, curr))
                    continue;

                int npos = enc(nx, ny);

                if(vis[npos]){
                    if(npos != par)
                        return true;
                }
                else{
                    if(dfs(npos, curr))
                        return true;
                }
            }

            return false;
        };

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int pos = enc(i, j);
                if(!vis[pos]){
                    if(dfs(pos, -1))
                        return true;
                }
            }
        }

        return false;
    };
};