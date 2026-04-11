#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SGT {
public:
    vector<ll> S;
    
    SGT(int n) {
        S.resize(4 * n + 1, 0);
    }

    void build(int idx, int low, int high, const vector<ll>& A) {
        if (low == high) {
            S[idx] = A[low];
            return;
        }
        int mid = (low + high)/2;
        build(2 * idx + 1, low, mid, A);
        build(2 * idx + 2, mid + 1, high, A);
        S[idx] = max(S[2 * idx + 1], S[2 * idx + 2]);
    }

    void pointUpdate(int idx, int low, int high, int targetIdx, ll updateVal) {
        if (low == high) {
            S[idx] += updateVal;
            return;
        }
        int mid = (low + high)/2;
        if (targetIdx <= mid)
            pointUpdate(2 * idx + 1, low, mid, targetIdx, updateVal);
        else
            pointUpdate(2 * idx + 2, mid + 1, high, targetIdx, updateVal);
        
        S[idx] = max(S[2 * idx + 1], S[2 * idx + 2]);
    }

    ll query(int idx, int low, int high, int l, int r) {
        // Completely inside target range
        if (low >= l && high <= r)
            return S[idx];
        
        // Completely outside target range
        if (low > r || high < l)
            return LLONG_MIN;
        
        // Overlapping
        int mid = (low + high)/2;
        ll left = query(2 * idx + 1, low, mid, l, r);
        ll right = query(2 * idx + 2, mid + 1, high, l, r);
        
        return max(left, right);
    }
};