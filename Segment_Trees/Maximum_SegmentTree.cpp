#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Maximum SGT tree
// A - input array, S - Segment tree
// excellent vid - Striver's SGT tree vid
// for sum just change max() to + ez
class SGT{
    public:
        vector<ll> A, S, L; // L is the Lazy tree for lazy propagation 
        SGT(vector<ll> &arr, int n){
            A = arr;
            S.resize(4*n + 1);
            L.resize(4*n + 1, 0);
        }
        void Build(int idx, int low, int high){
            if(low == high){
                S[idx] = A[low];
                return;
            }

            int mid = (low + high)/2;

            Build(2*idx + 1, low, mid);
            Build(2*idx + 2, mid + 1, high);

            S[idx] = max(S[2*idx + 1], S[2*idx + 2]);

        }
        // l, r = target ranges
        ll query(int idx, int low, int high, int l, int r){
            // if low and high completely lies inside target ranges, return max in that range
            if(low >= l && high <= r)
                return S[idx];
            
            //completely outside
            if(low > r || high < l)
                return LLONG_MIN;
            
            // go right and left and fetch the necessary values
            int mid = (low + high)/2;

            ll left = query(2*idx + 1, low, mid, l, r);
            ll right = query(2*idx + 2, mid + 1, high, l, r);

            return max(left, right);
        }

        void pointUpdates(int idx, int low, int high, int targetIdx, ll updateVal){
            if(low == high){
                A[low] += updateVal;
                S[idx] += updateVal;
            }
            else{
                int mid = (low + high)/2;
                if(targetIdx <= mid)
                    pointUpdates(2*idx + 1, low, mid, targetIdx, updateVal);
                else
                    pointUpdates(2*idx + 2, mid + 1, high, targetIdx, updateVal);
                
                S[idx] = max(S[2*idx + 1], S[2*idx + 2]);
            }
        }

        void rangeUpdate(int idx, int low, int high, int l, int r, ll updateVal){
            if(L[idx]){
                S[idx] += L[idx];

                if(low != high){ // if not at any of the leaves, propagate lazy update
                    L[2*idx + 1] += L[idx];
                    L[2*idx + 2] += L[idx];
                }
                // reset the current node to have no updates, already propagated
                L[idx] = 0;
            }

            if(low > r || high < l || low > high)
                return;
            
            if(low >= l && high <= r){

                S[idx] += updateVal;
                if(low != high){ // propagate
                    L[2*idx + 1] += updateVal;
                    L[2*idx + 2] += updateVal;
                }

                return;
            }

            int mid = (low + high)/2;

            rangeUpdate(2*idx + 1, low, mid, l, r, updateVal);
            rangeUpdate(2*idx + 2, mid + 1, high, l, r, updateVal);

            S[idx] = max(S[2*idx + 1], S[2*idx + 2]);
        }

        ll queryLazy(int idx, int low, int high, int l, int r){
            if(L[idx]){
                S[idx] += L[idx];
                
                if(low != high){
                    L[2*idx + 1] += L[idx];
                    L[2*idx + 2] += L[idx];
                }

                L[idx] = 0;
            }

            if(low > r || high < l || low > high)
                return LLONG_MIN;
            
            if(low >= l && high <= r)
                return S[idx];
            
            int mid = (low + high)/2;
            return max(queryLazy(2*idx + 1, low, mid, l, r), queryLazy(2*idx + 2, mid + 1, high, l, r));
        }


};
int main(){

    int n;  

    cout << "\nEnter number of elements : ";
    cin >> n;

    vector<ll> A(n);

    cout << "\nEnter the elements : ";

    for(ll &i : A)
        cin >> i;
    SGT S = SGT(A, n);
    S.Build(0, 0, n - 1);

    int q;
    cout << "\nEnter the number of queries : ";

    cin >> q;

    while(q--){
        int l, r;
        cout << "\nEnter query : ";
        cin >> l >> r;

        cout << "\nOutput : " << S.query(0, 0, n - 1, l, r);
    }

    return 0;
}