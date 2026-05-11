#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose + reverse rows = 90

        int n = matrix.size();


        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        for(auto &r : matrix)
            reverse(r.begin(), r.end());
    }
};