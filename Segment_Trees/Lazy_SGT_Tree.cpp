#include <bits/stdc++.h>
#define ll long long
using namespace std;

class LazySGT {
public:
    vector<ll> S, L;

    LazySGT(int n) {
        S.resize(4 * n + 1, 0);
        L.resize(4 * n + 1, 0);
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

    // Helper function to push pending lazy updates downwards
    void push(int idx, int low, int high) {
        if (L[idx] != 0) {
            S[idx] += L[idx]; // Apply pending update to current node
            
            if (low != high) { // If not a leaf, pass the laziness to children
                L[2 * idx + 1] += L[idx];
                L[2 * idx + 2] += L[idx];
            }
            L[idx] = 0; // Clear current node's laziness
        }
    }

    void rangeUpdate(int idx, int low, int high, int l, int r, ll updateVal) {
        push(idx, low, high); // Ensure current node is up-to-date first

        if (low > r || high < l) 
            return; // Completely outside
        
        if (low >= l && high <= r) { // Completely inside
            L[idx] += updateVal; // Mark lazily
            push(idx, low, high); // Apply immediately to this node
            return;
        }

        // Overlapping
        int mid = (low + high)/2;
        rangeUpdate(2 * idx + 1, low, mid, l, r, updateVal);
        rangeUpdate(2 * idx + 2, mid + 1, high, l, r, updateVal);
        
        S[idx] = max(S[2 * idx + 1], S[2 * idx + 2]);
    }

    ll query(int idx, int low, int high, int l, int r) {
        push(idx, low, high); // Always push before querying

        if (low > r || high < l) 
            return LLONG_MIN; // Completely outside
        
        if (low >= l && high <= r) 
            return S[idx]; // Completely inside
        
        // Overlapping
        int mid = (low + high)/2;
        ll left = query(2 * idx + 1, low, mid, l, r);
        ll right = query(2 * idx + 2, mid + 1, high, l, r);
        
        return max(left, right);
    }
};