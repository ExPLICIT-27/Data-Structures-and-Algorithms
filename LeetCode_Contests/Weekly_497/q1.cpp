#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    ans[i]++;
                    ans[j]++;
                }
            }
        }
        for(int &i : ans)
            i /= 2;
        return ans;
    }
};