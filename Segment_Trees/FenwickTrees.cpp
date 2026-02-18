#include <bits/stdc++.h>
#define ll long long
using namespace std;

// based on difference array updates
/*
look up proof later if needed, for now Prefix[x] = x*b1[x] - b2[x]
FenwickXorB aka Binary Indexed Trees (BIT)
For sums only
*/
// IMPORTANT VERY VERY : FENWICK TREES ARE 1 INDEXED pls dont mess up
class FenwickSum{
    public:

    int n;

    vector<ll> BIT1, BIT2; // these will be the difference arrays, BIT1 normal diff array, BIT2 diffarray*(range-1)

    FenwickSum(int n) : n(n) {
        BIT1.assign(n + 1, 0);
        BIT2.assign(n + 1, 0);
    }

    // call 1 by 1 on each array element
    void add(vector<ll> &BIT, int i, ll val){
        for(; i <= n; i += (i & -i)){ // find rightmost set BIT and subtract to go to parent
            BIT[i] += val;
        }   
    }

    // prefix sum func
    ll sum(vector<ll> &BIT, int i){
        ll res = 0;
        
        for(; i > 0; i -= (i & -i))
            res += BIT[i];
        
        return res;
    }

    // range add

    void rangeUpdate(int l, int r, ll val){
        // diff array update
        add(BIT1, l, val);
        add(BIT1, r + 1, -val);

        // diff*range update
        add(BIT2, l, val*(l - 1));
        add(BIT2, r + 1, -val*r);
    }

    // primary prefix sum func
    ll prefixSum(int i){
        return i*sum(BIT1, i) - sum(BIT2, i);
    }

    // rangesum
    ll rangeSum(int l, int r){
        if(l > r)
            return 0;
        
        return prefixSum(r) - prefixSum(l - 1);
    }

    // point update
    void pointUpdate(int i, ll val){
        rangeUpdate(i, i, val);
    }

    // point query
    ll pointQuery(int i){
        return rangeSum(i, i);
    }
};
/*There are two ways to use a FenwickXorB Tree for this problem.
Method A (Point Update / Range Query): You update one index and query the sum of a range.
Method B (Range Update / Point Query): You update a range [L, R] by XORing L and R+1. Then, a Prefix XOR at index i gives you the current value at i. 

cant do both at once
*/

// each node stores partial xor values
class FenwickXorA {// type A
public:
    int n;
    vector<ll> bit;

    FenwickXorA(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    // point update: a[i] ^= val
    void pointUpdate(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    // prefix xor [1..i]
    ll prefixXor(int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    // range xor [l..r]
    ll rangeXor(int l, int r) {
        return prefixXor(r) ^ prefixXor(l - 1);
    }


};

// each element stores difference array values
// hence for point query, you have to xor till start
class FenwickXorB { // method B
public:
    int n;
    vector<ll> bit;

    FenwickXorB(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void add(int i, int val){
        for(; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    // range XOR update
    void rangeUpdate(int l, int r, int val){
        add(l, val);
        add(r+1, val);
    }

    // point query
    ll pointQuery(int i){
        ll res = 0;
        for(; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }
};

int main(){
    vector<int> A = {1, 3, -1, 4, 5};
    FenwickSum F(5);


    for(int i = 0; i < 5; i++)
        F.pointUpdate(i + 1, A[i]);

    cout << F.rangeSum(1, 4) << endl;

    F.rangeUpdate(2, 3, 2);

    cout << F.rangeSum(1, 4) << endl;
    return 0;
}