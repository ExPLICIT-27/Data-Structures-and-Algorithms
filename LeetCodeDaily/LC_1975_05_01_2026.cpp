#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0, mn = INT_MAX;
        ll sm = 0;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sm += llabs(1ll*matrix[i][j]);
                if(matrix[i][j] < 0)
                    cnt++;
                mn = min(mn, abs(matrix[i][j]));
            }
        }

        if(cnt & 1)
            return sm - 2*mn;
        return sm;
    }
};