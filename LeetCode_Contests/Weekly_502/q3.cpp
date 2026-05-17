#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline '\n'
class SGT{
    public:

    vector<int> S;

    SGT(){}
    SGT(int n){
        S.resize(4*n + 1, -1);
    }

    void build(int l, int r, int i, const vector<int> &row){
        if(l == r){
            S[i] = row[l];
            return;
        }
        int m = l + (r - l)/2;

        build(l, m, 2*i + 1, row);
        build(m + 1, r, 2*i + 2, row);

        S[i] = max(S[2*i + 1], S[2*i + 2]);
    }

    int rangeQuery(int l, int r, int L, int R, int i){
        if(l > R || r < L)
            return -1;

        if(l >= L && r <= R)
            return S[i];

        int m = l + (r - l)/2;

        int left = rangeQuery(l, m, L, R, 2*i + 1);
        int right = rangeQuery(m + 1, r, L, R, 2*i + 2);

        return max(left, right);
    }
};
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& mat) {
        
        /*
        mat[i][j] >= 0

        check the square submatrix from mat[i][j] to mat[i - x][j - x] for every i, j
        ignore the corners of the square


        so current TC O(m*n*x^2)

        O(200*200^2), need to get rid of 1 200
        if i make a seg tree on the rows, then i get a log(n) check
        so thats what im gonna do
        */

        
        
        // for each row, a SGT
        int r = mat.size(), c = mat[0].size();
        
        vector<SGT> rows(r);

        for(int i = 0; i < r; i++){
            rows[i] = SGT(c);
            rows[i].build(0, c - 1, 0, mat[i]);
        }

        int ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 0)
                    continue;

                /*
                int strow = max(0, i - x)
                int e
                */
                int x = mat[i][j];
                int frow = max(0, i - x);
                int lrow = min(r - 1, i + x);
                // find the local maxima
                int maxima = x;

                for(int cr = frow; cr <= lrow; cr++){
                    int l, r;

                    if(cr == i - x || cr == i + x){
                        l = max(0, j - x + 1);
                        r = min(c - 1, j + x - 1);
                    }
                    else{
                        l = max(0, j - x);
                        r = min(c - 1, j + x);
                    }
                    
                    maxima = max(maxima, rows[cr].rangeQuery(0, c - 1, l, r, 0));
                }

                if(maxima == x)
                    ans++;
            }
        }

        return ans;
    }
};