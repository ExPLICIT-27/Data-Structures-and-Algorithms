#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));


        for(int x = 0; x <= n - k; x++){
            for(int y = 0; y <= m - k; y++){
                int sz = k*k;
                vector<int> T(sz, 0);
                int idx = 0;

                for(int xinc = 0; xinc < k; xinc++){
                    for(int yinc = 0; yinc < k; yinc++)
                        T[idx++] = grid[x + xinc][y + yinc];
                }

                sort(T.begin(), T.end());
                ans[x][y] = INT_MAX;
                
                for(int i = 1; i < sz; i++){
                    if(T[i] == T[i - 1])
                        continue;
                    ans[x][y] = min(ans[x][y], T[i] - T[i - 1]);
                }
                
                ans[x][y] = (ans[x][y] == INT_MAX)? 0 : ans[x][y];
            }
        }

        return ans;
    }
};