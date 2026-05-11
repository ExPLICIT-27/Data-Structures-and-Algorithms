#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        /*
        2*side + (side - y)
        */
        
        vector<ll> A;


        for(auto &p : points){
            if(p[0] == 0)
                A.push_back(p[1]);
            else if(p[1] == side)
                A.push_back(1ll*side + p[0]);
            else if(p[0] == side)
                A.push_back(2ll*side + (side - p[1]));
            else
                A.push_back(3ll*side + (side - p[0]));
        }

        sort(A.begin(), A.end());

        ll L = 0, R = side; // 4 pnts, max diff is side only

        int n = A.size();

        auto chck = [&](ll M) -> bool {
            for(int i = 0; i < n; i++){
                ll curr = A[i];
                for(int j = 0; j < k - 1; j++){
                    auto it = lower_bound(A.begin(), A.end(), curr + M);

                    if(it == A.end()){
                        curr = -1;
                        break;
                    }
                    curr = *it;
                }

                if(curr == -1)
                    continue;
                // front gap is okay, back gap we need to verify
                // basically turn the forward distance to backward distance
                // its just 4*side - curr, and +A[i]
                if(4ll*side - curr + A[i] >= M)
                    return true;

            }

            return false;
        };
        while(L <= R){
            ll M = L + (R - L)/2;
            if(chck(M))
                L = M + 1;
            else
                R = M - 1;
        }

        return R;
    }
};