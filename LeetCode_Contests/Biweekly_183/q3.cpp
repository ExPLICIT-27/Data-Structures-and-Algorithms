#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        /*
        i dont care about their individual totals
        i care about their intersecting totals

        (0,0) -> (n, m)
        (m - 1, 0) -> (0, n - 1)

        (i, j, q, k)


        top left to bottom right
        then from there i need to go to top 
        */

        int n = grid.size(), m = grid[0].size();

        // ok it doesnt seem like its a dp qn

        // max col sum,

        // max row sm
        int ans = INT_MIN;
        // at least two elements in top row and bottom row

        // top
        vector<int> pr(m + 1, 0);
        pr[1] = grid[0][0], pr[2] = grid[0][1] + grid[0][0];
        set<int> S; S.insert(0);
        ans = max(ans, pr[2]);
        for(int j = 3; j <= m; j++){
            S.insert(pr[j - 2]);
            pr[j] = pr[j - 1] + grid[0][j - 1];

            ans = max(ans, pr[j] - *(S.begin()));
        }

        // bottom
        fill(pr.begin(), pr.end(), 0);
        S.clear();
        pr[1] = grid[n - 1][0], pr[2] = grid[n - 1][1] + grid[n - 1][0];
        S.insert(0);
        ans = max(ans, pr[2]);
        for(int j = 3; j <= m; j++){
            S.insert(pr[j - 2]);
            pr[j] = pr[j - 1] + grid[n - 1][j - 1];

            ans = max(ans, pr[j] - *(S.begin()));
        }

        // mid rows
        for(int j = 1; j < n - 1; j++){
            auto &r = grid[j];
            ans = max(ans, r[0] + r[1]);
            ans = max(ans, r[m - 1] + r[m - 2]);

            int curr = r[0];
            for(int i = 1; i < m - 1; i++){
                curr = max(curr + r[i], r[i]);
                ans = max(ans, curr);
            }

            ans = max(ans, curr + r[m - 1]);
        }


        // left col
        pr.resize(n + 1, 0);
        S.clear();
        pr[1] = grid[0][0], pr[2] = grid[1][0] + grid[0][0];
        S.insert(0);
        ans = max(ans, pr[2]);
        for(int j = 3; j <= n; j++){
            S.insert(pr[j - 2]);
            pr[j] = pr[j - 1] + grid[j - 1][0];

            ans = max(ans, pr[j] - *(S.begin()));
        }

        // right col
        fill(pr.begin(), pr.end(), 0);
        S.clear();
        pr[1] = grid[0][m - 1], pr[2] = grid[1][m - 1] + grid[0][m - 1];
        S.insert(0);
        ans = max(ans, pr[2]);
        for(int j = 3; j <= n; j++){
            S.insert(pr[j - 2]);
            pr[j] = pr[j - 1] + grid[j - 1][m - 1];

            ans = max(ans, pr[j] - *(S.begin()));
        }
        
        for(int j = 1; j < m - 1; j++){
            
            ans = max(ans, grid[0][j] + grid[1][j]);
            ans = max(ans, grid[n - 1][j] + grid[n - 2][j]);

            int curr = grid[0][j];
            for(int i = 1; i < n - 1; i++){
                curr = max(curr + grid[i][j], grid[i][j]);
                ans = max(ans, curr);
            }

            ans = max(ans, curr + grid[n - 1][j]);
        }
        
        
        return ans;
    }
};