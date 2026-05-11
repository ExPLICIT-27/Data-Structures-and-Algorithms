#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& B) {
        /*
        A stone '#'
        A stationary obstacle '*'
        Empty '.'
        */
        int m = B.size(), n = B[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for(int i = 0; i < m; i++){
            int ccnt = 0;
            for(int j = 0; j < n; j++){
                if(B[i][j] == '#'){
                    ccnt++;
                }
                else if(B[i][j] == '*'){
                    ans[j][m - i - 1] = '*';
                    for(int k = 0; k < ccnt; k++)
                        ans[j - k - 1][m - i - 1] = '#';
                    ccnt = 0;
                }
            }

            for(int k = 0; k < ccnt; k++)
                ans[n - k - 1][m - i - 1] = '#';
        }

        return ans;
    }
};