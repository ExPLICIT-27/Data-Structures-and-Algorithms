#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> C(n, 0);
        vector<bool> vis(n + 1, false);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(vis[A[i]])
                cnt++;
            vis[A[i]] = true;
            if(vis[B[i]])
                cnt++;
            vis[B[i]] = true;
            C[i] = cnt;
        }

        return C;
    }
};