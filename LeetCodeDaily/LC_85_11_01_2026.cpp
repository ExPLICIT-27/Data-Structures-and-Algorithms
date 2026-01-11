#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> M(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++)
            M[0][j] = (matrix[0][j] == '1')? 1 : 0;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1')
                    M[i][j] = 1 + M[i - 1][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> pse(m), nse(m);
            stack<int> s1, s2;
            for(int j = 0; j < m; j++){
                while(!s1.empty() && M[i][s1.top()] >= M[i][j])
                    s1.pop();
                pse[j] = (s1.empty())? -1 : s1.top();
                s1.push(j);
            }
            for(int j = m - 1; j >= 0; j--){
                while(!s2.empty() && M[i][s2.top()] >= M[i][j])
                    s2.pop();
                nse[j] = (s2.empty())? m : s2.top();
                s2.push(j);
            }
            for(int j = 0; j < m; j++){
                ans = max(ans, M[i][j]*((nse[j] - 1) - (pse[j] + 1) + 1));
            }
        }

        return ans;
    }
};