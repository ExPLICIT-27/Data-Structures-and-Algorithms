#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    /*
    . .
    Y X
    */
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<int, bool>>> P(n, vector<pair<int, bool>>(m, make_pair(0, false)));

        if(grid[0][0] == 'X'){
            P[0][0].first = 1, P[0][0].second = true;
        }
        if(grid[0][0] == 'Y'){
            P[0][0].first = -1;
        }


        int ans = 0;
        for(int i = 1; i < n; i++){
            if(grid[i][0] == 'X'){
                P[i][0].first = 1 + P[i - 1][0].first;
                P[i][0].second = true || P[i - 1][0].second;
            }
            else if(grid[i][0] == 'Y'){
                P[i][0].first = P[i - 1][0].first - 1;
                P[i][0].second = P[i][0].second || P[i - 1][0].second;
            }
            else{
                P[i][0].first = P[i - 1][0].first;
                P[i][0].second = P[i - 1][0].second;
            }

            if(P[i][0].first == 0 && P[i][0].second)
                ans++;
        }

        for(int j = 1; j < m; j++){
            if(grid[0][j] == 'X'){
                P[0][j].first = 1 + P[0][j - 1].first;
                P[0][j].second = true || P[0][j - 1].second;
            }
            else if(grid[0][j] == 'Y'){
                P[0][j].first = P[0][j - 1].first - 1;
                P[0][j].second = P[0][j].second || P[0][j - 1].second;
            }
            else{
                P[0][j].first = P[0][j - 1].first;
                P[0][j].second = P[0][j - 1].second;
            }

            if(P[0][j].first == 0 && P[0][j].second)
                ans++;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                P[i][j].first = P[i - 1][j].first + P[i][j - 1].first - P[i - 1][j - 1].first;
                if(grid[i][j] == 'X'){
                    P[i][j].second = true;
                    P[i][j].first++;
                }
                else if(grid[i][j] == 'Y'){
                    P[i][j].first--;
                    P[i][j].second = (P[i][j].second || P[i - 1][j].second || P[i][j - 1].second || P[i - 1][j - 1].second);
                }
                else
                    P[i][j].second = (P[i][j].second || P[i - 1][j].second || P[i][j - 1].second || P[i - 1][j - 1].second);
                
                if(P[i][j].first == 0 && P[i][j].second)
                    ans++;
            }
        }
    
        return ans;
    }
};