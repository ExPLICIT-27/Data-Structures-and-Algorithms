#include <bits/stdc++.h>
using namespace std;


#define ll long long
class SGT{
private:    
    int N;
    vector<ll> S;
public:
    SGT(int N){
        this->N = N;
        S.resize(4*N + 1, 0);
    }

    void PU(int i, int l, int r, int tar, int val){
        if(l == r){
            S[i] += val;
            return;
        }

        int m = (l + r)/2;

        if(tar <= m)
            PU(2*i + 1, l, m, tar, val);
        else
            PU(2*i + 2, m + 1, r, tar, val);
        
        S[i] = S[2*i + 1] + S[2*i + 2];
    }

    ll RQ(int i, int l, int r, int L, int R){
        if(l > R || r < L || l > r)
            return 0;
        
        if(l >= L && r <= R)
            return S[i];
        
        int m = (l + r)/2;

        return RQ(2*i + 1, l, m, L, R) + RQ(2*i + 2, m + 1, r, L, R);
    }

};
class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {

        /*
        reduce TC from O(N^2) to O(NlogN) or O(N)
        yup, need seg trees for this qn
        

        x/y  <= a/b
        x*b <= a*y

        even*b <= odd*y
        
        in subarray [l...r], 
        length = (r - l + 1)

        (length - odd)*b <= odd*a
        length*b <= odd*(a + b)

        (r - l + 1)*b <= (pref[r + 1] - pref[l])*(a + b)
        b*r - l*b + b <= pref[r + 1]*(a + b) - pref[l]*(a + b)
        pref[l]*(a + b) - l*b <= pref[r + 1]*(a + b) - b*(r + 1)

        storing P[i] as pref[i]*(a + b) - i*b
        and then applying the standard non monotonic condition
        of count of P[r] >= P[l] using seg trees will generate the answer
        need to apply coordinate compressedion over P to using seg trees
        */

        int N = nums.size();
        vector<int> prefOdd(N + 1, 0);


        // odd prfx
        for(int i = 0; i < N; i++)
            prefOdd[i + 1]  = prefOdd[i] + (nums[i] & 1);
        
        vector<ll> P(N + 1);


        // valued prfx
        for(int i = 0; i <= N; i++)
            P[i] = 1ll*prefOdd[i]*(a + b) - 1ll*i*b;
        

        // coordinate compressedion
        vector<ll> compressed = P;
        sort(compressed.begin(), compressed.end());
        compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

        auto getIdx = [&](ll val) -> int {
            return lower_bound(compressed.begin(), compressed.end(), val) - compressed.begin();
        };


        int usz = compressed.size();

        SGT seg = SGT(usz);


        ll ans = 0;
        for(int i = 0; i <= N; i++){
            int idx = getIdx(P[i]);
            ans += seg.RQ(0, 0, usz - 1, 0, idx);
            seg.PU(0, 0, usz - 1, idx, 1);
        }

        return ans;
    }
};