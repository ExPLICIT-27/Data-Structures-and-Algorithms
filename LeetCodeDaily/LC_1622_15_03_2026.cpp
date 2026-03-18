#include <bits/stdc++.h>

using namespace std;


#define ll long long
/*
every num is represented as m*x + a

initially m = 1, a = 0

when you add 'y', you do a += y
when you multiply 'y', you mutiply both a and m by 'y'
since if m = 2, a = 3

num = 2*first + 3

multiply by 2, both m and a get multiplied

and becomes 4*first + 6


so now all we need to do is take care of append operations
final values of m, a we store in mul, add

hence what is left to do is now undo the operations done till the point before 
the element was appended to the array

hence element = ((element - add value at time of appending)/(mul value at time of appending))*(Curr mul value) + curr add value

so we store (e - add)/mul when we insert so that when we query, we can just do el*m + a
-
*/

class Fancy {
public:
    const int M = 1e9 + 7;
    vector<ll> A;

    ll mul, add;
    Fancy() {
        mul = 1, add = 0;
    }
    ll binexp(ll base, ll p){
        ll ans = 1;
        while(p){
            if(p & 1)
                ans = (__int128)(ans*base)%M;
            base = (__int128)(base*base)%M;
            p >>= 1;
        }

        return ans;
    }
    void append(int val) {

        // reset number to something it would be b4 applying operations
        ll curr = (val - add + M)%M;
        curr = (__int128)(curr*binexp(mul, M - 2))%M;
        A.push_back(curr);
    }
    
    void addAll(int inc) {
        add = (add + inc)%M;

    }
    
    void multAll(int m) {
        add = (__int128)(add*m)%M;
        mul = (__int128)(mul*m)%M;
    }
    
    int getIndex(int idx) {
        if(idx >= A.size())
            return -1;

        // apply ops
        
        int ans = ((__int128)A[idx]*mul%M + add)%M;

        return ans;
    }
};

