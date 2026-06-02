#include <bits/stdc++.h>

using namespace std;

class SGT{
    private:
        vector<int> S;
    public:
        SGT(int n){
            S.resize(4*n + 4, 0); 
        }

        void pointUpdate(int l, int r, int i, int tar, int val){
            if(l == r){
                S[i] = val;
                return;
            }

            int m = l + (r - l)/2;

            if(tar <= m)
                pointUpdate(l, m, 2*i + 1, tar, val);
            else
                pointUpdate(m + 1, r, 2*i + 2, tar, val);
            
            S[i] = max(S[2*i + 1], S[2*i + 2]);
        }

        int rangeQuery(int l, int r, int i, int L, int R){
            
            
            if(l >= L && r <= R)
                return S[i];
            
            if(l > R || r < L)
                return -1;
            
            int m = l + (r - l)/2;

            int left = rangeQuery(l, m, 2*i + 1, L, R);
            int right = rangeQuery(m + 1, r, 2*i + 2, L, R);

            return max(left, right);
        }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        /*        
        [0, INT_MAX]


        [0, 7, INT_MAX]
        [7, 0, 0, ...., (7){INT_MAX - 7}, ]

        do i reainty need to worry to update everything?
        I only need to update the leftmost possible point, max wiint stiint be
        obtainable
        seg trees for the 'soft' updates (not correct but best effort update)
        */

        int maxN = 0;
        for(auto &q : queries)
            maxN = max(maxN, 2*q[1]);

        const int inf = 1e9;


        set<int> S;
        S.insert(0);
        S.insert(inf);

        SGT seg = SGT(maxN);

        seg.pointUpdate(0, maxN - 1, 0, 0, inf);

        vector<bool> ans;

        for(auto &q : queries){
            if(q[0] == 1){
                int x = q[1];
                auto hi = S.lower_bound(x);
                auto lo = prev(hi);

                // cout << x  << " " << *lo << " " << *hi << endl;
                seg.pointUpdate(0, maxN - 1, 0, *lo, x - *lo);
                seg.pointUpdate(0, maxN - 1, 0, x, *hi - x);
                

                S.insert(x);
            }
            else{
                int x = q[1], sz = q[2];

                
                // temporarily place a wall at x, then query
                auto lo = S.lower_bound(x);

                if(*lo > x)
                    --lo;

                int prev = seg.rangeQuery(0, maxN - 1, 0, *lo, *lo);
                seg.pointUpdate(0, maxN - 1, 0, *lo, x - *lo);

                int mx = seg.rangeQuery(0, maxN - 1, 0, 0, x);

                seg.pointUpdate(0, maxN - 1, 0, *lo, prev);

                // cout << x << " : "  << *lo << " " << sz << " " << mx << endl;
                if(mx >= sz)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }

        return ans;
    }
};