#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& M) {
        /*
        without rearranges, it is the largest rectangle question

        with rearranges it becomes something else


        Idea - 1
        i form the heights, then for each row, i push the heights to a vector, sort it
        , cnt the number of elements with height >= every element i come across
        ans = cnt*height
        */
        int n = M.size(), m = M[0].size();

        vector<int> H(m, 0);

        for(int j = 0; j < m; j++)
            H[j] = M[0][j];
        sort(H.begin(), H.end());

        int ans = 0;

        for(int j = 0; j < m; j++)
            ans = max(ans, H[j]*(m - j));

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j])
                    M[i][j] += M[i - 1][j];
                H[j] = M[i][j];
            }
            sort(H.begin(), H.end());

            for(int j = 0; j < m; j++)
                ans = max(ans, H[j]*(m - j));
        }

        return ans;
    }
};